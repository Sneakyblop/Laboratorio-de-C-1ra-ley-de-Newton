# Laboratorio-de-C-1ra-ley-de-Newton
Trabajo de C del grupo "Las Ingenieras", com C 2026

## Avance actual

El programa  presenta un menu para leer sobre la
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

La opcion 6 estima el trabajo externo por unidad de masa hasta un punto donde
se igualan las atracciones gravitatorias de la Tierra y la Luna. Usa los datos
de referencia, supone que Orion llega en reposo y no considera la rotacion del
sistema. Es una aproximacion para el ejercicio, no una simulacion de la
trayectoria real.

Para compilar con GCC:

```sh
gcc -std=c99 -Wall -Wextra -pedantic main.c validaciones.c simulador.c -lm -o artemis
```

Al salir, se muestra un reporte de los calculos de energia cinetica, trabajo
y tiempo de viaje realizados durante la sesion. Se guardan hasta 50
resultados de cada tipo.