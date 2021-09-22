#ifndef FUNCIONESTP_H_INCLUDED
#define FUNCIONESTP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


#endif // FUNCIONESTP_H_INCLUDED

/** \brief Muestra el menu de la calculadora
 *
 * \param flagPrimerValor int es una flag que me permite verificar si ya se ingreso el primer valor
 * \param primerValor int primer valor ingresado
 * \param flagSegundoValor int es una flag que me permite verificar si ya se ingreso el segundo valor
 * \param segundoValor int segundo valor ingresado
 * \param resultadoSuma int me devuelve el resultado de la suma entre primerValor y segundoValor
 * \param resultadoResta int me devuelve el resultado de la resta entre primerValor y segundoValor
 * \param resultadoDivi float me devuelve el resultado de la division entre primerValor y segundoValor
 * \param resultadoMulti int me devuelve el resultado de la multiplicacion entre primerValor y segundoValor
 * \param primerFactorial int me devuelve el factorial del primerValor
 * \param segundoFactorial int me devuelve el factorial del segundoValor
 * \return int
 *
 */
int menu(int flagPrimerValor, int primerValor, int flagSegundoValor, int segundoValor, int resultadoSuma, int resultadoResta, float resultadoDivi, int resultadoMulti, int primerFactorial, int segundoFactorial);
/** \brief Realiza las operaciones matematicas entre los valores A y B
 *
 * \param primerValor int Es el valor de A
 * \param segundoValor int es el valor de B
 * \param resultadoSuma int* me indica el resultado de la suma entre A y B
 * \param resultadoResta int* me indica el resultado de la resta entre A y B
 * \param resultadoDivi float* me indica el resultado de la division entre A y B
 * \param resultadoMulti int* me indica el resultado de la multiplicacion entre A y B
 * \param primerFactorial int* me indica el factorial de A
 * \param segundoFactorial int* me indica el factorial de B
 * \return int
 *
 */
void calcularOperaciones(int primerValor, int segundoValor, int* resultadoSuma, int* resultadoResta, float* resultadoDivi,int* resultadoMulti,int* primerFactorial, int* segundoFactorial);
/** \brief  Muestra los calculos matematicos entre los valores A y B
 *
 * \param primerValor int Es el valor de A
 * \param segundoValor int es el valor de B
 * \param resultadoSuma int muestra el resultado de la suma entre A y B
 * \param resultadoResta int muestra el resultado de la resta entre A y B
 * \param resultadoDivi float muestra el resultado de la division entre A y B
 * \param resultadoMulti int muestra el resultado de la multiplicacion entre A y B
 * \param primerFactorial int muestra el factorial de A
 * \param segundoFactorial int muestra el factorial de B
 * \return void
 *
 */
void mostrarCalculos(int primerValor, int segundoValor, int resultadoSuma, int resultadoResta, float resultadoDivi, int resultadoMulti, int primerFactorial, int segundoFactorial);
/** \brief Se ingresa el valor del primer dato
 *
 * \param primerDato int* Se ingrea el valor del primer dato (A)
 * \return void
 *
 */
void ingresarPrimerDato(int* primerDato);
/** \brief Se ingresa el valor del segundo dato
 *
 * \return int retorna el valor del segundo dato(b)
 *
 */
int ingresarSegundoDato();
/** \brief calcula la suma de dos enteros
 *
 * \param primerValor int primer valor a sumar
 * \param segundoValor   int segundo valor a sumar
 * \return int
 *
 */
int suma(int primerValor, int segundoValor);
/** \brief calculas la resta de dos enteros
 *
 * \param primerValor int primer valor para restar
 * \param segundoValor int segundo valor para restar
 * \return int
 *
 */
int resta(int primerValor, int segundoValor);
/** \brief calcula la division entre dos enteros
 *
 * \param primerValor int Entero numerador
 * \param segundoValor int entero divisor
 * \return float
 *
 */

float division(int primerValor, int segundoValor);
/** \brief realiza el calculo de la multiplicacion entre 2 enteros
 *
 * \param primerValor int primer valor a multiplicar
 * \param segundoValor int segundo valor a multiplicar
 * \return float
 *
 */
int multiplicacion(int primerValor, int segundoValor);
/** \brief Calcula el factorial de un numero
 *
 * \param valor int entero que se calcula su factorial
 * \return int
 *
 */
int factorial(int valor);
