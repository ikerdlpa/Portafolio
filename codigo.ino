#include <Servo.h>

int pot1=A0;
int pot2=A1;
int pot3=A2;
int pot4=A3;
int pot5=A4;
int pot6=A5;

int mov1=0;
int mov2=0;
int mov3=0;
int mov4=0;
int mov5=0;
int mov6=0;

int potest1=0;
int potest2=0;
int potest3=0;
int potest4=0;
int potest5=0;
int potest6=0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);

  servo1.write(90);
  servo2.write(0);
  servo3.write(90);
  servo4.write(30);
  servo5.write(90);
  servo6.write(90);
  delay(5000);
  Serial.begin(9600);
}

void loop() {

  potest1=analogRead(pot1);
  potest2=analogRead(pot2);
  potest3=analogRead(pot3);
  potest4=analogRead(pot4);
  potest5=analogRead(pot5);
  potest6=analogRead(pot6);

  mov1=map(potest1,0,123,0,180);
  mov2=map(potest2,0,123,0,40);
  mov3=map(potest3,0,123,180,0);
  mov4=map(potest4,0,123,0,180);
  mov5=map(potest5,0,123,0,180);
  mov6=map(potest6,0,123,0,180);

  servo1.write(mov1);
  servo2.write(mov2);
  servo3.write(mov3);
  servo4.write(mov4);
  servo5.write(mov5);
  servo6.write(mov6);

  Serial.print(mov1);
  Serial.print(", ");
  Serial.print(mov2);
  Serial.print(", ");
  Serial.print(mov3);
  Serial.print(", ");
  Serial.print(mov4);
  Serial.print(", ");
  Serial.print(mov5);
  Serial.print(", ");
  Serial.println(mov6);

  delay(20);
}
