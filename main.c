#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double leerNumeroPositivo(const char mensaje[])
{
    char entrada[100];
    char *fin;
    double valor;
    int caracter;

    while (1)
    {
        printf("%s", mensaje);
        hola
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("\nNo se pudo leer el dato.\n");
            exit(EXIT_FAILURE);
        }

        if (strchr(entrada, '\n') == NULL && !feof(stdin))
        {
            while ((caracter = getchar()) != '\n' && caracter != EOF)
            {
            }
            printf("La entrada es demasiado larga. Intente nuevamente.\n");
            continue;
        }

        errno = 0;
        valor = strtod(entrada, &fin);

        while (isspace((unsigned char)*fin))
        {
            fin++;
        }

        if (fin == entrada || *fin != '\0' || errno == ERANGE ||
            !(valor > 0.0) || valor > DBL_MAX)
        {
            printf("Ingrese un numero valido mayor que cero.\n");
            continue;
        }

        return valor;
    }
}

int main(void)
{
    char opcion[10];
    double masa;
    double velocidad;
    double energiaCinetica;

    do
    {
        printf("\nSimulador de Misiones Artemis - Escenario TLI\n");
        printf("1. Leer sobre la inercia de Orion\n");
        printf("2. Calcular energia cinetica inicial\n");
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
            energiaCinetica = 0.5 * masa * velocidad * velocidad;
            printf("\nEnergia cinetica calculada:\n");
            printf("K = 1/2 * %.1f kg * (%.1f m/s)^2\n", masa, velocidad);
            printf("K = %.2e joules\n", energiaCinetica);
        }
        else if (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0)
        {
            printf("Opcion no valida. Ingrese 1, 2 o 0.\n");
        }
    } while (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0);

    return 0;
}