#include <Arduino.h>

#define Motor1A 2
#define Motor1B 3
#define Motor2A 4
#define Motor2B 5
#define Motor3A 6
#define Motor3B 7
#define Motor4A 8
#define Motor4B 9


void setup() {
  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2A, OUTPUT);
  pinMode(Motor2B, OUTPUT);
  pinMode(Motor3A, OUTPUT);
  pinMode(Motor3B, OUTPUT);
  pinMode(Motor4A, OUTPUT);
  pinMode(Motor4B, OUTPUT);

  Serial.begin(9600);
  Serial.println("Listo para recibir comandos");
}

void Avanzar(){
  digitalWrite(Motor1A, HIGH);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, LOW);
  digitalWrite(Motor2B, HIGH);
  digitalWrite(Motor3A, HIGH);
  digitalWrite(Motor3B, LOW);
  digitalWrite(Motor4A, LOW);
  digitalWrite(Motor4B, HIGH);
  Serial.println("Avanzar");
}

void Detener(){
  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, LOW);
  digitalWrite(Motor2B, LOW);
  digitalWrite(Motor3A, LOW);
  digitalWrite(Motor3B, LOW);
  digitalWrite(Motor4A, LOW);
  digitalWrite(Motor4B, LOW);
  Serial.println("Detenido");
}

void Retroceder(){
  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, HIGH);
  digitalWrite(Motor2A, HIGH);
  digitalWrite(Motor2B, LOW);
  digitalWrite(Motor3A, LOW);
  digitalWrite(Motor3B, HIGH);
  digitalWrite(Motor4A, HIGH);
  digitalWrite(Motor4B, LOW);
  Serial.println("Retrocediendo");
}

void Derecha(){
  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, HIGH);
  digitalWrite(Motor2A, LOW);
  digitalWrite(Motor2B, HIGH);
  digitalWrite(Motor3A, LOW);
  digitalWrite(Motor3B, HIGH);
  digitalWrite(Motor4A, LOW);
  digitalWrite(Motor4B, HIGH);
  Serial.println("Girando a la Derecha");
}

void Izquierda(){
  digitalWrite(Motor1A, HIGH);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2A, HIGH);
  digitalWrite(Motor2B, LOW);
  digitalWrite(Motor3A, HIGH);
  digitalWrite(Motor3B, LOW);
  digitalWrite(Motor4A, HIGH);
  digitalWrite(Motor4B, LOW);
  Serial.println("Girando Izquierda");
}

void loop() {
  if (Serial.available() > 0) {
    char tecla = Serial.read();

    if (tecla == 'w') {
      Avanzar();
    }

    if (tecla == 'q') {
      Detener();
    }

    if (tecla == 's') {
      Retroceder();
    }

    if (tecla == 'd') {
      Derecha();
    }

    if (tecla == 'a') {
      Izquierda();
    }
  }
}
