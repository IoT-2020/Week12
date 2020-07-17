#include <SoftwareSerial.h>
SoftwareSerial BTSerial(7,8); // Rx, Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Serial 통신 연결 완료!");

  BTSerial.begin(9600);
  while(!BTSerial);
  Serial.println("Bluetooth 통신 연결 완료!");
}

void loop() {
  // put your main code here, to run repeatedly:
  char c;
  if(BTSerial.available()) {
    c = BTSerial.read();
    Serial.write(c);
  }
  if(Serial.available()) {
    c = Serial.read();
    BTSerial.write(c);
    Serial.write(c);
  }
}
