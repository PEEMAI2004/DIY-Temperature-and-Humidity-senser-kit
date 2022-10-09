#define BLYNK_TEMPLATE_ID "xxx"
#define BLYNK_DEVICE_NAME "xxx"
#define BLYNK_AUTH_TOKEN "xxx"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#include "DHT.h"

// data pin connect to sensers
#define DHT1PIN D1
#define DHT2PIN D2
#define DHT3PIN D3
//sersor type
#define DHT1TYPE DHT11
#define DHT2TYPE DHT11
#define DHT3TYPE DHT11
 
DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);
DHT dht3(DHT3PIN, DHT3TYPE);

void setup()
{
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  dht1.begin();
  dht2.begin();
  dht3.begin();
  delay(100);

  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();

  if (isnan(t1) || isnan(h1)) {
    Serial.println("Failed to read from DHT #1");
  } else {
    Serial.print("Humidity 1: "); 
    Serial.print(h1);
    Serial.print(" %\t");
    Serial.print("Temperature 1: "); 
    Serial.print(t1);
    Serial.println(" *C");
  }
  if (isnan(t2) || isnan(h2)) {
    Serial.println("Failed to read from DHT #2");
  } else {
    Serial.print("Humidity 2: "); 
    Serial.print(h2);
    Serial.print(" %\t");
    Serial.print("Temperature 2: "); 
    Serial.print(t2);
    Serial.println(" *C");
  }
  if (isnan(t3) || isnan(h3)) {
    Serial.println("Failed to read from DHT #3");
  } else {
    Serial.print("Humidity 3: "); 
    Serial.print(h3);
    Serial.print(" %\t");
    Serial.print("Temperature 3: "); 
    Serial.print(t3);
    Serial.println(" *C");
  }
  Serial.println();

  //write virtualpin for blynk

  Blynk.virtualWrite(V0, h1);
  Blynk.virtualWrite(V1, t1);
  Blynk.virtualWrite(V2, h2);
  Blynk.virtualWrite(V3, t2);
  Blynk.virtualWrite(V4, h3);
  Blynk.virtualWrite(V5, t3);
}
