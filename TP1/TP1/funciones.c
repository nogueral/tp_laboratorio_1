#include <stdio.h>
#include <stdlib.h>

float funcionSuma (float a, float b) {

    float resultado;

    resultado = a + b;

    return resultado;
}

float funcionResta (float a, float b) {

    float resultado;

    resultado = a - b;

    return resultado;
}

float funcionDivision (float a, float b) {

    float resultado;

    resultado = a / b;

    return resultado;
}

float funcionMultiplicacion (float a, float b) {

    float resultado;

    resultado = a * b;

    return resultado;
}

float funcionFactorial (float num) {

    float factorial=1;
    int i;


    for(i=num; i>1; i--) {

    factorial=factorial*i;

   }

   return factorial;
}

float validarFactorial (float a)
{
    int entero;
    float resultado;
    int factorial=0;

    entero = a;
    resultado = a - entero;

    if(resultado==0) {
        factorial=1;
    }

    return factorial;
}
