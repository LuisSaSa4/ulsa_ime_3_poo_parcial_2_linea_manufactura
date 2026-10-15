# Documentación de la clase: Fresadora

> Copia este archivo como `docs/<Clase>.md` 

**Elaborada por:** Néstor Hiram López Valdovinos
<br>
**Matrícula:** 25218
**Bloque:** 5

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Representa una fresadora industrial. Su operación es ranurar o fresar la pieza; el tiempo de trabajo por pieza se configura al crear la máquina.

**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente es `HerramientaDeCorte`, que se desgasta con cada pieza fresada. Está incluida como atributo de la fresadora y se crea junto con ella; en este modelo no se administra como una herramienta independiente de la máquina.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

`tiempoPorPieza` guarda los segundos que tarda el fresado y el constructor rechaza valores menores o iguales a cero mediante `std::invalid_argument`. `herramienta` es el componente compuesto y recibe `vidaUtilHerramienta`; su constructor también rechaza una vida útil menor o igual a cero. La clase base almacena el identificador y el nombre; no se agrega validación para esos dos parámetros en esta clase.

**Métodos propios (los que la clase base no tiene):**

`fresar()` realiza la operación de fresado y devuelve si pudo procesar la pieza. `procesarOperacion()` sirve como punto de entrada para que la planta solicite el trabajo y delega en `fresar()`. En la implementación actual está declarado con `override`, pero `Maquina` no declara ese método; por eso esa declaración no compila hasta que el equipo acuerde cómo integrar esa interfaz.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

`mostrarEstado()` y `realizarMantenimiento()` redefinen métodos virtuales de `Maquina`. `mostrarEstado()` llama primero a `Maquina::mostrarEstado()` y después presenta el tiempo por pieza y el desgaste de la herramienta. `realizarMantenimiento()` restaura la herramienta y luego llama a `Maquina::realizarMantenimiento()` para quitar la falla y registrar un paro. Si la fresadora no está en falla, no realiza mantenimiento.

**¿Cómo modelaste el desgaste del componente y por qué así?**

Cada pieza procesada suma una unidad de desgaste a la herramienta. Al llegar al límite de vida útil, la pieza actual termina de procesarse y la fresadora registra la falla; no puede procesar la siguiente hasta recibir mantenimiento. El mantenimiento reinicia el desgaste a cero. Este modelo determinista permite anticipar cuándo se detiene la máquina.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Usa el estado general y los métodos heredados: `puedeProcesar()` para comprobar si está disponible; `registrarPieza()` y `agregarTiempo()` para actualizar la producción; `reportarFalla()` para registrar que la herramienta llegó a su límite; y `getNombre()` para mostrar mensajes. Agrega el tiempo por pieza, la herramienta compuesta y las operaciones de fresado, consulta de estado y mantenimiento específico.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[Inserta aquí tu diagrama]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Una decisión fue determinar cuándo registrar la falla: se registra después de que se completa la pieza que agota la herramienta. El mantenimiento de la fresadora se solicita aparte; el método de fresado no lo ejecuta automáticamente.

**Errores que encontraste y cómo los corregiste:**

Al revisar la integración se detectó que `Fresadora::procesarOperacion()` está marcado como `override`, aunque `Maquina` no declara un método virtual con ese nombre. La interfaz debe acordarse con el equipo antes de corregirla; este problema sigue pendiente y actualmente impide compilar el proyecto. No se encontró una imagen de diagrama en `docs/`, así que falta crearla en draw.io y enlazarla en la sección 3.
