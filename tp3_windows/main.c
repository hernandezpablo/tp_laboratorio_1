#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	char salir;
    char seguir = 's';

    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                           printf("No disponible");
                            break;
            case 3:
                           printf("No disponible");
                            break;
            case 4:
                            printf("No disponible");
                            break;
            case 5:
            				printf("No disponible");
                            break;
            case 6:
            				if (!controller_ListEmployee(listaEmpleados) )
            	            {
            	               printf("Error para mostrar empleado\n");
            	            }
                            break;
            case 7:
            				printf("No disponible");
                            break;
            case 8:
            				printf("No disponible");
                            break;
            case 9:
            				printf("No disponible");
                            break;
            case 10:
            			printf("Esta seguro que desea salir? (S/N)\n");
            	            fflush(stdin);
            	            scanf( "%c", &salir);
            	            salir = toupper(salir);
            	            if (salir =='S')
            	            {
            	                seguir ='n';
            	            }
            	            else
            	            {
            	              break;
            	            }
            	            break;
            default:
                            printf("Opcion invalida!\n");
                            break;
        }
    }while(seguir == 's');
    return 0;
}

