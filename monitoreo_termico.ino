Descripción: El equipo comenzó configurando el hardware básico. En esta fase solo se lee el valor del conversor analógico a digital (ADC) del sensor TMP36 y se imprime en el monitor serie para comprobar que hay conexión.

// --- 1. Definición de pines ---
const int pinTemp = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Lectura cruda del sensor (valor entre 0 y 1023)
  int lectura = analogRead(pinTemp);
  
  Serial.print("Lectura ADC: ");
  Serial.println(lectura);
  
  delay(500); // Pausa básica para no saturar la consola
}
