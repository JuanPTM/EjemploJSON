
#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // wait serial port initialization
  }

  StaticJsonBuffer<200> jsonBuffer;

  JsonObject& json = jsonBuffer.createObject();
  json["nombre"] = "SOLEPCC";
  json["valor1"] = 1351824120;

  JsonArray& datosS = json.createNestedArray("sensors");
  datosS.add(48.756080);
  datosS.add(2.302038);

  json.printTo(Serial);
  // This prints:
  // {"nombre":"SOLEPCC","valor1":1351824120,"sensors":[48.76,2.30]}

  Serial.println();

  json.prettyPrintTo(Serial);
  // Imprimirá
  // {
  //   "nombre": "SOLEPCC",
  //   "valor1": 1351824120,
  //   "sensors": [
  //     48.76,
  //     2.30
  //   ]
  // }
}

void loop() {
  // not used in this example
}
