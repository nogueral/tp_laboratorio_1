#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int InitEmployees(Employee[], int);

/** \brief Realiza el hardcodeo de datos para prueba del sistema
 *
 * \param Employee[]
 * \return
 *
 */
void HardcodeoEmpleados (Employee listaEmpleados[]);

/** \brief Muestra menu de opciones en main
 *
 * \param void
 * \return retorna la opcion seleccionada por el usuario
 *
 */
int MostrarMenu(void);

/** \brief Busca un espacio disponible en el array de estructura para cargar empleado
 *
 * \param Employee[]
 * \return valor del indice encontrado, o -1 si no hay espacio disponible
 *
 */
int BuscarLibre(Employee[]);

/** \brief Genera automaticamente un numero de ID de forma autoincremental
 *
 * \param void
 * \return int devuelve un numero entero
 *
 */
int GenerateId(void);

/** \brief Efectua la carga de un empleado en variables complementarias para subirlas a AddEmployees
 *
 * \param Employee[]
 * \param int
 * \return int 0 (cargado con exito) / -1 (no hay mas espacio)
 *
 */
int UpEmployees(Employee[]);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee[]
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (0) if Ok
*/
int AddEmployee(Employee[], int, char[],char[],float,int);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee[]
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int FindEmployeeByID(Employee[], int, int);

/** \brief Modifica los datos de un empleado previamente cargado
 *
 * \param lista empleados []
 * \param len int
 * \param id int
 * \return 0 (operacion ok) / -1 (no se encontro id) / 1 (operacion cancelada)
 *
 */
int ModificarEmpleado (Employee listaEmpleados[], int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok - (1) if the operation has been cancelled by user
*
*/
int RemoveEmployee (Employee listaEmpleados[], int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* (1) if the operation has been cancelled by use
*/
int SortEmployees(Employee[], int, int);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int PrintEmployees(Employee[], int);

/** \brief suma los los salarios cargados en el array
 *
 * \param Employee[]
 * \param
 * \return la sumatoria total de salarios
 *
 */
float SumarSalarios (Employee listaEmpleados[]);


/** \brief cuenta las posiciones cargadas en el array
 *
 * \param Employee []
 * \param
 * \return cantidad de posiciones cargadas
 *
 */
int CantidadPosicionesCargadas (Employee listaEmpleados[]);

/** \brief Calcula el promedio de sueldos cargados en el array
 * depende de funcion SumarSalarios y CantidadPosicionesCargadas
 * \param Employee[]
 * \param
 * \return promedio de sueldos
 *
 */
float CalculoPromedio (Employee[]);

/** \brief Muestra la cantidad de empleados que superan el salario promedio.
 * depende de la funcion promedio
 * \param Employee[]
 * \param
 * \return contador de empleados que superan el salario promedio
 *
 */
int ContadorPromedio (Employee[]);

#endif // ARRAYEMPLOYEES_H_INCLUDED
