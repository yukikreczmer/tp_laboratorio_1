#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagCargados=0;
    int retorno;
    LinkedList* listaPasajeros = ll_newLinkedList();

    Passenger* pNewPassenger;



    pNewPassenger=Passenger_newParametros(1, "roberto", "juarez", 154, "BA2491A","Econnomy", "aterrizado");
    ll_add(listaPasajeros, pNewPassenger);

    do{
    	menuPrincipal(&option);
        switch(option)
        {
            case 1:
                retorno=controller_loadFromText(listaPasajeros, &flagCargados);// "data.csv" desde  "..//data.csv"desde el .exe
                break;
            case 2:
            	retorno=controller_loadFromBinary(listaPasajeros, &flagCargados);
                break;
            case 3:
            	retorno=controller_addPassenger(listaPasajeros);
                break;
            case 4:
            	retorno=controller_editPassenger(listaPasajeros);
                break;
            case 5:
                retorno=controller_removePassenger(listaPasajeros);
                break;
            case 6:
                retorno=controller_ListPassenger(listaPasajeros);
                break;
            case 7:
            	retorno=controller_sortPassenger(listaPasajeros);
                break;
            case 8:
            	retorno=controller_saveAsText("data.csv", listaPasajeros);
                break;
            case 9:
            	retorno=controller_saveAsBinary("data.bin", listaPasajeros);
                break;
            case 10:
            	retorno=controller_saveAsText("data2.csv", listaPasajeros);
            	retorno=controller_saveAsBinary("data2.bin", listaPasajeros);
            	option=11;
        }
    }while(option != 11);

    return 0;
}

