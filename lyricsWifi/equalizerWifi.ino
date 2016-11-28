char receivedData;
int command = 0;
int inputStatus = -1;

void setup() {
  Serial.begin(115200);
  
  delay(1000);
  Serial.println("Arduino Start!");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.write(c);

    if (c == '@') {
      inputStatus = 1;
    }

    // 와이파이에서 들어온 명령 ex)@a, @b, @c, @d
    else if (inputStatus) {
      // play index 받을 때
      if (command == 1) {
        command = 0;
        inputStatus = 0;
        // c == index
        Serial.print("play ");
        Serial.print(inputStatus);
      }
      // play
      else if (c == 'a') {
        command = 1;
      }
      // stop
      else if (c == 'b') {
        command = 0;
        inputStatus = 0;
      }
      // next
      else if (c == 'c') {
        command = 0;
        inputStatus = 0;
      }
      // prev
      else if (c == 'd') {
        command = 0;
        inputStatus = 0;
      }
    }
  }
}
