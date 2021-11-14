#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
int todoOk = 0;
FILE* file;

	    if ( path != NULL && pArrayListEmployee != NULL )
	    {
	        system("cls");

	        printf("Cargando la informacion de los empleados del archivo data.csv en modo texto.\n");
	        file = fopen(path, "r");
	        if ( file==NULL)
	        {
	         printf("El archivo no se pudo abrir correctamente\n");
	        }
	        else {
	            if(parser_EmployeeFromText(file, pArrayListEmployee))
	            {
	               printf( "Se ha podido cargar los documentos correctamente\n" );
	                 todoOk = 1;
	            }
	        }
	    }
	    fclose(file);
	  return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(Employee* empleado, LinkedList* pArrayListEmployee)
{
	int todoOk =0;
	if(empleado !=NULL && pArrayListEmployee !=NULL){
	Node* nodoNuevo;
	nodoNuevo = (Node*) malloc(sizeof(nodoNuevo));
	nodoNuevo->pElement = empleado;
	nodoNuevo->pNextNode = NULL;
	ll_add(pArrayListEmployee, nodoNuevo);
	todoOk =1;
	}

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	/*Employee* auxEmpleado;
	int id= pedirIdEmpleado(pArrayListEmployee);
	auxEmpleado = ll_get(pArrayListEmployee, id-1);
*/
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
int todoOk = 0;
Employee* auxEmployee;
    if (pArrayListEmployee != NULL){
       system("cls");
       printf("Lista de empleados:  \n");
	   printf("Legajo  Nombre          Horas Trabajadas    Sueldo\n");
	       for (int i=0;i <ll_len(pArrayListEmployee);i++)
	        {
	    	 auxEmployee=(Employee*) ll_get(pArrayListEmployee, i);
	         showEmployee(auxEmployee);
	        todoOk = 1;
	    }

	}
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


