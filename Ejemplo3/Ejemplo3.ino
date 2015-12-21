#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // wait serial port initialization
  }

  StaticJsonBuffer<200> jsonBuffer;

/*
 * Esta cadena simula unos datos recibidos de cualquier fuente Serial,Ethernet,SD...
 */
  char jsonS[] =
      "{\"nombre\":\"SOLEPCC\",\"valor1\":1351824120,\"sensors\":[{\"name\":\"Sensor Humedad\",\"description\":\"Mide Humedad\",\"sensor-type\":\"Humedad\"},{\"name\":\"Sensor temperatura\",\"description\":\"Mide Temperatura\",\"sensor-type\":\"Temperatura\"}]}";

  JsonObject& json = jsonBuffer.parseObject(jsonS);

  if (!json.success()) {
    Serial.println("parseObject() falló");
    return;
  }

  const char* nombre = json["nombre"];
  long time = json["valor1"];
  JsonObject& pos1 = json["sensors"][0];

  Serial.println(nombre);
  Serial.println(time);
  pos1.prettyPrintTo(Serial);
}

void loop() {
  // not used in this example
}
