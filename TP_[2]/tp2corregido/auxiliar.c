#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auxiliar.h"
#include "arrayemployee.h"
#include "BibliotecaPersonal.h"

int menu()
{

    int option;
    system("cls");
    printf("   *** List of Employees ***\n");
    printf("1- Register Employee\n");
    printf("2- Modify Employee\n");
    printf("3- Remove Employee\n");
    printf("4- List Employees\n");
    printf("5- Exit\n");
    printf("Enter an option: \n");
    scanf("%d", &option);

    return option;

}

int findEmpty(Employee list[], int len){
    int index = -1;
    if(list !=NULL && len >0)
    {
        for (int i=0; i < len; i++)
        {
            if(list[i].isEmpty)
            {
                index = i;
                break;
            }
        }
    }
return index;
}

int checkValidString(char* input, int len){
int todoOk =0;
char buffer[4096];
fflush(stdin);
scanf("%s", buffer);
strncpy(input, buffer, len);

return todoOk;
}
int checkValidFloat(float* salary){
    int todoOk =-1;
    char auxSalaryBuffer[100];
    fflush(stdin);
    scanf("%s", auxSalaryBuffer);
    float auxSalary = atof(auxSalaryBuffer);
    if(auxSalary != 0){
        todoOk=0;
        *salary = auxSalary;
    }

return todoOk;
}

int checkValidInt(int* sector){
    int todoOk =-1;
    char auxSectorBuffer[100];
    fflush(stdin);
    scanf("%s", auxSectorBuffer);
    float auxSector = atof(auxSectorBuffer);
    if(auxSector != 0){
        todoOk=0;
        *sector = auxSector;
    }

return todoOk;
}
int addNewEmployee(Employee list[], int len, int* id){
    int todoOk = -1;
    int index;
    float auxFloat;
    int auxInt;
    Employee auxEmployee;
    if(list !=NULL && len>0 && id !=NULL){
        system("cls");
        printf("    *** Register Employee ***\n");

        index = findEmpty(list, len);
        if (index == -1){
            printf("There is no free space for new Employees\n");
        } else{
        auxEmployee.id= *id +1;
        *id = auxEmployee.id;

        pedirCadena(auxEmployee.name,"Ingrese Nombre: ", 20);



        pedirCadena(auxEmployee.lastName, "Ingrese Apellido: ", 20);


        validarFloat(&auxFloat,"Ingrese el salario: ", "Error, el numero ingresado es invalido, por favor ingrese un salario valido(5000-200000): ",5000,200000,10 );
        auxEmployee.salary = auxFloat;

        validarEntero(&auxInt, "Ingrese el sector del empleado: ", "Error el sector ingresado es incorrecto ingrese un sector valido: (1 a 10) ", 1,10,10);
        auxEmployee.sector = auxInt;

        if (addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector) == -1){
            printf("There was an error when the program tried to add a new employee");
        }else{
            todoOk = 0;
        }
        }

    }
    return todoOk;

}

int removeEmployeeMenu(Employee list[], int len){
    int todoOk= -1;
    int id;

    if (list !=NULL && len>0){
        system("cls");
        printf("    *** Remove Employee  ***\n\n");
        printf("Please enter your id: ");
        scanf("%d", &id);
        printf("%d", id);
        if(removeEmployee(list, len, id) == -1){
            printf("There was an error in the process of removing an employee\n");
        } else{
            printf("The Employee was removed");
        todoOk = 0;
        }
    }
     return todoOk;
}

void printEmployee(Employee list){

    printf("%4d  %-6s     %-6s    %-2.2f   %-2d \n",
           list.id,
           list.name,
           list.lastName,
           list.salary,
           list.sector);

}

int modifyMenuEmployee(Employee list[], int len, int index){

 int option;
    system("cls");
    printf("   *** Modify Employee ***\n");
    printf("%3s %-5s %-5s %-2s %-2s \n", "ID","Name","Last name","Salary","Sector");
    printf("%3d %-5s %-5s %.2f %-2d \n",
           list[index].id,
           list[index].name,
           list[index].lastName,
           list[index].salary,
           list[index].sector);
    printf("1- Modify Name\n");
    printf("2- Modify Last Name\n");
    printf("3- Modify Salary\n");
    printf("4- Modify Sector\n");
    printf("5- Exit\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &option);

    return option;

}
int orderMenu(Employee* list, int len){
int todoOk = -1;
int select;
if(list != NULL && len >0){
printf("***  Select how do you want to sort ***\n");
printf("1- Upward\n");
printf("2- Downward\n");
printf("Enter your selection: \n");
scanf("%d", &select);

sortEmployees(list, len, select);
todoOk = 0;
}
return todoOk;
}
