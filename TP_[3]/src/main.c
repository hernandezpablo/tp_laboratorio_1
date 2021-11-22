#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "BibliotecaPersonal.h"
#include "Controller.h"

int main()
{
    char seguir = 's';
    char salir;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        switch (menu())
        {
        case 1:
            if ( !controller_loadFromText("data.csv", listaEmpleados) )
            {
                printf("Error al cargar datos desde el archivo de texto\n");
            }
            break;
        case 2:
            if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
            {
                printf("Error al cargar datos desde el archivo binario\n");
            }
            break;
        case 3:
            if ( !controller_addEmployee(listaEmpleados) )
            {
                printf("Error en el alta de empleado\n");
            }
            break;
        case 4:
            if ( !controller_editEmployee(listaEmpleados) )
            {
                printf("Error en la edicion de empleado\n");
            }
            break;
        case 5:
            if ( !controller_removeEmployee(listaEmpleados) )
            {
                printf("Error en la baja de empleado\n");
            }
            break;
        case 6:
            if ( !controller_ListEmployee(listaEmpleados) )
            {
                printf("Error en listar los empleados\n");
            }
            break;
        case 7:
            if ( !controller_sortEmployee(listaEmpleados) )
            {
                printf("Error en el ordenamiento de empleados\n");
            }
            break;
        case 8:
            if ( !controller_saveAsText("data.csv", listaEmpleados) )
            {
                printf("Error al guardar en modo texto\n");
            }
            break;
        case 9:
            if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
            {
                printf("Error al guardar en modo binario\n");
            }
            break;
        case 10:
            printf("Esta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(seguir == 's');
    return 0;
}































