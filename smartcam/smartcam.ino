#include <Servo.h>
#define LIGHT 8

Servo vertical_servo;
Servo horizontal_servo;
int ch = 0;
String val = "";

void setup() {
  Serial.begin(9600);
  vertical_servo.attach(9);
  horizontal_servo.attach(10);
  vertical_servo.write(0);
  delay(300);
  horizontal_servo.write(0);
  delay(300);
  vertical_servo.write(90);
  delay(300);
  horizontal_servo.write(90);
  delay(300);
  vertical_servo.detach();
  horizontal_servo.detach();
  pinMode(LIGHT, OUTPUT);
  digitalWrite(LIGHT, 0);
  Serial.println("Smartcam ready!");
}

void loop() {
  if (Serial.available()) {  
    while (Serial.available()) { 
      ch = Serial.read();
      val += char(ch);
      delay(10);
    }
  }

  if(val.indexOf("Move up") > -1) {
    moveVertical("up");
  }
  if(val.indexOf("Move down") > -1) {
    moveVertical("down");
  }
  if(val.indexOf("Move left") > -1) {
    moveHorizontal("left");
  }
  if(val.indexOf("Move right") > -1) {
    moveHorizontal("right");
  }
  if(val.indexOf("Light ON") > -1) {
    light(1);
  }
  if(val.indexOf("Light OFF") > -1) {
    light(0);
  } else {
      Serial.println(val);  //печатаем в монитор порта пришедшую строку
    }
val = "";
}

void moveHorizontal(String direction) {
  if (direction == "right") {
    horizontal_servo.attach(10);
    horizontal_servo.write(0);
    delay(30);
    horizontal_servo.detach();
  } else if (direction == "left") {
    horizontal_servo.attach(10);
    horizontal_servo.write(180);
    delay(30);
    horizontal_servo.detach();
  } else {
    //nothing
  }
}

void moveVertical(String direction) {
  if (direction == "up") {
    horizontal_servo.attach(9);
    horizontal_servo.write(0);
    delay(30);
    horizontal_servo.detach();
  } else if (direction == "down") {
    horizontal_servo.attach(9);
    horizontal_servo.write(180);
    delay(30);
    horizontal_servo.detach();
  } else {
    //nothing
  }
}

void light(int light_status) {
  if (light_status = 0) {
    digitalWrite(LIGHT, LOW);
  }
  if (light_status = 1) {
    digitalWrite(LIGHT, HIGH);
  }
}

