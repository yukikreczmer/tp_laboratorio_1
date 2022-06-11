/*
 * menu.c
 *
 */
#include "menu.h"
#include <stdio.h>
#include "input.h"

void menuPrincipal (int* opcion)
{
	int opcionRetorno;
	printf("-----Menu de opciones-----\n"
			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
			"3. Alta de pasajero\n"
			"4. Modificar datos de pasajero\n"
			"5. Baja de pasajero\n"
			"6. Listar pasajeros\n"
			"7. Ordenar pasajeros\n"
			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n"
			"10. Salir\n");

	opcionRetorno=PedirOpcionValidandoCaracteres("\nIngrese una opcion: ", 1, 10, "Error. ");
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
void subMenuOrdenar(int* opcion)
{
	int opcionRetorno;

	printf("1. Ordenar por Id.\n");
	printf("2. Ordenar por Nombre.\n");
	printf("3. Ordenar por Apellido.\n");
	printf("4. Ordenar por Precio.\n");
	printf("5. Ordenar por Codigo de Vuelo.\n");
	printf("6. Ordenar por Tipo de Pasajero.\n");
	printf("7. Ordenar por Estado de Vuelo.\n");

	opcionRetorno=PedirOpcionValidandoCaracteres("\nIngrese una opcion: ", 1, 7, "Error. En número. ");
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
