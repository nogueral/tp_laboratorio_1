#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion, operandoA, operandoB;
    int suma, resta, multiplicacion;
    int factorialA, factorialB;
    float division;
    int flagA=1, flagB=1, flagC=1;

    do {

       printf("\nSeleccione una opcion: ");
       if(flagA==1){
           printf("\n1. Ingresar el 1er operando: ");
       } else {
           printf("\n1. Ingresar el 1er operando: %d", operandoA);
       }
       if(flagB==1) {
            printf("\n2. Ingresar el 2do operando: ");
       } else {
            printf("\n2. Ingresar el 2do operando: %d", operandoB);
       }
       if(flagC==1) {
            printf("\n3. Realizar todas las operaciones: ");
       } else {
            printf("\n3. Realizar todas las operaciones: Calculos completos");
       }
       printf("\n4. Informar resultados: ");
       printf("\n5. Salir: \n");
       scanf("%d", &opcion);

        switch(opcion) {

            case 1:
            printf("\nIngrese 1er operando: ");
            scanf("%d", &operandoA);
            flagA=0;
            break;

            case 2:
            printf("\nIngrese 2do operando: ");
            scanf("%d", &operandoB);
            flagB=0;
            break;

            case 3:
            suma = funcionSuma(operandoA, operandoB);
            resta = funcionResta(operandoA, operandoB);
            if (operandoB!=0) {
            division = funcionDivision(operandoA, operandoB);
            }
            multiplicacion = funcionMultiplicacion(operandoA, operandoB);
            if(operandoA>-1) {
            factorialA = funcionFactorial(operandoA);
            }
            if(operandoB>-1) {
            factorialB = funcionFactorial(operandoB);
            }
            flagC=0;
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
            if(operandoA>-1 && operandoB>-1) {
            printf("\nEl factorial de %d es %d y el factorial de %d es %d",
            operandoA, factorialA, operandoB, factorialB);
            }
            if(operandoA<0) {
                printf("\nNo se puede calcular el factorial de %d porque es negativo", operandoA);
                printf("\nEl factorial de %d es %d", operandoB, factorialB);
            }
            if(operandoB<0) {
                printf("\nEl factorial de %d es %d", operandoA, factorialA);
                printf("\nNo se puede calcular el factorial de %d porque es negativo", operandoB);
            }
            break;
        }

    } while(opcion!=5);


    return 0;
}
