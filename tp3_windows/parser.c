#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
int todoOk = 0;
char id[50];
int tam;
char horasT[50];
char nombre[50];
char sueldo[50];
Employee* auxEmployee;

if (pFile !=NULL && pArrayListEmployee!= NULL)
{
	 fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasT, sueldo);
    do {
        tam = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasT, sueldo);
        if (tam < 4)
        {
            break;
        }

        auxEmployee = employee_newParametros( id, nombre, horasT, sueldo);
        if (auxEmployee != NULL)
        {
            ll_add( pArrayListEmployee, auxEmployee );
            auxEmployee = NULL;
            todoOk = 1;
        }
    }
     while(!feof(pFile));
}
return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
