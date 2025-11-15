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
void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  int qualidadeAr = analogRead(MQ135_PIN);
  int luz = analogRead(LDR_PIN);

  Serial.println("====================================");
  Serial.println("Leituras dos Sensores");
  Serial.println("------------------------------------");
  Serial.print("Temperatura: "); Serial.println(temperatura);
  Serial.print("Umidade: "); Serial.println(umidade);
  Serial.print("Qualidade do Ar: "); Serial.println(qualidadeAr);
  Serial.print("Luz: "); Serial.println(luz);
  Serial.println("------------------------------------");

  // Análise das condições
  Serial.println("Análise das Condições:");

  // Temperatura
  if (temperatura < 18)
    Serial.println("Temperatura baixa. Ambiente frio.");
  else if (temperatura > 30)
    Serial.println("Temperatura alta. Ambiente muito quente.");
  else
    Serial.println("Temperatura dentro do nível ideal.");

  // Umidade
  if (umidade < 40)
    Serial.println("Umidade baixa. O ar está seco.");
  else if (umidade > 70)
    Serial.println("Umidade alta. O ambiente está úmido.");
  else
    Serial.println("Umidade adequada.");

  // Qualidade do Ar
  if (qualidadeAr > 2500) {
    Serial.println("Qualidade do ar ruim. Nível alto de gases detectado.");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("Qualidade do ar boa.");
    digitalWrite(LED_PIN, LOW);
  }

  // Luz
  if (luz > 1000)
    Serial.println("Ambiente escuro.");
  else if (luz < 3000)
    Serial.println("Ambiente muito iluminado.");
  else
    Serial.println("Iluminação adequada.");

  Serial.println("====================================");
  Serial.println();

  // Envio dos dados ao ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(server) + "?api_key=" + apiKey +
                 "&field1=" + String(temperatura) +
                 "&field2=" + String(umidade) +
                 "&field3=" + String(qualidadeAr) +
                 "&field4=" + String(luz);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0)
      Serial.println("Dados enviados com sucesso ao ThingSpeak.");
    else
      Serial.println("Falha ao enviar os dados.");

    http.end();
  } else {
    Serial.println("Falha na conexão WiFi. Tentando reconectar...");
    WiFi.begin(ssid, password);
  }

  delay(20000); // ThingSpeak permite 1 envio a cada 15 segundos
}
