/** \brief carga los datos de los empleados de un archivo en modo texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief carga los datos de los empleados de un archivo en modo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un errror, 1 si salio todo bien
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief crea un empleado nuevo en la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error o 1 si salio todo bien
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief edita los datos de un empleado existente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief funcion menu para la funcion de editar empleado
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuEdicion();
/** \brief elimina un empleado buscandolo por su id de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error o 1 si salio todo bien
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief lista todos los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si ocurrio algun error o 1 si salio todo bien
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief utiliza una funcion de ordenamiento para ordenar la lista segun esos criterios
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si hubo un error o un 1 si salio todo bien
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief menu para elegir la opcion del ordenamiento de la funcion sort employee
 *
 * \return int devuelve que opcion elegiste
 *
 */
int menuOrdenar();
/** \brief funcion de ordenamiento que ordena por horas trabajadas
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int devuelve 0 si hubo algun error, 1 si salio todo bien
 *
 */
int compararEmpleadosHorasTrabajadas(void* employeeA, void* employeeB);
/** \brief funcion de ordenamiento que ordena por el sueldo de los empleados
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int devuelve 0 si hubo un error, 1 si salio todo bien
 *
 */
int compararEmpleadosSueldo(void* employeeA, void* employeeB);
/** \brief guarda los cambios realizados a la lista en el archivo de modo texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si ocurrio algun error, 1 si salio bien
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief guarda los cambios realizados en la lista en el archivo en modo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si ocurrio algun error, 1 si salio todo bien.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

