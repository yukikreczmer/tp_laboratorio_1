/*
 ============================================================================
 Name        : TP_2.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "menu.h"

#define len 10

int main(void) {

	setbuf(stdout, NULL);

	int contadorId=0;
	int contadorAltas=0;

	int lenTypePassenger=4;
	int lenStatusFlight=3;

	int opcion;
	int retorno;
	ePassenger list[len];
	eTypePassenger listaTypes[lenTypePassenger];
	eStatusFlight listaStatusFlight[lenStatusFlight];

	retorno=initPassengers(list, len);

	eTypePassengerHardcode(listaTypes);
	eStatusFlightHardcode(listaStatusFlight);

		if(retorno)
		{
			printf("Error al inicializar la lista de pasajeros.\n");
		}
	do{
		menuVuelos(&opcion);

		switch (opcion)
		{
		case 1://ALTA
			if(findFreePassenger(list, len) != -1)
			{
				retorno=controllerAddPassenger(list, len, &contadorId, listaTypes, lenTypePassenger, listaStatusFlight, lenStatusFlight);
				contadorAltas++;
			}
			else
			{
				printf("No hay espacio disponible en la lista.\n");
			}
		break;
		case 2:
			if(contadorAltas<=0)
			{
				printf("Primero se debe realizar la carga de al menos un pasajero.\n");
			}
			else
			{
				retorno=controllerModificacion(list, len, listaTypes, lenTypePassenger, listaStatusFlight, lenStatusFlight, contadorId);
			}
		break;
		case 3:
			if(contadorAltas<=0)
			{
				printf("Primero se debe realizar la carga de al menos un pasajero.\n");
			}
			else
			{
				retorno=controllerBaja(list, len, listaTypes, lenTypePassenger, listaStatusFlight, lenStatusFlight, contadorId);
				contadorAltas--;
			}
		break;
		case 4:
			if(contadorAltas<=0)
			{
				printf("Primero se debe realizar la carga de al menos un pasajero.\n");
			}
			else
			{
				retorno=controllerInformes(list, len, listaTypes, lenTypePassenger, listaStatusFlight, lenStatusFlight);
			}
		break;
		case 5:
			retorno=initPassengers(list, len);
			ePassengerHardcode(list);
			contadorId=5;
			contadorAltas=5;
		}

	}while(opcion!=6);
		return EXIT_SUCCESS;
}
