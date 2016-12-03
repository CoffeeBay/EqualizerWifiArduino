typedef struct {
    unsigned long long b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
    unsigned long long b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1;
    unsigned long long b14:1, b15:1, b16:1, b17:1, b18:1, b19:1, b20:1;
    unsigned long long b21:1, b22:1, b23:1, b24:1, b25:1, b26:1, b27:1;
    unsigned long long b28:1, b29:1, b30:1, b31:1, b32:1, b33:1, b34:1;
} Alphabet;


Alphabet alphabet[26];

const int timerCharactor = 1;              // time between columns  12V = 1, 9V = 2
const int frame_len = 5;                    // frame length
const int charactorSpaceTime = 2;         //  12V = 2, 9V = 4


int printAlphabet(char c) {
  if (c == ' ') {
    delay(timerCharactor * 5 + charactorSpaceTime);
    return timerCharactor * 5 + charactorSpaceTime;
  }
  
  int n = c - 'A';
  int i = 0;


  digitalWrite(latchPin, LOW);
  if (alphabet[n].b6)
    i += B00111000;
  if (alphabet[n].b5)
    i += B11000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  
  i = 0;
  if (alphabet[n].b5)
    i += B00000001;
  if (alphabet[n].b4)
    i += B00001110;
  if (alphabet[n].b3)
    i += B01110000;
  if (alphabet[n].b2)
    i += B10000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);

  i = 0;
  if (alphabet[n].b2)
    i += B00000011;
  if (alphabet[n].b1)
    i += B00011100;
  if (alphabet[n].b0)
    i += B11100000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  digitalWrite(latchPin, HIGH);
  


  delay(timerCharactor);

  

  i = 0;
  digitalWrite(latchPin, LOW);
  if (alphabet[n].b13)
    i += B00111000;
  if (alphabet[n].b12)
    i += B11000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  
  i = 0;
  if (alphabet[n].b12)
    i += B00000001;
  if (alphabet[n].b11)
    i += B00001110;
  if (alphabet[n].b10)
    i += B01110000;
  if (alphabet[n].b9)
    i += B10000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);

  i = 0;
  if (alphabet[n].b9)
    i += B00000011;
  if (alphabet[n].b8)
    i += B00011100;
  if (alphabet[n].b7)
    i += B11100000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  digitalWrite(latchPin, HIGH);
  


  delay(timerCharactor);



  i = 0;
  digitalWrite(latchPin, LOW);
  if (alphabet[n].b20)
    i += B00111000;
  if (alphabet[n].b19)
    i += B11000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  
  i = 0;
  if (alphabet[n].b19)
    i += B00000001;
  if (alphabet[n].b18)
    i += B00001110;
  if (alphabet[n].b17)
    i += B01110000;
  if (alphabet[n].b16)
    i += B10000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);

  i = 0;
  if (alphabet[n].b16)
    i += B00000011;
  if (alphabet[n].b15)
    i += B00011100;
  if (alphabet[n].b14)
    i += B11100000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  digitalWrite(latchPin, HIGH);


  delay(timerCharactor);



  i = 0;
  digitalWrite(latchPin, LOW);
  if (alphabet[n].b27)
    i += B00111000;
  if (alphabet[n].b26)
    i += B11000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  
  i = 0;
  if (alphabet[n].b26)
    i += B00000001;
  if (alphabet[n].b25)
    i += B00001110;
  if (alphabet[n].b24)
    i += B01110000;
  if (alphabet[n].b23)
    i += B10000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);

  i = 0;
  if (alphabet[n].b23)
    i += B00000011;
  if (alphabet[n].b22)
    i += B00011100;
  if (alphabet[n].b21)
    i += B11100000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  digitalWrite(latchPin, HIGH);
  


  delay(timerCharactor);


  i = 0;
  digitalWrite(latchPin, LOW);
  if (alphabet[n].b34)
    i += B00111000;
  if (alphabet[n].b33)
    i += B11000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  
  i = 0;
  if (alphabet[n].b33)
    i += B00000001;
  if (alphabet[n].b32)
    i += B00001110;
  if (alphabet[n].b31)
    i += B01110000;
  if (alphabet[n].b30)
    i += B10000000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);

  i = 0;
  if (alphabet[n].b30)
    i += B00000011;
  if (alphabet[n].b29)
    i += B00011100;
  if (alphabet[n].b28)
    i += B11100000;
  shiftOut(dataPin, clockPin, LSBFIRST, i);
  digitalWrite(latchPin, HIGH);




  delay(timerCharactor);


  
  
  turnOffLED();


  delay(charactorSpaceTime);
  return timerCharactor * 5 + charactorSpaceTime;
}


void turnOffLED() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0);
  shiftOut(dataPin, clockPin, LSBFIRST, 0);
  shiftOut(dataPin, clockPin, LSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
}


void initAlphabet() {
  setA();
  setB();
  setC();
  setD();
  setE();
  setF();
  setG();
  setH();
  setI();
  setJ();
  setK();
  setL();
  setM();
  setN();
  setO();
  setP();
  setQ();
  setR();
  setS();
  setT();
  setU();
  setV();
  setW();
  setX();
  setY();
  setZ();
}



