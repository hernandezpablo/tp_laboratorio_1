/*
 ============================================================================
 Name        : TP_2.c
 Author      : Pablo Hernandez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayemployee.h"
#include "BibliotecaPersonal.h"
#include "auxiliar.h"

#define LEN 1000

int main()
{

    Employee list[LEN];
    char exit = 'n';
    char next = 'y';
    int nextId = 0;
    int addedEmployee = 0;
    float fullSalario;
    float totalSalario;
    if(initEmployees(list, LEN) == -1 ){
        printf("Error in the space or null pointer!\n");
    }

   do{
    switch(menu())
    {
        case 1:
            if(addNewEmployee(list, LEN, &nextId) == -1){
                printf("Cannot Register correctly \n");
            } else{
                printf("You register an employee correctly \n");
            }
             printEmployees(list, LEN);
            addedEmployee =1;
            break;
        case 2:
            if(addedEmployee ==0){
                printf("You cant change employees without adding no employees\n");
            } else{
            if (modifyEmployee(list, LEN) == 1){
                printf("You have moddified an employee");
            } else {
            printf("There was a error in the change of the employee");
            }
            }
            break;
        case 3:
             if(addedEmployee ==0){
                printf("You cant remove employees without adding no employees\n");
            } else{
            if(removeEmployeeMenu(list, LEN) == -1){
                printf("You couldnt remove that Employee correctly\n");
                } else{
                printf("You removed correctly that Employee!\n");
                       }
                }
            break;
        case 4:
            if(addedEmployee ==0){
                printf("You cant list employees without adding no employees\n");
            } else{
                if (orderMenu(list, LEN) == -1){
                    printf("The program couldnt sort the program");
                }
            //sortEmployees(list,LEN,1);
            printEmployees(list, LEN);
            }
            break;
        case 5:
            printf("Are you shure you want to leave? Y/N\n");
            fflush(stdin);
            scanf("%c", &exit);
            exit = toupper(exit);
                if (exit =='Y'){
                    next = 'n';
                } else{
                break;
                }
            break;
        case 6:
             if (addedEmployee ==0)
	            {
	                printf("You dont have employees to enter this option: \n");
	            }
	            else
	            {
	                if (salarioEmpleados(list, LEN, &fullSalario, &totalSalario))
	                {
	                    printf("No se pudo promediar el salario de  las personas\n");
	                }
	                else
	                {
	                    printf("El total a pagar por salarios es de %.2f y el promedio de salario es de : %.2f\n", totalSalario ,fullSalario);
	                    cobranEncimaPromedio(list, LEN,fullSalario, totalSalario);
	                }
	            }
	            break;
        default:
             printf("Invalid Option!!!\n");
             break;
    }
     system("pause");

   }while(next =='y');


    return 0;
}

