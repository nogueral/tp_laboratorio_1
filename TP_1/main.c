#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;

    do {

       printf("Seleccione una opción: ");
       printf("\n1. Ingresar el 1er operando: ");
       printf("\n2. Ingresar el 2do operando: ");
       printf("\n3. Realizar todas las operaciones: ");
       printf("\n4. Informar resultados: ");
       printf("\n5. Salir: ");
       scanf("%d", &opcion);

    } while(opcion!=5);



    return 0;
}
