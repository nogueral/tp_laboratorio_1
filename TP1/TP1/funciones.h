#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief calcula la suma de 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la suma de los 2 parametros
 *
 */
float funcionSuma (float, float);

/** \brief calcula la resta de 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la resta de los 2 parametros
 *
 */
float funcionResta (float, float);

/** \brief calcula la division entre 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la division de los 2 parametros
 *
 */
float funcionDivision (float, float);

/** \brief calcula la multiplicacion entre 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la multiplicacion de los 2 parametros
 *
 */
float funcionMultiplicacion (float, float);

/** \brief calcula el factorial del parametro ingresado
 *
 * \param el parametro que se ingresa
 * \return el factorial del numero ingresado
 *
 */
float funcionFactorial (float);

/** \brief valida si se puede calcular factorial en funcion de si el numero es entero o decimal.
 *
 * \param el parametro que se ingresa, siempre es flotante.
 * \return si el numero es entero devuelve 1, si es decimal devuelve 0.
 *
 */
float validarFactorial (float);

#endif // FUNCIONES_H_INCLUDED
