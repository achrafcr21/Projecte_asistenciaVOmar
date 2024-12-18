#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <MFRC522.h>
#include <SPI.h>
#include "secrets.h"

// Definició de pines
#define SS_PIN 5
#define RST_PIN 0
#define LED_VERD 26
#define LED_VERMELL 27

MFRC522 mfrc522(SS_PIN, RST_PIN);
WiFiClientSecure net;
PubSubClient client(net);

String uidAnterior = "";

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Missatge rebut de topic ");
  Serial.println(topic);

  char message[length + 1]; // Array de caràcters per al missatge
  for (unsigned int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  message[length] = '\0'; // Afegir el terminador de cadena

  Serial.print("Missatge processat: ");
  Serial.println(message);

  // Separar les condicions per a cada LED
  if (strcmp(message, "activar_verd") == 0) {
    Serial.println("Activant LED Verd...");
    digitalWrite(LED_VERD, HIGH);
    digitalWrite(LED_VERMELL, LOW);
    delay(2000);
    digitalWrite(LED_VERD, LOW);
    Serial.println("LED Verd activat i apagat.");
  } 

  if (strcmp(message, "activar_vermell") == 0) {
    Serial.println("Activant LED Vermell...");
    digitalWrite(LED_VERMELL, HIGH);
    digitalWrite(LED_VERD, LOW);
    delay(2000);
    digitalWrite(LED_VERMELL, LOW);
    Serial.println("LED Vermell activat i apagat.");
  }

  if (strcmp(message, "activar_verd") != 0 && strcmp(message, "activar_vermell") != 0) {
    Serial.println("Comanda desconeguda.");
  }
}

void inicialitzarWiFi() {
  Serial.print("Connectant a WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connectat.");
}

void inicialitzarMQTT() {
  net.setCACert(rootCA);
  net.setCertificate(certificate);
  net.setPrivateKey(privateKey);
  client.setServer(AWS_IOT_ENDPOINT, 8883);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.print("Connectant a AWS IoT...");
    if (client.connect(THINGNAME)) {
      client.subscribe("esp32/sub");
      Serial.println("Connectat i subscrit al topic.");
    } else {
      Serial.print("Error: ");
      Serial.println(client.state());
      delay(1000);
    }
  }
}

void enviarMQTT(const String &payload) {
  if (!client.publish("esp32/pub", payload.c_str())) {
    Serial.println("Error enviant el missatge.");
  } else {
    Serial.println("Missatge enviat: " + payload);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_VERD, OUTPUT);
  pinMode(LED_VERMELL, OUTPUT);

  inicialitzarWiFi();
  inicialitzarMQTT();

  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("RFID llest per llegir.");
}

void loop() {
  client.loop();

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uidActual = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uidActual += String(mfrc522.uid.uidByte[i], HEX);
      if (i < mfrc522.uid.size - 1) uidActual += ":";
    }
    mfrc522.PICC_HaltA();

    if (uidActual != uidAnterior) {
      uidAnterior = uidActual;
      Serial.println("UID detectat: " + uidActual);
      String payload = "{\"uid\": \"" + uidActual + "\"}";
      enviarMQTT(payload);
    }
  }
}
