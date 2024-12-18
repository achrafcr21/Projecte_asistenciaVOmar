from awscrt import mqtt
from awsiot import mqtt_connection_builder
import time
import json
import pymysql
import requests

# Configuración de AWS IoT
ENDPOINT = "a2h5k7r8gs78nl-ats.iot.us-east-1.amazonaws.com"  # Nuevo endpoint MQTT
CLIENT_ID = "esp32"                # Identificador único para tu dispositivo
TOPIC = "esp32/pub"                 # Topic al que te suscribirás
RESPONSE_TOPIC = "esp32/sub"  # Topic para enviar confirmaciones
CERTIFICATE_PATH = "certificats/new_certificate.pem.crt"  # Corrige la extensión
PRIVATE_KEY_PATH = "certificats/new_private.pem.key"      # Ya correcto
CA_PATH = "certificats/AmazonRootCA1.pem"                 # Correcto              # Ruta del Amazon Root CA

# Configuración de MySQL
DB_HOST = "localhost"
DB_USER = "root"
DB_PASSWORD = "system"
DB_NAME = "projecte_assistencia"

# URL del endpoint de FastAPI
FASTAPI_URL = "http://localhost:8000/asistencias/"

# Callback para cuando se recibe un mensaje
# Callback para cuando se recibe un mensaje
def on_message_received(topic, payload, **kwargs):
    print(f"Mensaje recibido en el topic '{topic}': {payload.decode()}")
    try:
        data = json.loads(payload)
        insertar_en_base_de_datos(data)
    except Exception as e:
        print(f"Error procesando el mensaje: {e}")


# Guardar datos en la base de datos y enviar a la API
def insertar_en_base_de_datos(data):
    try:
        conexion = pymysql.connect(
            host=DB_HOST,
            user=DB_USER,
            password=DB_PASSWORD,
            database=DB_NAME
        )
        with conexion.cursor() as cursor:
            query_buscar_usuario = "SELECT id FROM Usuarios WHERE uid = %s"
            cursor.execute(query_buscar_usuario, (data['uid'],))
            resultado = cursor.fetchone()

        if resultado:
            usuario_id = resultado[0]
            payload = {
                "usuario_id": usuario_id,
                "fecha": time.strftime("%Y-%m-%d"),
                "hora_entrada": time.strftime("%H:%M:%S"),
                "estado": "presente"
            }
            response = requests.post(FASTAPI_URL, json=payload)
            response.raise_for_status()  # Si hay un error, se captura abajo
            print("Datos enviados correctamente a la API.")
            enviar_confirmacion("activar_verd")  # Solo éxito → activar_verd
        else:
            print("No se encontró el usuario con el UID.")
            enviar_confirmacion("activar_vermell")  # No encontrado → activar_vermell

    except requests.exceptions.RequestException as e:
        print(f"Error al enviar datos a la API: {e}")
        enviar_confirmacion("activar_vermell")  # Error en la API → activar_vermell
    except Exception as e:
        print(f"Error: {e}")
        enviar_confirmacion("activar_vermell")  # Otro error → activar_vermell
    finally:
        conexion.close()


# Publicar confirmación al topic de respuesta
def enviar_confirmacion(mensaje):
    mqtt_connection.publish(
        topic=RESPONSE_TOPIC,
        payload=mensaje,
        qos=mqtt.QoS.AT_LEAST_ONCE
    )
    print(f"Mensaje enviado al topic '{RESPONSE_TOPIC}': {mensaje}")

    # Publicar el mensaje en el topic de respuesta
    mqtt_connection.publish(
        topic=RESPONSE_TOPIC,
        payload=mensaje,  # Envía solo el string adecuado
        qos=mqtt.QoS.AT_LEAST_ONCE
    )
    print(f"Mensaje enviado al topic '{RESPONSE_TOPIC}': {mensaje}")

# Crear conexión MQTT con el nuevo endpoint y certificados
mqtt_connection = mqtt_connection_builder.mtls_from_path(
    endpoint=ENDPOINT,
    cert_filepath=CERTIFICATE_PATH,
    pri_key_filepath=PRIVATE_KEY_PATH,
    ca_filepath=CA_PATH,
    client_id=CLIENT_ID,
    clean_session=False,
    keep_alive_secs=30,
)

# Conexión y suscripción
print(f"Conectando al nuevo endpoint {ENDPOINT}...")
connect_future = mqtt_connection.connect()
connect_future.result()
print("¡Conexión exitosa a AWS IoT!")

print(f"Suscribiéndose al topic '{TOPIC}'...")
subscribe_future, _ = mqtt_connection.subscribe(
    topic=TOPIC,
    qos=mqtt.QoS.AT_LEAST_ONCE,
    callback=on_message_received
)
subscribe_future.result()
print(f"¡Suscripción completada al topic '{TOPIC}'!")

# Mantener la conexión activa
try:
    print("Esperando mensajes... (Ctrl+C para salir)")
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    print("Desconectando...")
    mqtt_connection.disconnect()