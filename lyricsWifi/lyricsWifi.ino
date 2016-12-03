// 1411
#include <SoftwareSerial.h>
#define CYCLE_TIME_MILLS 132   // loop 한 번에 12V = 121ms 

char receivedData;
int command = 0;
int inputStatus = -1;

int clockPin = 8;
int latchPin = 9;
int dataPin = 10;

const int timerSentence = 6;                    // time between frames

int count = 0;
char lyrics[100];
SoftwareSerial mySerial(6, 5); // RX, TX


void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  delay(1000);

  Serial.write('6');
  initAlphabet();

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

//  int sec;
//  while(1) {
//    sec = 0;
//    sec += printSentence("ABC");
//    
//    delay(CYCLE_TIME_MILLS - sec);
//  }
}


void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '@') {
      inputStatus = 1;
    }

    // 와이파이에서 들어온 명령 ex)@a, @b, @c, @d
    else if (inputStatus) {
      // play index 받을 때
      if (command == 1) {
        command = 0;
        inputStatus = 0;
        mySerial.print("@a");
        mySerial.write(c);
      }
      // play
      else if (c == 'a') {
        command = 1;
      }
      // stop
      else if (c == 'b') {
        command = 0;
        inputStatus = 0;
        mySerial.print("@b");
      }
    }
  }

  if (mySerial.available()) {
    char c = mySerial.read();
    Serial.write(c);
    lyrics[count++] = c;

    // 가사 한 줄 전송 완료
    if (c == '\n') {
      lyrics[count] = '\0';
      count = 0;
    }
  }

//  printSentence(lyrics);
//  delay(timerSentence);
}

int printSentence(char *str) {
//  Serial.println(str);
  int i = 0;
  int timeSec = 0;
  
  while(str[i] != '\0') {
    timeSec += printAlphabet(str[i++]);
  }
  return timeSec;
}
