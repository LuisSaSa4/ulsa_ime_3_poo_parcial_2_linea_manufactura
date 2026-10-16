# Documentación de la clase: RobotSoldador

> Copia este archivo como `docs/<Clase>.md` (por ejemplo, con el nombre de tu máquina) y llena tu copia. No modifiques la plantilla.

**Elaborada por:** Luis Samano Saavedra

**Matrícula:** 24090

**Bloque:** 1

<br>

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

La clase RobotSoldador representa a el robot encargado de hacer las operaciones de soldadura dentro de la planta de manufactura automatizada. Su función es soldar las piezas que pasan por la línea de producción. Para realizar esta operación, verifica que la máquina pueda trabajar, utiliza la antorcha y registra el tiempo de procesamiento de cada pieza.

<br>

**¿Cuál es su componente y por qué no existe sin la máquina?**

El componente de RobotSoldador es la clase Antorcha, este componente representa la herramienta utilizada para realizar la soldadura a las piezas. 

Se creo este componente usando composición porque el robot soldador tiene un objeto llamado Antorcha como parte de su estructura y lo utiliza directamente en sus operaciones de soldadura. En el diseño con el que se trabajo la antorcha forma parte del robot soldador y no se administra como una máquina independiente de la planta.

<br>

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

1.- tiempoPorPieza: Este atributo almacena el tiempo en segundos del proceso de soldadura de cada una de las piezas. Se debe validar que sea mayor que cero para evitar tiempos de procesamiento inválidos.

2.- antorcha: objeto de la clase Antorcha que controla la vida útil y el desgaste del componente utilizado para soldar.

La clase Antorcha cuenta tambien con sus propios atributos:

1.- vidaUtil: Este metodo representa el límite de uso permitido para la antorcha. Su valor inicial debe ser mayor que cero.

2.- desgaste: Este metodo egistra el uso acumulado de la antorcha. Comienza en cero y aumenta cuando se utiliza el componente.

<br>

**Métodos propios (los que la clase base no tiene):**

1.- soldar(): realiza la operación específica de soldadura, comprueba si el robot puede trabajar y utiliza la antorcha.

2.- procesarOperacion(): implementa la operación que la planta solicita al robot soldador para procesar una pieza.

Además, la clase Antorcha proporciona los métodos registrarUso(), estaDesgastado() y restaurar(), que permiten registrar el uso, comprobar si se alcanzó el límite de desgaste y restablecer el componente después del mantenimiento.

<br>


**Método de la base que redefines, y cómo reutilizas la versión de la base:**

La clase RobotSoldador redefine los métodos virtuales mostrarEstado() y realizarMantenimiento() de la clase base Maquina.

En mostrarEstado(), se puede llamar a Maquina::mostrarEstado() para mostrar primero la información general de la máquina y después agregar los datos específicos del robot soldador y su antorcha.

En realizarMantenimiento(), se puede llamar a Maquina::realizarMantenimiento() para reutilizar el comportamiento general de mantenimiento y después restaurar la antorcha mediante antorcha.restaurar() cuando corresponda.

<br>

**¿Cómo modelaste el desgaste del componente y por qué así?**

El desgaste se modeló en la clase Antorcha mediante el atributo desgaste, de tipo double, y el atributo vidaUtil, de tipo int. Cada vez que la antorcha se utiliza, el método registrarUso() incrementa el desgaste. El método estaDesgastado() permite comprobar si se alcanzó el límite establecido, mientras que restaurar() reinicia el desgaste a cero.

Se eligió este diseño para separar el control del desgaste de la lógica de soldadura. De esta manera, RobotSoldador se encarga de realizar la operación y Antorcha administra su vida útil.

<br>

**¿Qué usa tu clase de `Maquina` y qué agrega?**

RobotSoldador hereda de Maquina los atributos y métodos generales necesarios para controlar el estado de la máquina, su encendido, las fallas, las piezas procesadas, el tiempo trabajado y los paros.

Además, agrega el atributo tiempoPorPieza, el objeto antorcha y los métodos específicos para soldar y procesar operaciones. También redefine los métodos virtuales necesarios para mostrar su estado particular y realizar el mantenimiento de su componente.

<br>

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

![Diagrama del Robot Soldador](DIagramaRobotSoldador.png)

<br>

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Una de las dudas que tuve fue cómo lograr que el robot soldador identificara cuándo la antorcha ya no podía seguir utilizándose. Para resolverlo, se utilizó el método estaDesgastado() de la clase Antorcha, que permite comprobar si el componente alcanzó su límite de uso.

También tuve dudas sobre cómo realizar el mantenimiento sin mezclar las responsabilidades de ambas clases. Lo resolví haciendo que RobotSoldador se encargue del proceso de soldadura y del mantenimiento, mientras que Antorcha se encarga de controlar su desgaste y restaurarlo.

**Errores que encontraste y cómo los corregiste:**


Durante el desarrollo, fue necesario revisar que los métodos declarados en los archivos .h coincidieran con sus implementaciones en los archivos .cpp. Para corregir posibles problemas, revisé los nombres, los parámetros y los tipos de retorno de cada método, también revisé que el mantenimiento restaurara correctamente la antorcha y que el robot pudiera continuar procesando piezas después de atender una falla.