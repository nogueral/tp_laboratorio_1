#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    int operandoA;
    int OperandoB;

    do {

       printf("Seleccione una opcion: ");
       printf("\n1. Ingresar el 1er operando: ");
       printf("\n2. Ingresar el 2do operando: ");
       printf("\n3. Realizar todas las operaciones: ");
       printf("\n4. Informar resultados: ");
       printf("\n5. Salir: ");
       scanf("%d", &opcion);

        switch(opcion) {

            case 1:
            printf("\nIngrese 1er operando: ");
            scanf("%d", &operandoA);
            break;
            case 2:
            printf("\nIngrese 2do operando: ");
            scanf("%d", &OperandoB);
            break;

        }

    } while(opcion!=5);



    return 0;
}
