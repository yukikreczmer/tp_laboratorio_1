/*
 * ArrayPassenger.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "input.h"
#include "menu.h"

//HARDCODEO
void eTypePassengerHardcode (eTypePassenger list[])
{
	eTypePassenger hardcode[] = {
	    {1, "Primera Clase"},
	    {2, "Clase Ejecutiva o Business"},
	    {3, "Clase Premium Economy"},
	    {4, "Clase Turista o Economica"}
	};

	for (int i = 0; i < 4; i++) {
		list[i] = hardcode[i];
	}
}

void eStatusFlightHardcode(eStatusFlight list[])
{
	eStatusFlight hardcode[] = {
		{1, "ACTIVO"},
		{2, "CANCELADO"},
		{3, "DEMORADO"}
	};

	for (int i = 0; i < 3; i++) {
		list[i] = hardcode[i];
	}
}

void ePassengerHardcode(ePassenger list[])
{
	ePassenger hardcode[] = {
		{1,"Juan","Gimenez",150000,"ABC123",1,1,0},
		{2,"Jose","Perez",140000,"ABD123",2,1,0},
		{3,"Andrea","Del Valle",220000,"ABC124",3,2,0},
		{4,"Julia","Chavez",210000,"ABC124",4,1,0},
		{5,"Juan","Chavez",150000,"ABD124",1,3,0}

	};

	for (int i = 0; i < 5; i++) {
		list[i] = hardcode[i];
	}
}

//INICIALIZACION ISEMPTY
int initPassengers(ePassenger* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=TRUE;
		}
		retorno=0;
	}

	return retorno;
}


//FIND
int findFreePassenger(ePassenger* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty==TRUE)
				{
					retorno=i;
					break;
				}
			}
		}
	return retorno;
}

int findPassengerById(ePassenger* list, int len, int id)
{
	int retorno=-1;
	int i;
	if (list != NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty==FALSE)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}
//MOSTRAR - PRINT
int MostrarTiposPasajeros(eTypePassenger* list, int len)
{
	int retorno=-1;
	int i;
	if(list != NULL && len>0)
	{
		printf("Numero ID:          Descripcion:\n\n");
		for(i=0;i<len;i++)
		{
			printf("%-20d%s\n",list[i].id, list[i].description);
		}
		retorno=0;
	}

	return retorno;
}

int MostrarEstadosVuelos (eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int retorno=-1;
	int i;
	if(listaStatusFlight != NULL && lenStatusFlight >0)
	{
		printf("CODIGO:   ESTADO:\n\n");
		for(i=0;i<lenStatusFlight;i++)
		{
			printf(" %-10d%-20s\n",listaStatusFlight[i].codigo, listaStatusFlight[i].description);
		}

		retorno=0;
	}

	return retorno;
}

void printPassenger(ePassenger unPasajero, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int i, j;
	if(listaTypePassenger != NULL && lenTypePassenger>0)
	{

		for(i=0; i<lenTypePassenger; i++)
		{
			if(listaTypePassenger[i].id == unPasajero.typePassenger)
			{
				for(j=0; j<lenStatusFlight; j++)
				{
					if(listaStatusFlight[j].codigo == unPasajero.statusFlight)
					{
							//ID:   APELLIDO:                       NOMBRE:                         PRECIO:       CODIGO DE VUELO:   TIPO DE PASAJERO:   ESTADO DE VUELO:
						printf("%-6d%-28s%-28s%9.2f     %-20s %-35s %-20s\n",unPasajero.id, unPasajero.lastName, unPasajero.name, unPasajero.price, unPasajero.flyCode, listaTypePassenger[i].description, listaStatusFlight[j].description);
					}
				}
			}
		}
	}
}

int printPassengers(ePassenger* listaPassengers, int lenPassengers, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int retorno=-1;
	int i;
	if(listaPassengers != NULL && lenPassengers>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
	{
		printf("ID:   APELLIDO:                   NOMBRE:                     PRECIO:       CODIGO DE VUELO:     TIPO DE PASAJERO:                   ESTADO DE VUELO:\n\n");
		for(i=0; i<lenPassengers; i++)
		{
			if(listaPassengers[i].isEmpty == FALSE)
			{
				printPassenger(listaPassengers[i], listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
			}
		}
		retorno=0;
	}

	return retorno;
}

//ALTA
int addPassenger(ePassenger* list, int len, int* id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFlight)
{
	int retorno = -1;
	int index;
	index = findFreePassenger(list, len);
	if(list != NULL && len > 0 && index != -1 && id != NULL)
	{
		*id+=1;
		list[index].id=*id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price=price;
		list[index].typePassenger=typePassenger;
		strcpy(list[index].flyCode,flyCode);
		list[index].statusFlight=statusFlight;
		list[index].isEmpty=FALSE;

		retorno=0;
	}

	return retorno;
}


int controllerAddPassenger(ePassenger* list, int len, int* id, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int retorno = -1;
	char name[51];
	char lastName[51];
	float price;
	int typePassenger;
	char flyCode[10];
	int statusFlight;

	if(list != NULL && len > 0 && id != NULL)
	{

		PedirStringPrimeraMayusc("Ingrese el nombre: ", name);
		PedirStringPrimeraMayusc("Ingrese el apellido: ", lastName);
		price=PedirFlotantePositivoValidandoCaracteres("Ingrese el precio del vuelo: ");
		MostrarTiposPasajeros(listaTypePassenger, lenTypePassenger);
		typePassenger=PedirOpcionValidandoCaracteres("Ingrese el Numero ID del tipo de pasajero: ", 1, lenTypePassenger, "Error. ");
		PedirString("Ingrese el codigo del vuelo: ", flyCode);
		strupr(flyCode);
		MostrarEstadosVuelos(listaStatusFlight, lenStatusFlight);
		statusFlight=PedirOpcionValidandoCaracteres("Ingrese el codigo del estado de vuelo: ", 1, lenStatusFlight, "Error. ");

		retorno=addPassenger(list, len, id, name, lastName, price, typePassenger, flyCode, statusFlight);
		if(!retorno)
		{
			printf("La carga de %s, %s ha sido exitosa\n", lastName, name);
		}
		else
		{
			printf("Hubo un problema al intentar dar de alta.\n");
		}
	}

	return retorno;
}

//BAJA
int removePassenger (ePassenger* list, int len, int id)

{
	int retorno=-1;
	int index;

	index=findPassengerById(list, len, id);
	if(index >=0)
	{
		list[index].isEmpty=1;
		retorno=0;
	}

	return retorno;
}
int controllerBaja(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight, int contadorId)
{
	int retorno=-1;
	int contador=0;
	int idABajar;
	int posicionABajar;

	if(list != NULL && len>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
	{
		retorno=printPassengers(list, len, listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
		do{
		if(contador>0)
		{
			printf("Pasajero no encontrado.\n");
		}
		idABajar=PedirOpcionValidandoCaracteres("Ingrese el numero ID del pasajero/a a dar de baja: ", 1, contadorId, "Error. ");
		posicionABajar=findPassengerById(list, len, idABajar);
		contador++;
		}while(posicionABajar<0);
		printf("Se dara de baja al siguiente pasajero:\n");
		printf("ID:   APELLIDO:                   NOMBRE:                     PRECIO:       CODIGO DE VUELO:     TIPO DE PASAJERO:                   ESTADO DE VUELO:\n");
		printPassenger(list[posicionABajar], listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
		if(Confirmar())
		{
			retorno=removePassenger(list, len, idABajar);
		}
		retorno=0;
	}

	return retorno;
}

//MODIFICACION
int ePassengerModificarNombre(ePassenger* list, int len, int idAModificar)
{
	int retorno=-1;
	int posicionAMod;
	char nombreAux[51];
	if(list != NULL && len >0)
	{
		posicionAMod=findPassengerById(list, len, idAModificar);
		if(posicionAMod >= 0)
		{
			PedirStringPrimeraMayusc("Ingrese el nuevo nombre: ", nombreAux);
			printf("Se cambiara el nombre de '%s' por '%s'\n",list[posicionAMod].name, nombreAux);
			if(Confirmar())
			{
				strcpy(list[posicionAMod].name,nombreAux);
			}
		}
		retorno=0;
	}

	return retorno;
}

int ePassengerModificarApellido(ePassenger* list, int len, int idAModificar)
{
	int retorno=-1;
	int posicionAMod;
	char apellidoAux[51];
	if(list != NULL && len >0)
	{
		posicionAMod=findPassengerById(list, len, idAModificar);
		if(posicionAMod >= 0)
		{
			PedirStringPrimeraMayusc("Ingrese el nuevo apellido: ", apellidoAux);
			printf("Se cambiara el apellido de '%s' por '%s'\n",list[posicionAMod].lastName, apellidoAux);
			if(Confirmar())
			{
				strcpy(list[posicionAMod].lastName,apellidoAux);
			}
		}
		retorno=0;
	}

	return retorno;
}

int ePassengerModificarPrecio(ePassenger* list, int len, int idAModificar)
{
	int retorno=-1;
	int posicionAMod;
	float precioAux;
	if(list != NULL && len >0)
	{
		posicionAMod=findPassengerById(list, len, idAModificar);
		if(posicionAMod >= 0)
		{
			precioAux=PedirFlotantePositivoValidandoCaracteres("Ingrese el nuevo precio: ");
			printf("Se cambiara el precio de '%.2f' a %.2f\n",list[posicionAMod].price, precioAux);
			if(Confirmar())
			{
				list[posicionAMod].price=precioAux;
			}
		}
		retorno=0;
	}

	return retorno;
}

int ePassengerModificarTypePassenger(ePassenger* list, int len, int idAModificar, eTypePassenger* listaTypePassenger, int lenTypePassenger)
{
	int retorno=-1;
	int posicionAMod;
	int tipoAux;

	if(list != NULL && len >0)
	{
		posicionAMod=findPassengerById(list, len, idAModificar);
		if(posicionAMod >= 0)
		{
			MostrarTiposPasajeros(listaTypePassenger, lenTypePassenger);
			tipoAux=PedirOpcionValidandoCaracteres("Ingrese el numero ID del nuevo tipo de pasajero: ", 1, lenTypePassenger, "Error. ");

			printf("Se cambiara el tipo de pasajero de %d a %d\n",list[posicionAMod].typePassenger, tipoAux);
			if(Confirmar())
			{
				list[posicionAMod].typePassenger=tipoAux;
			}
		}
		retorno=0;
	}

	return retorno;
}

int ePassengerModificarFlyCode(ePassenger* list, int len, int idAModificar)
{
	int retorno=-1;
	int posicionAMod;
	char codigoAux[10];

	if(list != NULL && len >0)
	{
		posicionAMod=findPassengerById(list, len, idAModificar);
		if(posicionAMod >= 0)
		{
			PedirString("Ingrese el nuevo codigo de vuelo: ", codigoAux);
			strupr(codigoAux);

			printf("Se cambiara el codigo de vuelo de '%s' a %s\n",list[posicionAMod].flyCode, codigoAux);
			if(Confirmar())
			{
				strcpy(list[posicionAMod].flyCode, codigoAux);
			}
		}
		retorno=0;
	}

	return retorno;
}

int controllerModificacion(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight, int contadorId)
{
	int retorno=-1;
	int idAModificar;
	int posicionAMod;
	int opcion;
	int contador=0;
	if(list != NULL && len>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
	{
		retorno=printPassengers(list, len, listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
		do{
		if(contador>0)
		{
			printf("Pasajero no encontrado.\n");
		}
		idAModificar=PedirOpcionValidandoCaracteres("Ingrese el numero ID del pasajero/a a modificar: ", 1, contadorId, "Error. ");
		posicionAMod=findPassengerById(list, len, idAModificar);
		contador++;
		}while(posicionAMod<0);
		subMenuModificar(&opcion);
		switch(opcion)
		{
		case 1:
			retorno=ePassengerModificarNombre(list, len, idAModificar);
		break;
		case 2:
			retorno=ePassengerModificarApellido(list, len, idAModificar);
		break;
		case 3:
			retorno=ePassengerModificarPrecio(list, len, idAModificar);
		break;
		case 4:
			retorno=ePassengerModificarTypePassenger(list, len, idAModificar, listaTypePassenger, lenTypePassenger);
		break;
		case 5:
			retorno=ePassengerModificarFlyCode(list, len, idAModificar);
		break;
		case 6:
		break;
		}

	}

	return retorno;
}

//SORT - ORDENAMIENTO
int sortPassengers(ePassenger* list, int len, int order)
{
	int retorno=-1;
	int i, j;
	ePassenger aux;
	if(list != NULL && len>0)
	{
		switch(order)
		{
		case 0:
			for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
					{
						if(list[i].isEmpty==FALSE && strcmpi(list[i].lastName, list[j].lastName)<0)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
						else
						{
							if(list[i].isEmpty==FALSE && strcmpi(list[i].lastName, list[j].lastName)==0)
							{
								if(list[i].typePassenger<list[j].typePassenger)
								{
									aux=list[i];
									list[i]=list[j];
									list[j]=aux;
								}
							}
						}
					}
			}
		break;
		case 1:
			for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
					{
						if(list[i].isEmpty==FALSE && strcmpi(list[i].lastName, list[j].lastName)>0)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
						else
						{
							if(list[i].isEmpty==FALSE && strcmpi(list[i].lastName, list[j].lastName)==0)
							{
								if(list[i].typePassenger>list[j].typePassenger)
								{
									aux=list[i];
									list[i]=list[j];
									list[j]=aux;
								}
							}
						}
					}
			}

		break;
		}
	}

	return retorno;
}

int sortPassengersByCode(ePassenger* list, int len, int order)

{
	int retorno=-1;
	int i, j;
	ePassenger aux;
	if(list != NULL && len>0)
	{
		switch(order)
		{
		case 0:
			for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
					{
						if(list[i].isEmpty==FALSE && strcmpi(list[i].flyCode, list[j].flyCode)<0)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
						else
						{
							if(list[i].isEmpty==FALSE && strcmpi(list[i].flyCode, list[j].flyCode)==0)
							{
								if(list[i].statusFlight<list[j].statusFlight)
								{
									aux=list[i];
									list[i]=list[j];
									list[j]=aux;
								}
							}
						}
					}
			}
		break;
		case 1:
			for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
					{
						if(list[i].isEmpty==FALSE && strcmpi(list[i].flyCode, list[j].flyCode)>0)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
						else
						{
							if(list[i].isEmpty==FALSE && strcmpi(list[i].flyCode, list[j].flyCode)==0)
							{
								if(list[i].statusFlight>list[j].statusFlight)
								{
									aux=list[i];
									list[i]=list[j];
									list[j]=aux;
								}
							}
						}
					}
			}

		break;
		}
	}

	return retorno;
}

//INFORMES
int InformarAlfabeticamenteApellidoYTipo(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int retorno=-1;
	int order;
	if(list != NULL && len>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
	{
		order=PedirOpcionValidandoCaracteres("Ingrese '1' para ordernar de manera ascendente o '0' para hacerlo de manera descendente: ", 0, 1, "Error. ");
		retorno=sortPassengers(list, len, order);
		retorno=printPassengers(list, len, listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
		retorno=0;
	}

	return retorno;
}



int InformarTotalYPromedioPrecios(ePassenger* list, int len)
{
	int retorno=-1;
	int i;
	float totalPrecios=0;
	int contadorAltas=0;
	float precioPromedio;
	int contadorSuperanPromedio=0;

	if(list != NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				totalPrecios+=list[i].price;
				contadorAltas++;
			}
		}
		precioPromedio=totalPrecios/contadorAltas;

		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price>precioPromedio)
			{
				contadorSuperanPromedio++;
			}
		}
		printf("Total de precios de los pasajes: %.2f\n",totalPrecios);
		printf("Promedio de los precios de los pasajes: %.2f\n",precioPromedio);
		printf("Cantidad de pasajeros que superan el precio promedio: %d\n",contadorSuperanPromedio);

		retorno=0;
	}

	return retorno;
}

int InformarAlfabeticamentePorCodigoYEstadoActivo(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int retorno=-1;
	int order;
	int i;
	if(list != NULL && len>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
	{
		/*3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’  */
		order=PedirOpcionValidandoCaracteres("Ingrese '1' para ordernar de manera ascendente o '0' para hacerlo de manera descendente: ", 0, 1, "Error. ");
		retorno=sortPassengersByCode(list, len, order);

		printf("ID:   APELLIDO:                   NOMBRE:                     PRECIO:       CODIGO DE VUELO:     TIPO DE PASAJERO:                   ESTADO DE VUELO:\n\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].statusFlight ==1 )
			{
				printPassenger(list[i], listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
			}
		}
		retorno=0;
	}

	return retorno;
}

int controllerInformes(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight)
{
	int retorno=-1;
	int opcion;
	if(list != NULL && len>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
	{
		subMenuInformar(&opcion);
		switch(opcion)
		{
			case 1:
				retorno=InformarAlfabeticamenteApellidoYTipo(list, len, listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
			break;
			case 2:
				retorno=InformarTotalYPromedioPrecios(list, len);
			break;
			case 3:
				retorno=InformarAlfabeticamentePorCodigoYEstadoActivo(list, len, listaTypePassenger, lenTypePassenger, listaStatusFlight, lenStatusFlight);
			break;
			retorno=0;

		}
	}

	return retorno;
}


// PARAMETROS FORMALES		ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight
// VALIDACION 				if(list != NULL && len>0 && listaTypePassenger !=NULL && lenTypePassenger >0 && listaStatusFlight != NULL && lenStatusFlight >0)
