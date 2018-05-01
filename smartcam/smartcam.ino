#include <Servo.h>

Servo vertical_servo;
Servo horizontal_servo;

void setup() {
  Serial.begin(9600);
  vertical_servo.attach(10);
  horizontal_servo.attach(9);
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
  Serial.println("Smartcam ready!");
}

void loop() {
  //moveHorizontal("right");
  //delay(100);
  //moveHorizontal("left");
  //delay(100);
  //moveVertical("up");
  //delay(100);
  //moveVertical("down");
  //delay(100);
}

void moveHorizontal(String direction) {
  if (direction == "right") {
    horizontal_servo.attach(9);
    horizontal_servo.write(90);
    delay(30);
    horizontal_servo.detach();
  } else if (direction == "left") {
    horizontal_servo.attach(9);
    horizontal_servo.write(180);
    delay(30);
    horizontal_servo.detach();
  } else {
    //nothing
  }
}

void moveVertical(String direction) {
  if (direction == "up") {
    horizontal_servo.attach(10);
    horizontal_servo.write(90);
    delay(30);
    horizontal_servo.detach();
  } else if (direction == "down") {
    horizontal_servo.attach(10);
    horizontal_servo.write(180);
    delay(30);
    horizontal_servo.detach();
  } else {
    //nothing
  }
}
