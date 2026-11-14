#include <float.h>
#include <stdio.h>

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

    inicializarReporte(&reporte);  
    printf("Bienvenido/a, somos el grupo \"Las Ingenieras\".\n");
    printf("En este programa vas a conocer el viaje de Orion hacia la Luna\n");
    printf("y explorar algunos conceptos del escenario de inyeccion translunar.\n");

    do
    {
        printf("\nSimulador de Misiones Artemis - Escenario TLI\n");
        printf("1. Leer sobre la inercia de Orion\n");
        printf("2. Calcular energia cinetica inicial\n");
        printf("3. Leer sobre el gasto de combustible\n");
        printf("4. Estimar tiempo de viaje a velocidad constante\n");
        printf("5. Ver datos de referencia de la mision\n");
        printf("6. Estimar trabajo externo hasta el punto de equilibrio\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        opcion = leerEnteroEnRango("Seleccione una opcion: ", 0, 6); 

        if (opcion == 1)
        {
            printf("\nLuego de la maniobra TLI, los motores se apagan y Orion\n");
            printf("continua su movimiento. Segun la primera ley de Newton,\n");
            printf("la nave mantendria su velocidad si no actuaran fuerzas\n");
            printf("sobre ella; la gravedad terrestre modifica su movimiento.\n");
        }
        else if (opcion == 2)       
        {
            masa = leerNumeroPositivo("Ingrese la masa de Orion en kg: ");
            velocidad = leerNumeroPositivo("Ingrese la velocidad en m/s: ");
            energiaCinetica = calcularEnergiaCinetica(masa, velocidad);
            printf("\nEnergia cinetica calculada:\n");
            printf("K = 1/2 * %.1f kg * (%.1f m/s)^2\n", masa, velocidad);
            printf("K = %.2e joules\n", energiaCinetica);
            if (!registrarEnergia(&reporte, masa, velocidad, energiaCinetica))
            {
                printf("El reporte esta lleno; este resultado no se guardara.\n");
            }
        }   
        else if (opcion == 3)
        {
            printf("\nLa Tierra tiene una masa mucho mayor que la Luna y, por eso,\n");
            printf("su atraccion gravitatoria es mas intensa. Alejarse de la\n");
            printf("Tierra requiere aportar energia para vencer esa atraccion.\n");
            printf("En el regreso, la gravedad terrestre ayuda a acelerar la\n");
            printf("nave. La trayectoria y las condiciones iniciales tambien\n");
            printf("influyen en el combustible necesario.\n");
        }
        else if (opcion == 4) 
        {
            printf("\nEstimacion idealizada: no considera la gravedad ni cambios\n");
            printf("de velocidad, por lo que no representa la trayectoria real.\n");
            distanciaKm = leerNumeroPositivo("Distancia en km: ");
            velocidad = leerNumeroPositivo("Velocidad constante en m/s: ");

            if (distanciaKm > DBL_MAX / 1000.0 ||
                velocidad < (distanciaKm * 1000.0) / DBL_MAX)
            {
                printf("Los valores ingresados son demasiado grandes para calcular.\n");
            }
            else
            {
                tiempoSegundos = (distanciaKm * 1000.0) / velocidad;
                printf("Tiempo estimado: %.0f segundos (%.2f horas).\n",
                       tiempoSegundos, tiempoSegundos / 3600.0);
                printf("Se uso la formula tiempo = distancia / velocidad.\n");
                if (!registrarTiempo(&reporte, distanciaKm, velocidad,
                                     tiempoSegundos))
                {
                    printf("El reporte esta lleno; este resultado no se guardara.\n");
                }
            }
        }
        else if (opcion == 5) 
        {
            printf("\nDatos de referencia del escenario:\n");
            printf("Masa de Orion: %.0f kg\n", MASA_ORION_KG); 
            printf("Velocidad luego de la TLI: %.0f m/s\n", VELOCIDAD_TLI_MS);
            printf("Altitud de orbita baja: %.0f m\n", ALTITUD_ORBITA_M);
            printf("Distancia media Tierra-Luna: %.0f km\n",
                   DISTANCIA_TIERRA_LUNA_M / 1000.0);
            printf("Estos valores pueden usarse como referencia en los calculos.\n");
        }
        else if (opcion == 6) 
        {
            printf("\nEstimacion con los datos de referencia de la mision.\n");
            printf("El punto se estima igualando la atraccion de la Tierra y la Luna.\n");
            printf("Se ignora la rotacion del sistema y se supone llegada en reposo.\n");

            if (calcularTrabajoPorMasa(ALTITUD_ORBITA_M,
                                       DISTANCIA_TIERRA_LUNA_M,
                                       VELOCIDAD_TLI_MS,
                                       &distanciaEquilibrio,
                                       &trabajoPorMasa))
            {
                printf("Punto de equilibrio estimado: %.2f km desde el centro terrestre.\n",
                       distanciaEquilibrio / 1000.0);
                printf("Trabajo externo por unidad de masa: %.2e J/kg\n",
                       trabajoPorMasa);
                printf("Se usa Wext/m = diferencia de energia potencial - K inicial/m.\n");
                if (!registrarTrabajo(&reporte, distanciaEquilibrio,
                                      trabajoPorMasa))
                {
                    printf("El reporte esta lleno; este resultado no se guardara.\n");
                }
            }
            else
            {
                printf("No se pudo calcular con estos datos del modelo.\n");
            }
        }
    } while (opcion != 0); 

    mostrarReporte(&reporte); 
    printf("\nGracias por usar el simulador: acompanando a Orion en su viaje a la Luna.\n");
    printf("AED 2026, Comision C. Hasta la proxima!\n");

    return 0;
}