#include <math.h>
#include <stddef.h>

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