
#define ledPin 13

#define enableMotor1 6
#define sentidoFrenteMotor1 5
#define sentidoTrasMotor1 7

#define enableMotor2 10
#define sentidoFrenteMotor2 9
#define sentidoTrasMotor2 8




char inputByte = 'z';

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  Serial.begin(9600); // Default communication rate of the Bluetooth module

  pinMode(enableMotor1, OUTPUT);
  pinMode(sentidoFrenteMotor1, OUTPUT);
  pinMode(sentidoTrasMotor1, OUTPUT);

  pinMode(enableMotor2, OUTPUT);
  pinMode(sentidoFrenteMotor2, OUTPUT);
  pinMode(sentidoTrasMotor2, OUTPUT);

  digitalWrite(enableMotor1, HIGH);
  //digitalWrite(enableMotor2, HIGH);

}

void loop() {
  while (Serial.available() > 0) {
    analogWrite(enableMotor2, 220);
    inputByte = Serial.read();
    //Serial.println("working");
    Serial.write(inputByte);
    if (inputByte == 'a') {
      digitalWrite(13, HIGH);
      //Serial.println("letter A");
      frente();
    } else if (inputByte == 'b') {
      //Serial.println("letter B");
      digitalWrite(13, LOW);
      tras();
    } else if (inputByte == 'c') {
      girar();
    } else if (inputByte == 'd') {
      parar();
    }
  }

  /*int velocidade = 500;

    analogWrite(enableMotor1, 255);
    analogWrite(enableMotor2, 70);

    digitalWrite(sentidoFrenteMotor1, HIGH);
    digitalWrite(sentidoTrasMotor1, LOW);
    digitalWrite(sentidoFrenteMotor2, HIGH);
    digitalWrite(sentidoTrasMotor2, LOW);*/

}

void girar() {
  digitalWrite(sentidoFrenteMotor1, HIGH);
  digitalWrite(sentidoTrasMotor1, LOW);

  digitalWrite(sentidoFrenteMotor2, LOW);
  digitalWrite(sentidoTrasMotor2, HIGH);

  delay(500);
}

void frente() {
  digitalWrite(sentidoFrenteMotor1, HIGH);
  digitalWrite(sentidoTrasMotor1, LOW);

  digitalWrite(sentidoFrenteMotor2, HIGH);
  digitalWrite(sentidoTrasMotor2, LOW);

  delay(500);
}

void tras() {
  digitalWrite(sentidoFrenteMotor1, LOW);
  digitalWrite(sentidoTrasMotor1, HIGH);

  digitalWrite(sentidoFrenteMotor2, LOW);
  digitalWrite(sentidoTrasMotor2, HIGH);

  delay(500);
}

void parar() {
  digitalWrite(sentidoFrenteMotor1, LOW);
  digitalWrite(sentidoTrasMotor1, LOW);

  digitalWrite(sentidoFrenteMotor2, LOW);
  digitalWrite(sentidoTrasMotor2, LOW);
}
