#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(16); // Pin donde está conectado el DATA del receptor
}

void loop() {
  if (mySwitch.available()) {
    Serial.print("Código recibido: ");
    Serial.println(mySwitch.getReceivedValue());
    mySwitch.resetAvailable();
  }
}
