/*
 ============================================================================
 Name        : TP2.c
 Author      : Kreczmer Nakasone Ezequiel Yukio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayEmployees.h"
#include "menu.h"
#define len 1000

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	int opcionListados;


	char toAddName[51];
	char toAddLastName[51];
	float toAddSalary;
	int toAddSector;

	int retornoInitEmployees;
	int retornoGenerarId;
	int retornoAdd;
	int IDLibre;
	int retornoPrint;
	int retornoOrderToSort;
	int retornoOrdenarPorID;
	int retornoPromedioSalario;

	float refSalarioTotal;
	float refPromedioSalario;
	int refSuperanPromedioSalario;

	Employee list[len];

	retornoInitEmployees=initEmployees(list, len);
	ValidarRetorno(retornoInitEmployees,"Hubo un error en la lista de empleados\n");

	retornoGenerarId=GenerarId(list, len);
	ValidarRetorno(retornoGenerarId, "Hubo un error en la lista de empleados\n");

	do
	{
		menuEmployees(&opcion);
		switch (opcion)
		{
			case 1:
				retornoOrdenarPorID=OrdenarPorID(list, len);
				ValidarRetorno(retornoOrdenarPorID, "Error en la lista de empleados.\n");
				if(retornoOrdenarPorID!=-1)
				{
					IDLibre=BuscarIdLibre(list, len);
					ValidarRetorno(IDLibre, "No hay espacio libre.\n");
					if(IDLibre!=-1)
					{
						DatosToAddEmployee(toAddName, toAddLastName, &toAddSalary, &toAddSector);
						retornoAdd=addEmployee(list, len, IDLibre, toAddName, toAddLastName, toAddSalary, toAddSector);
						ValidarRetorno(retornoAdd, "Error.\n");
					}
				}
			break;
			case 2:

				if(HayEmpleadosEnAlta(list, len)==-1)
				{
					printf("Primero debe realizar la carga de al menos 1 empleado.\n");
				}
				else
				{
					ModificarEmployee(list, len);
				}

			break;
			case 3:
				if(HayEmpleadosEnAlta(list, len)!=1)
				{
					printf("Primero debe realizar la carga de al menos 1 empleado.\n");
				}
				else
				{
					BajaEmployee(list,len);
				}

			break;
			case 4:
				if(HayEmpleadosEnAlta(list, len)!=1)
				{
					printf("Primero debe realizar la carga de al menos 1 empleado.\n");
				}
				else
				{
					printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
							"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
					opcionListados=PedirOpcionValidandoCaracteres("Ingrese una opcion: ", 1, 2, "Error. ");
					switch (opcionListados)
					{
						case 1:
							retornoOrderToSort=PedirOpcionValidandoCaracteres("Ingrese 1 para mostrar el listado de empleados ordenado por apellido y sector de manera ascendente, o 0 para hacerlo de manera descendente: ", 0, 1, "Error, ingrese 0 o 1. ");
							sortEmployees(list, len, retornoOrderToSort);
							retornoPrint=printEmployees(list, len);
							ValidarRetorno(retornoPrint,"No se encontraron empleados en la lista.\n");
						break;
						case 2:
							retornoPromedioSalario=PromedioSalarios(list, len, &refSalarioTotal, &refPromedioSalario, &refSuperanPromedioSalario);
							ValidarRetorno(retornoPromedioSalario, "Error en la lista.\n");
							if(retornoPromedioSalario!=-1)
							{
								printf("El total de los salarios es: %.2f\n"
										"El promedio de los salarios es: %.2f\n"
										"%d empleados superan el salario promedio\n\n",refSalarioTotal, refPromedioSalario, refSuperanPromedioSalario);
							}

						break;
					}
				}

			break;
		}

	}while(opcion!=5);



	return EXIT_SUCCESS;
}