void setA() {
    alphabet[0].b0 = 0;
    alphabet[0].b1 = 1;
    alphabet[0].b2 = 1;
    alphabet[0].b3 = 1;
    alphabet[0].b4 = 1;
    alphabet[0].b5 = 1;
    alphabet[0].b6 = 1;

    alphabet[0].b7 = 0;
    alphabet[0].b8 = 0;
    alphabet[0].b9 = 0;
    alphabet[0].b10 = 1;
    alphabet[0].b11 = 0;
    alphabet[0].b12 = 0;
    alphabet[0].b13 = 0;
    
    alphabet[0].b14 = 1;
    alphabet[0].b15 = 0;
    alphabet[0].b16 = 0;
    alphabet[0].b17 = 1;
    alphabet[0].b18 = 0;
    alphabet[0].b19 = 0;
    alphabet[0].b20 = 0;

    alphabet[0].b21 = 1;
    alphabet[0].b22 = 0;
    alphabet[0].b23 = 0;
    alphabet[0].b24 = 1;
    alphabet[0].b25 = 0;
    alphabet[0].b26 = 0;
    alphabet[0].b27 = 0;

    alphabet[0].b28 = 0;
    alphabet[0].b29 = 1;
    alphabet[0].b30 = 1;
    alphabet[0].b31 = 1;
    alphabet[0].b32 = 1;
    alphabet[0].b33 = 1;
    alphabet[0].b34 = 1;
}

void setB() {
    alphabet[1].b0 = 1;
    alphabet[1].b1 = 1;
    alphabet[1].b2 = 1;
    alphabet[1].b3 = 1;
    alphabet[1].b4 = 1;
    alphabet[1].b5 = 1;
    alphabet[1].b6 = 1;

    alphabet[1].b7 = 1;
    alphabet[1].b8 = 0;
    alphabet[1].b9 = 0;
    alphabet[1].b10 = 1;
    alphabet[1].b11 = 0;
    alphabet[1].b12 = 0;
    alphabet[1].b13 = 1;

    alphabet[1].b14 = 1;
    alphabet[1].b15 = 0;
    alphabet[1].b16 = 0;
    alphabet[1].b17 = 1;
    alphabet[1].b18 = 0;
    alphabet[1].b19 = 0;
    alphabet[1].b20 = 1;

    alphabet[1].b21 = 1;
    alphabet[1].b22 = 0;
    alphabet[1].b23 = 0;
    alphabet[1].b24 = 1;
    alphabet[1].b25 = 0;
    alphabet[1].b26 = 0;
    alphabet[1].b27 = 1;

    alphabet[1].b28 = 0;
    alphabet[1].b29 = 1;
    alphabet[1].b30 = 1;
    alphabet[1].b31 = 0;
    alphabet[1].b32 = 1;
    alphabet[1].b33 = 1;
    alphabet[1].b34 = 0;
}

void setC() {
    alphabet[2].b0 = 0;
    alphabet[2].b1 = 1;
    alphabet[2].b2 = 1;
    alphabet[2].b3 = 1;
    alphabet[2].b4 = 1;
    alphabet[2].b5 = 1;
    alphabet[2].b6 = 0;

    alphabet[2].b7 = 1;
    alphabet[2].b8 = 0;
    alphabet[2].b9 = 0;
    alphabet[2].b10 = 0;
    alphabet[2].b11 = 0;
    alphabet[2].b12 = 0;
    alphabet[2].b13 = 1;

    alphabet[2].b14 = 1;
    alphabet[2].b15 = 0;
    alphabet[2].b16 = 0;
    alphabet[2].b17 = 0;
    alphabet[2].b18 = 0;
    alphabet[2].b19 = 0;
    alphabet[2].b20 = 1;

    alphabet[2].b21 = 1;
    alphabet[2].b22 = 0;
    alphabet[2].b23 = 0;
    alphabet[2].b24 = 0;
    alphabet[2].b25 = 0;
    alphabet[2].b26 = 0;
    alphabet[2].b27 = 1;

    alphabet[2].b28 = 1;
    alphabet[2].b29 = 0;
    alphabet[2].b30 = 0;
    alphabet[2].b31 = 0;
    alphabet[2].b32 = 0;
    alphabet[2].b33 = 0;
    alphabet[2].b34 = 1;

}

void setD() {
    alphabet[3].b0 = 1;
    alphabet[3].b1 = 1;
    alphabet[3].b2 = 1;
    alphabet[3].b3 = 1;
    alphabet[3].b4 = 1;
    alphabet[3].b5 = 1;
    alphabet[3].b6 = 1;

    alphabet[3].b7 = 1;
    alphabet[3].b8 = 0;
    alphabet[3].b9 = 0;
    alphabet[3].b10 = 0;
    alphabet[3].b11 = 0;
    alphabet[3].b12 = 0;
    alphabet[3].b13 = 1;

    alphabet[3].b14 = 1;
    alphabet[3].b15 = 0;
    alphabet[3].b16 = 0;
    alphabet[3].b17 = 0;
    alphabet[3].b18 = 0;
    alphabet[3].b19 = 0;
    alphabet[3].b20 = 1;

    alphabet[3].b21 = 1;
    alphabet[3].b22 = 0;
    alphabet[3].b23 = 0;
    alphabet[3].b24 = 0;
    alphabet[3].b25 = 0;
    alphabet[3].b26 = 0;
    alphabet[3].b27 = 1;

    alphabet[3].b28 = 0;
    alphabet[3].b29 = 1;
    alphabet[3].b30 = 1;
    alphabet[3].b31 = 1;
    alphabet[3].b32 = 1;
    alphabet[3].b33 = 1;
    alphabet[3].b34 = 0;
}


