#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "menu.h"
#include "input.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListPassenger, int* flagCargados)
{
	int retorno=-1;
	char path[100];
	FILE* pArchivo;
	if(*flagCargados ==0)
	{
		PedirString("Ingrese el Path del archivo a cargar: ", path);
		pArchivo=fopen(path,"r");

		if(pArchivo != NULL)
		{
			if(pArrayListPassenger != NULL)
			{
				retorno=parser_PassengerFromText(pArchivo, pArrayListPassenger);
				*flagCargados=1;
			}
			if(retorno>0)
			{
				printf("%d pasajeros no pudieron ser cargados correctamente.\n", retorno);
			}
			else
			{
				printf("Pasajeros cargados correctamente.\n");
			}
		}
		else
		{
			printf("Error al intentar abrir el archivo %s.\n",path);
		}

	}
	else
	{
		printf("Los datos del archivo ya fueron cargados. No puede volver a cargarlos.\n");
	}
	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(LinkedList* pArrayListPassenger, int* flagCargados)
{
	int retorno=-1;
	char path[100];
	FILE* pArchivo;
	if(*flagCargados ==0)
	{
		PedirString("Ingrese el Path del archivo a cargar: ", path);
		pArchivo=fopen(path,"rb");

		if(pArchivo != NULL)
		{
			if(pArrayListPassenger != NULL)
			{
				retorno=parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
				*flagCargados=1;
			}
			if(retorno>0)
			{
				printf("%d pasajeros no pudieron ser cargados correctamente.\n", retorno);
			}
			else
			{
				printf("Pasajeros cargados correctamente.\n");
			}
		}
		else
		{
			printf("Error al intentar abrir el archivo %s.\n",path);
		}

	}
	else
	{
		printf("Los datos del archivo ya fueron cargados. No puede volver a cargarlos.\n");
	}
	fclose(pArchivo);

	return retorno;

}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;//int id
	char nombre[50];
	char apellido[50];
	float precio;//float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];
	Passenger* pNewPassenger;
	if(pArrayListPassenger != NULL)
	{
		id=Id_CreateNew("ultimoId.txt");
		PedirStringSinDigitos("Ingrese el nombre del pasajero/a: ", nombre);
		PedirStringSinDigitos("Ingrese el apellido del pasajero/a: ", apellido);
		precio=PedirFlotantePositivoValidandoCaracteres("Ingrese el precio del pasaje: ");
		PedirString("Ingrese el codigo del vuelo: ", codigoVuelo);
		strupr(codigoVuelo);
		MostrarTypePassenger();
		PedirTypePassenger(tipoPasajero);
		MostrarStatusFlight();
		PedirStatusFlight(statusFlight);

		pNewPassenger=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);
		if(pNewPassenger!=NULL)
		{
			ll_add(pArrayListPassenger, pNewPassenger);
			retorno=0;
		}
	}

	//primero passenger_newParametros (lo creo en heap)
	//despues ll_ad lo agrego a la lista
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int lastId;
	int idAModificar;
	int indexAModificar;
	int opcion;
	Passenger* pPassengerAModificar;

	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger))
		{
			printf("Primero debe realizar la carga de algun pasajero/a\n");
		}
		else
		{
			lastId=Id_GetLast("ultimoId.txt");
			if(lastId>0)
			{
				controller_ListPassenger(pArrayListPassenger);
				idAModificar=PedirOpcionValidandoCaracteres("\nIngrese el ID del Pasajero/a a modificar: ", 1, lastId, "Error. ");
				indexAModificar=Passenger_FindIndexById(pArrayListPassenger, idAModificar, &indexAModificar);
				pPassengerAModificar=(Passenger*)ll_get(pArrayListPassenger, indexAModificar);
				printf("El pasajero a modificar es:\n");
				Passenger_printOne(pPassengerAModificar);
				if(Confirmar())
				{
					subMenuModificar(&opcion);
					switch(opcion)
					{
					case 1:
						retorno=Passenger_ModificarNombre(pPassengerAModificar);//ePassengerModificarNombre(list, len, idAModificar);
					break;
					case 2:
						retorno=Passenger_ModificarApellido(pPassengerAModificar);//ePassengerModificarApellido(list, len, idAModificar);
					break;
					case 3:
						retorno=Passenger_ModificarPrecio(pPassengerAModificar);//ePassengerModificarPrecio(list, len, idAModificar);
					break;
					case 4:
						retorno=Passenger_ModificarTypePassenger(pPassengerAModificar);//ePassengerModificarTypePassenger(list, len, idAModificar, listaTypePassenger, lenTypePassenger);
					break;
					case 5:
						retorno=Passenger_ModificarCodigoVuelo(pPassengerAModificar);//ePassengerModificarFlyCode(list, len, idAModificar);
					break;
					case 6:
					break;
					}
				}
			}
		}
	}

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
		int lastId;
		int idABajar;
		int indexABajar;
		Passenger* pPassengerABajar;

		if(pArrayListPassenger != NULL)
		{
			if(ll_isEmpty(pArrayListPassenger))
			{
				printf("Primero debe realizar la carga de algun pasajero/a\n");
			}
			else
			{
				lastId=Id_GetLast("ultimoId.txt");
				if(lastId>0)
				{
					controller_ListPassenger(pArrayListPassenger);
					idABajar=PedirOpcionValidandoCaracteres("\nIngrese el ID del Pasajero/a a dar de baja: ", 1, lastId, "Error. ");
					indexABajar=Passenger_FindIndexById(pArrayListPassenger, idABajar, &indexABajar);
					pPassengerABajar=(Passenger*)ll_get(pArrayListPassenger, indexABajar);
					printf("El pasajero a dar de baja es:\n");
					Passenger_printOne(pPassengerABajar);
					if(Confirmar())
					{
						retorno=ll_remove(pArrayListPassenger, indexABajar);
					}
				}
			}
		}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int len, i;
	Passenger* pAux;

	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger))
		{
			printf("Primero debe realizar la carga de algun/a pasajero/a. \n");
		}
		else
		{
			len=ll_len(pArrayListPassenger);

			printf("ID:     Nombre:              Apellido:                Precio:          Codigo de Vuelo:  Tipo de Pasajero:    Estado de vuelo:\n\n");//precio, codigoVuelo, tipoPasajero, statusFlight)
			for(i=0;i<len;i++)
			{
				pAux=(Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_printOne(pAux);
			}
			retorno=0;
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int orden;
	if(pArrayListPassenger !=NULL)
	{
		retorno=0;
		if(ll_isEmpty(pArrayListPassenger))
		{
			printf("Primero debe realizar la carga de algun/a pasajero/a. \n");
		}
		else
		{
			subMenuOrdenar(&opcion);
			switch(opcion)
			{
			case 1:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareById, orden);
			break;
			case 2:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareByName, orden);
			break;
			case 3:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareByLastName, orden);
			break;
			case 4:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareByPrecio, orden);
			break;
			case 5:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareByCodigoVuelo, orden);
			break;
			case 6:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareByTipoPasajero, orden);
			break;
			case 7:
				orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
				printf("Ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_CompareByStatusFlight, orden);
			break;
			}
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];
	Passenger* pNewPassenger;
	int i;
	int len;
	FILE* pArchivo = fopen(path,"w");

	if(pArrayListPassenger != NULL && pArchivo != NULL)
	{
		len=ll_len(pArrayListPassenger);
		fprintf(pArchivo, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i=0; i<len; i++)
		{
			pNewPassenger= (Passenger*)ll_get(pArrayListPassenger, i);

			Passenger_getId(pNewPassenger, &id);
			Passenger_getNombre(pNewPassenger, nombre);
			Passenger_getApellido(pNewPassenger, apellido);
			Passenger_getPrecio(pNewPassenger, &precio);
			Passenger_getCodigoVuelo(pNewPassenger, codigoVuelo);
			Passenger_getTipoPasajero(pNewPassenger, tipoPasajero);
			Passenger_getStatusFlight(pNewPassenger, statusFlight);

			fprintf(pArchivo,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);

		}
		fclose(pArchivo);
		retorno=0;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pNewPassenger;
	int i;
	int len;
	FILE* pArchivo = fopen(path,"wb");

	if(pArrayListPassenger != NULL && pArchivo != NULL)
	{
		len=ll_len(pArrayListPassenger);
		for(i=0; i<len; i++)
		{
			pNewPassenger= (Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(pNewPassenger,sizeof(Passenger),1,pArchivo);
		}
		retorno=0;
	}

    return retorno;
}

