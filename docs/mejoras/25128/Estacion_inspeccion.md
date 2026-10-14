# Documentación de la clase: [Estacion_inspeccion]

**Elaborada por:** [Diego Jiménez Mena]
**Matrícula:** [25128]
**Bloque:** [Inserta aquí tu número de bloque]

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

EstacionInspeccion representa la estación de inspección de la línea de manufactura. Su operación es medir la pieza: cuando la pieza llega a la estación, el sensor la mide y la estación registra que la procesó. Cada pieza tarda un tiempo propio de segundosPorPieza segundos, y la medición se hace con una tolerancia de toleranciaMm milímetros.

**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente es el Sensor. Lleva una calibración que se pierde con cada medición. Es una relación de composición: el sensor es un atributo (no un apuntador) de la estación, se crea en su constructor y se destruye junto con ella. Un sensor no tiene sentido por sí solo en la planta, porque solo se desgasta y se recalibra cuando la estación lo usa para medir piezas.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

[Inserta aquí tu respuesta]

**Métodos propios (los que la clase base no tiene):**

[Inserta aquí tu respuesta]

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

[Inserta aquí tu respuesta]

**¿Cómo modelaste el desgaste del componente y por qué así?**

[Inserta aquí tu respuesta]

**¿Qué usa tu clase de `Maquina` y qué agrega?**

[Inserta aquí tu respuesta]

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[Inserta aquí tu diagrama]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[Inserta aquí tu respuesta]

**Errores que encontraste y cómo los corregiste:**

[Inserta aquí tu respuesta]
