#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor1;
Servo servoMotor2;
int caseNum;
bool standBy = false;
int led1 = 7;
int led2 = 4;
int led3 = 2;
int posServo1, posServo2;

void resetPosition(){
  posServo1 = servoMotor1.read();
  posServo2 = servoMotor2.read();
  
  for (int i = posServo1; i >= 50; i-=5) {
    servoMotor1.write(i);
    delay(80);
  }
  delay(1000);

  for (int j = posServo2; j >= 40; j-=5) {
    servoMotor2.write(j);
    delay(80);
  }
  delay(1000);
  
  standBy = true;
}

void verticalMovement(){
  for (int j = 40; j <= 80; j+=5) {
    servoMotor2.write(j);
    delay(80);
  }
  delay(1000);

  for (int j = 80; j >= 40; j-=5) {
    servoMotor2.write(j);
    delay(80);
  }
  delay(1000);
}

void movimiento (int angle) {
  standBy = false;
   
  for (int i = 50; i <= angle; i+=5) {
    servoMotor1.write(i);
    delay(90);
  }
  delay(1500);

  verticalMovement();

  for (int i = angle; i >= 50; i-=5) {
    servoMotor1.write(i);
    delay(90);
  }
  delay(1000);
  standBy = true;
 }


void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // Se definen los diferentes puertos y se asignan a los diferentes servomotores disponibles
  servoMotor1.attach(9); // servo de la base
  servoMotor2.attach(10); // servo del "codo"
}

void loop() {
  
  
  if (! standBy){
    resetPosition();
  }

  caseNum = Serial.parseInt();
  if (caseNum == 1) {
    digitalWrite(led1, HIGH);
    movimiento(180);
    digitalWrite(led1, LOW);
  } else if (caseNum == 2) {
    digitalWrite(led2, HIGH);
    movimiento(135);
    digitalWrite(led2, LOW);
  } else if (caseNum == 3) {
    digitalWrite(led3, HIGH);
    movimiento(90);
    digitalWrite(led3, LOW);
  } else if (caseNum == 4){
    verticalMovement();
  }
  caseNum = 0;


}
