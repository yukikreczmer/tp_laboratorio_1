/*
 * ArrayEmployees.h
 *
 *  Created on: 11 oct. 2021
 *      Author:
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/// @brief busca espacio libre en la lista de manera lógica(isEmpty=1)
///
/// @param list
/// @param len
/// @return retorna -1 si no encuentra lugar libre o el id de la posicion de array libre
int BuscarIdLibre(Employee list[], int len);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 */
int printEmployees(Employee* list, int len);

/// @brief muestra un empleado
///
/// @param empleado
void printOneEmployee(Employee empleado);

/// @brief Genera Id automaticamente para todas las posiciones de la lista
///
/// @param list
/// @param len
/// @return retorna -1 si la lista es NULL o su tamaño no es mayor que 0. O 0 si esta ok
int GenerarId(Employee list[], int len);

/// @brief ordena las posiciones del array por su ID de manera ascendente
///
/// @param list
/// @param len
/// @return	retorna -1 si la lista es NULL o su tamaño no es mayor que 0. O 0 si esta ok
int OrdenarPorID(Employee list[], int len);

/// @brief Pide datos para agregar un nuevo empleado y los pasa por referencia
///
/// @param toAddName espacio en memoria para agregar el nombre
/// @param toAddLastName espacio en memoria para agregar el apellido
/// @param toAddSalary espacio en memoria para agregar el salario
/// @param toAddSector espacio en memoria para agregar el sector
void DatosToAddEmployee(char toAddName[], char toAddLastName[], float* toAddSalary, int* toAddSector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/// @brief  Se muestra una lista de empleados dados de alta y permite modificar Nombre, Apellido, Salario o Sector eligiendo el ID a modificar
///
/// @param list
/// @param len
/// @return retorna -1 si la lista es NULL o su tamaño no es mayor que 0. O 0 si esta ok
int ModificarEmployee(Employee list[], int len);

/// @brief Se muestra una lista de empleados dados de alta y permite dar de baja eligiendo el ID.
///
/// @param list
/// @param len
/// @return retorna -1 si la lista es NULL o su tamaño es menor o igual a 0. O 0 si esta ok
int BajaEmployee(Employee list[],int len);

/// @brief Pasa por referencia el salario total de los empleados, el promedio de salario por empleado y la cantidad de empleados que superan al promedio
///
/// @param list
/// @param len
/// @param refSalarioTotal
/// @param refPromedioSalario
/// @param refSuperanPromedioSalario
/// @return retorna -1 si la lista es NULL o su tamaño no es mayor que 0. O 0 si esta ok
int PromedioSalarios(Employee list[], int len, float* refSalarioTotal, 	float* refPromedioSalario, int* refSuperanPromedioSalario);

/// @brief se le pasa por parámetro un retorno. si este mismo es "-1" se imprime el mensaje de error
///
/// @param retorno
/// @param ErrorMensaje
void ValidarRetorno(int retorno, char ErrorMensaje[]);

/// @brief
///
/// @param list
/// @param len
/// @return retorna -1 si la lista es NULL, o su tamaño no es mayor que 0, o si no hay empleados dados de alta. O 1 si esta ok
int HayEmpleadosEnAlta(Employee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
