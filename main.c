#include <math.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "simulador.h"
#include "validaciones.h"

int main(void)
{
    int opcion;
    double masa;
    double velocidad;
    double energiaCinetica;
    double distanciaKm;
    double tiempoSegundos;
    double distanciaEquilibrio;
    double trabajoPorMasa;
    Reporte reporte;

#ifdef _WIN32
    if (!SetConsoleOutputCP(CP_UTF8) || !SetConsoleCP(CP_UTF8))
    {
        fprintf(stderr, "Aviso: no se pudo configurar la consola en UTF-8.\n");
    }
#endif

    inicializarReporte(&reporte);
    printf("Bienvenido/a, somos el grupo \"Las Ingenieras\".\n");
    printf("En este programa vas a conocer el viaje de Orion hacia la Luna\n");
    printf("y explorar algunos conceptos del escenario de inyección translunar.\n");

    do
    {
        printf("\nSimulador de Misiones Artemis - Escenario TLI\n");
        printf("1. Leer sobre la inercia de Orion\n");
        printf("2. Calcular energía cinética inicial\n");
        printf("3. Leer sobre el viaje Tierra-Luna\n");
        printf("4. Estimar tiempo de viaje a velocidad constante\n");
        printf("5. Ver datos de referencia de la misión\n");
        printf("6. Estimar trabajo externo hasta el punto de igualdad gravitatoria\n");
        printf("0. Salir\n");
        opcion = leerEnteroEnRango("Seleccioná una opción: ", 0, 6);

        switch (opcion)
        {
        case 1:
            mostrarInercia();
            break;
        case 2:
            masa = leerNumeroPositivo("Ingresá la masa de Orion en kg: ");
            velocidad = leerNumeroPositivo("Ingresá la velocidad en m/s: ");
            energiaCinetica = calcularEnergiaCinetica(masa, velocidad);

            if (!isfinite(energiaCinetica))
            {
                printf("No se pudo calcular: el resultado es demasiado grande.\n");
                break;
            }

            if (masa != MASA_ORION_KG || velocidad != VELOCIDAD_TLI_MS)
            {
                printf("\nAviso: estos valores no coinciden con los datos de Orion\n");
                printf("(%.0f kg y %.0f m/s). El resultado corresponde a los\n",
                       MASA_ORION_KG, VELOCIDAD_TLI_MS);
                printf("valores que ingresaste, no al caso de referencia.\n");
            }

            printf("\nEnergía cinética calculada:\n");
            printf("K = 1/2 * %.1f kg * (%.1f m/s)^2\n", masa, velocidad);
            printf("K = %.2e J\n", energiaCinetica);
            if (!registrarEnergia(&reporte, masa, velocidad, energiaCinetica))
            {
                printf("El reporte está lleno; este resultado no se guardará.\n");
            }
            break;
        case 3:
            mostrarJustificacionEnergetica();
            break;
        case 4:
            printf("\nEstimación idealizada: no considera la gravedad ni los\n");
            printf("cambios de velocidad de una trayectoria real.\n");
            distanciaKm = leerNumeroPositivo("Ingresá la distancia en km: ");
            velocidad = leerNumeroPositivo("Ingresá la velocidad constante en m/s: ");

            if (!calcularTiempoViaje(distanciaKm, velocidad, &tiempoSegundos))
            {
                printf("No se pudo calcular: los valores son demasiado grandes.\n");
                break;
            }

            printf("Tiempo estimado: %.0f segundos (%.2f horas).\n",
                   tiempoSegundos, tiempoSegundos / 3600.0);
            printf("Se usó la fórmula tiempo = distancia / velocidad.\n");
            if (!registrarTiempo(&reporte, distanciaKm, velocidad,
                                 tiempoSegundos))
            {
                printf("El reporte está lleno; este resultado no se guardará.\n");
            }
            break;
        case 5:
            mostrarDatosMision();
            break;
        case 6:
            printf("\nEstimación con los datos de referencia de la misión.\n");
            printf("Se igualan las atracciones gravitatorias y se supone llegada\n");
            printf("en reposo. El modelo no considera la rotación del sistema.\n");

            if (!calcularTrabajoPorMasa(ALTITUD_ORBITA_M,
                                        DISTANCIA_TIERRA_LUNA_M,
                                        VELOCIDAD_TLI_MS,
                                        &distanciaEquilibrio,
                                        &trabajoPorMasa))
            {
                printf("No se pudo calcular con los datos de este modelo.\n");
                break;
            }

            printf("Punto estimado: %.2f km desde el centro de la Tierra.\n",
                   distanciaEquilibrio / 1000.0);
            printf("Trabajo externo neto por unidad de masa: %.2e J/kg\n",
                   trabajoPorMasa);
            printf("Wext/m = cambio de energía potencial - K inicial/m.\n");
            if (!registrarTrabajo(&reporte, distanciaEquilibrio,
                                  trabajoPorMasa))
            {
                printf("El reporte está lleno; este resultado no se guardará.\n");
            }
            break;
        }
    } while (opcion != 0);

    mostrarReporte(&reporte);
    printf("\nGracias por usar el simulador: siguiendo el viaje de Orion hacia la Luna.\n");
    printf("AED 2026, Comisión C. ¡Hasta la próxima!\n");

    return 0;
}