char receivedData[10];
int count = 0;
int command = 0;

void setup() {
  Serial.begin(115200);
  
  delay(1000);
  Serial.println("start1");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c >= 'a' && c <= 'z') {
      receivedData[count++] = c;
    }

    if (count == 2) {
      // play
      if (receivedData[0] == 'p' && receivedData[1] == 'l') {
        Serial.println("play");
      }
      // next
      if (receivedData[0] == 'n') {
        Serial.println("next");
      }
      // stop
      if (receivedData[0] == 's') {
        Serial.println("stop");
      }
      // prev
      if (receivedData[0] == 'p' && receivedData[1] == 'r') {
        Serial.println("prev");
      }
      count = 0;
    }
  }
}
