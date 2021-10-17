/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct. 2021
 *      Author:
 */

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"


int initEmployees(Employee* list, int len)
{
	int i;
	int retorno=-1;
	if(len>0 && list!=NULL)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}

int BuscarIdLibre(Employee list[], int len)//retorna -1 si no encuentra lugar libre o el id del elemento libre
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				retorno=list[i].id;
				break;
			}
		}
	}
	return retorno;
}
int GenerarId(Employee list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].id=i+1;
		}
		retorno=0;
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retornoAdd=-1;
	int i;


	if(len>0 && list!=NULL && id!=-1)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				list[i].id=id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary=salary;
				list[i].sector=sector;
				list[i].isEmpty=0;
				retornoAdd=0;
				break;
			}
		}
	}
	return retornoAdd;
}
void printOneEmployee(Employee empleado)
{
		printf("%04d %10s %20s %20.2f %15d\n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{
	int retorno=-1;
	int i;
	printf("\nID:       NOMBRE:             APELLIDO:           SALARIO:       SECTOR:\n\n");
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			printOneEmployee(list[i]);
			retorno=0;
		}

	}

 return retorno;
}

void DatosToAddEmployee(char toAddName[], char toAddLastName[], float* toAddSalary, int* toAddSector)
{
	char auxName[51];
	char auxLastName[51];
	float auxToAddSalary;
	int auxToAddSector;
	PedirString("\nIngrese el nombre: ", auxName);
	PedirString("\nIngrese el apellido: ", auxLastName);
	auxToAddSalary=PedirFlotantePositivoValidandoCaracteres("\nIngrese el salario: ");
	auxToAddSector=PedirEnteroValidandoCaracteres("\nIngrese el sector: ", "\nError, el sector tiene que estar indicado con su número correspondiente.");
	*toAddSalary=auxToAddSalary;
	*toAddSector=auxToAddSector;
	strcpy(toAddName,auxName);
	strcpy(toAddLastName,auxLastName);
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				retorno=i;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;

	if(len>0 && list!=NULL)
	{
		int retornoFindByID;
		retornoFindByID=findEmployeeById(list, len, id);
		list[retornoFindByID].isEmpty=1;
		retorno=0;
	}
	return retorno;
}
int HayEmpleadosEnAlta(Employee list[], int len)//Retorna -1 si no hay hay empleados dados de alta o 1 si hay
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order. (Ordena el array de empleados por apellido y sector de manera ascendente o descendente)
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	if(list!=NULL && len>0)
	{
		retorno=0;
		int i;
		int j;
		Employee auxiliar;
		if(order==1)
		{
			for(i=0;i<len;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp( list[i].lastName,list[j].lastName)>0)
					{
						auxiliar= list[i];
						list[i]=list[j];
						list[j]=auxiliar;
					}
					else if(strcmp(list[i].lastName,list[j].lastName)==0)
					{
						if(list[i].sector>list[j].sector)
						{
							auxiliar= list[i];
							list[i]=list[j];
							list[j]=auxiliar;
						}
					}
				}
			}
		}
		else if(order==0)
		{
			for(i=0;i<len;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp( list[i].lastName,list[j].lastName)<0)
					{
						auxiliar= list[i];
						list[i]=list[j];
						list[j]=auxiliar;
					}
					else if(strcmp( list[i].lastName,list[j].lastName)==0)
					{
						if(list[i].sector<list[j].sector)
						{
							auxiliar= list[i];
							list[i]=list[j];
							list[j]=auxiliar;
						}
					}
				}
			}
		}
	}
	return retorno;

}

int OrdenarPorID(Employee list[], int len)
{
	int retorno=-1;
	int i;
	int j;
	Employee aux;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].id>list[j].id)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
			}
		}

		retorno=0;
	}
	return retorno;

}

int ModificarEmployee(Employee list[], int len)
{
	int retorno=-1;
	int retornoOrdenarPorID;
	int retornoPrint;
	int IdToModificar;
	int retornoFindEmployee;
	int opcionAModificar;
	int contadorIntentos=0;
	if(list!=NULL && len>0)
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al empleado. ");
			}
			retornoOrdenarPorID=OrdenarPorID(list, len);
			ValidarRetorno(retornoOrdenarPorID, "Error en la lista de empleados.\n");
			retornoPrint=printEmployees(list, len);
			ValidarRetorno(retornoPrint, "Error en la lista de empleados.\n");
			IdToModificar=PedirOpcionValidandoCaracteres("Ingrese el ID del empleado a modificar", 1, len, "Error. ");
			retornoFindEmployee=findEmployeeById(list, len, IdToModificar);

			contadorIntentos++;
		}while(retornoFindEmployee==-1|| list[retornoFindEmployee].isEmpty==1);
		printf(	"1. Nombre\n"
				"2. Apellido\n"
				"3. Salario\n"
				"4. Sector\n");

		opcionAModificar=PedirOpcionValidandoCaracteres("Ingrese opcion a modificar: ", 1, 4, "Error. ");
		switch(opcionAModificar)
		{
			case 1:
				PedirString("Ingrese el nombre: ", list[retornoFindEmployee].name);
				break;
			case 2:
				PedirString("Ingrese el apellido: ", list[retornoFindEmployee].lastName);
				break;
			case 3:
				list[retornoFindEmployee].salary=PedirFlotantePositivoValidandoCaracteres("Ingrese el salario: ");
				break;
			case 4:
				list[retornoFindEmployee].sector=PedirEnteroValidandoCaracteres("Ingrese el sector: ", "Error. ");
				break;
			retornoPrint=printEmployees(list, len);
		}
		retorno=0;

	}
	return retorno;
}
int BajaEmployee(Employee list[],int len)
{
	int retorno=-1;
	int retornoPrint;
	int retornoOrdenar;
	int idToBaja;
	int retornoRemove;
	int retornoFind;
	int contadorIntentos=0;

	if(list!=NULL && len>0)
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al empleado. ");
			}
		retornoOrdenar=OrdenarPorID(list, len);
		ValidarRetorno(retornoOrdenar, "Error en la lista de empleados.\n");
		retornoPrint=printEmployees(list, len);
		ValidarRetorno(retornoPrint, "Error.\n");
		idToBaja=PedirEnteroPositivoValidandoCaracteres("Ingrese el ID del empleado a dar de baja: \n", "Error. ");
		retornoFind=findEmployeeById(list, len, idToBaja);
		contadorIntentos++;
		}while(retornoFind==-1|| list[retornoFind].isEmpty==1);

		retornoRemove=removeEmployee(list, len, idToBaja);
		ValidarRetorno(retornoRemove, "Error.\n");
		retorno=0;
	}
	return retorno;
}

int PromedioSalarios(Employee list[], int len, float* refSalarioTotal, 	float* refPromedioSalario, int* refSuperanPromedioSalario)
{
	float retorno=-1;
	int i;
	int contadorEmployees=0;
	float totalSalary=0;
	float promedioSalary;
	int superanPromedioSalary=0;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				contadorEmployees++;
				totalSalary+=list[i].salary;
			}
		}
		if(contadorEmployees>0)
		{
			promedioSalary=totalSalary/contadorEmployees;
		}
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0 && list[i].salary>promedioSalary)
			{
				superanPromedioSalary++;
			}
		}
		retorno=0;
	}
	*refSalarioTotal=totalSalary;
	*refPromedioSalario=promedioSalary;
	*refSuperanPromedioSalario=superanPromedioSalary;

	return retorno;
}
void ValidarRetorno(int retorno, char ErrorMensaje[])
{
	if(retorno==-1)
	{
		printf("%s",ErrorMensaje);
	}
}
