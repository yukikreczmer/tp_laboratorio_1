/*
 * menu.c
 *
 */
#include "menu.h"
#include <stdio.h>
#include "input.h"

void menuVuelos (int* opcion)
{
	int opcionRetorno;
	printf("-----Menu de opciones-----\n"
			"1. ALTAS\n"
			"2. MODIFICAR\n"
			"3. BAJA\n"
			"4. INFORMAR:\n"
			"5. ALTA FORZADA DE PASAJEROS.\n"
			"6. SALIR.");
	opcionRetorno=PedirOpcionValidandoCaracteres("\nIngrese una opcion: ", 1, 6, "Error. ");
	*opcion=opcionRetorno;
}
void subMenuModificar(int* opcion)
{
	int opcionRetorno;
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Precio\n");
	printf("4. Tipo de pasajero\n");
	printf("5. Codigo de vuelo\n");
	printf("6. Cancelar\n");

	opcionRetorno=PedirOpcionValidandoCaracteres("\nIngrese una opcion a modificar: ", 1, 6, "Error. ");
	*opcion = opcionRetorno;
}

void subMenuInformar(int* opcion)
{
	int opcionRetorno;

	printf("1. Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de Pasajero.\n");
	printf("2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
	printf("3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n");


	opcionRetorno=PedirOpcionValidandoCaracteres("\nIngrese una opcion: ", 1, 3, "Error. ");
	*opcion = opcionRetorno;
}
