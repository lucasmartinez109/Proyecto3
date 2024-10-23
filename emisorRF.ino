#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableTransmit(17); // Pin donde está conectado el DATA del emisor
}

void loop() {
  // Generar un código único (puedes cambiar esto)
  unsigned long code = 12345; // Código a enviar
  mySwitch.send(code, 24); // 24 es la longitud del código
  Serial.println("Mensaje enviado.");
  delay(1000); // Espera 1 segundo antes de enviar de nuevo
}
