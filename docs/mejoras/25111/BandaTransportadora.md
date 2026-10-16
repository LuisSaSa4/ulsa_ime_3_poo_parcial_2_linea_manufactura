 Documentación de la clase: [Banda Transportadora]

> 
**Elaborada por:** [Renata Lucía Farías Esquivel]
**Matrícula:** [25111]
**Bloque:** [3]

## 1. Propósitos

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Mi clase representa una banda transportadora, la cual se encarga de desplazar las piezas a las diferentes estaciones y maquinas que existen en una línea de producción. Es la máquina que garantiza el flujo continuo de las piezas.

**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente en el código es MotorBanda y, sin el no hay movimiento ni traslado de piezas. Por lo que es un miembro fundamental dentro de la clase, por eso la forma en la que se modelo este componente, ya que fuera de la banda este no tiene sentido. 

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

ATRIBUTO: tiempoPorPieza TIPO: int  VALIDACIÓN: Debe ser > 0. Se valida en el constructor lanzando std::invalid_argument si es <= 0. Representa los segundos que tarda la banda en trasladar una pieza
ATRIBUTO: Motor TIPO: MotorBanda VALIDACIÓN: Se inicializa en el constructor con vidaUtilMotor

**Métodos propios (los que la clase base no tiene):**
bool transportar(): realiza el traslado de una pieza. Verifica que la banda pueda procesar (puedeProcesar()), que el motor no esté desgastado, registra la pieza (registrarPieza()), acumula el tiempo (agregarTiempo()) y registra el uso del motor (motor.registrarUso()). Devuelve true si el traslado se completó.

BandaTransportadora(...): constructor propio que configura los parámetros de la banda y de su motor.

bool procesarOperacion() override: adapta la banda a la interfaz de Maquina, delegando a transportar().

void mostrarEstado() const override: imprime las estadísticas propias de la banda (tiempo por pieza, vida útil del motor, desgaste actual) además de las heredadas.

void realizarMantenimiento() override: atiende la falla restaurando el motor (motor.restaurar()) y luego llama a Maquina::realizarMantenimiento().

**Método de la base que redefines, y cómo reutilizas la versión de la base:**
edefino procesarOperacion(), mostrarEstado() y realizarMantenimiento() de la clase Maquina.

En procesarOperacion() no llamo a la versión de la base (no aplica directamente en C++ para un método virtual puro), sino que encargo a transportar(), que a su vez usa los métodos heredados puedeProcesar(), registrarPieza() y agregarTiempo(). Así reutilizo la lógica de la base.

En realizarMantenimiento() reutilizo la versión de la base llamando a Maquina::realizarMantenimiento(); al final, después de restaurar el motor. Así la falla se libera correctamente y el contador de mantenimientos de la base se actualiza.

**¿Cómo modelaste el desgaste del componente y por qué así?**

El motor se desgasta cada 50 piezas (vida útil = 50). Lo modelé con la clase MotorBanda, que lleva internamente:

vidaUtil: número de piezas que soporta antes de desgastarse (50).

desgaste: contador acumulado de usos.

estaDesgastado(): devuelve true cuando desgaste >= vidaUtil.

registrarUso(): incrementa el contador en cada traslado.

restaurar(): reinicia el contador a 0 tras el mantenimiento.

¿Por qué asi?
Permite que el mantenimiento correctivo sea 0 dentro de las 20 piezas de la simulación, pero deja el mecanismo listo por si se extiende el proceso.

Encapsula el desgaste en el componente (MotorBanda), no en la banda, lo cual es correcto porque el desgaste es una propiedad del motor, no del transportador.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

[¿Qué usa tu clase de Maquina y qué agrega?

Usa de Maquina:

El atributo id y nombre (heredados y pasados en el constructor).

Los métodos puedeProcesar(), registrarPieza(), agregarTiempo(), reportarFalla(), estaEnFalla(), getNombre().

La implementación base de mostrarEstado() y realizarMantenimiento() (reutilizadas explícitamente).

La interfaz virtual procesarOperacion() que se sobrescribe.

Agrega:

El atributo tiempoPorPieza (5 s en este proyecto).

El componente motor (composición con MotorBanda).

El método transportar(), que es la operación específica de la banda.

La lógica de desgaste del motor integrada al ciclo de traslado.

El reporte extendido en mostrarEstado() con datos del motor.]

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.


## 4. Bitácora

¿El desgaste del motor debía detener la máquina?
La tabla indica que el mantenimiento correctivo es 0 para la banda. Entendí que dentro de las 20 piezas de la simulación el motor no se desgasta (porque se desgasta cada 50), así que no hay paradas. Modelé el desgaste igual que en las otras máquinas para mantener consistencia, pero sé que no se activará en este escenario.



**Errores que encontraste y cómo los corregiste:**

Olvidé validar que tiempoPorPieza fuera positivo, y en una prueba puse -1 y la simulación daba tiempos negativos.
Corrección: Agregué la validación en el constructor con throw std::invalid_argument si tiempoPorPieza <= 0.

