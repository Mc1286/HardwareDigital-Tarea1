//Descripción: Se añade el segundo actuador exigido por la tarea. El buzzer se acopla a la lógica del umbral de temperatura para sonar simultáneamente con el LED rojo.

// --- 1. Definición de pines ---
const int pinTemp   = A0;
const int pinBuzzer = 8;
const int ledRojo   = 6;
const int ledAzul  = 5;
const int ledVerde   = 4;

float limiteTemperatura = 31.0;

void setup() {
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  noTone(pinBuzzer);
  setColor(LOW, LOW, LOW);
}

void loop() {
  int lectura = analogRead(pinTemp);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperaturaC = (voltaje - 0.5) * 100.0;

  if (temperaturaC >= limiteTemperatura) {
    setColor(HIGH, LOW, LOW);
    tone(pinBuzzer, 1000);    // Activar sonido
  } else {
    setColor(LOW, HIGH, LOW);
    noTone(pinBuzzer);        // Silenciar sonido
  }

  delay(500);
}

void setColor(int rojo, int verde, int azul) {
  digitalWrite(ledRojo, rojo);
  digitalWrite(ledVerde, verde);
  digitalWrite(ledAzul, azul);
}
