/*
 * input.h
 *
 *  Created on: 7 sep. 2021
 *      Author: YUKI
 */

#ifndef INPUT_H_
#define INPUT_H_
/// @brief pide un entero y lo retorna
///
/// @param mensaje para pedir el entero
/// @return entero
int PedirEntero(char[]);

/// @brief valida entero entre minimo y max
///
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @param mensaje
/// @return numero válido
int ValidarEntero(int numeroIngresado, int minimo , int maximo, char mensaje[]);

/// @brief Pide un string
///
/// @param Mensaje a mostrar para pedir el string
/// @param Dirección de memoria del char[] donde se guardará el string
void PedirString (char mensaje[], char stringIngresado []);

/// @brief Pide un flotante y valida si hay algun caracter ingresado o un - en el medio
///
/// @param Mensaje a mostrar para pedir el número
/// @return Numero flotante validado
float PedirFlotanteValidandoCaracteres(char mensaje[]);

/// @brief Pide una opcion y la devuelve validada (valida caracteres y tambien minimo y maximo)
///
/// @param mensaje inicial para que ingrese la opcion
/// @param min	parametro minimo
/// @param max	parametro maximo
/// @param mensajeError	para indicar que hubo un error
/// @return	opcion validada
int PedirOpcionValidandoCaracteres (char mensaje[], int min, int max, char mensajeError[]);



#endif /* INPUT_H_ */
