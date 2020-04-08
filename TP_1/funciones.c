#include <stdio.h>
#include <stdlib.h>

int funcionSuma (int a, int b) {

    int resultado;

    resultado = a + b;

    return resultado;
}

int funcionResta (int a, int b) {

    int resultado;

    resultado = a - b;

    return resultado;
}

float funcionDivision (int a, int b) {

    float resultado;

    resultado = (float) a / b;

    return resultado;
}

int funcionMultiplicacion (int a, int b) {

    int resultado;

    resultado = a * b;

    return resultado;
}

int funcionFactorial (int num) {

    int factorial=1;
    int i;


    for(i=num; i>1; i--) {

    factorial=factorial*i;

   }

   return factorial;
}
