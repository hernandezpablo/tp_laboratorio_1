#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int menu(){
	int opcion =0;
	system("cls");
	printf("ABM de Empleados: \n");
	printf("1) Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n");
	printf("2) Cargar los datos  de los empleados desde el archivo data.csv(modo binario) \n");
	printf("3) Alta de empleado \n");
	printf("4) Modificar empleado \n");
	printf("5) Baja del empleado \n");
	printf("6) Listar los empleados \n");
	printf("7) Ordenar los empleados \n");
	printf("8) Guardar los empleados en el archivo data.csv en modo texto \n");
	printf("9) Guardar los empleados en el archivo data.csv en modo binario \n");
	printf("10) Salir \n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}


Employee* employee_new(){
	Employee* nuevoEmpleado;

	nuevoEmpleado = (Employee*) malloc(sizeof(nuevoEmpleado));

	nuevoEmpleado->id = -1;
	strcpy(nuevoEmpleado->nombre,"");
	nuevoEmpleado->sueldo = 0.0;
	nuevoEmpleado->horasTrabajadas = 0;

	return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){
	Employee* nuevoEmpleado;

	nuevoEmpleado = (Employee*) malloc(sizeof(nuevoEmpleado));

	nuevoEmpleado->id = atoi(idStr);
	strcpy(nuevoEmpleado->nombre,nombreStr);
	nuevoEmpleado->sueldo = atof(sueldo);
	nuevoEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);

	return nuevoEmpleado;
}

int pedirIdEmpleado(LinkedList* pArrayListEmployee){
	int id=0;
	if(pArrayListEmployee != NULL){
	//controller_ListEmployee(pArrayListEmployee);

	printf("Elija el Id del usuario que quiere modificar: \n");
	scanf("%d", &id);
	while(id <=0){
		printf("Elija una Id valida de usuario que quiere modificar: \n");
			scanf("%d", &id);
	}
	}

	return id;
}
int employee_setNombre(Employee* this,char* nombre)
{
 int todoOk =0;
    if (this !=NULL && nombre !=NULL && strlen(nombre) >0 && strlen(nombre) <128)
    {
      strcpy(this->nombre,nombre);

        todoOk= 1;
   }
  return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}



int employee_setId(Employee* this,int id)
{
 int todoOk =0;
   if (this !=NULL && id >0)
    {
      this->id = id;

        todoOk =1;
    }
   return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk =0;
    if (this !=NULL && id !=NULL)
    {
       *id = this->id;

       todoOk =1;
    }
    return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
   int todoOk =0;
    if (this !=NULL && horasTrabajadas !=NULL)
    {
       *horasTrabajadas = this->horasTrabajadas;

        todoOk =1;
    }
  return todoOk;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
  int todoOk =0;
    if (this !=NULL && horasTrabajadas >0)
    {
        this->horasTrabajadas = horasTrabajadas;

        todoOk =1;
    }
 return todoOk;
}
//Para definir el sueldo
int employee_setSueldo(Employee* this,int sueldo)
{
  int todoOk =0;
    if (this !=NULL && sueldo >0)
    {
        this->sueldo = sueldo;

        todoOk =1;
    }
return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
 int todoOk =0;
    if (this !=NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;

        todoOk =1;
    }
  return todoOk;
}
int showEmployee(Employee* employee)
{
 int todoOk =0;
 int id;
 int horasTrabajadas;
 char nombre[50];

 int sueldo;

    if (employee!=NULL)
    {
        todoOk= 1;
        if (employee_getId(employee, &id) &&
               employee_getNombre(employee, nombre) &&
                employee_getHorasTrabajadas(employee, &horasTrabajadas) &&
               employee_getSueldo(employee , &sueldo)
           )
        {
            printf ("%-7d %-15s %-8d           %-6d\n", id, nombre,horasTrabajadas,sueldo);
            todoOk = 1;
        }
    }
    return todoOk;
}
