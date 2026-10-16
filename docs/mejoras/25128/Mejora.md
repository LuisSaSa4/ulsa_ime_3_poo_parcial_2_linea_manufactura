# Propuesta de mejora: Bitácora de paros del turno

**Propuesta de mejora elaborada por:** Diego Jiménez Mena

## 1. Impacto

**¿Es una mejora o una corrección?**

Es una mejora: la planta hoy no registra el historial de los paros. Solo lleva un contador de paros por máquina.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

El reporte del turno solo dice cuántos paros tuvo cada máquina (por ejemplo, "Torno CNC ... 2 paros"). Cuando el equipo hace su cálculo a mano, en cambio, predice cuándo y por qué falla cada máquina (por ejemplo, "2 fallas, después de las piezas 8 y 16"). El programa no deja evidencia de eso: solo se puede comparar el total, y si el reporte no coincide con el cálculo, no hay forma de saber en qué pieza falló cada máquina ni qué componente causó la falla. Además, el contador de Maquina pierde la información de cada falla: guarda cuántos paros hubo, pero no su contexto.

**¿Qué mejora o qué corrige, y por qué vale la pena?**

Agrega una bitácora de paros al turno: cada vez que una máquina falla y se le da mantenimiento, la planta registra un evento con la máquina, el número de pieza en que ocurrió y la descripción de la falla (por ejemplo, "sensor descalibrado"). El reporte del turno imprime esa bitácora después del resumen.

Vale la pena porque:

Permite comprobar el cálculo a mano pieza por pieza, no solo el total de paros (que es parte de los criterios de aceptación del proyecto).
Facilita depurar cuando el reporte no coincide con lo esperado, porque se ve exactamente dónde falló cada máquina.
Le da a la planta información útil para el mantenimiento: qué componente falla más y en qué momento del lote.

## 2. Qué implica

**Clases nuevas:**

EventoParo: representa un paro individual. Guarda idMaquina, nombreMaquina (copia del nombre), numeroPieza (pieza del lote en la que se detectó la falla) y descripcionFalla. Sus atributos son privados, con validación (numeroPieza mayor que 0, descripción no vacía) y accesores de solo lectura.
BitacoraTurno: guarda los EventoParo del turno. Métodos: registrar(...), getTotalEventos(), getEvento(indice), contarPorMaquina(id) y mostrar() const.

**Comportamiento nuevo en clases existentes:**

Maquina (clase base): un método virtual nuevo, virtual std::string descripcionFalla() const, con una versión por omisión ("falla no especificada"). Es un cambio a Maquina.h, así que se acuerda con el equipo y se documenta en el README.
Cada máquina derivada (por ejemplo EstacionDeInspeccion) redefine descripcionFalla() para describir la falla de su componente, por ejemplo "sensor descalibrado". Esto aprovecha el polimorfismo: la planta no necesita saber de qué tipo es cada máquina.
Planta: tiene un atributo BitacoraTurno. Al procesar el lote, cuando detecta una falla, antes de dar mantenimiento pide descripcionFalla() a la máquina y registra el evento en la bitácora. generarReporte() agrega al final la bitácora completa.

**Interacciones nuevas entre objetos:**

Planta le pregunta a la Maquina (por apuntador a la base) si está en falla y le pide su descripcionFalla().
Planta crea el evento con el número de pieza actual y se lo entrega a BitacoraTurno.registrar(...).
Planta realiza el mantenimiento de la máquina como hasta ahora.
Al terminar, Planta.generarReporte() pide a BitacoraTurno que se muestre, y main no cambia su escenario.

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

Composición Planta ◆── BitacoraTurno (1 a 1): la bitácora registra los paros del turno de esa planta; no tiene sentido sin ella y se crea y destruye con ella.
Composición BitacoraTurno ◆── EventoParo (1 a muchos): los eventos los crea y administra la propia bitácora; un evento no existe fuera de ella. Guarda una copia del nombre de la máquina, no un apuntador, para no depender del tiempo de vida de la máquina.
Herencia / redefinición (ya existente, comportamiento nuevo): cada máquina derivada redefine descripcionFalla() de Maquina.
La relación existente Planta ◇── Maquina (agregación) no cambia: las máquinas se siguen creando en main.

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

Existente (un color): Maquina, las máquinas derivadas (puedes dibujar solo EstacionDeInspeccion y las demás como una caja resumida), Planta y la agregación Planta ◇── Maquina.

Nuevo (otro color): BitacoraTurno, EventoParo, la composición Planta ◆── BitacoraTurno, la composición BitacoraTurno ◆── EventoParo (1 a *) y el método +descripcionFalla() const: string en Maquina y en las derivadas.