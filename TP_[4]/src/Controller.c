#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "BibliotecaPersonal.h"
#include <ctype.h>
#include "Controller.h"
#include "../inc/LinkedList.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
int todoOk = 0;
    FILE* pFile;
    if (path != NULL && pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");

        pFile = fopen( path, "r");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if (parser_EmployeeFromText( pFile, pArrayListEmployee ) )
            {
                printf( "Carga de archivo de texto exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
int todoOk = 0;
    FILE* pFile;

    if (path !=NULL && pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");

        pFile = fopen( path, "rb");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if ( parser_EmployeeFromBinary( pFile, pArrayListEmployee ) )
            {
                printf( "Carga de archivo binario exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    Employee* auxEmpleado;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    int posicion;

    if ( pArrayListEmployee != NULL )
    {
        system("cls");
        printf("Alta de empleado\n");
        auxEmpleado = employee_new();
        id = buscarMayorId(pArrayListEmployee);
        id = id + 1;
        pedirCadena(nombre, "Ingrese nombre: ", 50);
        validarEntero(&sueldo, "Ingrese el sueldo: ", "Ingrese un sueldo valido (5.000-100.000): ", 5000, 100000, 10);
        validarEntero(&horasTrabajadas, "Ingrese horas trabajadas: ", "Ingrese cantidad de horas valida (0-1000): ", 0, 1000, 10);

        if (employee_setId(auxEmpleado, id) &&
            employee_setNombre(auxEmpleado, nombre) &&
            employee_setSueldo(auxEmpleado, sueldo) &&
            employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas)
           )
        {
            printf("En que posicion desea ingresar el empleado (0-%d):\n", ll_len(pArrayListEmployee)-1);
            scanf("%d", &posicion);
            while(posicion< 0 || posicion >= ll_len(pArrayListEmployee)){
            printf("Posicion ingresada erronea, ingrese una posicion valida: ");
            scanf("%d", &posicion);
            }
            if (posicion == ll_len(pArrayListEmployee)-1){

            ll_add(pArrayListEmployee, auxEmpleado );
            printf("Empleado cargado con exito\n");
            }else{
            ll_push(pArrayListEmployee,posicion,auxEmpleado);
            }
            todoOk = 1;
        }
        else
        {
            employee_delete(auxEmpleado);
        }
    }
    return todoOk;
}
/** \brief Modifica los datos de un empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
int todoOk = 0;
    Employee* auxEmpleado;
    char seguir = 's';
    char salir;
    int id;
    int opcion;
    int indice;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    char confirma;

    controller_ListEmployee(pArrayListEmployee);
    if (pArrayListEmployee != NULL)
    {
        printf("Modificar datos de empleado\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = buscarEmpleadosId( pArrayListEmployee, id );
        if ( indice == -1 )
        {
            printf("No se encontro el empleado\n");
        }
        else
        {
            auxEmpleado = ll_get(pArrayListEmployee, indice);
            do
            {
                system("cls");
                printf("\n");
                printf("Legajo  Nombre          Horas Trabajadas    Sueldo\n");
                showEmployee(auxEmpleado);
                opcion = menuEdicion();

                switch (opcion)
                {
                case 1:
                    system("cls");
                    printf("  Editar Nombre  \n");
                    pedirCadena(nombre, "Ingrese nombre: ", 50);

                    printf("Confirma cambio nombre? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setNombre(auxEmpleado, nombre);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    system("cls");
                    printf("  Editar Horas Trabajadas\n");
                    validarEntero(&horasTrabajadas, "Ingrese horas trabajadas: ", "Ingrese cantidad de horas valida (0-1000): ", 0, 1000, 10);
                    printf("Confirma cambio horas trabajadas? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }

                    break;
                case 3:
                    system("cls");
                    printf(" Editar sueldo\n");
                    validarEntero(&sueldo, "Ingrese el sueldo: ", "Ingrese un sueldo valido (5.000-100.000): ", 5000, 100000, 10);
                    printf("Confirma cambio sueldo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setSueldo(auxEmpleado, sueldo);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 4:
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
                    break;
                }
                todoOk =1;
                system("pause");
            }
            while(seguir == 's');
        }
    }
    return todoOk;
}
int menuEdicion()
{
    int opcion = 0;
    printf("\n");
    printf("     *** Menu de edicion ***\n");
    printf("  1- Editar nombre\n");
    printf("  2- Editar horas trabajadas\n");
    printf("  3- Editar sueldo\n");
    printf("  4- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
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
int todoOk = 0;
    Employee* auxEmpleado;
    int id;
    int indice;
    char confirma;

    controller_ListEmployee(pArrayListEmployee);
    if (pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Baja de empleado\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = buscarEmpleadosId( pArrayListEmployee, id );
        if ( indice == -1 )
        {
            printf("No se encontro el empleado\n");
        }
        else
        {
            auxEmpleado = ll_get(pArrayListEmployee, indice);
            printf("Empleado seleccionado: ");
            showEmployee(auxEmpleado);
            if(ll_contains(pArrayListEmployee, auxEmpleado)){
                printf("El empleado se encuentra en esta lista");
            }
            printf("\n");
            printf("Confirma la baja? (S/N)\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if ( toupper(confirma) == 'S' )
            {
               auxEmpleado = ll_pop(pArrayListEmployee, indice);
               showEmployee(auxEmpleado);
               if(ll_contains(pArrayListEmployee, auxEmpleado)){
                printf("El empleado sigue en la lista");
               }else{
                printf("Este usuario fue eliminado de la lista correctamente\n");
                todoOk = 1;
               }
            }
        }
    }
    return todoOk;
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
    Employee* auxEmpleado;
    int controlador;
    controlador = ll_isEmpty(pArrayListEmployee);
    if (pArrayListEmployee != NULL)
    {
        if(controlador == 0){
        system("cls");
        printf("Listar empleados\n");

        printf("Legajo  Nombre          Horas Trabajadas    Sueldo\n");
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get( pArrayListEmployee, i );
            showEmployee(auxEmpleado);
        }
        todoOk = 1;
        }else{
            printf("La lista esta vacia\n");
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
    char seguir = 's';
    char salir;
    int todoOk = 0;
    int opcion;
    if (pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Ordenar empleados\n");
        do
        {
            opcion = menuOrdenar();
            switch (opcion)
            {
            case 1:
                system("cls");
                printf("  Ordenar por Sueldo de menor a mayor\n");
                ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 1 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                 system("cls");
                printf("  Ordenar por Sueldo de mayor a menor\n");
                ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 0 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                 system("cls");
                printf("  Ordenar por Horas trabajadas de menor a mayor  \n");
                ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 1 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                system("cls");
                printf("  Ordenar por Horas trabajadas de mayor a menor\n");
                ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 0 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 5:
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
                break;
            }
            system("pause");
        }
        while(seguir == 's');
    }
    return todoOk;
}
int menuOrdenar()
{
    int opcion = 0;
    system("cls");
    printf("     *** Menu de ordenamiento ***\n");
    printf("  1- Ordenar por Sueldo de menor a mayor \n");
    printf("  2- Ordenar por Sueldo de mayor a menor \n");
    printf("  3- Ordenar por Horas trabajadas de menor a mayor\n");
    printf("  4- Ordenar por Horas trabajadas de mayor a menor\n");
    printf("  5- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int compararEmpleadosSueldo(void* employeeA, void* employeeB)
{
int todoOk= 0;

    if(((Employee*)employeeA)->sueldo > ((Employee*)employeeB)->sueldo)
    {
        todoOk= 1;
    }
    if(((Employee*)employeeA)->sueldo <
            ((Employee*)employeeB)->sueldo)
    {
        todoOk = -1;
    }
    return todoOk;

}
int compararEmpleadosHorasTrabajadas(void* employeeA, void* employeeB)
{
int todoOk= 0;

    if( ((Employee*)employeeA)->horasTrabajadas > ((Employee*)employeeB)->horasTrabajadas )
    {
        todoOk= 1;
    }
    if( ((Employee*)employeeA)->horasTrabajadas < ((Employee*)employeeB)->horasTrabajadas )
    {
        todoOk = -1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmpleado;

    if (path != NULL && pArrayListEmployee != NULL){
        system("cls");
        printf("Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");

        pFile = fopen(path, "w");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        fprintf( pFile, "id,nombre,horasTrabajadas,sueldo\n" );

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if (employee_getId( auxEmpleado, &id ) &&
                employee_getNombre( auxEmpleado, nombre ) &&
                employee_getHorasTrabajadas( auxEmpleado, &horasTrabajadas) &&
                employee_getSueldo(auxEmpleado, &sueldo)
               )
            {
                fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
int todoOk = 0;
    FILE* pFile;
    Employee* auxEmpleado;
    if (path != NULL && pArrayListEmployee != NULL){
        system("cls");
        printf("Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        pFile = fopen(path, "wb");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);

            if ((auxEmpleado) != NULL)
            {
                fwrite( auxEmpleado, sizeof(Employee), 1, pFile );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
///////////////////////////////////////////////////////////////////////////
int controller_remplaceEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;
    int index;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Ingrese el indice donde quiere agregar un empleado: \n");
        scanf("%d", &auxId);

        index = buscarEmpleadosId(pArrayListEmployee, auxId);
        if(index == -1)
        {
            printf("No existe la posicion del empleado: \n");
        }else{
        system("cls");
        printf("El empleado en esta posicion es: \n");
        auxEmployee = ll_get(pArrayListEmployee, index);
        printf("Legajo      Nombre      Horas trabajadas        Sueldo\n");
        showEmployee(auxEmployee);

        printf("Ingrese nombre del empleado\n");
        fflush(stdin);
        scanf("%s", auxNombre);
        mayusculaPrimerCaracter(auxNombre);
         validarEntero(&auxHorasTrabajadas, "Ingrese las horas trabajadas del empleado:\n", "ERROR... Ingrese las horas trabajadas del empleado:\n", 2, 2000, 10);
        validarEntero(&auxSueldo, "Ingrese el sueldo  del empleado:\n", "ERROR... Ingrese el sueldo  del empleado:\n", 10000, 60000, 10);
        if(!(employee_setId(auxEmployee, auxId) &&
                    employee_setNombre(auxEmployee, auxNombre) &&
                    employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas )&&
                    employee_setSueldo(auxEmployee, auxSueldo)))
            {
                free(auxEmployee);
                auxEmployee = NULL;
            }
            else
            {
                ll_set(pArrayListEmployee, index,auxEmployee);
                printf("Datos empleado reemplazado con exito!\n");;
            }

        }

        todoOk =1;

    }
    return todoOk;
}

int controller_clearList(LinkedList* pArrayListEmployee){
    int todoOk=0;
    char confirmar;

    if(pArrayListEmployee !=NULL){
        printf("Esta seguro que desea borrar todos los empleados? (S o N) \n");
        fflush(stdin);
        scanf("%c", &confirmar);
        if(tolower(confirmar) =='s')
        {
            ll_clear(pArrayListEmployee);
            printf("Empleados borrados con exito\n");
            }else{
                printf("Accion cancelada correctamente por el usuario\n");
        }
        todoOk =1;
    }
    return todoOk;
}
int controller_deleteList(LinkedList* pArrayListEmployee){
int todoOk =0;
char confirmar;

if(pArrayListEmployee !=NULL){
    printf("Esta seguro que desea borrar toda la lista? (S/N)\n");
    fflush(stdin);

    scanf("%c", &confirmar);
    if(tolower(confirmar) == 's'){
        if(!ll_deleteLinkedList(pArrayListEmployee)){
        pArrayListEmployee = NULL;
        printf("Lista de empleados eliminados con exito\n");
        todoOk =1;
            }
    }
}
return todoOk;
}
int controller_searchEmployee(LinkedList* pArrayListEmployee)
{

    int indice = -1;
    int idAux;
    int indice2;
    Employee* auxEmpleado;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese el id de la persona que desea encontrar: \n");
        scanf("%d", &idAux);
        indice = buscarEmpleadosId(pArrayListEmployee, idAux);
        if(indice == -1)
        {
            printf("No se pudo encontrar el empleado\n");
        }
        else
        {
            printf("El empleado a buscar dicho indice es \n");
            auxEmpleado = ll_get(pArrayListEmployee, indice);
            showEmployee(auxEmpleado);
            indice2 = ll_indexOf(pArrayListEmployee, auxEmpleado);
            printf("El indice traido es %d \n", indice2);

        }
    }
    return indice;
}

int controller_subList(LinkedList* pArrayListEmployee){
    int todoOk = 0;
    int principio;
    int fin;
    LinkedList* auxLista = NULL;

   if(pArrayListEmployee != NULL){
    auxLista = ll_newLinkedList();
   printf(" Crear sublista ");

   controller_ListEmployee(pArrayListEmployee);
   printf("Ingrese el inicio de sublista:");
   scanf("%d", &principio);
   printf("Ingrese el fin de sublista:");
   scanf("%d", &fin);

  auxLista =ll_subList(pArrayListEmployee,principio,fin);

  if(ll_containsAll(pArrayListEmployee,auxLista)){
    controller_ListEmployee(auxLista);
     printf("La sublista fue creada correctamente\n");

     }
    else{
        printf("Error al crear sublista\n");
    }

    todoOk =1;
   }
   return todoOk;
}
int controller_cloneList(LinkedList* pArrayListEmployee){
int todoOk= 0;

LinkedList* auxLista = NULL;
if(pArrayListEmployee != NULL){

    auxLista= ll_newLinkedList();
    printf("Clonar lista");

    auxLista = ll_clone(pArrayListEmployee);

    if(ll_containsAll(pArrayListEmployee, auxLista)){
        controller_ListEmployee(auxLista);
        printf("Lista clonada correctamente");
    }
    else{
        printf("No se pudo clonar");
    }
    todoOk =1;
}
return todoOk;
}