// E
void setE() {
    alphabet[4].b0 = 1;
    alphabet[4].b1 = 1;
    alphabet[4].b2 = 1;
    alphabet[4].b3 = 1;
    alphabet[4].b4 = 1;
    alphabet[4].b5 = 1;
    alphabet[4].b6 = 1;

    alphabet[4].b7 = 1;
    alphabet[4].b8 = 0;
    alphabet[4].b9 = 0;
    alphabet[4].b10 = 1;
    alphabet[4].b11 = 0;
    alphabet[4].b12 = 0;
    alphabet[4].b13 = 1;

    alphabet[4].b14 = 1;
    alphabet[4].b15 = 0;
    alphabet[4].b16 = 0;
    alphabet[4].b17 = 1;
    alphabet[4].b18 = 0;
    alphabet[4].b19 = 0;
    alphabet[4].b20 = 1;

    alphabet[4].b21 = 1;
    alphabet[4].b22 = 0;
    alphabet[4].b23 = 0;
    alphabet[4].b24 = 1;
    alphabet[4].b25 = 0;
    alphabet[4].b26 = 0;
    alphabet[4].b27 = 1;

    alphabet[4].b28 = 1;
    alphabet[4].b29 = 0;
    alphabet[4].b30 = 0;
    alphabet[4].b31 = 1;
    alphabet[4].b32 = 0;
    alphabet[4].b33 = 0;
    alphabet[4].b34 = 1;
}
// F
void setF() {
    alphabet[5].b0 = 1;
    alphabet[5].b1 = 1;
    alphabet[5].b2 = 1;
    alphabet[5].b3 = 1;
    alphabet[5].b4 = 1;
    alphabet[5].b5 = 1;
    alphabet[5].b6 = 1;

    alphabet[5].b7 = 1;
    alphabet[5].b8 = 0;
    alphabet[5].b9 = 0;
    alphabet[5].b10 = 1;
    alphabet[5].b11 = 0;
    alphabet[5].b12 = 0;
    alphabet[5].b13 = 0;

    alphabet[5].b14 = 1;
    alphabet[5].b15 = 0;
    alphabet[5].b16 = 0;
    alphabet[5].b17 = 1;
    alphabet[5].b18 = 0;
    alphabet[5].b19 = 0;
    alphabet[5].b20 = 0;

    alphabet[5].b21 = 1;
    alphabet[5].b22 = 0;
    alphabet[5].b23 = 0;
    alphabet[5].b24 = 1;
    alphabet[5].b25 = 0;
    alphabet[5].b26 = 0;
    alphabet[5].b27 = 0;

    alphabet[5].b28 = 1;
    alphabet[5].b29 = 0;
    alphabet[5].b30 = 0;
    alphabet[5].b31 = 1;
    alphabet[5].b32 = 0;
    alphabet[5].b33 = 0;
    alphabet[5].b34 = 0;
}
// G
void setG() {
    alphabet[6].b0 = 1;
    alphabet[6].b1 = 1;
    alphabet[6].b2 = 1;
    alphabet[6].b3 = 1;
    alphabet[6].b4 = 1;
    alphabet[6].b5 = 1;
    alphabet[6].b6 = 1;

    alphabet[6].b7 = 1;
    alphabet[6].b8 = 0;
    alphabet[6].b9 = 0;
    alphabet[6].b10 = 0;
    alphabet[6].b11 = 0;
    alphabet[6].b12 = 0;
    alphabet[6].b13 = 1;

    alphabet[6].b14 = 1;
    alphabet[6].b15 = 0;
    alphabet[6].b16 = 0;
    alphabet[6].b17 = 1;
    alphabet[6].b18 = 0;
    alphabet[6].b19 = 0;
    alphabet[6].b20 = 1;

    alphabet[6].b21 = 1;
    alphabet[6].b22 = 0;
    alphabet[6].b23 = 0;
    alphabet[6].b24 = 1;
    alphabet[6].b25 = 0;
    alphabet[6].b26 = 0;
    alphabet[6].b27 = 1;

    alphabet[6].b28 = 1;
    alphabet[6].b29 = 0;
    alphabet[6].b30 = 0;
    alphabet[6].b31 = 1;
    alphabet[6].b32 = 1;
    alphabet[6].b33 = 1;
    alphabet[6].b34 = 1;
}
// H
void setH() {
    alphabet[7].b0 = 1;
    alphabet[7].b1 = 1;
    alphabet[7].b2 = 1;
    alphabet[7].b3 = 1;
    alphabet[7].b4 = 1;
    alphabet[7].b5 = 1;
    alphabet[7].b6 = 1;

    alphabet[7].b7 = 0;
    alphabet[7].b8 = 0;
    alphabet[7].b9 = 0;
    alphabet[7].b10 = 1;
    alphabet[7].b11 = 0;
    alphabet[7].b12 = 0;
    alphabet[7].b13 = 0;

    alphabet[7].b14 = 0;
    alphabet[7].b15 = 0;
    alphabet[7].b16 = 0;
    alphabet[7].b17 = 1;
    alphabet[7].b18 = 0;
    alphabet[7].b19 = 0;
    alphabet[7].b20 = 0;

    alphabet[7].b21 = 0;
    alphabet[7].b22 = 0;
    alphabet[7].b23 = 0;
    alphabet[7].b24 = 1;
    alphabet[7].b25 = 0;
    alphabet[7].b26 = 0;
    alphabet[7].b27 = 0;

    alphabet[7].b28 = 1;
    alphabet[7].b29 = 1;
    alphabet[7].b30 = 1;
    alphabet[7].b31 = 1;
    alphabet[7].b32 = 1;
    alphabet[7].b33 = 1;
    alphabet[7].b34 = 1;
}
//I
void setI() {
    alphabet[8].b0 = 1;
    alphabet[8].b1 = 0;
    alphabet[8].b2 = 0;
    alphabet[8].b3 = 0;
    alphabet[8].b4 = 0;
    alphabet[8].b5 = 0;
    alphabet[8].b6 = 1;

    alphabet[8].b7 = 1;
    alphabet[8].b8 = 0;
    alphabet[8].b9 = 0;
    alphabet[8].b10 = 0;
    alphabet[8].b11 = 0;
    alphabet[8].b12 = 0;
    alphabet[8].b13 = 1;

    alphabet[8].b14 = 1;
    alphabet[8].b15 = 1;
    alphabet[8].b16 = 1;
    alphabet[8].b17 = 1;
    alphabet[8].b18 = 1;
    alphabet[8].b19 = 1;
    alphabet[8].b20 = 1;

    alphabet[8].b21 = 1;
    alphabet[8].b22 = 0;
    alphabet[8].b23 = 0;
    alphabet[8].b24 = 0;
    alphabet[8].b25 = 0;
    alphabet[8].b26 = 0;
    alphabet[8].b27 = 1;

    alphabet[8].b28 = 1;
    alphabet[8].b29 = 0;
    alphabet[8].b30 = 0;
    alphabet[8].b31 = 0;
    alphabet[8].b32 = 0;
    alphabet[8].b33 = 0;
    alphabet[8].b34 = 1;
}

