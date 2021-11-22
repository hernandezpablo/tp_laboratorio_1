int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

int controller_addEmployee(LinkedList* pArrayListEmployee);

int controller_editEmployee(LinkedList* pArrayListEmployee);
int menuEdicion();
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int menuOrdenar();
int compararEmpleadosHorasTrabajadas(void* employeeA, void* employeeB);
int compararEmpleadosSueldo(void* employeeA, void* employeeB);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_remplaceEmployee(LinkedList* pArrayListEmployee);
int controller_clearList(LinkedList* pArrayListEmployee);
int controller_deleteList(LinkedList* pArrayListEmployee);
int controller_searchEmployee(LinkedList* pArrayListEmployee);
int controller_subList(LinkedList* pArrayListEmployee);
int controller_cloneList(LinkedList* pArrayListEmployee);
