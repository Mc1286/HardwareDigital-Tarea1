//Descripción: El código final y optimizado. Se elimina el bloqueante delay(), se implementan temporizadores con millis(), se agrega el sistema antirrebote por software para el botón, y se divide la lógica en funciones especializadas para mantener el loop() limpio.

// --- 1. Definición de pines ---
const int pinTemp   = A0;
const int pinBoton  = 3;
const int pinBuzzer = 8;
const int ledRojo   = 6;
const int ledAzul  = 5;
const int ledVerde   = 4;

// --- 2. Variables del sistema ---
float limiteTemperatura = 31.0;
float temperaturaC = 0.0; // Variable global para la temperatura
bool alarmaSilenciada = false;

// Anti-rebote del botón
bool estadoAnteriorBoton = HIGH;
bool estadoEstableBoton  = HIGH;
unsigned long tiempoUltimoRebote = 0;
const unsigned long DEBOUNCE_MS = 50;

// Temporizador para parpadeo asíncrono
unsigned long tiempoAnteriorParpadeo = 0;
bool estadoParpadeo = false;

// --- 3. Declaración de funciones ---
void setColor(int rojo, int verde, int azul);
void leerTemperatura();
void verificarBoton();
void controlarAlarma();

void setup() {
  Serial.begin(9600);
  pinMode(pinBoton, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  noTone(pinBuzzer);
  
  // En Cátodo Común, enviar LOW a todos apaga el LED
  setColor(LOW, LOW, LOW); 
}

// Loop principal limpio, delegando tareas a funciones específicas
void loop() {
  leerTemperatura();
  verificarBoton();
  controlarAlarma();
}

// --- 4. Implementación de funciones ---

// Función: Lee el sensor analógico y documenta la conversión ADC
void leerTemperatura() {
  int lectura = analogRead(pinTemp);
  
  // Conversión de ADC a Magnitud Física:
  // 1. El ADC de 10 bits va de 0 a 1023. Multiplicar por (5.0/1023.0) nos da el voltaje real.
  float voltaje = lectura * (5.0 / 1023.0);
  // 2. El TMP36 tiene un offset de 0.5V a 0°C y una resolución de 10mV (0.01V) por grado Celsius.
  temperaturaC = (voltaje - 0.5) * 100.0;
  
  // Imprimir cada 500ms para no saturar el monitor serial usando millis()
  static unsigned long ultimoPrint = 0;
  if (millis() - ultimoPrint > 500) {
    Serial.print("Temperatura: ");
    Serial.print(temperaturaC, 1);
    Serial.println(" C");
    ultimoPrint = millis();
  }
}

// Función: Controla el antirrebote del pulsador
void verificarBoton() {
  bool lecturaBruta = digitalRead(pinBoton);

  // Reinicia temporizador si hay ruido o cambio
  if (lecturaBruta != estadoAnteriorBoton) {
    tiempoUltimoRebote = millis();
  }

  // Verifica si el estado lleva suficiente tiempo estable
  if ((millis() - tiempoUltimoRebote) > DEBOUNCE_MS) {
    if (lecturaBruta == LOW && estadoEstableBoton == HIGH) { // Flanco de bajada (botón presionado)
      if (temperaturaC >= limiteTemperatura) {
        alarmaSilenciada = true;
        Serial.println("Alarma silenciada por el usuario.");
      }
    }
    estadoEstableBoton = lecturaBruta;
  }
  estadoAnteriorBoton = lecturaBruta;
}

// Función: Lógica de actuadores según el umbral
void controlarAlarma() {
  if (temperaturaC >= limiteTemperatura) {
    if (!alarmaSilenciada) {
      // Parpadeo usando millis() para no usar delay() y trabar el botón
      if (millis() - tiempoAnteriorParpadeo >= 500) {
        tiempoAnteriorParpadeo = millis();
        estadoParpadeo = !estadoParpadeo; // Alterna el estado
        
        if (estadoParpadeo) {
          tone(pinBuzzer, 1000);
          setColor(HIGH, LOW, LOW);   // Rojo
        } else {
          noTone(pinBuzzer);
          // Apagar LED en Cátodo Común
          setColor(LOW, LOW, LOW); 
        }
      }
    } else {
      // Alarma silenciada
      noTone(pinBuzzer);
      setColor(HIGH, LOW, LOW);     // Rojo fijo
    }
  } else {
    // Sistema en estado normal
    setColor(LOW, HIGH, LOW);       // Verde
    noTone(pinBuzzer);
    alarmaSilenciada = false;       // Rearma la alarma automáticamente
  }
}

// Función: Establece el color del LED RGB (Cátodo Común)
// Se eliminaron las exclamaciones (!). La lógica ahora es directa.
void setColor(int rojo, int verde, int azul) {
  digitalWrite(ledRojo,  rojo);
  digitalWrite(ledVerde, verde);
  digitalWrite(ledAzul,  azul);
}