// J
void setJ() {
    alphabet[9].b0 = 1;
    alphabet[9].b1 = 0;
    alphabet[9].b2 = 0;
    alphabet[9].b3 = 0;
    alphabet[9].b4 = 0;
    alphabet[9].b5 = 1;
    alphabet[9].b6 = 1;

    alphabet[9].b7 = 1;
    alphabet[9].b8 = 0;
    alphabet[9].b9 = 0;
    alphabet[9].b10 = 0;
    alphabet[9].b11 = 0;
    alphabet[9].b12 = 0;
    alphabet[9].b13 = 1;

    alphabet[9].b14 = 1;
    alphabet[9].b15 = 0;
    alphabet[9].b16 = 0;
    alphabet[9].b17 = 0;
    alphabet[9].b18 = 0;
    alphabet[9].b19 = 0;
    alphabet[9].b20 = 1;

    alphabet[9].b21 = 1;
    alphabet[9].b22 = 1;
    alphabet[9].b23 = 1;
    alphabet[9].b24 = 1;
    alphabet[9].b25 = 1;
    alphabet[9].b26 = 1;
    alphabet[9].b27 = 1;

    alphabet[9].b28 = 1;
    alphabet[9].b29 = 0;
    alphabet[9].b30 = 0;
    alphabet[9].b31 = 0;
    alphabet[9].b32 = 0;
    alphabet[9].b33 = 0;
    alphabet[9].b34 = 0;
}

//K
void setK() {
    alphabet[10].b0 = 1;
    alphabet[10].b1 = 1;
    alphabet[10].b2 = 1;
    alphabet[10].b3 = 1;
    alphabet[10].b4 = 1;
    alphabet[10].b5 = 1;
    alphabet[10].b6 = 1;

    alphabet[10].b7 = 0;
    alphabet[10].b8 = 0;
    alphabet[10].b9 = 0;
    alphabet[10].b10 = 1;
    alphabet[10].b11 = 0;
    alphabet[10].b12 = 0;
    alphabet[10].b13 = 0;

    alphabet[10].b14 = 0;
    alphabet[10].b15 = 0;
    alphabet[10].b16 = 1;
    alphabet[10].b17 = 0;
    alphabet[10].b18 = 1;
    alphabet[10].b19 = 0;
    alphabet[10].b20 = 0;

    alphabet[10].b21 = 0;
    alphabet[10].b22 = 1;
    alphabet[10].b23 = 0;
    alphabet[10].b24 = 0;
    alphabet[10].b25 = 0;
    alphabet[10].b26 = 1;
    alphabet[10].b27 = 0;

    alphabet[10].b28 = 1;
    alphabet[10].b29 = 0;
    alphabet[10].b30 = 0;
    alphabet[10].b31 = 0;
    alphabet[10].b32 = 0;
    alphabet[10].b33 = 0;
    alphabet[10].b34 = 1;
}

