/*
 * menu.c
 *
 *  Created on: 16 oct. 2021
 *      Author: YUKI III THE GREAT
 */
#include "menu.h"
#include <stdio.h>
#include "input.h"

void menuEmployees (int* opcion)
{
	int opcionRetorno;
	printf("-----Menu de opciones-----\n"
			"1. ALTAS\n"
			"2. MODIFICAR\n"
			"3. BAJA\n"
			"4. INFORMAR:\n"
			"5. SALIR.");
	opcionRetorno=PedirOpcionValidandoCaracteres("\nIngrese una opcion: ", 1, 5, "Error. ");
	*opcion=opcionRetorno;
}
