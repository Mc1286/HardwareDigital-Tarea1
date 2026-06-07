HardwareDigital-Tarea1

"Primer proyecto práctico para la asignatura ISF-215 Hardware Digital (UV). Sistema embebido basado en Arduino UNO que integra sensores analógicos y digitales con control de actuadores."

Sistema de Monitoreo Ambiental para Servidores con Protocolo de Acuse de Recibo

Este repositorio contiene el código fuente y la documentación para la Tarea 1 de la asignatura ISF-215 Hardware Digital de la Universidad de Valparaíso.

Descripción del Proyecto y Caso de Uso
El sistema es un prototipo embebido basado en Arduino UNO diseñado para el monitoreo térmico continuo en cuartos de servidores (Data Centers) y racks de telecomunicaciones. Utiliza un sensor analógico (TMP36) para realizar mediciones constantes del entorno ambiental y proteger el hardware frente a fallas en los sistemas de climatización (HVAC).

Si la temperatura del aire supera el umbral crítico de riesgo de 31°C, el sistema determina que la refrigeración ha fallado y activa un protocolo de alerta de dos vías: un buzzer emite un tono de advertencia audible por sobre el ruido constante de los ventiladores de los racks, y un LED RGB parpadea en color rojo como baliza visual de emergencia.

Para evitar la fatiga auditiva de los administradores de TI sin comprometer la integridad de los equipos, el sistema incluye una función de "reconocimiento de alarma" (Acknowledge). Mediante un pulsador digital (implementado con debouncing por software), el administrador puede confirmar que está al tanto de la falla silenciando el buzzer temporalmente mientras gestiona el apagado seguro de los servidores o revisa el aire acondicionado. Sin embargo, el LED rojo se mantiene encendido de forma fija como indicador innegociable de que el peligro de sobrecalentamiento continúa. Una vez que el problema se resuelve y la temperatura ambiente vuelve a niveles operativos normales, el sistema se rearma automáticamente (LED verde).

Esquema de Conexiones
El circuito está montado sobre una placa de pruebas (protoboard) conectada al Arduino UNO con la siguiente distribución de pines:

Entradas:

Sensor de Temperatura (TMP36): Conectado al pin analógico A0.

Pulsador (Silenciador): Conectado al pin digital 3 (configurado como INPUT_PULLUP, conectado directamente a GND al presionarse).

Salidas:

Buzzer: Conectado al pin digital 8.

LED RGB (Cátodo Común): Canal Rojo al pin digital 6, Canal Verde al pin digital 4, y Canal Azul al pin digital 5.

(Nota: Puedes visualizar el diagrama físico en el archivo esquema.png adjunto en este repositorio).

Instrucciones de Compilación y Ejecución
Para compilar y cargar este código en una placa Arduino UNO física, sigue estos pasos:

Asegúrate de tener instalado el Arduino IDE.

Clona este repositorio en tu equipo local o descarga el archivo .ino.

Abre el archivo .ino con Arduino IDE.

En el menú superior, ve a Herramientas > Placa y selecciona Arduino Uno.

Ve a Herramientas > Puerto y selecciona el puerto COM correspondiente a tu placa.

Haz clic en el botón Verificar para compilar el código.

Haz clic en el botón Subir para cargar el programa en el microcontrolador.

(Opcional) Abre el Monitor Serie configurado a 9600 baudios para monitorear las lecturas de temperatura en tiempo real y probar la lógica de umbral.