//L
void setL() {
    alphabet[11].b0 = 1;
    alphabet[11].b1 = 1;
    alphabet[11].b2 = 1;
    alphabet[11].b3 = 1;
    alphabet[11].b4 = 1;
    alphabet[11].b5 = 1;
    alphabet[11].b6 = 1;

    alphabet[11].b7 = 0;
    alphabet[11].b8 = 0;
    alphabet[11].b9 = 0;
    alphabet[11].b10 = 0;
    alphabet[11].b11 = 0;
    alphabet[11].b12 = 0;
    alphabet[11].b13 = 1;

    alphabet[11].b14 = 0;
    alphabet[11].b15 = 0;
    alphabet[11].b16 = 0;
    alphabet[11].b17 = 0;
    alphabet[11].b18 = 0;
    alphabet[11].b19 = 0;
    alphabet[11].b20 = 1;

    alphabet[11].b21 = 0;
    alphabet[11].b22 = 0;
    alphabet[11].b23 = 0;
    alphabet[11].b24 = 0;
    alphabet[11].b25 = 0;
    alphabet[11].b26 = 0;
    alphabet[11].b27 = 1;

    alphabet[11].b28 = 0;
    alphabet[11].b29 = 0;
    alphabet[11].b30 = 0;
    alphabet[11].b31 = 0;
    alphabet[11].b32 = 0;
    alphabet[11].b33 = 0;
    alphabet[11].b34 = 1;
}
//M
void setM() {
    alphabet[12].b0 = 1;
    alphabet[12].b1 = 1;
    alphabet[12].b2 = 1;
    alphabet[12].b3 = 1;
    alphabet[12].b4 = 1;
    alphabet[12].b5 = 1;
    alphabet[12].b6 = 1;

    alphabet[12].b7 = 0;
    alphabet[12].b8 = 1;
    alphabet[12].b9 = 0;
    alphabet[12].b10 = 0;
    alphabet[12].b11 = 0;
    alphabet[12].b12 = 0;
    alphabet[12].b13 = 0;

    alphabet[12].b14 = 0;
    alphabet[12].b15 = 0;
    alphabet[12].b16 = 1;
    alphabet[12].b17 = 0;
    alphabet[12].b18 = 0;
    alphabet[12].b19 = 0;
    alphabet[12].b20 = 0;

    alphabet[12].b21 = 0;
    alphabet[12].b22 = 1;
    alphabet[12].b23 = 0;
    alphabet[12].b24 = 0;
    alphabet[12].b25 = 0;
    alphabet[12].b26 = 0;
    alphabet[12].b27 = 0;

    alphabet[12].b28 = 1;
    alphabet[12].b29 = 1;
    alphabet[12].b30 = 1;
    alphabet[12].b31 = 1;
    alphabet[12].b32 = 1;
    alphabet[12].b33 = 1;
    alphabet[12].b34 = 1;
}

//N
void setN() {
    alphabet[13].b0 = 1;
    alphabet[13].b1 = 1;
    alphabet[13].b2 = 1;
    alphabet[13].b3 = 1;
    alphabet[13].b4 = 1;
    alphabet[13].b5 = 1;
    alphabet[13].b6 = 1;

    alphabet[13].b7 = 0;
    alphabet[13].b8 = 0;
    alphabet[13].b9 = 1;
    alphabet[13].b10 = 0;
    alphabet[13].b11 = 0;
    alphabet[13].b12 = 0;
    alphabet[13].b13 = 0;

    alphabet[13].b14 = 0;
    alphabet[13].b15 = 0;
    alphabet[13].b16 = 0;
    alphabet[13].b17 = 1;
    alphabet[13].b18 = 0;
    alphabet[13].b19 = 0;
    alphabet[13].b20 = 0;

    alphabet[13].b21 = 0;
    alphabet[13].b22 = 0;
    alphabet[13].b23 = 0;
    alphabet[13].b24 = 0;
    alphabet[13].b25 = 1;
    alphabet[13].b26 = 0;
    alphabet[13].b27 = 0;

    alphabet[13].b28 = 1;
    alphabet[13].b29 = 1;
    alphabet[13].b30 = 1;
    alphabet[13].b31 = 1;
    alphabet[13].b32 = 1;
    alphabet[13].b33 = 1;
    alphabet[13].b34 = 1;
}

