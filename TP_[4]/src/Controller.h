
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Funcion que crea un nuevo empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si no hubo problemas y 0 si hubo un error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Edita los datos de un empleado existente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief funcion menu para editar empleado
 *
 * \return int
 *
 */
int menuEdicion();
/** \brief Elimina un empleado existente ingresando la id.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 1 si salio todo bien, 0 si hubo un error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief lista todos los empleados existentes
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordena los empleados dependiendo de distintos ordenes con la funcion ll_sort
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief funcion menu para elegir el parametro de ordenamiento
 *
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int menuOrdenar();
/** \brief funcion que da el parametro de ordenamiento de las cantidad de horas trabajadas
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int devuelve 0 si hubo algun error, 1 si salio todo bien
 *
 */
int compararEmpleadosHorasTrabajadas(void* employeeA, void* employeeB);
/** \brief funcion que da el parametro de ordenamiento del sueldo
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int compararEmpleadosSueldo(void* employeeA, void* employeeB);
/** \brief funcion que guarda todo lo ingresado en el archivo modo texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief funcion que guarda los datos modificados o ingresados en el archivo modo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief  remplaza la ubicacion un empleado, por otro nuevo, empujandolo uno mas.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_remplaceEmployee(LinkedList* pArrayListEmployee);
/** \brief limpia el contenido de la linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_clearList(LinkedList* pArrayListEmployee);
/** \brief  elimina la lista de Linked List
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_deleteList(LinkedList* pArrayListEmployee);
/** \brief busca un empleado dentro de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_searchEmployee(LinkedList* pArrayListEmployee);
/** \brief crea una sublista a base de una lista existente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_subList(LinkedList* pArrayListEmployee);
/** \brief clona una lista existente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_cloneList(LinkedList* pArrayListEmployee);
