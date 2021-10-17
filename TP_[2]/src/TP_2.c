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
#include "ArrayEmployee.h"
#include "auxiliar.h"

#define LEN 1000

int main()
{
	setbuf(stdout,NULL);
    Employee list[LEN];
    char exit = 'n';
    char next = 'y';
    int nextId = 0;
    int addedEmployee = 0;
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
            addedEmployee =1;
            break;
        case 2:
            if(addedEmployee ==0){
                printf("You cant list employees without adding no employees\n");
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
                printf("You cant list employees without adding no employees\n");
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
        default:
             printf("Invalid Option!!!\n");
             break;
    }
     system("pause");

   }while(next =='y');


    return 0;
}

