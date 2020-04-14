#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    float operandoA, operandoB;
    float suma, resta, multiplicacion, division;
    float factorialA, factorialB;
    int validacionFactorialA, validacionFactorialB;
    int flagA=1, flagB=1, flagC=1;

    do {

       printf("\nSeleccione una opcion: ");
       if(flagA==1){
           printf("\n1. Ingresar el 1er operando: ");
       } else {
           printf("\n1. Ingresar el 1er operando: %.2f", operandoA);
       }
       if(flagB==1) {
            printf("\n2. Ingresar el 2do operando: ");
       } else {
            printf("\n2. Ingresar el 2do operando: %.2f", operandoB);
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
            scanf("%f", &operandoA);
            flagA=0;
            break;

            case 2:
            printf("\nIngrese 2do operando: ");
            scanf("%f", &operandoB);
            flagB=0;
            break;

            case 3:
            suma = funcionSuma(operandoA, operandoB);

            resta = funcionResta(operandoA, operandoB);

            if (operandoB!=0) {
            division = funcionDivision(operandoA, operandoB);
            }

            multiplicacion = funcionMultiplicacion(operandoA, operandoB);

            validacionFactorialA = validarFactorial(operandoA);
            validacionFactorialB = validarFactorial(operandoB);

            if(operandoA>-1 && validacionFactorialA==1) {
            factorialA = funcionFactorial(operandoA);
            }
            if(operandoB>-1 && validacionFactorialB==1) {
            factorialB = funcionFactorial(operandoB);
            }
            flagC=0;
            break;

            case 4:
            printf("\nEl resultado de %.2f + %.2f es %.2f", operandoA, operandoB, suma);

            printf("\nEl resultado de %.2f - %.2f es %.2f", operandoA, operandoB, resta);

            if(operandoB==0) {
                printf("\nNo es posible dividir por 0");
            } else {
                printf("\nEl resultado de %.2f / %.2f es %.2f", operandoA, operandoB, division);
            }

            printf("\nEl resultado de %.2f * %.2f es %.2f", operandoA, operandoB, multiplicacion);

            if(operandoA>-1 && validacionFactorialA==1) {
                printf("\nEl factorial de %.2f es %.2f", operandoA, factorialA);
            } else {
                printf("\nNo se puede calcular el factorial de numeros negativos o decimales. Error al ingresar %.2f", operandoA);
            }
            if(operandoB>-1 && validacionFactorialB==1) {
                printf("\nEl factorial de %.2f es %.2f\n", operandoB, factorialB);
            } else {
                printf("\nNo se puede calcular el factorial de numeros negativos o decimales. Error al ingresar %.2f\n", operandoB);
            }
            flagA=1;
            flagB=1;
            flagC=1;
            break;
        }

        system("pause");
        system("cls");

    } while(opcion!=5);


    return 0;
}
