#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include "simulador.h"

double calcularEnergiaCinetica(double masa, double velocidad)
{
    return 0.5 * masa * velocidad * velocidad;
}

int calcularTrabajoPorMasa(double altitud, double distancia,
                           double velocidadInicial,
                           double *distanciaEquilibrio,
                           double *trabajoPorMasa)
{
    double radioInicial;
    double puntoEquilibrio;
    double potencialInicial;
    double potencialEquilibrio;
    double energiaCineticaInicial;
    double trabajoCalculado;

    if (distanciaEquilibrio == NULL || trabajoPorMasa == NULL ||
        !isfinite(altitud) || !isfinite(distancia) ||
        !isfinite(velocidadInicial) || altitud < 0.0 ||
        distancia <= 0.0 || velocidadInicial < 0.0)
    {
        return 0;
    }

    radioInicial = RADIO_TIERRA + altitud;
    puntoEquilibrio = distancia /
                      (1.0 + sqrt(MASA_LUNA / MASA_TIERRA));

    if (!isfinite(radioInicial) || !isfinite(puntoEquilibrio) ||
        radioInicial >= puntoEquilibrio || puntoEquilibrio >= distancia)
    {
        return 0;
    }

    potencialInicial = -G_UNIVERSAL * MASA_TIERRA / radioInicial
                       - G_UNIVERSAL * MASA_LUNA / (distancia - radioInicial);
    potencialEquilibrio = -G_UNIVERSAL * MASA_TIERRA / puntoEquilibrio
                          - G_UNIVERSAL * MASA_LUNA /
                                (distancia - puntoEquilibrio);
    energiaCineticaInicial = 0.5 * velocidadInicial * velocidadInicial;
    trabajoCalculado = potencialEquilibrio - potencialInicial
                       - energiaCineticaInicial;

    if (!isfinite(trabajoCalculado))
    {
        return 0;
    }

    *distanciaEquilibrio = puntoEquilibrio;
    *trabajoPorMasa = trabajoCalculado;
    return 1;
}

void inicializarReporte(Reporte *reporte)
{
    if (reporte != NULL)
    {
        reporte->cantidadEnergias = 0;
        reporte->cantidadTrabajos = 0;
        reporte->cantidadTiempos = 0;
    }
}

int registrarEnergia(Reporte *reporte, double masa, double velocidad,
                     double energia)
{
    RegistroEnergia *registro;

    if (reporte == NULL || reporte->cantidadEnergias >= MAX_REGISTROS)
    {
        return 0;
    }

    registro = &reporte->energias[reporte->cantidadEnergias];
    registro->masa = masa;
    registro->velocidad = velocidad;
    registro->energia = energia;
    reporte->cantidadEnergias++;
    return 1;
}

int registrarTrabajo(Reporte *reporte, double distanciaEquilibrio,
                     double trabajoPorMasa)
{
    RegistroTrabajo *registro;

    if (reporte == NULL || reporte->cantidadTrabajos >= MAX_REGISTROS)
    {
        return 0;
    }

    registro = &reporte->trabajos[reporte->cantidadTrabajos];
    registro->distanciaEquilibrio = distanciaEquilibrio;
    registro->trabajoPorMasa = trabajoPorMasa;
    reporte->cantidadTrabajos++;
    return 1;
}

int registrarTiempo(Reporte *reporte, double distanciaKm, double velocidad,
                    double tiempoSegundos)
{
    RegistroTiempo *registro;

    if (reporte == NULL || reporte->cantidadTiempos >= MAX_REGISTROS)
    {
        return 0;
    }

    registro = &reporte->tiempos[reporte->cantidadTiempos];
    registro->distanciaKm = distanciaKm;
    registro->velocidad = velocidad;
    registro->tiempoSegundos = tiempoSegundos;
    reporte->cantidadTiempos++;
    return 1;
}

void mostrarReporte(const Reporte *reporte)
{
    int i;

    if (reporte == NULL)
    {
        return;
    }

    printf("\n===== Reporte de esta sesion =====\n");
    printf("Calculos de energia cinetica: %d\n", reporte->cantidadEnergias);
    for (i = 0; i < reporte->cantidadEnergias; i++)
    {
        printf("%d) m = %.1f kg, v = %.1f m/s -> K = %.2e J\n",
               i + 1, reporte->energias[i].masa,
               reporte->energias[i].velocidad,
               reporte->energias[i].energia);
    }

    printf("Calculos de trabajo por unidad de masa: %d\n",
           reporte->cantidadTrabajos);
    for (i = 0; i < reporte->cantidadTrabajos; i++)
    {
        printf("%d) x = %.2f km -> Wext/m = %.2e J/kg\n",
               i + 1, reporte->trabajos[i].distanciaEquilibrio / 1000.0,
               reporte->trabajos[i].trabajoPorMasa);
    }

    printf("Estimaciones de tiempo de viaje: %d\n", reporte->cantidadTiempos);
    for (i = 0; i < reporte->cantidadTiempos; i++)
    {
        printf("%d) distancia = %.1f km, velocidad = %.1f m/s"
               " -> tiempo = %.0f s (%.2f h)\n",
               i + 1, reporte->tiempos[i].distanciaKm,
               reporte->tiempos[i].velocidad,
               reporte->tiempos[i].tiempoSegundos,
               reporte->tiempos[i].tiempoSegundos / 3600.0);
    }
}