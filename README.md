HardwareDigital-Tarea1
"Primer proyecto práctico para la asignatura ISF-215 Hardware Digital (UV). Sistema embebido basado en Arduino UNO que integra sensores analógicos y digitales con control de actuadores."

Sistema de Monitoreo Térmico Agroindustrial con Protocolo de Acuse de Recibo

Este repositorio contiene el código fuente y la documentación para la Tarea 1 de la asignatura ISF-215 Hardware Digital de la Universidad de Valparaíso.

Descripción del Proyecto y Caso de Uso
El sistema es un prototipo embebido basado en Arduino UNO diseñado para el monitoreo de la cadena de frío y ambientes de temperatura controlada (ej. cámaras frigoríficas en plantas de procesamiento agrícola). Utiliza un sensor analógico (TMP36) para realizar mediciones constantes del entorno.

Si la temperatura supera el umbral crítico de riesgo (31°C), el sistema activa un protocolo de alerta de dos vías: un buzzer emite un tono de advertencia audible sobre el ruido de la maquinaria, y un LED RGB parpadea en color rojo como baliza visual.

Para evitar la fatiga auditiva de los operarios sin comprometer la seguridad industrial, el sistema incluye una función de "reconocimiento de alarma" (Acknowledge). Mediante un pulsador digital (implementado con debouncing por software), el operario puede confirmar que está al tanto de la falla silenciando el buzzer temporalmente. Sin embargo, el LED rojo se mantiene encendido de forma fija como indicador innegociable de que el peligro térmico continúa. Una vez que el problema se resuelve y la temperatura vuelve a niveles operativos normales, el sistema se rearma automáticamente (LED verde).

Esquema de Conexiones
El circuito está montado sobre una placa de pruebas (protoboard) conectada al Arduino UNO con la siguiente distribución de pines:

Entradas:

Sensor de Temperatura (TMP36): Conectado al pin analógico A0.

Pulsador (Silenciador): Conectado al pin digital 3 (configurado como INPUT_PULLUP, conectado directamente a GND al presionarse).

Salidas:

Buzzer: Conectado al pin digital 8.

LED RGB (Cátodo Común): Canal Rojo al pin digital 6, Canal Verde al pin digital 5, y Canal Azul al pin digital 4.

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
