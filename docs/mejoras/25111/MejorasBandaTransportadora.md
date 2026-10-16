# Propuesta de mejora: Evitar la doble verificación del motor y unificar mensajes de la banda



**Propuesta de mejora elaborada por:** Renata Lucía Farías Esquivel

## 1. Impacto

**¿Es una mejora o una corrección?**

[Es una mejora de diseño mas que nada, pero también una corrección por que evita la redundancia.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

Dos cosas concretas:
 En BandaTransportadora::transportar(), si el motor solo se desgasta al usarse (motor.registrarUso()), entonces la primera revisión nunca va a ser verdadera cuando la banda está recién construida. Solo sirve si el motor ya venía desgastado de antes, y en el primer caso no se habia registrado uso previamente.
 Los mensajes están escritos a mano uno por uno con std::cout, y son distintos entre sí (unos dicen "Banda transportadora", otros "La banda", otros "Revisando el motor de la banda"...). Eso hace difícil cambiar el formato después.


**¿Qué mejora o qué corrige, y por qué vale la pena?**

-Elimina la verificación doble que no tenía razon de ser y deja una sola revisión, al final del transporte, justo después de motor.registrarUso(), que es cuando el motor realmente cambia. El código queda más corto y fácil de leer.
-Unifica los mensajes con un pequeño método privado imprimirMensaje(...) para que todos digan [Banda <nombre>]. Así, si alguna vez quieres cambiar el formato, lo haces en un solo lugar.

## 2. Qué implica

**Clases nuevas:**

Ninguna

**Comportamiento nuevo en clases existentes:**

BandaTransportadora:

-Se elimina el primer if (motor.estaDesgastado()) de transportar().
-Se deja solo la verificación al final, después de motor.registrarUso().

**Interacciones nuevas entre objetos:**
Ninguna interacción nueva entre objetos. Es una reorganización interna de la clase. 
La forma en que Planta usa a BandaTransportadora no cambia.


**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

BandaTransportadora hereda de Maquina (herencia).

BandaTransportadora tiene un Motor (composición).

Planta tiene BandaTransportadora (composición).

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

