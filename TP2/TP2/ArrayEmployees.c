#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int InitEmployees(Employee listadoEmpleados[], int tam)
{
       int i;
       int retorno=-1;
       int contador=0;

    for(i=0; i<tam; i++)
    {
        listadoEmpleados[i].isEmpty = LIBRE;
        contador++;
    }

    if(contador==tam)
    {
        retorno=0;
    }

    return retorno;
}
void HardcodeoEmpleados (Employee listaEmpleados[])
{
    int i;

    int id[5]={1,2,3,4,5};
    char name[5][51]={"Leandro","Maria","Juan","Laura","Nicolas"};
    char lastName[5][51]={"Noguera","Perez","Gomez","Rodriguez","Gomez"};
    float salary[5]={200,300,100,500,600};
    int sector[5]={2,2,3,4,5};
    int isEmpty[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    for(i=0; i<5; i++)
    {
        listaEmpleados[i].id=id[i];
        strcpy(listaEmpleados[i].name, name[i]);
        strcpy(listaEmpleados[i].lastName, lastName[i]);
        listaEmpleados[i].salary=salary[i];
        listaEmpleados[i].sector=sector[i];
        listaEmpleados[i].isEmpty=isEmpty[i];
    }
}
int MostrarMenu(void)
{
    int opcion;

    printf("\n***** Menu *****\n\n");
    printf("\n1. ALTAS: \n2. MODIFICAR: \n3. BAJAS: \n4. INFORMAR: \n5. SALIR: ");
    printf("\nSeleccione la opcion deseada: ");
    scanf("%d", &opcion);
    printf("\n\n****************\n");

    return opcion;
}

int BuscarLibre(Employee listaEmpleados[])
{
    int i;
    int indice = -1;

    for(i=0; i<TAM; i++)
    {
        if(listaEmpleados[i].isEmpty==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int GenerateId(void)
{
    static int generatedId = 0;

    generatedId++;

    return generatedId;

}

int UpEmployees(Employee listaEmpleados[]){

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int indice;
    int retorno;

    indice = BuscarLibre(listaEmpleados);


    if(indice!=-1)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lastName);
        printf("Ingrese salario: ");
        scanf("%f", &salary);
        printf("Ingrese sector: ");
        scanf("%d",&sector);
        id=indice;

        retorno = AddEmployee(listaEmpleados,id,name,lastName,salary,sector);


    }else{

        retorno = indice;
    }

    return retorno;
}

int AddEmployee(Employee listaEmpleados[], int id, char name[],char lastName[],float salary,int sector)
{
    listaEmpleados[id].id=GenerateId();
    listaEmpleados[id].isEmpty=OCUPADO;
    listaEmpleados[id].salary=salary;
    listaEmpleados[id].sector=sector;
    strcpy(listaEmpleados[id].name,name);
    strcpy(listaEmpleados[id].lastName,lastName);

    printf("\nSu numero de ID es: %d", listaEmpleados[id].id);

 return 0;
}

int FindEmployeeByID(Employee listaEmpleados[], int len, int id)
{
    int i;
    int index = -1;

    for(i=0; i<len; i++)
    {
        if(listaEmpleados[i].isEmpty==OCUPADO && listaEmpleados[i].id==id)
        {
            index = i;
            break;
        }
    }

    return index;
}

int ModificarEmpleado (Employee listaEmpleados[], int len, int id)
{
    int opcion;
    int valorDeRetorno=-1;
    int index;
    char respuesta;

    index = FindEmployeeByID(listaEmpleados, len, id);

    if(index!=-1)
    {
        do{
        printf("\nEsta por modificar el ID %d del empleado %s %s", listaEmpleados[index].id, listaEmpleados[index].name, listaEmpleados[index].lastName);
        printf("\nDesea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        }while(respuesta!='s'&&respuesta!='n');

        if(respuesta=='s')
        {

        do{
        printf("\n Ingrese el dato a modificar: ");
        printf("\n 1. Nombre: \n 2. Apellido: \n 3. Salario: \n 4. Sector: \n 5. Salir: \n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(listaEmpleados[index].name);
            break;
            case 2:
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(listaEmpleados[index].lastName);
            break;
            case 3:
            printf("Ingrese salario: ");
            scanf("%f", &listaEmpleados[index].salary);
            break;
            case 4:
            printf("Ingrese sector: ");
            scanf("%d",&listaEmpleados[index].sector);
            break;
        }

        }while(opcion!=5);

        valorDeRetorno=0;

    } else {
        valorDeRetorno=1;
    }
    }

    return valorDeRetorno;

}
int RemoveEmployee (Employee listaEmpleados[], int len, int id)
{
    int valorDeRetorno=-1;
    int index;

    index = FindEmployeeByID(listaEmpleados, len, id);

    if(index!=-1)
    {
        listaEmpleados[index].isEmpty=LIBRE;
        printf("\nSe ha dado de baja el ID %d del empleado %s %s",
               listaEmpleados[index].id,
               listaEmpleados[index].name,
               listaEmpleados[index].lastName);
               valorDeRetorno=0;
    }

    return valorDeRetorno;
}

int SortEmployees(Employee listaEmpleados[], int len, int order)
{
    int i;
    int j;
    int retorno;
    Employee auxEmpleados;

    if(order==1)
    {
         for(i=0; i<len-1; i++)
    {
        if(listaEmpleados[i].isEmpty!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<len; j++)
        {
             if(listaEmpleados[j].isEmpty!=OCUPADO)
             {
                 continue;
             }
            if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)<0)
            {
                auxEmpleados = listaEmpleados[i];
                listaEmpleados[i] = listaEmpleados[j];
                listaEmpleados[j] = auxEmpleados;

            } else {

                if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)==0)
                {
                    if(listaEmpleados[i].sector<listaEmpleados[j].sector)
                    {
                        auxEmpleados = listaEmpleados[i];
                        listaEmpleados[i] = listaEmpleados[j];
                        listaEmpleados[j] = auxEmpleados;
                    }

                }
            }
        }
    }

    retorno=0;
    }

    if(order==0)
    {
          for(i=0; i<len-1; i++)
    {
        if(listaEmpleados[i].isEmpty!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<len; j++)
        {
             if(listaEmpleados[j].isEmpty!=OCUPADO)
             {
                 continue;
             }
            if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)>0)
            {
                auxEmpleados = listaEmpleados[i];
                listaEmpleados[i] = listaEmpleados[j];
                listaEmpleados[j] = auxEmpleados;

            } else {

                if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)==0)
                {
                    if(listaEmpleados[i].sector>listaEmpleados[j].sector)
                    {
                        auxEmpleados = listaEmpleados[i];
                        listaEmpleados[i] = listaEmpleados[j];
                        listaEmpleados[j] = auxEmpleados;
                    }

                }
            }
        }
    }

    retorno=0;

    }

    if(order!=0&&order!=1)
    {
        retorno=-1;
    }

    return retorno;
}

