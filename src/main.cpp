#include <Arduino.h>

// Definición de pines (Uso de arreglos para escalabilidad)
const int pinesMotores[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pinesMotores[i], OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.println("Sistema listo. Use W, A, S, D para mover y Q para detener.");
}

// Función maestra para controlar los motores
// Permite enviar los 8 estados de un solo golpe
void controlarMotores(bool m1a, bool m1b, bool m2a, bool m2b, bool m3a, bool m3b, bool m4a, bool m4b) {
  digitalWrite(2, m1a); digitalWrite(3, m1b);
  digitalWrite(4, m2a); digitalWrite(5, m2b);
  digitalWrite(6, m3a); digitalWrite(7, m3b);
  digitalWrite(8, m4a); digitalWrite(9, m4b);
}

void loop() {
  if (Serial.available() > 0) {
    char tecla = Serial.read();

    switch (tolower(tecla)) { // tolower permite que funcione con 'W' o 'w'
      case 'w':
        controlarMotores(HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH);
        Serial.println("Estado: Avanzar");
        break;
        
      case 's':
        controlarMotores(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW);
        Serial.println("Estado: Retroceder");
        break;
        
      case 'a':
        controlarMotores(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW);
        Serial.println("Estado: Girar Izquierda");
        break;
        
      case 'd':
        controlarMotores(LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH);
        Serial.println("Estado: Girar Derecha");
        break;
        
      case 'q':
        controlarMotores(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW);
        Serial.println("Estado: Detenido");
        break;

      default:
        // Opcional: ignorar saltos de línea o caracteres extraños
        break;
    }
  }
}