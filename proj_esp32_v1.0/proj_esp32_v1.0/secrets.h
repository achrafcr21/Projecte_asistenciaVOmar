
#ifndef SECRETS_H
#define SECRETS_H

#include <pgmspace.h>

// AWS IoT endpoint y configuración WiFi
#define SECRET
#define THINGNAME "ESP32"
const char WIFI_SSID[] = "AP projecte";
const char WIFI_PASSWORD[] = "clauinsegura";
const char AWS_IOT_ENDPOINT[] = "a2h5k7r8gs78nl-ats.iot.us-east-1.amazonaws.com";

// Amazon Root CA 1
static const char rootCA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char certificate[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUbBbONsOCT6NW5yGNetivsArsgd0wDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI0MTExNDE1MjMw
M1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALUNiJ8AbE1qq12hx2Y8
2HNOH4Lc2i6zzRJF7SxGtwthoaDcbdbyCAQEwZztrKFYjlO5oQ1UNlMsryLdD/r/
Sp4udAlt/h+wK0Ydz2hf81GwyJPWj4UQ/d6pdDkjg8z4mVYKMwpVXmOlgVmtr0Ec
bbPqHyL+KGR+d3Al6MHli6MuwnDt5MO/wKaPTYNNDe0951CjoQEw+n3TWyHab8if
RKn0CQL8tFBM6pe4RkHZYGieDRc3CQjQ/jibf4rlZyRwVFPCC74xpwTq99bvoFLs
5MXYStzw7lskKenFVmlStsrhoB/MTsFW5XZIcbK+JN9owUMScPOzPeWBw3mVuWwL
rW0CAwEAAaNgMF4wHwYDVR0jBBgwFoAUBVKVBP6sJueDz0ESBVLKi369b3swHQYD
VR0OBBYEFMGHDigwe89zOmeRjTBwde1IRjdUMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBFNRrZW/hHT4e2WnlTSsUlgcFV
Juv6oEClmlGV3PGxAHGtuD0sB5e58khOpYnpuqpiuOcbsZ5b/fIB5+W97sdtE7jZ
LSg802TuDXtZNTXe0i7e46ZVDpppx/7DO10rcmEJRFPJrEhpQ7HZF0awGRspFF1z
3kfXPbO8rgaoZtsiZ0DoI3CIoKBSkafI1RR/xMi9g4FX9TyMwn/kJoPml5W4uHiY
+4Re+Aja/j1NgzHMUynwKIGYSaeNA3/jYg0KgTqeSi2KDpguUNly7uWIlWwwivCn
CrZV9MXnY5j9yqqG8wW3qAtHbxnKihj3/p90LZQel9T6LMyoWDPlFpR6z5IY
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char privateKey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAtQ2InwBsTWqrXaHHZjzYc04fgtzaLrPNEkXtLEa3C2GhoNxt
1vIIBATBnO2soViOU7mhDVQ2UyyvIt0P+v9Kni50CW3+H7ArRh3PaF/zUbDIk9aP
hRD93ql0OSODzPiZVgozClVeY6WBWa2vQRxts+ofIv4oZH53cCXoweWLoy7CcO3k
w7/Apo9Ng00N7T3nUKOhATD6fdNbIdpvyJ9EqfQJAvy0UEzql7hGQdlgaJ4NFzcJ
CND+OJt/iuVnJHBUU8ILvjGnBOr31u+gUuzkxdhK3PDuWyQp6cVWaVK2yuGgH8xO
wVbldkhxsr4k32jBQxJw87M95YHDeZW5bAutbQIDAQABAoIBADElkVaICN4i/I2Y
IsaP8bmrFUayqM9Qo3Q4Yx9HutxuDi/aZj6YyLA+kkgFBH1vyoLTuvIhT/XYBVqT
Y4kgz6KMvZbpsrfrXHPWF70ffq9IK8plzeOzLxbILPJtv5NeUFFYx24gqlSmUqyD
RzWHgAf8n6MiFtjgs49P2xT3OKZ8z+m9lpufzC/2OXMperEWfwUHUaIPvBJkqyT+
DapFES6ioe+z8m7BFPJfeHFfTO+K4J3PTlLwbKYdsb6JjswDTkFclZLgaoj3ahzw
JXxCy/bumUG6DW/a8bB3ypVbxeFRIOec2n7m5lpMuQZl1YrYNFvEr5NU8EwZ5yPG
69eCfEkCgYEA4hHDV64msrpl1sIVMHea5J1/DK+RgKeRr54loZgOWbFX+UCMhBvv
BhNVidIMqWskRtwDl5zGImt5UWP76PVMWxSHAX8GqA4VXOvc/9WCQiuEdYdkUBUQ
vijcVAG5BlFHGooZUPqE59gUSmYDx9M8MQkVkpOS9qn102rsyTgAi5MCgYEAzQYD
JV8u26z7xPWdFlIw8/idCzgEhXZZpopWVty/YIOIzKOlJFZG325OJYBLX0GDyZ4P
5cbkCj6qoRjKgZYdWa4NF+V1zd/A3iwrfKcWE14cdR4Db10CGg4T0biGckPp+xVt
43I+cfznaAoAyh1jZrJyW+LAiCVTTybVnFTggv8CgYEAocnAmSFjRImtlFJ1w6f1
TCOC51tGsGI8Gwj9OXaO3pXStekCJxGusBRqJSYUNbMd1TBjyb9C9SMhQaRihkf3
Cz/XlrSH2QGrPEL4eIcen6hxNYNdwQoyX0Ty2ZQaDHFih5XJpHCFaT701oHHttxv
uVAdBjdi9/COo21kZGUVzs0CgYBmtQ9YZnFz7RmHVr+mEfCiF7aciyiAr4RD0ONl
ylo5AEvEsGonZO1GOtz9HmMjyg86LmuqYVOV6kTSRTgVaN01MuMuSG4Wf3QAGMKE
RLPjae75oNp5rG9EHC9DjZwUm/8YIGkXWwD7W4WVcgVpOwWzyctOSq7GxWQRr9Os
6Dw8gwKBgQCNlVOF3WcIHloqSSMGCIxtmRGLN9DzdyIriCvkGnNFN+KacSzoHwd+
ynrYF875knjZHWV9wz7fGpwCLSHpPzgj+4SBMeaP+AH+58llDrpFfVN6GBA2qdH7
1/MXxhUETU6tayYpLCj79MR26wPGpqlHYqqtlLVk8noBFd/UyPqKZg==
-----END RSA PRIVATE KEY-----
)KEY";

#endif  // Cierra el #ifndef
