#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

int main()
{
    Employee listadoEmpleados[TAM];
    int retorno;
    int opcion;
    int id;
    int i;
    int order;
    int print;
    float suma;
    float promedio;
    int contador;

    retorno=InitEmployees(listadoEmpleados, TAM);
    if(retorno==0)
    {
        printf("\nEl programa esta listo para operar\n");

    } else {

        printf("\nError! Invalid length\n");
    }

    HardcodeoEmpleados(listadoEmpleados);

     do{
        opcion=MostrarMenu();

        switch(opcion)
        {
            case 1:
            retorno = UpEmployees(listadoEmpleados);
            switch(retorno)
            {
                case 0:
                printf("\nCargado con exito\n");
                break;
                case -1:
                printf("\nNo hay mas espacio\n");
                break;
            }
            break;
            case 2:
            for(i=0; i<TAM; i++)
            {
                if(listadoEmpleados[i].isEmpty==OCUPADO)
                {
                    printf("\nInIngrese el ID a modificar: ");
                    scanf("%d", &id);
                    retorno = ModificarEmpleado(listadoEmpleados, TAM, id);
                    switch(retorno)
                    {
                        case 0:
                        printf("\nModificado con exito\n");
                        break;
                        case 1:
                        printf("\nNo se modificaron los datos, operacion cancelada\n");
                        break;
                        case -1:
                        printf("\nID inexistente\n");
                        break;
                    }

                    break;
                }
            }
            if(i==TAM)
            {
                printf("\nAun no hay datos cargados\n");
            }
            break;
            case 3:
            for(i=0; i<TAM; i++)
            {
                if(listadoEmpleados[i].isEmpty==OCUPADO)
                {
                    printf("\nInIngrese el ID a eliminar: ");
                    scanf("%d", &id);
                    retorno = RemoveEmployee(listadoEmpleados, TAM, id);
                    switch(retorno)
                    {
                        case 0:
                        printf("\nOperacion realizada con exito\n");
                        break;
                        case 1:
                        printf("\nNo se modificaron los datos, operacion cancelada\n");
                        break;
                        case -1:
                        printf("\nID inexistente\n");
                        break;
                    }

                    break;
                }
            }
            if(i==TAM)
            {
                printf("\nAun no hay datos cargados\n");
            }
            break;
            case 4:
            for(i=0; i<TAM; i++)
            {
                if(listadoEmpleados[i].isEmpty==OCUPADO)
                {
                    printf("\nSeleccione: ");
                    printf("\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.");
                    printf("\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
                    scanf("%d", &print);
                    switch(print)
                    {
                        case 1:
                        printf("\nSeleccione el tipo de ordenamiento: \n 0 - Descendente: \n 1 - Ascendente: \n");
                        scanf("%d", &order);
                        retorno=SortEmployees(listadoEmpleados, TAM, order);
                        switch(retorno)
                        {
                        case 0:
                        printf("\nOrdenamiento realizado con exito\n");
                        break;
                        case -1:
                        printf("\nIngreso una opcion erronea, no se realizo el ordenamiento\n");
                        break;
                        }
                        retorno=PrintEmployees(listadoEmpleados, TAM);
                        break;
                        case 2:
                        suma=SumarSalarios(listadoEmpleados);
                        printf("\nLa sumatoria de salarios es: %.2f", suma);
                        promedio=CalculoPromedio(listadoEmpleados);
                        printf("\nEl promedio de salarios es: %.2f", promedio);
                        contador=ContadorPromedio(listadoEmpleados);
                        printf("\nLa cantidad de personas que superan el promedio de salarios es: %d \n", contador);
                        break;
                    }

                break;
                }
            }
            if(i==TAM)
            {
                printf("\nAun no hay datos cargados\n");
            }
            break;
        }

     system("pause");
     system("cls");

    }while(opcion!=5);

    return 0;
}
