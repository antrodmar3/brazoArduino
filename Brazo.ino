#include <Servo.h>

const int analogPinX = 0;
const int analogPinY = 1;

const int botonRed = 2;
const int botonYel = 3;
const int botonGre = 4;
const int botonBlu = 5;
const int botonE = 6;
const int botonF = 7;
const int Rojo = A2;
const int Verde = A3;
const int Azul = A5;

const int DELAY = 100;

Servo servoPinza;
Servo servoIzq;
Servo servoDer;
Servo servoBas;

void setup() {

 Serial.begin(9600);

 pinMode(Rojo, OUTPUT);
 pinMode(Verde, OUTPUT);
 pinMode(Azul, OUTPUT);

 pinMode(botonRed, INPUT);
 digitalWrite(botonRed, HIGH);

 pinMode(botonYel, INPUT);
 digitalWrite(botonYel, HIGH);

 pinMode(botonGre, INPUT);
 digitalWrite(botonGre, HIGH);
 
 pinMode(botonBlu, INPUT);
 digitalWrite(botonBlu, HIGH);

 pinMode(botonE, INPUT);
 digitalWrite(botonE, HIGH);
 
 pinMode(botonF, INPUT);
 digitalWrite(botonF, HIGH);

 servoIzq.attach(9);
 servoDer.attach(10);
 servoBas.attach(11);
 servoPinza.attach(13);
}
/*Esta función controla el color en el led RGB*/
  void establecerColor(int R, int G, int B) {
  analogWrite(Rojo, R);
  analogWrite(Verde, G);
  analogWrite(Azul, B);
  }

void loop() {

int sensorValueX=analogRead(analogPinX);
int gradosX=(sensorValueX/1023.0)*180;
int gradosD = (sensorValueX/1023.0)*140;
int sensorValueY=analogRead(analogPinY);
int gradosY=(sensorValueY/1023.0)*180;

 /*Con estos condicionales vamos cambiando
 el servo que movemos con el joystick usando los botones
 y además encendemos el led con el color correspondiente al botón
 que hemos pulsado */
 if(digitalRead(botonRed) == LOW) {
   establecerColor(255,0,0);
   servoPinza.write(gradosX);
   Serial.println("Boton A pulsado");
   
   delay(DELAY);

 }
 else if(digitalRead(botonYel) == LOW) {
   establecerColor(255,128,0);
   servoIzq.write(gradosY);
   Serial.println("Boton B pulsado");

   delay(DELAY);
 }
 else if(digitalRead(botonGre) == LOW) {
   establecerColor(0,255,0);
   servoDer.write(gradosD);
   Serial.println("Boton C pulsado");

   delay(DELAY);
 }
  else if(digitalRead(botonBlu) == LOW) {
   establecerColor(0,0,255);
   servoBas.write(gradosX);
   Serial.println("Boton D pulsado");

   delay(DELAY);
 }
  else if(digitalRead(botonE) == LOW) {
   establecerColor(0,0,0);
   servoPinza.write(86);
   servoDer.write(67);
   servoIzq.write(88);
   servoBas.write(86);
   Serial.println("Boton E pulsado");

   delay(DELAY);
 } 
  else if(digitalRead(botonF) == LOW) {
   establecerColor(255,255,255);
   Serial.println("Boton F pulsado");

   delay(DELAY);
 }
 Serial.print("gradosX = ");
 Serial.println(gradosX);
  Serial.print("gradosY = ");
  Serial.println(gradosY);
   Serial.print("gradosD = ");
   Serial.println(gradosD);
   delay(500);
}
