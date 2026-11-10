#include <stdio.h>
#include <string.h>

int main(void)
{
    char opcion[10];

    do
    {
        printf("\nSimulador de Misiones Artemis - Escenario TLI\n");
        printf("1. Leer sobre la inercia de Orion\n");
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
        else if (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0)
        {
            printf("Opcion no valida. Ingrese 1 o 0.\n");
        }
    } while (strcmp(opcion, "0\n") != 0 && strcmp(opcion, "0") != 0);

    return 0;
}
