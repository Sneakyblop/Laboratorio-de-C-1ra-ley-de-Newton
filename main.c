#include <stdio.h>
#include <string.h>

int main(void)
{
    char opcion[10];
    double masa = 26000.0;
    double velocidad = 10900.0;
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
            energiaCinetica = 0.5 * masa * velocidad * velocidad;
            printf("\nEnergia cinetica inicial de Orion:\n");
            printf("K = 1/2 * masa * velocidad^2\n");
            printf("K = %.2e joules\n", energiaCinetica);
        }
        else if (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0)
        {
            printf("Opcion no valida. Ingrese 1, 2 o 0.\n");
        }
    } while (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0);

    return 0;
}