//O
void setO() {   
    alphabet[14].b0 = 0;
    alphabet[14].b1 = 1;
    alphabet[14].b2 = 1;
    alphabet[14].b3 = 1;  
    alphabet[14].b4 = 1;  
    alphabet[14].b5 = 1;  
    alphabet[14].b6 = 0;  
 
    alphabet[14].b7 = 1;  
    alphabet[14].b8 = 0;  
    alphabet[14].b9 = 0;  
    alphabet[14].b10 = 0; 
    alphabet[14].b11 = 0; 
    alphabet[14].b12 = 0; 
    alphabet[14].b13 = 1; 
    
    alphabet[14].b14 = 1; 
    alphabet[14].b15 = 0; 
    alphabet[14].b16 = 0; 
    alphabet[14].b17 = 0; 
    alphabet[14].b18 = 0; 
    alphabet[14].b19 = 0; 
    alphabet[14].b20 = 1; 
    
    alphabet[14].b21 = 1; 
    alphabet[14].b22 = 0; 
    alphabet[14].b23 = 0; 
    alphabet[14].b24 = 0; 
    alphabet[14].b25 = 0; 
    alphabet[14].b26 = 0; 
    alphabet[14].b27 = 1; 
    
    alphabet[14].b28 = 0; 
    alphabet[14].b29 = 1; 
    alphabet[14].b30 = 1; 
    alphabet[14].b31 = 1; 
    alphabet[14].b32 = 1; 
    alphabet[14].b33 = 1; 
    alphabet[14].b34 = 0; 
}
//P
void setP() {
    alphabet[15].b0 = 1;
    alphabet[15].b1 = 1;
    alphabet[15].b2 = 1;
    alphabet[15].b3 = 1;
    alphabet[15].b4 = 1;
    alphabet[15].b5 = 1;
    alphabet[15].b6 = 1;

    alphabet[15].b7 = 1;
    alphabet[15].b8 = 0;
    alphabet[15].b9 = 0;
    alphabet[15].b10 = 1;
    alphabet[15].b11 = 0;
    alphabet[15].b12 = 0;
    alphabet[15].b13 = 0;

    alphabet[15].b14 = 1;
    alphabet[15].b15 = 0;
    alphabet[15].b16 = 0;
    alphabet[15].b17 = 1;
    alphabet[15].b18 = 0;
    alphabet[15].b19 = 0;
    alphabet[15].b20 = 0;
    
    alphabet[15].b21 = 1;
    alphabet[15].b22 = 0;
    alphabet[15].b23 = 0;
    alphabet[15].b24 = 1;
    alphabet[15].b25 = 0;
    alphabet[15].b26 = 0;
    alphabet[15].b27 = 0;
   
    alphabet[15].b28 = 0;
    alphabet[15].b29 = 1;
    alphabet[15].b30 = 1;
    alphabet[15].b31 = 0;
    alphabet[15].b32 = 0;
    alphabet[15].b33 = 0;
    alphabet[15].b34 = 0;
}
//Q
void setQ(){
    alphabet[16].b0 = 0;
    alphabet[16].b1 = 1;
    alphabet[16].b2 = 1;
    alphabet[16].b3 = 1;
    alphabet[16].b4 = 1;
    alphabet[16].b5 = 1;
    alphabet[16].b6 = 0;

    alphabet[16].b7 = 1;
    alphabet[16].b8 = 0;
    alphabet[16].b9 = 0;
    alphabet[16].b10 = 0;
    alphabet[16].b11 = 0;
    alphabet[16].b12 = 0;
    alphabet[16].b13 = 1;

    alphabet[16].b14 = 1;
    alphabet[16].b15 = 0;
    alphabet[16].b16 = 0;
    alphabet[16].b17 = 0;
    alphabet[16].b18 = 1;
    alphabet[16].b19 = 0;
    alphabet[16].b20 = 1;

    alphabet[16].b21 = 1;
    alphabet[16].b22 = 0;
    alphabet[16].b23 = 0;
    alphabet[16].b24 = 0;
    alphabet[16].b25 = 0;
    alphabet[16].b26 = 1;
    alphabet[16].b27 = 0;

    alphabet[16].b28 = 0;
    alphabet[16].b29 = 1;
    alphabet[17].b30 = 1;
    alphabet[16].b31 = 1;
    alphabet[16].b32 = 1;
    alphabet[16].b33 = 0;
    alphabet[16].b34 = 1;
}

//R
void setR(){
    alphabet[17].b0 = 1;
    alphabet[17].b1 = 1;
    alphabet[17].b2 = 1;
    alphabet[17].b3 = 1;
    alphabet[17].b4 = 1;
    alphabet[17].b5 = 1;
    alphabet[17].b6 = 1;

    alphabet[17].b7 = 1;
    alphabet[17].b8 = 0;
    alphabet[17].b9 = 0;
    alphabet[17].b10 = 1;
    alphabet[17].b11 = 0;
    alphabet[17].b12 = 0;
    alphabet[17].b13 = 0;

    alphabet[17].b14 = 1;
    alphabet[17].b15 = 0;
    alphabet[17].b16 = 0;
    alphabet[17].b17 = 1;
    alphabet[17].b18 = 0;
    alphabet[17].b19 = 0;
    alphabet[17].b20 = 0;

    alphabet[17].b21 = 1;
    alphabet[17].b22 = 0;
    alphabet[17].b23 = 0;
    alphabet[17].b24 = 1;
    alphabet[17].b25 = 1;
    alphabet[17].b26 = 0;
    alphabet[17].b27 = 0;

    alphabet[17].b28 = 0;
    alphabet[17].b29 = 1;
    alphabet[17].b30 = 1;
    alphabet[17].b31 = 0;
    alphabet[17].b32 = 1;
    alphabet[17].b33 = 1;
    alphabet[17].b34 = 1;
}

//S
void setS() {
    alphabet[18].b0 = 0;
    alphabet[18].b1 = 1;
    alphabet[18].b2 = 1;
    alphabet[18].b3 = 0;
    alphabet[18].b4 = 0;
    alphabet[18].b5 = 1;
    alphabet[18].b6 = 0;

    alphabet[18].b7 = 1;
    alphabet[18].b8 = 0;
    alphabet[18].b9 = 0;
    alphabet[18].b10 = 1;
    alphabet[18].b11 = 0;
    alphabet[18].b12 = 0;
    alphabet[18].b13 = 1;

    alphabet[18].b14 = 1;
    alphabet[18].b15 = 0;
    alphabet[18].b16 = 0;
    alphabet[18].b17 = 1;
    alphabet[18].b18 = 0;
    alphabet[18].b19 = 0;
    alphabet[18].b20 = 1;

    alphabet[18].b21 = 1;
    alphabet[18].b22 = 0;
    alphabet[18].b23 = 0;
    alphabet[18].b24 = 1;
    alphabet[18].b25 = 0;
    alphabet[18].b26 = 0;
    alphabet[18].b27 = 1;

    alphabet[18].b28 = 0;
    alphabet[18].b29 = 1;
    alphabet[18].b30 = 0;
    alphabet[18].b31 = 0;
    alphabet[18].b32 = 1;
    alphabet[18].b33 = 1;
    alphabet[18].b34 = 0;
}

