# Propuesta de mejora:Rechazo de piezas después de la Estación de inspección

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** Néstor Hiram López Valdovinos 

## 1. Impacto

**¿Es una mejora o una corrección?**

Es una corrección. La planta sí tiene una Estación de inspección, pero no hace nada útil con lo que mide.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

Al revisar nuestra solución me di cuenta de que la Estación de inspección solamente mide la pieza, pero ese resultado no cambia nada. Ni siquiera existe la pieza como objeto: solo llevamos un contador

**¿Qué mejora o qué corrige, y por qué vale la pena?**

Hace que la inspección sí cumpla su trabajo donde aprueba o rechaza cada pieza, el desgaste de los componentes ya no solo causa fallas, también afecta la calidad de lo que se fabrica.
## 2. Qué implica

**Clases nuevas:**

***Pieza:*** Representa cada pieza del lote como un objeto propio, para poder saber si salió bien o mal.

***EstadoPieza:*** Define los estados posibles de una pieza en proceso, aprobada o rechazada para que no tenga dos a la vez.

**Comportamiento nuevo en clases existentes:**

| Clase | Qué cambia |
|---|---|
| Maquina | procesar ahora recibe la pieza: procesar(Pieza&). Como esto toca Maquina.h, se documenta en el README con acuerdo del equipo. |
| Máquinas derivadas | Al procesar una pieza, le suman desviación según el desgaste de su componente: entre más piezas lleva desde su último mantenimiento, más error le agrega. Cuando recibe mantenimiento, ese conteo vuelve a cero. |
| EstacionInspeccion | Redefine procesar(Pieza&): usa la versión de la base, compara la desviación total de la pieza con su tolerancia y la aprueba o la rechaza. Cuenta las piezas aprobadas y rechazadas. |
| Planta | Crea cada pieza, la pasa por las estaciones y descarta las rechazadas. Lleva la cuenta de aprobadas y rechazadas. |
| Reporte del turno | Agrega piezas aprobadas, rechazadas y porcentaje de rechazo. |
<br>

**Interacciones nuevas entre objetos:**

[Inserta aquí tu respuesta]

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

[Inserta aquí tu respuesta]

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

[Inserta aquí tu diagrama]
