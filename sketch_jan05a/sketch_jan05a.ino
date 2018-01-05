#define LED_EYE 13
#define LED_LIGHT 2

int hb = 0;

void setup() {
  pinMode(LED_EYE, OUTPUT);
  pinMode(LED_LIGHT, OUTPUT);
  analogWrite(LED_EYE, 0);
  digitalWrite(LED_LIGHT,1);
  delay(100);
  digitalWrite(LED_LIGHT,0);
}

void loop() {
  digitalWrite(LED_EYE, hb);
  delay(3000);
  hb = 1;
  digitalWrite(LED_EYE, hb);
  delay(200);
  hb = 0;
}
