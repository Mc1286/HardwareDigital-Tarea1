Descripción: Se aplica la fórmula matemática documentada para transformar la lectura del ADC a voltaje y, finalmente, a la magnitud física requerida (grados Celsius).

// --- 1. Definición de pines ---
const int pinTemp = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(pinTemp);

  // Conversión de ADC a Magnitud Física
  float voltaje = lectura * (5.0 / 1023.0);
  float temperaturaC = (voltaje - 0.5) * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(temperaturaC, 1);
  Serial.println(" C");

  delay(500);
}
