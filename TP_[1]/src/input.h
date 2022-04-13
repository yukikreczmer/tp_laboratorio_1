/*
 * input.h
 *
 */

#ifndef INPUT_H_
#define INPUT_H_


/// @brief Pide un numero entero al usuario y lo retorna
///
/// @param mensaje Mensaje a mostrar para el ingreso del entero
/// @return entero ingresado
int PedirEntero(char mensaje[]);

/// @brief Pide un numero flotante al usuario y lo retorna
///
/// @param mensaje Mensaje a mostrar para el ingreso del flotante
/// @return flotante ingresado
float PedirFlotante(char mensaje[]);

/// @brief Pide el ingreso de un numero entero validando minimo, maximo y caracteres
///
/// @param mensaje Mensaje a mostrar para el ingreso del entero
/// @param min Minimo
/// @param max Maximo
/// @param mensajeError
/// @return Entero ingresado validado
int PedirEnteroMinMax (char mensaje[], int min, int max, char mensajeError[]);

/// @brief Pide el ingreso de un numero flotante validando minimo, maximo y caracteres
///
/// @param mensaje Mensaje a mostrar para el ingreso del flotante
/// @param min Minimo
/// @param max Maximo
/// @return Flotante ingresado validado
float PedirFlotanteMinMax(char mensaje[], int min, int max);


#endif /* INPUT_H_ */