//T
void setT() {
    alphabet[19].b0 = 1;
    alphabet[19].b1 = 0;
    alphabet[19].b2 = 0;
    alphabet[19].b3 = 0;
    alphabet[19].b4 = 0;
    alphabet[19].b5 = 0;
    alphabet[19].b6 = 0;

    alphabet[19].b7 = 1;
    alphabet[19].b8 = 0;
    alphabet[19].b9 = 0;
    alphabet[19].b10 = 0;
    alphabet[19].b11 = 0;
    alphabet[19].b12 = 0;
    alphabet[19].b13 = 0;

    alphabet[19].b14 = 1;
    alphabet[19].b15 = 1;
    alphabet[19].b16 = 1;
    alphabet[19].b17 = 1;
    alphabet[19].b18 = 1;
    alphabet[19].b19 = 1;
    alphabet[19].b20 = 1;

    alphabet[19].b21 = 1;
    alphabet[19].b22 = 0;
    alphabet[19].b23 = 0;
    alphabet[19].b24 = 0;
    alphabet[19].b25 = 0;
    alphabet[19].b26 = 0;
    alphabet[19].b27 = 0;

    alphabet[19].b28 = 1;
    alphabet[19].b29 = 0;
    alphabet[19].b30 = 0;
    alphabet[19].b31 = 0;
    alphabet[19].b32 = 0;
    alphabet[19].b33 = 0;
    alphabet[19].b34 = 0;
}

//U
void setU() {
    alphabet[20].b0 = 1;
    alphabet[20].b1 = 1;
    alphabet[20].b2 = 1;
    alphabet[20].b3 = 1;
    alphabet[20].b4 = 1;
    alphabet[20].b5 = 1;
    alphabet[20].b6 = 0;

    alphabet[20].b7 = 0;
    alphabet[20].b8 = 0;
    alphabet[20].b9 = 0;
    alphabet[20].b10 = 0;
    alphabet[20].b11 = 0;
    alphabet[20].b12 = 1;
    alphabet[20].b13 = 1;

    alphabet[20].b14 = 0;
    alphabet[20].b15 = 0;
    alphabet[20].b16 = 0;
    alphabet[20].b17 = 0;
    alphabet[20].b18 = 0;
    alphabet[20].b19 = 1;
    alphabet[20].b20 = 1;

    alphabet[20].b21 = 0;
    alphabet[20].b22 = 0;
    alphabet[20].b23 = 0;
    alphabet[20].b24 = 0;
    alphabet[20].b25 = 0;
    alphabet[20].b26 = 1;
    alphabet[20].b27 = 1;

    alphabet[20].b28 = 1;
    alphabet[20].b29 = 1;
    alphabet[20].b30 = 1;
    alphabet[20].b31 = 1;
    alphabet[20].b32 = 1;
    alphabet[20].b33 = 1;
    alphabet[20].b34 = 0;
}

//V
void setV() {
    alphabet[21].b0 = 1;
    alphabet[21].b1 = 1;
    alphabet[21].b2 = 1;
    alphabet[21].b3 = 1;
    alphabet[21].b4 = 1;
    alphabet[21].b5 = 0;
    alphabet[21].b6 = 0;

    alphabet[21].b7 = 0;
    alphabet[21].b8 = 0;
    alphabet[21].b9 = 0;
    alphabet[21].b10 = 0;
    alphabet[21].b11 = 1;
    alphabet[21].b12 = 1;
    alphabet[21].b13 = 0;

    alphabet[21].b14 = 0;
    alphabet[21].b15 = 0;
    alphabet[21].b16 = 0;
    alphabet[21].b17 = 0;
    alphabet[21].b18 = 0;
    alphabet[21].b19 = 1;
    alphabet[21].b20 = 1;

    alphabet[21].b21 = 0;
    alphabet[21].b22 = 0;
    alphabet[21].b23 = 0;
    alphabet[21].b24 = 0;
    alphabet[21].b25 = 1;
    alphabet[21].b26 = 1;
    alphabet[21].b27 = 0;

    alphabet[21].b28 = 1;
    alphabet[21].b29 = 1;
    alphabet[21].b30 = 1;
    alphabet[21].b31 = 1;
    alphabet[21].b32 = 1;
    alphabet[21].b33 = 0;
    alphabet[21].b34 = 0;
}

