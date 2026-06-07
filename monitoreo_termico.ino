//Descripción: Se introduce la entrada digital (INPUT_PULLUP) y la variable alarmaSilenciada. En esta versión preliminar, la lectura se hace de forma directa (sin debouncing) y el programa aún depende de la función delay().

const int pinTemp   = A0;
const int pinBoton  = 3;
const int pinBuzzer = 8;
const int ledRojo   = 6;
const int ledAzul  = 5;
const int ledVerde   = 4;

float limiteTemperatura = 31.0;
bool alarmaSilenciada = false;

void setup() {
  Serial.begin(9600);
  pinMode(pinBoton, INPUT_PULLUP);
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

  // Lectura básica del botón (sin antirrebote)
  if (digitalRead(pinBoton) == LOW) {
    alarmaSilenciada = true;
  }

  if (temperaturaC >= limiteTemperatura) {
    if (!alarmaSilenciada) {
      setColor(HIGH, LOW, LOW); 
      tone(pinBuzzer, 1000);
    } else {
      setColor(HIGH, LOW, LOW); // LED fijo indicador de falla
      noTone(pinBuzzer);        // Buzzer silenciado manualmente
    }
  } else {
    setColor(LOW, HIGH, LOW);
    noTone(pinBuzzer);
    alarmaSilenciada = false;   // Rearme automático
  }

  delay(200);
}

void setColor(int rojo, int verde, int azul) {
  digitalWrite(ledRojo, rojo);
  digitalWrite(ledVerde, verde);
  digitalWrite(ledAzul, azul);
}
