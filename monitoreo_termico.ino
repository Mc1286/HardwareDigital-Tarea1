Descripción: Se incorpora la lógica de umbral. Se configuran los pines del LED RGB y se define el límite de temperatura (31°C). Si se supera, enciende rojo; si no, verde.
// --- 1. Definición de pines ---
const int pinTemp  = A0;
const int ledRojo  = 6;
const int ledAzul = 5;
const int ledVerde  = 4;

// --- 2. Variables del sistema ---
float limiteTemperatura = 31.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  setColor(LOW, LOW, LOW); // Apagar LED inicial (Cátodo Común)
}

void loop() {
  int lectura = analogRead(pinTemp);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperaturaC = (voltaje - 0.5) * 100.0;

  // Lógica del umbral visual
  if (temperaturaC >= limiteTemperatura) {
    setColor(HIGH, LOW, LOW); // Rojo encendido
  } else {
    setColor(LOW, HIGH, LOW); // Verde encendido
  }

  delay(500);
}

// Función para controlar el LED RGB (Cátodo Común)
void setColor(int rojo, int verde, int azul) {
  digitalWrite(ledRojo, rojo);
  digitalWrite(ledVerde, verde);
  digitalWrite(ledAzul, azul);
}
