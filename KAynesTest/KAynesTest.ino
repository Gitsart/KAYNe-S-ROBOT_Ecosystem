#include<TimerOne.h>
int a, b, c, d, e, f, g, h, i, j, k, l;
#define sen1 A0
#define sen2 A1
#define sen3 A2
#define sen4 A3
#define sen5 A4
#define sen6 A5
#define pulse 40
bool Start = false;
void setup() {
  pinMode(sen1, INPUT_PULLUP); //a
  pinMode(sen2, INPUT_PULLUP); //b
  pinMode(sen3, INPUT_PULLUP); //c
  pinMode(sen4, INPUT_PULLUP); //d
  pinMode(sen5, INPUT_PULLUP); //e
  pinMode(sen6, INPUT_PULLUP); //f
  pinMode(pulse, OUTPUT);
  digitalWrite(sen4, HIGH);
  Serial.begin(9600);
  Timer1.initialize(30000);
  Timer1.attachInterrupt(readSen);
}
void loop() {
  while(!Start) {
    Serial.println("NOPULSE");
  }

}

void readSen() {
  a = digitalRead(sen1);
  Serial.print("SENSOR1:"); Serial.println(a);
  b = digitalRead(sen2);
  Serial.print("SENSOR2:"); Serial.println(b);
  c = digitalRead(sen3);
  Serial.print("SENSOR3:"); Serial.println(c);
  d = digitalRead(sen4);
  Serial.print("SENSOR4:"); Serial.println(d);
  e = digitalRead(sen5);
  Serial.print("SENSOR5:"); Serial.println(e);
  f = digitalRead(sen6);
  Serial.print("SENSOR6:"); Serial.println(f);
  if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0)) {
    Start = true;
    digitalWrite(pulse, LOW);
  }
  else if((a != 0) || (b != 0) || (c != 0) || (d != 0) || (e != 0) || (f != 0) ) {
    digitalWrite(pulse,HIGH);
  }
}
