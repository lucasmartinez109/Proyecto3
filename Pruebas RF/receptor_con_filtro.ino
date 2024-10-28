#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// Cabecera esperada del TPMS
const unsigned long TPMS_HEADER = 0xFFFF;
// Cabecera esperada de otro emisor
const unsigned long OTHER_HEADER = 0xBBBB;

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(16); // Pin donde está conectado el DATA del receptor
}

void loop() {
  if (mySwitch.available()) {
    unsigned long receivedValue = mySwitch.getReceivedValue();

    // Extraer la cabecera del mensaje recibido (primeros 16 bits)
    //Serial.print(receivedValue);
    unsigned long receivedHeader = (receivedValue >> 8) & 0xFFFF; // Los primeros 16 bits
    unsigned long receivedData = receivedValue & 0xFF;           // Los últimos 16 bits
    //1111 1111 1111 1111 1000 1011
    if (receivedHeader == TPMS_HEADER) {
      // Mensaje del TPMS
      Serial.print("TPMS Código recibido: ");
      Serial.println(receivedData, HEX); // Mostrar solo la parte relevante (el valor de 'h')
    } else if (receivedHeader == OTHER_HEADER) {
      // Mensaje de otro emisor
      Serial.print("Emisor genérico Código recibido: ");
      Serial.println(receivedData, HEX); // Mostrar solo el valor enviado por el otro emisor
    } else {
      // Mensaje desconocido
      Serial.println("Mensaje desconocido recibido.");
      Serial.println(receivedHeader);
    }

    mySwitch.resetAvailable();
  }
}
