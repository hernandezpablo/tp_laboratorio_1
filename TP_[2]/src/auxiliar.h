#ifndef AUXILIAR_H_INCLUDED
#define AUXILIAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
struct Employee;

/** \brief Show the menu of the application
 *
 * \return int
 *
 */
int menu();
/** \brief Find the closest Employee empty
 *
 * \param list[] Employee
 * \param len int
 * \return int the ubication of that Employee
 *
 */
int findEmpty(Employee list[], int len);
/** \brief Use the AddEmployee and let you add new Employees
 *
 * \param list[] Employee
 * \param len int
 * \param id int*
 * \return int Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int addNewEmployee(Employee list[], int len, int* id);
/** \brief Show you a single Employee
 *
 * \param list Employee
 * \return void
 *
 */
void printEmployee(Employee list);
/** \brief Its a Menu an use the removeEmployee Function
 *
 * \param list[] Employee
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int removeEmployeeMenu(Employee list[], int len);
/** \brief Its a Menu and use modifyEmployee
 *
 * \param list[] Employee
 * \param len int
 * \param index int
 * \return int
 *
 */
int modifyMenuEmployee(Employee list[], int len, int index);
/** \brief Check if it is a valid String and dont ocupate more space thant he should
 *
 * \param string char*
 * \param len int
 * \return int
 *
 */
int checkValidString(char* string, int len);
/** \brief its a Menu and use SortEmployee function
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int orderMenu(Employee* list, int len);
/** \brief transform a string in a float and validate it
 *
 * \param salary float*
 * \return int
 *
 */
int checkValidFloat(float* salary);
/** \brief transform a string in a int and validate it
 *
 * \param sector int*
 * \return int
 *
 */
int checkValidInt(int* sector);
#endif // AUXILIAR_H_INCLUDED
