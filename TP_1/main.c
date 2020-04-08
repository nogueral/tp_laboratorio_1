#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion, operandoA, operandoB;
    int suma, resta, multiplicacion, factorialA, factorialB;
    float division;

    do {

       printf("\nSeleccione una opcion: ");
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
            scanf("%d", &operandoB);
            break;
            case 3:
            suma = funcionSuma(operandoA, operandoB);
            resta = funcionResta(operandoA, operandoB);
            division = funcionDivision(operandoA, operandoB);
            multiplicacion = funcionMultiplicacion(operandoA, operandoB);
            factorialA = funcionFactorial(operandoA);
            factorialB = funcionFactorial(operandoB);
            break;
            case 4:
            printf("\nEl resultado de %d + %d es %d", operandoA, operandoB, suma);
            printf("\nEl resultado de %d - %d es %d", operandoA, operandoB, resta);
            if(operandoB==0) {
                printf("\nNo es posible dividir por 0");
            } else {
                printf("\nEl resultado de %d / %d es %f", operandoA, operandoB, division);
            }
            printf("\nEl resultado de %d * %d es %d", operandoA, operandoB, multiplicacion);
            printf("\nEl factorial de %d es %d y el factorial de %d es %d",
            operandoA, factorialA, operandoB, factorialB);
            break;
        }

    } while(opcion!=5);



    return 0;
}
