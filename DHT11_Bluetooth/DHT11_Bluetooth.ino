#include <SoftwareSerial.h>
#include <DHT.h>
#define DHT_PIN 8

float temp;
float humidity;

DHT dht(DHT_PIN, DHT11);
SoftwareSerial BTSerial(2,3);  // Rx, Tx

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  while(!Serial);
  Serial.println("시리얼통신 연결 완료!");

  while(!BTSerial);
  Serial.println("블루투스 통신 연결 완료!");
  
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  humidity = dht.readHumidity();
  BTSerial.println("Temp: " + String(temp) + " C");
  BTSerial.println("Humidity: " + String(humidity) + " %");

  Serial.println("Temp: " + String(temp) + " C");
  Serial.println("Humidity: " + String(humidity) + " %");

  delay(1000);

}
