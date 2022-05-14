/*
 * ArrayPassenger.h
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TRUE 1
#define FALSE 0

//ESTRUCTURAS
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

typedef struct{
	int id;
	char description[51];
}eTypePassenger;

typedef struct{
	int codigo;
	char description[51];
}eStatusFlight;

//HARDCODE
/// @brief Hardcodea una lista de tipos de pasajeros para determinar y relacionar un codigo ID para cada tipo de pasajero
///
/// @param lista de tipo de pasajeros
void eTypePassengerHardcode (eTypePassenger list[]);

/// @brief Hardcodea una lista de estados de vuelo para determinar y relacionar un codigo ID para cada estado de vuelo
///
/// @param lista de estados de vuelo
void eStatusFlightHardcode(eStatusFlight list[]);

/// @brief Hardcodea (Carga forzada) una lista de pasajeros con 5 pasajeros y sus diferentes caracteristicas de vuelo
///
/// @param lista de pasajeros
void ePassengerHardcode(ePassenger list[]);

//INICIALIZACION

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */
int initPassengers(ePassenger* list, int len);

//FIND

/// @brief Encuentra un pasajero libre (isEmpty==TRUE) en el array de lista de pasajeros
///
/// @param lista de pasajeros
/// @param len int array length
/// @return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received
int findFreePassenger(ePassenger* list, int len);

///@brief find a Passenger by Id en returns the index position in array.
///@param list Passenger*
///@param len int
///@param id int
///@return Return passenger index position or (-1) if [Invalid length or
///NULL pointer received or passenger not found]
int findPassengerById(ePassenger* list, int len, int id);

//MOSTRAR
/// @brief Muestra los numeros de id y descripciones de la lista de tipos de pasajeros
///
/// @return -1 si el puntero a la lista (array) de tipos de pasajeros es nula o len invalido. 0 si esta ok.
int MostrarTiposPasajeros();

/// @brief Muestra los numeros de id y descripciones de la lista de estados de vuelo
///
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @return -1 si el puntero a la lista (array) de estados de vuelo es nula o len invalido. 0 si esta ok.
int MostrarEstadosVuelos (eStatusFlight* listaStatusFlight, int lenStatusFlight);

/// @brief Imprime un pasajero con sus caracteristicas
///
/// @param unPasajero
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
void printPassenger(ePassenger unPasajero, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight);

/// @brief  Imprime a los pasajeros de la lista (array)
///
/// @param listaPassengers
/// @param lenPassengers
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int printPassengers(ePassenger* listaPassengers, int lenPassengers, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight);


//ALTA
/// @brief  Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer posición libre.
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flyCode
/// @param statusFlight
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addPassenger(ePassenger* list, int len, int* id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFlight);

/// @brief Pide los valores para agregar a un nuevo pasajero en la primer posicion libre
///
/// @param list
/// @param len
/// @param id
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int controllerAddPassenger(ePassenger* list, int len, int* id, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight);

//BAJA

/// @brief  Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
///
/// @param list
/// @param len
/// @param id
/// @return return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int removePassenger (ePassenger* list, int len, int id);

/// @brief Imprime una lista de pasajeros dados de alta en la lista. Se pide el ingreso de un id para dar de baja y se lo pasa a la funcion remove para darle la baja logica
///
/// @param list
/// @param len
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @param contadorId
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int controllerBaja(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight, int contadorId);


//MODIFICAR
/// @brief Modifica el nombre de un pasajero recibiendo como parámetro su Id
///
/// @param list
/// @param len
/// @param idAModificar
/// @return -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int ePassengerModificarNombre(ePassenger* list, int len, int idAModificar);

/// @brief Modifica el apellido de un pasajero recibiendo como parámetro su Id
///
/// @param list
/// @param len
/// @param idAModificar
/// @return -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int ePassengerModificarApellido(ePassenger* list, int len, int idAModificar);

/// @brief Modifica el Precio de un vuelo de un pasajero recibiendo como parámetro su Id
///
/// @param list
/// @param len
/// @param idAModificar
/// @return  -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int ePassengerModificarPrecio(ePassenger* list, int len, int idAModificar);

/// @brief Modifica el tipo de pasajero de un pasajero recibiendo como parámetro su Id
///
/// @param list
/// @param len
/// @param idAModificar
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @return  -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int ePassengerModificarTypePassenger(ePassenger* list, int len, int idAModificar, eTypePassenger* listaTypePassenger, int lenTypePassenger);

/// @brief Modifica el codigo de vuelo de un pasajero recibiendo como parámetro su Id
///
/// @param list
/// @param len
/// @param idAModificar
/// @return  -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int ePassengerModificarFlyCode(ePassenger* list, int len, int idAModificar);

/// @brief Lista los pasajeros dados de alta y muestra un menu para seleccionar el campo a modificar de un pasajero
///
/// @param list
/// @param len
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @param contadorId
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int controllerModificacion(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight, int contadorId);

//SORT
/// @brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
///
/// @param list
/// @param len
/// @param order
/// @return  -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int sortPassengers(ePassenger* list, int len, int order);

/// @brief  Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
///
/// @param list
/// @param len
/// @param order
/// @return  -1 si puntero al array de lista es NULL o len invalido. 0 si esta ok
int sortPassengersByCode(ePassenger* list, int len, int order);

//INFORMAR

/// @brief  Muestra los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
///
/// @param list
/// @param len
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int InformarAlfabeticamenteApellidoYTipo(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight);

/// @brief Muestra total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio
///
/// @param list
/// @param len
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int InformarTotalYPromedioPrecios(ePassenger* list, int len);

/// @brief Muestra listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
///
/// @param list
/// @param len
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int InformarAlfabeticamentePorCodigoYEstadoActivo(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight);

/// @brief  Despliega un submenu para elegir opcion a informar, una vez elegida la opcion llama a la funcion indicada para que lo realice
///
/// @param list
/// @param len
/// @param listaTypePassenger
/// @param lenTypePassenger
/// @param listaStatusFlight
/// @param lenStatusFlight
/// @return -1 si algun puntero a alguna lista(array) es NULL o algun len invalido. 0 si esta ok
int controllerInformes(ePassenger* list, int len, eTypePassenger* listaTypePassenger, int lenTypePassenger, eStatusFlight* listaStatusFlight, int lenStatusFlight);







#endif /* ARRAYPASSENGER_H_ */
