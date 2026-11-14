#include <float.h>
#include <stdio.h>
#include <string.h>

#include "simulador.h"
#include "validaciones.h"

int main(void)
{
    char opcion[10];
    double masa;
    double velocidad;
    double energiaCinetica;
    double distanciaKm;
    double tiempoSegundos;

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
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");

        if (fgets(opcion, sizeof(opcion), stdin) == NULL)
        {
            printf("\nNo se pudo leer la opcion.\n");
            return 1;
        }

        if (strcmp(opcion, "1\n") == 0 || strcmp(opcion, "1") == 0)
        {
            printf("\nLuego de la maniobra TLI, los motores se apagan y Orion\n");
            printf("continua su movimiento. Segun la primera ley de Newton,\n");
            printf("la nave mantendria su velocidad si no actuaran fuerzas\n");
            printf("sobre ella; la gravedad terrestre modifica su movimiento.\n");
        }
        else if (strcmp(opcion, "2\n") == 0 || strcmp(opcion, "2") == 0)
        {
            masa = leerNumeroPositivo("Ingrese la masa de Orion en kg: ");
            velocidad = leerNumeroPositivo("Ingrese la velocidad en m/s: ");
            energiaCinetica = calcularEnergiaCinetica(masa, velocidad);
            printf("\nEnergia cinetica calculada:\n");
            printf("K = 1/2 * %.1f kg * (%.1f m/s)^2\n", masa, velocidad);
            printf("K = %.2e joules\n", energiaCinetica);
        }
        else if (strcmp(opcion, "3\n") == 0 || strcmp(opcion, "3") == 0)
        {
            printf("\nLa Tierra tiene una masa mucho mayor que la Luna y, por eso,\n");
            printf("su atraccion gravitatoria es mas intensa. Alejarse de la\n");
            printf("Tierra requiere aportar energia para vencer esa atraccion.\n");
            printf("En el regreso, la gravedad terrestre ayuda a acelerar la\n");
            printf("nave. La trayectoria y las condiciones iniciales tambien\n");
            printf("influyen en el combustible necesario.\n");
        }
        else if (strcmp(opcion, "4\n") == 0 || strcmp(opcion, "4") == 0)
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
            }
        }
        else if (strcmp(opcion, "5\n") == 0 || strcmp(opcion, "5") == 0)
        {
            printf("\nDatos de referencia del escenario:\n");
            printf("Masa de Orion: 26000 kg\n");
            printf("Velocidad luego de la TLI: 10900 m/s\n");
            printf("Altitud de orbita baja: 192000 m\n");
            printf("Distancia media Tierra-Luna: 384000 km\n");
            printf("Estos valores pueden usarse como referencia en los calculos.\n");
        }
        else if (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0)
        {
            printf("Opcion no valida. Ingrese 1, 2, 3, 4, 5 o 0.\n");
        }
    } while (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0);

    printf("\nGracias por usar el simulador: acompanando a Orion en su viaje a la Luna.\n");
    printf("AED 2026, Comision C. Hasta la proxima!\n");

    return 0;
}