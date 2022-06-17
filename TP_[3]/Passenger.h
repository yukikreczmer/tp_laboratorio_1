/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];

}Passenger;


//CONSTRUCTORES - DESTRUCTOR
Passenger* Passenger_new(); //para leer desde binario
Passenger* Passenger_newParametros(int id,char* nombre, char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* statusFlight);
void Passenger_delete(Passenger* this);



//SETTERS - GETTERS
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this,char* statusFlight);
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);

int getLastId(char* path, int* id);
//TYPE PASSENGER

void MostrarTypePassenger(void);
int PedirTypePassenger(char* typePassenger);

//STATUS FLIGHT
void MostrarStatusFlight(void);
int PedirStatusFlight(char* statusFlight);




//LISTAR
int Passenger_printOne(Passenger* this);

//FIND
int Passenger_FindIndexById(LinkedList* this, int id, int* index);


//COMPARES
int Passenger_CompareById(void* p1, void* p2);
int Passenger_CompareByName(void* p1, void* p2); //unboxing
int Passenger_CompareByLastName(void* p1, void* p2);
int Passenger_CompareByPrecio(void* p1, void* p2);
int Passenger_CompareByCodigoVuelo(void* p1, void* p2);
int Passenger_CompareByTipoPasajero(void* p1, void* p2);
int Passenger_CompareByStatusFlight(void* p1, void* p2);

//ID
int Id_CreateNew(char* pathArchivoIds);
int Id_GetLast(char* pathArchivoIds);


//MODIFICAR
int Passenger_ModificarNombre(Passenger* this);
int Passenger_ModificarApellido(Passenger* this);
int Passenger_ModificarPrecio(Passenger* this);
int Passenger_ModificarTypePassenger(Passenger* this);
int Passenger_ModificarCodigoVuelo(Passenger* this);



#endif /* PASSENGER_H_ */
