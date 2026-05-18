# Monitor de Pulsos con ESP32

## Descripción
Sistema de medición de frecuencia cardíaca en tiempo real utilizando un ESP32, un LED rojo y un fototransistor para detectar variaciones de flujo sanguíneo en el dedo.

---

## Objetivo
Desarrollar un monitor de ritmo cardíaco funcional, accesible y capaz de mostrar BPM en tiempo real mediante procesamiento de señal analógica.

---

## Tecnologías utilizadas
- ESP32
- Arduino IDE
- MCP6002
- Fototransistor
- Señal analógica
- Filtrado digital
- Fusion 360

---

## Funcionamiento del sistema

El sistema funciona mediante un LED rojo que ilumina el dedo del usuario y un fototransistor que detecta cambios en la intensidad de luz reflejada.

Cuando el corazón bombea sangre, el volumen sanguíneo en el dedo aumenta ligeramente, provocando cambios en la luz recibida por el fototransistor. Estos cambios son convertidos en una señal de voltaje que posteriormente es procesada por el ESP32.

---

## Desarrollo del hardware

### Primer prototipo

El primer prototipo fue construido utilizando:

- LED rojo
- Fotoresistencia
- Resistencias
- ESP32

Aunque se lograba detectar una señal en condiciones de oscuridad, el sistema presentaba problemas debido a:

- Alta sensibilidad a la luz ambiental
- Baja velocidad de lectura
- Detección duplicada de latidos

### Cambio a fototransistor

Después de analizar las limitaciones del sistema, la fotoresistencia fue reemplazada por un fototransistor, permitiendo:

- Lecturas más rápidas
- Mejor respuesta temporal
- Una señal más estable

### Amplificación de señal

La señal obtenida seguía siendo demasiado pequeña, por lo que se implementó un amplificador operacional.

Inicialmente se utilizó un LM358N, pero los resultados no fueron suficientemente limpios. Posteriormente se reemplazó por un MCP6002, obteniendo una señal considerablemente más estable y usable.

---

## Procesamiento de señal y lógica del código

La señal obtenida presenta una forma de onda donde cada latido genera un pico.

Para detectar correctamente cada latido se implementaron distintas etapas de procesamiento.

### Filtrado

Se aplicó filtrado digital para:

- Reducir ruido
- Suavizar la señal
- Eliminar variaciones pequeñas no deseadas

### Umbral dinámico

Se implementó un umbral dinámico que funciona como referencia para detectar cuándo ocurre un latido.

El umbral debía adaptarse constantemente debido a:

- Cambios de iluminación
- Presión del dedo
- Variaciones naturales de la señal

### Offset

Se agregó un parámetro de offset para ajustar qué tan alta debe ser la señal antes de considerarse un latido válido.

### Tiempo muerto

Para evitar detectar un mismo latido dos veces, se implementó un tiempo muerto de 400 ms después de cada detección.

Cálculo realizado:

- BPM máximo considerado: 150
- 150 / 60 = 2.5 latidos por segundo
- 1 / 2.5 = 0.4 segundos
- Tiempo muerto = 400 ms

Esto significa que el sistema ignora nuevas detecciones dentro de ese intervalo.

### Cálculo de BPM

El BPM se obtiene midiendo el tiempo entre picos consecutivos mediante la función `millis()` del ESP32.

Fórmula utilizada:

```text
BPM = 60000 / intervalo
```

Donde:

- `60000` representa los milisegundos de un minuto
- `intervalo` representa el tiempo entre latidos consecutivos

### Suavizado de BPM

Para evitar fluctuaciones bruscas:

- Se almacenan varios intervalos consecutivos
- Se calcula un promedio
- Posteriormente se aplica un filtro digital

Esto permitió obtener lecturas más similares a las de un oxímetro comercial.

---

## Diseño PCB y carcasa

El circuito fue diseñado en Fusion 360 para desarrollar una PCB (Printed Circuit Board) y una carcasa personalizada para el dispositivo.

---

## Retos y soluciones

| Problema | Solución |
|---|---|
| Ruido en la señal | Filtrado digital |
| Doble detección de latidos | Tiempo muerto |
| Señal débil | Amplificador MCP6002 |
| Variaciones por luz ambiente | Umbral dinámico |

---

## Resultados

Se logró desarrollar un prototipo funcional capaz de:

- Detectar pulsos en tiempo real
- Mostrar BPM mediante el monitor serial
- Funcionar incluso con luz ambiental normal

Las mediciones obtenidas presentaron resultados relativamente cercanos a los de un oxímetro comercial.

---

## Galería

- Fotos del prototipo
- PCB
- Diagramas del circuito

---

## Autor

Iker de la Parra
