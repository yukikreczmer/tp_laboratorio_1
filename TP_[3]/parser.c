#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int pasajerosNoCargados=0;
	Passenger* pAux;
	char id[5];//int id
	char nombre[50];
	char apellido[50];
	char precio[10];//float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);
			pAux=Passenger_newParametros(atoi(id), nombre, apellido, atof(precio), codigoVuelo, tipoPasajero, statusFlight);
			if(pAux!=NULL)
			{
				ll_add(pArrayListPassenger, pAux);
			}
			else
			{
				pasajerosNoCargados++;
			}
		}
	}

    return pasajerosNoCargados;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int pasajerosNoCargados=0;
	Passenger* pAux;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			pAux=Passenger_new();
			if(pAux != NULL)
			{
				if(fread(pAux, sizeof(Passenger),1,pFile) == 1)
				{
					ll_add(pArrayListPassenger, pAux);
				}
			}
		}

	}



    return pasajerosNoCargados;
}

int parser_UltimoId(FILE* pFile)
{
	int retorno=-1;

	if(pFile != NULL)
	{

	}

	return retorno;
}



