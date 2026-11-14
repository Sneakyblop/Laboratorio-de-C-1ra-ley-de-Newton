# Laboratorio-de-C-1ra-ley-de-Newton
Trabajo de C del grupo "Las Ingenieras", com C 2026

## Avance actual

El programa comienza con una bienvenida y presenta un menu para leer sobre la
inercia de Orion, calcular su energia cinetica y consultar una explicacion
cualitativa sobre el viaje Tierra-Luna. Tambien permite estimar un tiempo de
viaje a velocidad constante; esta aproximacion no considera la gravedad ni
representa la trayectoria real.

Para el calculo de energia, se ingresan la masa en kg y la velocidad en m/s.
Como referencia, se pueden usar los valores del escenario: 26000 kg y
10900 m/s.

El programa todavia no simula la trayectoria. La lectura y validacion de
numeros esta separada en `validaciones.c` y `validaciones.h`, y el calculo de
energia cinetica esta en `simulador.c` y `simulador.h`.

## Compilacion

Con GCC, desde la carpeta del proyecto:

```sh
gcc -std=c99 -Wall -Wextra -pedantic main.c validaciones.c simulador.c -o artemis
```
