# Monitor de Pulso Cardíaco

## Descripción del proyecto

Este proyecto nació con el objetivo de desarrollar un monitor de pulso cardíaco desde cero, diseñando tanto la electrónica como el software necesario para adquirir y procesar la señal. Durante el desarrollo fabriqué diferentes prototipos, diseñé mis propias PCB y realicé varias iteraciones hasta obtener un sistema funcional capaz de medir la frecuencia cardíaca de manera confiable.

Más que un proyecto de electrónica, este trabajo representó un proceso completo de diseño, prueba, análisis de errores y mejora continua.

---

## Desarrollo del proyecto

### Versión 1.0 – Primer prototipo

La primera versión fue una prueba de concepto construida utilizando un LED y una fotoresistencia para detectar las variaciones de luz causadas por el flujo sanguíneo en el dedo.

Aunque la idea parecía viable, esta versión no funcionó como esperaba. Durante las pruebas encontré que la señal obtenida tenía una gran cantidad de ruido, lo que dificultaba distinguir claramente los latidos cardíacos. Además, la fotoresistencia no era lo suficientemente rápida (trbaja a 10 milisegundos para ser exactos) para responder a los cambios de intensidad luminosa que requería la aplicación.

A pesar de no obtener resultados satisfactorios, esta etapa fue fundamental para comprender las limitaciones del diseño y definir una mejor estrategia para la siguiente versión.

### Versión 2.0 – Rediseño del sistema

Gracias a los conocimientos cde la versión 1, realicé ajustes en el circuito para adaptarlo a una configuración más eficiente orientada a obtener las señales biomédicas.

En esta versión, llevé a cabo además el diseño y la fabricación de la primera placa de circuito impreso (PCB) para el proyecto. Sin embargo, al momento de ensamblar y testear los componentes, surgieron diversas complicaciones que comprometieron el desempeño del sistema. Tales dificultades se debieron, en parte, a errores míos en el trazado de las conexiones durante la elaboración del esquema, aunado a criterios de diseño que resultaron en una gestión poco óptima de la superficie de la placa.

Aunque esta versión supuso un avance considerable frente a la anterior, los fallos detectados me pusieron en la necesidad de someter el diseño a una revisión exhaustiva para poder encontrar mis errores y corregirlos en la siguiente versión.

### Versión 3.0 – Diseño funcional final

La versión 3.0 fue el resultado de todas las lecciones aprendidas durante el desarrollo del proyecto.

En esta etapa corregí los errores eléctricos encontrados en la versión anterior, optimicé la distribución de componentes y rediseñé la PCB para aprovechar mejor el espacio disponible. Esto permitió reducir significativamente el tamaño de la tarjeta y obtener un diseño más limpio y profesional.

El resultado fue un monitor de pulso cardíaco completamente funcional, capaz de medir la frecuencia cardíaca de forma estable y consistente. Para validar su desempeño, comparé las mediciones obtenidas con las de un oxímetro comercial, observando resultados muy similares en la función de monitoreo del ritmo cardíaco.

### Versión 3.1 - Ajustes de LED y Fototransistor

Para esta versión el cambio que se realizó fue que se dezplazó tanto el LED como el fotoransistor un poco más apartados del microcontrolador con el fin de poder diseñar el encapsulado donde se colocará el dedo y de esta forma el fototransistor pueda obtener una lectura correcta en el centro del dedo de la persona que este usando el dispositivo.

---

## Resultados obtenidos

Al finalizar el proyecto logré desarrollar un sistema funcional que pasó de una idea inicial con múltiples limitaciones a un dispositivo capaz de medir el pulso cardíaco de manera confiable.

Además del resultado final, este proyecto me permitió fortalecer habilidades en:

- Diseño y análisis de circuitos electrónicos.
- Acondicionamiento y procesamiento de señales.
- Diseño, fabricación y depuración de PCB.
- Programación de sistemas embebidos.
- Resolución de problemas mediante iteraciones de ingeniería.

Uno de los aspectos más valiosos de este desarrollo fue experimentar de primera mano cómo los errores encontrados en cada versión se transformaron en mejoras para la siguiente, hasta llegar a una solución funcional y validada.

---

## Tecnologías utilizadas

- ESP32
- Diseño de PCB
- Electrónica analógica
- Procesamiento de señales
- Sistemas embebidos

---

## Futuras Mejoras

Como siguiente etapa del proyecto, planeo incorporar conectividad Wi-Fi utilizando el ESP32 para transmitir los datos en tiempo real y visualizarlos ya sea en un teléfono, tablet o hasta en una computadora. Mi objetivo es desarrollar una interfaz tipo HMI que permita visualizar las mediciones de manera remota, facilitando el monitoreo y análisis de la información obtenida por el dispositivo.

Gracias a este proyecto pude ver como puedo pasar de una idea, a un prototipo y seguir mejorandola hasta llegar a resultados buenos donde pueda seguir expandiendo tantos mis conocimiento e ir creando metas con más enfoque y dificultad para lograr cosas asombrosas.
