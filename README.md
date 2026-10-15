# Simulador de una Planta de Manufactura Automatizada

Proyecto del Parcial 2 de Programación Orientada a Objetos.

## 1. Equipo

| Bloque | Matrícula | Nombre | Usuario de GitHub | Máquina | Componente |
| --- | --- | --- | --- | --- | --- |
| 1 | | | | | |
| 2 | | | | | |
| 3 | | | | | |
| 4 | | | | | |
| 5 |25218 |Néstor Hiram López Valdovinos |nestor-lopez-07 |Fresadora |Herramienta de corte |
| 6 | | | | | |

## 2. Orden de la línea
1. Torno CNC
2. Fresadora
3. Robot soldador
4. Banda transportadora
5. Estación de inspección

## 3. Cómo compilar y ejecutar

Desde la carpeta raíz del proyecto, en una terminal con `g++` disponible:

**Compilar:**

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o planta
```

**Ejecutar:**

```bash
./planta
```

## 4. Reglas de la simulación

**¿En qué momento exacto falla una máquina?**

La falla se registra al terminar de procesar la pieza que agota la vida útil del componente. Esa pieza cuenta como procesada; la máquina queda en falla y necesita mantenimiento antes de procesar la siguiente. En el robot soldador, el código realiza el mantenimiento inmediatamente después de detectar la falla.

**¿El mantenimiento suma tiempo al turno? ¿Cuánto?**

No. El mantenimiento no agrega segundos al tiempo trabajado; se registra como un paro de la máquina.

## 5. Cálculo a mano del reporte

Lote de 20 piezas. Una fila por máquina.

| Máquina | Segundos por pieza | Límite del componente | Fallas en 20 piezas | Tiempo trabajado |
| --- | --- | --- | --- | --- |
| Torno CNC | 30 | Husillo: 8 piezas | 2 (después de las piezas 8 y 16) | 20 × 30 = 600 s |
| Fresadora | 45 | Herramienta de corte: 25 piezas | 0 | 20 × 45 = 900 s |
| Robot soldador | 20 | Antorcha: 12 piezas | 1 (después de la pieza 12) | 20 × 20 = 400 s |
| Banda transportadora | 5 | Motor: 50 piezas | 0 | 20 × 5 = 100 s |
| Estación de inspección | 10 | Sensor: 30 piezas | 0 | 20 × 10 = 200 s |

**Reporte esperado (piezas terminadas, tiempo total y paros):**

20 piezas terminadas, 2200 s de trabajo y 3 paros por mantenimiento: 2 del torno CNC y 1 del robot soldador. Después del mantenimiento, todas las máquinas terminan el lote sin falla.

**¿Coincide con lo que imprime el programa? Si no coincidió al primer intento, ¿qué encontraron?**

Todavía no se puede comparar con la ejecución: `src/main.cpp` contiene únicamente el esqueleto de los pasos y el repositorio aún no implementa la clase `Planta` ni el escenario del lote. Al completar la integración con los valores de esta tabla, el reporte deberá coincidir con el cálculo esperado.

## 6. Diagrama general

Diagrama de clases de la solución completa, hecho en draw.io. Guarden la imagen como `docs/diagrama_general.png`.

![Diagrama general](docs/diagrama_general.png)

## 7. Documentación individual

| Integrante | Documentación de su clase | Propuesta de mejora |
| --- | --- | --- |
| Néstor Hiram López Valdovinos | `docs/mejoras/25218/Fresadora.md` | `docs/mejoras/25218/Mejora.md` |
| | | |
| | | |
| | | |
| | | |

## 8. Cambios a `Maquina.h`

Si el equipo modificó la interfaz de la clase base, expliquen qué cambió y por qué. Si no hubo cambios, escriban "Sin cambios".

Sin cambios.
