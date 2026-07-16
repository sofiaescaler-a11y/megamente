
const int sensorPins[8] = {A1, A2, A3, A4, A5, A6, A7, A8};


void leitura() {
  int sensorValues[8];

  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

    for (int i = 0; i < 8; i++) {
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  
  Serial.println();

   delay(100);
}