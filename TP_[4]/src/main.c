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
// **  FUNCIONES UTILIZADAS  ***

/*
        // ll_newLinkedList --- UTILIZADA utilizada en el main y en otras funciones
        // ll_len ------------- UTILIZADA lo utilice en muchas funcines
        // ll_add ------------- UTILIZADA en la funcion controller addEmployee
        // ll_get ------------- UTILIZADA lo utilice en muchas funciones
        // ll_set --------------------------- UTILIZADA en la funcion controller_remplaceEmployee
        // ll_remove ---------- --------------UTILIZADA en la funcion ll_pop
        // ll_clear ------------------------- UTILIZADA en la funcion controller_clearList
        // ll_deleteLinkedList -------------- UTILIZADA en la funcion controller deleteList
        // ll_indexOf ----------------------- UTILIZADA  en la funcion controller findEmployee
        // ll_isEmpty ----------------------- UTILIZADA en la funcion ListEmployee
        // ll_push -------------------------- UTILIZADA en la funcion controllerAddEmployee
        // ll_pop --------------------------- UTILIZADA en la funcion removeEmployee
        // ll_contains ---------------------- UTILIZADA en la funcion removeEmployee
        // ll_containsAll ------------------- UTILIZADA en las funciones controller subList/controller clone
        // ll_subList -----------------------UTILIZADA en la funcion controller subList
        // ll_clone -------------------------NO UTILIZADA en la funcion controller clone
        // ll_sort ------------ No UTILIZADA en la funcion controller sortEmployee
*/
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
                printf("Error al cargar desde texto\n");
            }
            break;
        case 2:
            if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
            {
                printf("Error al cargar desde binario\n");
            }
            break;
        case 3:
            if ( !controller_addEmployee(listaEmpleados) )
            {
                printf("Error en alta de empleado\n");
            }
            break;
        case 4:
            if ( !controller_editEmployee(listaEmpleados) )
            {
                printf("Error en edicion de empleado\n");
            }
            break;
        case 5:
            if ( !controller_removeEmployee(listaEmpleados) )
            {
                printf("Error en baja de empleado\n");
            }
            break;
        case 6:
            if ( !controller_ListEmployee(listaEmpleados) )
            {
                printf("Error en listar el empleado\n");
            }
            break;
        case 7:
            if ( !controller_sortEmployee(listaEmpleados) )
            {
                printf("Error en ordenamiento de empleados\n");
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
            if (!controller_remplaceEmployee(listaEmpleados)){
                printf("Funcion erronea\n");
            }
            break;
        case 11:
            if(!controller_clearList(listaEmpleados)){
                printf("No se pudieron vaciar la lista por un error\n");
            }
            break;
        case 12:
            if(!controller_deleteList(listaEmpleados)){
                printf("No se pudo eliminar la lista\n");
            }
            listaEmpleados = NULL;
            break;
        case 13:
            if(!controller_searchEmployee(listaEmpleados)){
                printf("No se pudo encontrar el empleado\n");
            }
        case 14:
            if(!controller_subList(listaEmpleados)){
                printf("No se pudo realizar subLista\n");
            }
            break;
         case 15:
            if(!controller_cloneList(listaEmpleados)){
                printf("No se pudo clonar Lista\n");
            }
            break;
        case 16:
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































