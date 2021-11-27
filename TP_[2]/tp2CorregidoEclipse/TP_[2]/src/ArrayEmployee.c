#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#include "auxiliar.h"
#include "BibliotecaPersonal.h"
struct Employee;

int initEmployees(Employee* list, int len){

    int todoOk =-1;
    if(list !=NULL && len >0)
    {
        for (int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 0;
    }

    return todoOk;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector){
    int todoOk = -1;
    int index;

    if (list !=NULL && len >0 && name !=NULL && lastName !=NULL && salary >0 && sector >0){

        index = findEmpty(list, len);
        list[index].id = id;
        strcpy(list[index].name,name);
        strcpy(list[index].lastName, lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = 0;
        todoOk = 0;
    }
return todoOk;
}

int findEmployeeById(Employee* list, int len, int id){
    int index = -1;
    if(list !=NULL && len >0)
    {
        for (int i=0; i < len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int removeEmployee(Employee* list, int len, int id){
 int todoOk = -1;
 int index;
 char confirm;
 if (list != NULL && len> 0){


        index =  findEmployeeById(list, len, id);
        if (index ==-1){
            printf("This id: %d is not registered in the system", id);

        } else{

            printEmployee(list[index]);
            printf("Confirm remove Employee?: Y/N \n");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm = tolower(confirm);
            if (confirm == 'y'){
                list[index].isEmpty = 1;
                todoOk =0;
            } else{
                printf("Baja cancelada por el usuario\n");
                todoOk =0;
            }
        }

 }
 return todoOk;
}

int printEmployees(Employee* list, int len){

    int todoOk = 0;
    float totalSalary;
    int activeEmployees;
    if (list != NULL && len> 0)
    {

        system("cls");
        printf("          *** List of Employees ***\n");
        printf("-------------------------------------\n");
        printf("  ID  Name      Last Name     Salary     Sector \n");
        printf("-------------------------------------------------\n");
        for (int i=0; i < len; i++)
        {
                if(!list[i].isEmpty)
            {
                totalSalary = list[i].salary + totalSalary;
                printEmployee(list[i]);
                activeEmployees++;


            }
            }
        printf("-----------------------------------------\n");
        printf("%-10s\n","Total Salaries-");
        fflush(stdin);
        printf("%-10.2f\n", totalSalary);
        todoOk =1;

    }

    return todoOk;
}

int modifyEmployee(Employee list[], int len){

 int todoOk = 0;
 int seguir = 's';
 int index;
 int id;
 float auxFloat;
 int auxInt;
 Employee auxEmployee;
 int confirm;
 char exit;
 if (list != NULL && len> 0){
        system("cls");
        printf("    *** Modify Employee  ***\n\n");
        printf("Enter your id: ");
        scanf("%d", &id);

        index =  findEmployeeById(list, len, id);
        if (index ==-1){
            printf("This id: %d is not registered in the system\n", id);

        } else{
            do{
                switch(modifyMenuEmployee(list, len, index))
                {
                case 1:
                    pedirCadena(auxEmployee.name,"Ingrese un nombre: ", 20);
                    fflush(stdin);
                    printf("Are you shure? Yes = 1/No = other number\n");
                    scanf("%d", &confirm);
                    if (confirm == 1){
                        strcpy(list[index].name, auxEmployee.name);
                    } else{
                    printf("The name was not moddified\n");
                    }
                    break;
                case 2:
                    pedirCadena(auxEmployee.lastName, "Ingrese un apellido: ", 20);
                    fflush(stdin);
                    printf("Are you shure? Yes = 1/ No = other number\n");
                    scanf("%d", &confirm);
                    if (confirm == 1){
                        strcpy(list[index].lastName, auxEmployee.lastName);
                    } else{
                    printf("The Last Name was not moddified\n");
                    }
                    break;
                case 3:
                    validarFloat(&auxFloat,"Ingrese un salario entre 5000 y 200000: ","Error usted ingreso un salario invalido",5000,200000,1);
                    fflush(stdin);
                    auxEmployee.salary = auxFloat;

                    printf("Are you shure? Yes = 1/No = other number\n");
                    scanf("%d", &confirm);
                    if (confirm == 1){
                            list[index].salary = auxEmployee.salary;
                    } else{
                    printf("The Salary was not moddified\n");
                    }
                    break;
                case 4:
                     validarEntero(&auxInt,"Ingrese un sector entre 1 y 10: ", "Sector ingresado incorrecto, por favor intente de nuevo: ",1,10,1);
                    printf("Are you shure? Yes = 1/ No = 2\n");
                    scanf("%d", &confirm);
                    if (confirm == 1){
                            list[index].sector = auxEmployee.sector;
                    } else{
                    printf("The Salary was not moddified\n");
                    }
                    break;
                case 5:
                    printf("Are you shure you want to exit? Y/N\n");
                    fflush(stdin);
                    scanf("%c", &exit);
                    exit = toupper(exit);
                    if (exit == 'Y'){
                    seguir = 'n';
                    } else {
                    break;
                    }
                    break;

                default:
                    printf("Wrong option\n");
                    }
            }while(seguir == 's');

            todoOk = 1;
        }

 }
 return todoOk;
}

int sortEmployees(Employee* list, int len, int order){

int todoOk = -1;
Employee auxEmployee;

if(list != NULL && len >0){

     for(int i = 0;i<len -1; i++){
     for(int j= i+1; j<len; j++){
            if ((strcmp(list[i].lastName, list[j].lastName)>0 && order == 1 )||
                (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            } else if ((strcmp(list[i].lastName, list[j].lastName)<0 && order == 2 )||
                (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector)){
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
                }
        }
     }
     todoOk = 0;
    }
    return todoOk;
}
int cobranEncimaPromedio(Employee* lista, int len, float salario, float totalSalario)
{
    int todoOk = -1;

    int cont = 0;

    salarioEmpleados(lista,len, &salario, &totalSalario);
    if (lista !=NULL && len >0){

        for(int i = 0; i < len; i++)
        {
            if (lista[i].isEmpty == 0 )
            {
                if(lista[i].salary > salario)
                {
                    cont++;
                }
            }
        }
        todoOk = 0;
    }

    printf("La cantidad de personas que cobran mas del promedio de los salarios totales es: %d \n", cont);

    return todoOk;
}
int salarioEmpleados(Employee* lista, int len, float *pSalario, float *pTotalSalario)
{
    int todoOk = -1;
    float auxSalario = 0;
    int contSalario = 0;

    if (lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (lista[i].isEmpty == 0 )
            {
                auxSalario += lista[i].salary;
                contSalario++;
            }
        }
        todoOk= 0;

        *pSalario = (float)auxSalario /contSalario;
        *pTotalSalario = auxSalario;

    }

    return todoOk;
}

