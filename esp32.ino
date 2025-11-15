// - Pedro Marchese – RM 563339
// - Jonas Esteves – RM 564143
// - Augusto Valerio – RM 562185
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT11
#define MQ135_PIN 34
#define LDR_PIN 35
#define LED_PIN 2

// Wi-Fi Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingSpeak
String apiKey = "M7PW9C6NLUIRKOD7";
const char* server = "http://api.thingspeak.com/update";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();

  Serial.print("Conectando ao WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado com sucesso!");
}