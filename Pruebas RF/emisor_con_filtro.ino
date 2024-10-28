#include <RCSwitch.h>

RCSwitch emisorTPMS = RCSwitch();

void setup() {
  Serial.begin(115200);
  
  // Configura el pin para el emisor del TPMS
  emisorTPMS.enableTransmit(17);   // Pin 17 para el emisor del TPMS
}

void loop() {
  // Mensaje a enviar: ffff 8b (24 bits)
  unsigned long mensajeCompleto = 0xFFFF; // Cabecera
  mensajeCompleto = (mensajeCompleto << 8) | 0x8B; // Añadir 8B

  // Enviar mensaje completo como un solo paquete
  emisorTPMS.send(mensajeCompleto, 24); // Enviar 24 bits en total
  delay(1000); // Espera un segundo antes de enviar nuevamente
  Serial.println(mensajeCompleto);
  Serial.println("Mensaje de 24 bits enviado.");
}
#include <RCSwitch.h>

RCSwitch emisorTPMS = RCSwitch();

void setup() {
  Serial.begin(115200);
  
  // Configura el pin para el emisor del TPMS
  emisorTPMS.enableTransmit(17);   // Pin 17 para el emisor del TPMS
}

void loop() {
  // Mensaje a enviar: ffff 8b (24 bits)
  unsigned long mensajeCompleto = 0xFFFF; // Cabecera
  mensajeCompleto = (mensajeCompleto << 8) | 0x8B; // Añadir 8B

  // Enviar mensaje completo como un solo paquete
  emisorTPMS.send(mensajeCompleto, 24); // Enviar 24 bits en total
  delay(1000); // Espera un segundo antes de enviar nuevamente
  Serial.println(mensajeCompleto);
  Serial.println("Mensaje de 24 bits enviado.");
}
