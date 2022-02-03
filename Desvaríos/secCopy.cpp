void movimiento (int angulo) {
  for (int i = 25; i <= 70; i++) {
    servoMotor1.write(i);
    delay(250);
  }
  //servoMotor2.write(70);
  delay(500);
  for (int j = 70; j >= 25; j--) {
    servoMotor2.write(j);
    delay(250);
  }
  //servoMotor3.write(0);
  //servoMotor4.write(0);
  delay(500);
  for (int k = 0; k <= angulo; k++) {
    servoMotor1.write(k);
    delay(250);
  }
  //servoMotor1.write(angulo);
  delay(1000);
  for (int n = angulo; n >= 0; n--) {
    servoMotor1.write(n);
    delay(250);
  }
  //servoMotor1.write(0);
  //servoMotor3.write(0);
  //servoMotor4.write(0);
  // <-se suelta el objeto->
}


// Función original

void movimiento (int angulo) {
    servoMotor2.write(70);
    delay(500);
    servoMotor2.write(25);
    //servoMotor3.write(0);
    //servoMotor4.write(0);
    delay(1000);
    servoMotor1.write(angulo);
    delay(1000);
    servoMotor1.write(0);
    //servoMotor3.write(0);
    //servoMotor4.write(0);
    // <-se suelta el objeto->
}
