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
  int velAlta = 140;
  int velBaja = 80; // Velocidad reducida para las ruedas interiores en un giro
  if (Serial.available() > 0) {
    char tecla = Serial.read();
    switch (tolower(tecla)) {
      case 'w': // AVANZAR
        controlarMotores(HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, velAlta, velAlta, velAlta, velAlta);
        Serial.println("Estado: Avanzar");
        break;
        
      case 's': // RETROCEDER
        controlarMotores(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW, velAlta, velAlta, velAlta, velAlta);
        Serial.println("Estado: Retroceder");
        break;

      case 'q': // AVANZAR HACIA LA IZQUIERDA (Giro abierto)
        // Motores derechos a tope, izquierdos lentos
        controlarMotores(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, velAlta, velAlta, velAlta, velAlta);
        delay(50);
        controlarMotores(HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, velAlta, velAlta, velAlta, velAlta);
        delay(100);
        Serial.println("Estado: Avanzar Izquierda");
        break;

      case 'e': // AVANZAR HACIA LA DERECHA (Giro abierto)
        // Motores izquierdos a tope, derechos lentos
        controlarMotores(HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, velBaja, velAlta, velBaja, velAlta);
        Serial.println("Estado: Avanzar Derecha");
        break;
        
      case 'a': // GIRAR IZQUIERDA (Sobre su eje)
        controlarMotores(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, velAlta, velAlta, velAlta, velAlta);
        Serial.println("Estado: Rotar Izquierda");
        break;
        
      case 'd': // GIRAR DERECHA (Sobre su eje)
        controlarMotores(LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, velAlta, velAlta, velAlta, velAlta);
        Serial.println("Estado: Rotar Derecha");
        break;
      
      case ' ': // ESPACIO PARA DETENER
        controlarMotores(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, 0, 0, 0, 0);
        Serial.println("Estado: DETENIDO (Freno)");
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