//W
void setW() {
    alphabet[22].b0 = 1;
    alphabet[22].b1 = 1;
    alphabet[22].b2 = 1;
    alphabet[22].b3 = 1;
    alphabet[22].b4 = 1;
    alphabet[22].b5 = 0;
    alphabet[22].b6 = 0;

    alphabet[22].b7 = 0;
    alphabet[22].b8 = 0;
    alphabet[22].b9 = 0;
    alphabet[22].b10 = 1;
    alphabet[22].b11 = 1;
    alphabet[22].b12 = 1;
    alphabet[22].b13 = 1;

    alphabet[22].b14 = 0;
    alphabet[22].b15 = 1;
    alphabet[22].b16 = 1;
    alphabet[22].b17 = 1;
    alphabet[22].b18 = 1;
    alphabet[22].b19 = 0;
    alphabet[22].b20 = 0;

    alphabet[22].b21 = 0;
    alphabet[22].b22 = 0;
    alphabet[22].b23 = 0;
    alphabet[22].b24 = 1;
    alphabet[22].b25 = 1;
    alphabet[22].b26 = 1;
    alphabet[22].b27 = 1;

    alphabet[22].b28 = 1;
    alphabet[22].b29 = 1;
    alphabet[22].b30 = 1;
    alphabet[22].b31 = 1;
    alphabet[22].b32 = 1;
    alphabet[22].b33 = 0;
    alphabet[22].b34 = 0;
}

// X
void setX() {
    alphabet[23].b0 = 1;
    alphabet[23].b1 = 1;
    alphabet[23].b2 = 0;
    alphabet[23].b3 = 0;
    alphabet[23].b4 = 0;
    alphabet[23].b5 = 1;
    alphabet[23].b6 = 1;

    alphabet[23].b7 = 0;
    alphabet[23].b8 = 0;
    alphabet[23].b9 = 1;
    alphabet[23].b10 = 0;
    alphabet[23].b11 = 1;
    alphabet[23].b12 = 0;
    alphabet[23].b13 = 0;

    alphabet[23].b14 = 0;
    alphabet[23].b15 = 0;
    alphabet[23].b16 = 0;
    alphabet[23].b17 = 1;
    alphabet[23].b18 = 0;
    alphabet[23].b19 = 0;
    alphabet[23].b20 = 0;

    alphabet[23].b21 = 0;
    alphabet[23].b22 = 0;
    alphabet[23].b23 = 1;
    alphabet[23].b24 = 0;
    alphabet[23].b25 = 1;
    alphabet[23].b26 = 0;
    alphabet[23].b27 = 0;

    alphabet[23].b28 = 1;
    alphabet[23].b29 = 1;
    alphabet[23].b30 = 0;
    alphabet[23].b31 = 0;
    alphabet[23].b32 = 0;
    alphabet[23].b33 = 1;
    alphabet[23].b34 = 1;
}


// Y
void setY() {
    alphabet[24].b0 = 1;
    alphabet[24].b1 = 1;
    alphabet[24].b2 = 0;
    alphabet[24].b3 = 0;
    alphabet[24].b4 = 0;
    alphabet[24].b5 = 0;
    alphabet[24].b6 = 0;

    alphabet[24].b7 = 0;
    alphabet[24].b8 = 0;
    alphabet[24].b9 = 1;
    alphabet[24].b10 = 0;
    alphabet[24].b11 = 0;
    alphabet[24].b12 = 0;
    alphabet[24].b13 = 0;

    alphabet[24].b14 = 0;
    alphabet[24].b15 = 0;
    alphabet[24].b16 = 0;
    alphabet[24].b17 = 1;
    alphabet[24].b18 = 1;
    alphabet[24].b19 = 1;
    alphabet[24].b20 = 1;

    alphabet[24].b21 = 0;
    alphabet[24].b22 = 0;
    alphabet[24].b23 = 1;
    alphabet[24].b24 = 0;
    alphabet[24].b25 = 0;
    alphabet[24].b26 = 0;
    alphabet[24].b27 = 0;

    alphabet[24].b28 = 1;
    alphabet[24].b29 = 1;
    alphabet[24].b30 = 0;
    alphabet[24].b31 = 0;
    alphabet[24].b32 = 0;
    alphabet[24].b33 = 0;
    alphabet[24].b34 = 0;
}

// Z
void setZ() {
    alphabet[25].b0 = 1;
    alphabet[25].b1 = 0;
    alphabet[25].b2 = 0;
    alphabet[25].b3 = 0;
    alphabet[25].b4 = 0;
    alphabet[25].b5 = 1;
    alphabet[25].b6 = 1;

    alphabet[25].b7 = 1;
    alphabet[25].b8 = 0;
    alphabet[25].b9 = 0;
    alphabet[25].b10 = 0;
    alphabet[25].b11 = 1;
    alphabet[25].b12 = 0;
    alphabet[25].b13 = 1;

    alphabet[25].b14 = 1;
    alphabet[25].b15 = 0;
    alphabet[25].b16 = 0;
    alphabet[25].b17 = 1;
    alphabet[25].b18 = 0;
    alphabet[25].b19 = 0;
    alphabet[25].b20 = 1;

    alphabet[25].b21 = 1;
    alphabet[25].b22 = 0;
    alphabet[25].b23 = 1;
    alphabet[25].b24 = 0;
    alphabet[25].b25 = 0;
    alphabet[25].b26 = 0;
    alphabet[25].b27 = 1;

    alphabet[25].b28 = 1;
    alphabet[25].b29 = 1;
    alphabet[25].b30 = 0;
    alphabet[25].b31 = 0;
    alphabet[25].b32 = 0;
    alphabet[25].b33 = 0;
    alphabet[25].b34 = 1;
}
