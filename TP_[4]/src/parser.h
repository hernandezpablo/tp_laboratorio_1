/** \brief parsea los datos de los empleados desde el archivo que se utiliza en modo texto
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief parsea los datos de los empleados desde el archivo que se utiliza en modo binario
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
