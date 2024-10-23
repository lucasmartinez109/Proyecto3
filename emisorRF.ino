#include <RCSwitch.h>

//unsigned long t = 0;
unsigned long h=0;

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableTransmit(17); // Pin donde está conectado el DATA del emisor
}

void loop() {
  // t=t+1; // Código a enviar
   h=h+1;
  // Generar un código único (puedes cambiar esto)
 
  mySwitch.send(h, 24); // 24 es la longitud del código
  Serial.println("Mensaje enviado.");
  delay(1000); // Espera 1 segundo antes de enviar de nuevo
}
