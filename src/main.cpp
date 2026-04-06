#include <Arduino.h>

// Definición de pines (Uso de arreglos para escalabilidad)
const int pinesMotores[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(pinesMotores[i], OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.println("Sistema listo. Use W, A, S, D para mover y Q para detener.");
}

// Función maestra para controlar los motores
// Permite enviar los 8 estados de un solo golpe
void controlarMotores(bool m1a, bool m1b, bool m2a, bool m2b, bool m3a, bool m3b, bool m4a, bool m4b, int m1p, int m2p, int m3p, int m4p) {
  digitalWrite(2, m1a); digitalWrite(4, m1b); analogWrite(3, m1p);
  digitalWrite(7, m2a); digitalWrite(8, m2b); analogWrite(5, m2p);
  digitalWrite(10, m3a); digitalWrite(11, m3b); analogWrite(6, m3p);
  digitalWrite(12, m4a); digitalWrite(13, m4b); analogWrite(9, m4p);
}
void ControlTeclado(){
  if (Serial.available() > 0) {
    char tecla = Serial.read();

    switch (tolower(tecla)) { // tolower permite que funcione con 'W' o 'w'
      case 'w':
        controlarMotores(HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, 127, 127, 127, 127);
        Serial.println("Estado: Avanzar");
        break;
        
      case 's':
        controlarMotores(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW, 127, 127, 127, 127);
        Serial.println("Estado: Retroceder");
        break;
        
      case 'a':
        controlarMotores(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, 127, 127, 127, 127);
        Serial.println("Estado: Girar Izquierda");
        break;
        
      case 'd':
        controlarMotores(LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, 127, 127, 127, 127);
        Serial.println("Estado: Girar Derecha");
        break;
        
      case 'q':
        controlarMotores(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, 0, 0, 0, 0);
        Serial.println("Estado: Detenido");
        break;

      default:
        // Opcional: ignorar saltos de línea o caracteres extraños
        break;
    }
  }
}
void loop() {
  /*controlarMotores(HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, 90, 90, 90, 90);
  delay(3000);
  controlarMotores(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, 90, 90, 90, 90);
  delay(1000);
  controlarMotores(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW, 90, 90, 90, 90);
  delay(3000);
  controlarMotores(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, 0, 0, 0, 0);
  delay(5000);*/
  ControlTeclado();
}