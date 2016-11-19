void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.print("데이터 수신 : ");
    Serial.write(Serial.read());
  }
}
