import processing.serial.*;
Serial port;
String val;

void setup() {
  String portName = Serial.list()[2];
  port = new Serial(this, "/dev/ttyUSB0", 9600);
  println(portName);
  //exit();
}

void draw() {
  if ( port.available() > 0) {  
    val = port.readStringUntil('\n');         
  } 
  println(val);
  port.write("Move down");
  delay(100);
  port.write("Move down");
  delay(100);
  port.write("Move down");
  delay(100);
  port.write("Move down");
  delay(100);
}