int PrintEmployees(Employee listaEmpleados[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(listaEmpleados[i].isEmpty==OCUPADO)
        {
            printf("\n%10d %20s %20s %20.2f %10d\n",
                   listaEmpleados[i].id,
                   listaEmpleados[i].name,
                   listaEmpleados[i].lastName,
                   listaEmpleados[i].salary,
                   listaEmpleados[i].sector);
        }
    }

    return 0;
}

float SumarSalarios (Employee listaEmpleados[])
{
    float suma=0;
    int i;

    for(i=0; i<TAM; i++) {

        if(listaEmpleados[i].isEmpty==OCUPADO)
        {
        suma+=listaEmpleados[i].salary;
        }

    }

    return suma;
}

int CantidadPosicionesCargadas (Employee listaEmpleados[])
{
    int i;
    int contador=0;

    for(i=0; i<TAM; i++){
        if(listaEmpleados[i].isEmpty==OCUPADO){
            contador++;
        }
    }
    return contador;
}

float CalculoPromedio (Employee listaEmpleados[])
{
    float promedio;
    float acumulador;
    int contador;

    acumulador=SumarSalarios(listaEmpleados);
    contador=CantidadPosicionesCargadas(listaEmpleados);

    promedio = acumulador/contador;

    return promedio;
}

int ContadorPromedio (Employee listaEmpleados[])
{
    int i;
    float promedio;
    int contador=0;

    promedio=CalculoPromedio(listaEmpleados);

    for(i=0;i<TAM; i++)
    {
        if(listaEmpleados[i].salary>=promedio && listaEmpleados[i].isEmpty==OCUPADO)
        {
            contador++;
        }

    }

    return contador;
}
