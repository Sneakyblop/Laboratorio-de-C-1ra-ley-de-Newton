#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones.h"

double leerNumeroPositivo(const char mensaje[])
{
    char entrada[100];
    char *fin;
    double valor;
    int caracter;

    while (1)
    {
        printf("%s", mensaje);

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

int leerEnteroEnRango(const char mensaje[], int minimo, int maximo)
{
    char entrada[100];
    char *fin;
    long valor;
    int caracter;

    while (1)
    {
        printf("%s", mensaje);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("\nNo se pudo leer la opcion.\n");
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
        valor = strtol(entrada, &fin, 10);

        while (isspace((unsigned char)*fin))
        {
            fin++;
        }

        if (fin == entrada || *fin != '\0' || errno == ERANGE)
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
            continue;
        }

        if (valor < minimo || valor > maximo)
        {
            printf("Opcion fuera de rango. Ingrese un valor entre %d y %d.\n",
                   minimo, maximo);
            continue;
        }

        return (int)valor;
    }
}