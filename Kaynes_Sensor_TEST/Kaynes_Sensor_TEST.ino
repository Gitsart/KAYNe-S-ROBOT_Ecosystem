#include<TimerOne.h>
int a, b, c, d, e;
const int lim = 17;
const int sena = 20;
const int senb = 8;
const int possen = 9;
const int senc = 18;
bool Start = false;
void setup() {
  pinMode(lim, INPUT_PULLUP);
  pinMode(sena, INPUT_PULLUP); //pb
  pinMode(senb, INPUT_PULLUP);
  pinMode(possen, INPUT_PULLUP); //limit
  pinMode(senc, INPUT_PULLUP); //cloth
  Serial.begin(9600);
  Timer1.initialize(30000);
  Timer1.attachInterrupt(readSensor);


}

void loop() {
  if(!Start) {
    Serial.println("BLAAAAAA");
  }
  }



void readSensor() {
  a = digitalRead(lim);
  b = digitalRead(sena);
  c = digitalRead(senb);
  d = digitalRead(possen);
  e = digitalRead(senc);
  if ((a == 1 && b == 0 && c == 0 && d == 0 && e ==0)) {
    Serial.println("ROBOT SIGNAL");
    Start = true;
  }
  else if ((a==0)||(b==1) || (c==1) || (d ==1) || (e ==1)) {
    Start = false;
  }

}
