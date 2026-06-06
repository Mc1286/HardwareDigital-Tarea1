# HardwareDigital-Tarea1
"Primer proyecto práctico para la asignatura ISF-215 Hardware Digital (UV). Sistema embebido basado en Arduino UNO que integra sensores analógicos y digitales con control de actuadores."

**Sistema de Monitoreo de Temperatura con Alarma**

Este repositorio contiene el código fuente y la documentación para la Tarea 1 de la asignatura ISF-215 Hardware Digital de la Universidad de Valparaíso.

Descripción del Proyecto

El sistema es un prototipo embebido basado en Arduino UNO diseñado para el monitoreo constante de la temperatura ambiental. Utiliza un sensor analógico (TMP36) para realizar las mediciones. Si la temperatura supera el umbral crítico de 31°C, el sistema activa una alarma audiovisual: un buzzer emite un tono de advertencia y un LED RGB parpadea en color rojo.

El sistema incluye una función de "reconocimiento de alarma": mediante un pulsador digital (con debouncing por software), el usuario puede silenciar el buzzer temporalmente mientras la temperatura siga alta, dejando el LED rojo fijo como indicador visual del peligro continuo. Una vez que la temperatura vuelve a niveles normales, el sistema se rearma automáticamente (LED verde).

Esquema de Conexiones

El circuito está montado sobre una placa de pruebas (protoboard) conectada al Arduino UNO con la siguiente distribución de pines:

Entradas:

Sensor de Temperatura (TMP36): Conectado al pin analógico A0.

Pulsador (Silenciador): Conectado al pin digital 3 (configurado como INPUT_PULLUP, conectado directamente a GND al presionarse).

Salidas:

Buzzer: Conectado al pin digital 8.

LED RGB (Ánodo Común): Canal Rojo al pin digital 6, Canal Verde al pin digital 5, y Canal Azul al pin digital 4.

(Nota: Puedes visualizar el diagrama físico en el archivo esquema.png adjunto en este repositorio).

Instrucciones de Compilación y Ejecución

Para compilar y cargar este código en una placa Arduino UNO física, sigue estos pasos:

Asegúrate de tener instalado el Arduino IDE.

Clona este repositorio en tu equipo local o descarga el archivo .ino.

Abre el archivo .ino con Arduino IDE.

En el menú superior, ve a Herramientas > Placa y selecciona Arduino Uno.

Ve a Herramientas > Puerto y selecciona el puerto COM correspondiente a tu Arduino.

Haz clic en el botón Verificar (icono de visto bueno) para compilar el código.

Haz clic en el botón Subir (icono de flecha hacia la derecha) para cargar el programa en la placa.

(Opcional) Abre el Monitor Serie (lupa en la esquina superior derecha) configurado a 9600 baudios para monitorear las lecturas de temperatura en tiempo real.
