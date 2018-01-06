#include <Stepper.h>

#define LED_EYE 13
#define LED_LIGHT 2
#define OPTO A5

int hb = 0;
int vert_flag;

void setup() {
  pinMode(LED_EYE, OUTPUT);
  pinMode(LED_LIGHT, OUTPUT);
  pinMode(OPTO, OUTPUT);
  analogWrite(LED_EYE, 0);
  digitalWrite(LED_LIGHT,1);
  delay(100);
  digitalWrite(LED_LIGHT,0);
}

void loop() {
  //digitalWrite(LED_EYE, hb);
  //delay(3000);
  //hb = 1;
  //digitalWrite(LED_EYE, hb);
  //delay(200);
  //hb = 0;
  vert_flag = analogRead(OPTO);
  analogWrite(LED_EYE, vert_flag + 100);
  //delay(vert_flag);
  //analogWrite(LED_EYE, LOW);
  //delay(vert_flag);
  //analogWrite(LED_EYE, vert_flag);
}
