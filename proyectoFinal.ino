// Incluímos la librería para poder controlar el servo
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor1;
Servo servoMotor2;
int caseNum;

void movimiento (int angulo) {
  for (int i = 25; i <= 70; i++) {
    servoMotor1.write(i);
    delay(50);
  }
  //servoMotor2.write(70);
  delay(500);
  for (int j = 70; j >= 25; j--) {
    servoMotor2.write(j);
    delay(50);
  }
  //servoMotor3.write(0);
  //servoMotor4.write(0);
  delay(500);
  for (int k = 0; k <= angulo; k++) {
    servoMotor1.write(k);
    delay(50);
  }
  //servoMotor1.write(angulo);
  delay(1000);
  for (int n = angulo; n >= 0; n--) {
    servoMotor1.write(n);
    delay(50);
  }
  //servoMotor1.write(0);
  //servoMotor3.write(0);
  //servoMotor4.write(0);
  // <-se suelta el objeto->
}

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);

  // Se definen los diferentes puertos y se asignan a los diferentes servomotores disponibles
  servoMotor1.attach(9); // servo de la base
  servoMotor2.attach(10); // servo del "codo"
  //servoMotor3.attach(11); // servo de la "muñeca"
  //servoMotor3.attach(6); // servo de la garra
}

void loop() {

  // Esperamos 1 segundo antes de proceder
  //delay(1000);

  // Desplazamos todos los servomotores para que el brazo quede en la posición inicial
  // Desplazamos el angulo de la base a la posición 90º (Para que el brazo quede "mirando al frente")
  //servoMotor1.write(40);
  // Desplazamos el "codo" a la posición 90º (Para que el brazo quede horizontal)
  //servoMotor2.write(70);
  // Desplazamos la "muñeca" a la posición inicial
  //servoMotor3.write(x);
  // Desplazamos la garra a la posición inicial
  //servoMotor4.write(x);

  // Esperamos 1 segundo antes de proceder
  //delay(1000);

  // Se recoge el objeto..
  // Se baja el brazo para recoger el objeto
  //servoMotor2.write(25);
  // Se agarra el objeto
  // <-codigo aquí->

  // Esperamos 1 segundo antes de proceder
  //delay(1000);

  // Se levanta el objeto hasta la altura inicial
  //servoMotor2.write(25);

  // Se procede a mover el objeto dependiendo de la clasificación obtenida
  caseNum = Serial.parseInt();
  if (caseNum == 1) {
    movimiento(180);
  } else if (caseNum == 2) {
    movimiento(135);
  } else if (caseNum == 3) {
    movimiento(90);
  }
}
