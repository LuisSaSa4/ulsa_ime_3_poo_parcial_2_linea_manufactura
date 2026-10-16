# Documentación de la clase: Estacion_inspeccion

**Elaborada por:** Diego Jiménez Mena
**Matrícula:** 25128
**Bloque:** [Inserta aquí tu número de bloque]

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

EstacionDeInspeccion representa la estación de inspección de la línea. Su operación es medir la pieza (inspeccionar()). Cada pieza tarda tiempoPorPieza segundos, y la planta la ejecuta mediante procesarOperacion().


**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente es SensorInspeccion, el sensor con el que la estación mide las piezas. Es una composición 1 a 1: el sensor es atributo de la estación, se crea en su constructor y se destruye con ella. Solo se usa, se desgasta y se restaura dentro de una estación de inspección.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

tiempoPorPieza (int): debe ser mayor que 0. Si no, se usa un valor por omisión y se avisa.
sensor (SensorInspeccion): es el componente, creado con vidaUtilSensor.
En el sensor, vidaUtil (int) debe ser mayor que 0 al crearse y nunca baja de 0.
En el sensor, desgaste (double) se limita siempre al rango de 0.0 a 1.0.

**Métodos propios (los que la clase base no tiene):**

inspeccionar(): mide una pieza y devuelve false si el sensor está desgastado.
Del componente: registrarUso(), estaDesgastado(), restaurar(), getVidaUtil() y getDesgaste()

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

mostrarEstado() const override llama primero a Maquina::mostrarEstado() y después agrega el tiempo por pieza y los datos del sensor.
procesarOperacion() y realizarMantenimiento() también son override. Dentro de ellos uso los métodos protegidos de la base: registrarPieza(), agregarTiempo(), reportarFalla() y registrarMantenimiento().

**¿Cómo modelaste el desgaste del componente y por qué así?**

Cada medición llama a registrarUso(), que resta 1 a vidaUtil y actualiza desgaste, que va de 0.0 (nuevo) a 1.0 (agotado). Cuando vidaUtil llega a 0, estaDesgastado() es true. La estación falla en la misma pieza que agota el sensor. El mantenimiento llama a restaurar(), luego a registrarMantenimiento(), y no suma tiempo. Un contador entero es determinista, por lo que el reporte se puede calcular a mano: con límite L y N piezas hay ⌊N / L⌋ fallas.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Usa: el constructor con lista de inicialización, los métodos protegidos registrarPieza(), agregarTiempo(), reportarFalla() y registrarMantenimiento(), además de puedeProcesar() y mostrarEstado().
Agrega: el tiempo por pieza, el sensor con su desgaste, inspeccionar() y las versiones propias de procesarOperacion(), realizarMantenimiento() y mostrarEstado().

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[Inserta aquí tu diagrama]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

La forma de sincronizar la clase con las de demas clases para que no encuentren conflicto a la hora de ejecutarse 

**Errores que encontraste y cómo los corregiste:**

Diferencia de variavbles en el desgloce del codigo 