
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

  JsonObject& s1 = jsonBuffer.createObject();// Creacion 1º objeto del array

  s1["name"] = "Sensor Humedad";
  s1["description"] = "Mide Humedad";                 // Aquí podriamos añadir los datos y campos que quisieramos mientras no sobreparasamos el limite del buffer.
  s1["sensor-type"] = "Humedad";

  JsonObject& s2 = jsonBuffer.createObject(); // Creacion 2º objeto del array 

  s2["name"] = "Sensor temperatura";
  s2["description"] = "Mide Temperatura";            // Aquí podriamos añadir los datos y campos que quisieramos mientras no sobreparasamos el limite del buffer.
  s2["sensor-type"] = "Temperatura";

  JsonArray& datosS = json.createNestedArray("sensors");
  datosS.add(s1);
  datosS.add(s2);

  json.printTo(Serial);
  // Escribirá:
  // {"nombre":"SOLEPCC","valor1":1351824120,"sensors":[{"name":"Sensor Humedad","description":"Mide Humedad","sensor-type":"Humedad"},{"name":"Sensor temperatura","description":"Mide Temperatura","sensor-type":"Temperatura"}]}


  Serial.println();

  json.prettyPrintTo(Serial);
  // Imprimirá
  //{
  //  "nombre": "SOLEPCC",
  //  "valor1": 1351824120,
  //  "sensors": [
  //    {
  //      "name": "Sensor Humedad",
  //      "description": "Mide Humedad",
  //      "sensor-type": "Humedad"
  //    },
  //    {
  //      "name": "Sensor temperatura",
  //      "description": "Mide Temperatura",
  //      "sensor-type": "Temperatura"
  //    }
  //  ]
  //}
}

void loop() {
  // not used in this example
}
