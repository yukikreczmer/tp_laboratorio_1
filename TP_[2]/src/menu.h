/*
 * menu.h
 *
 *  Created on: 16 oct. 2021
 *      Author: YUKI III THE GREAT
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief Despliega el menu principal
///
/// @param opcion
void menuVuelos (int* opcion);
/// @brief despliega el menu de opciones a modificar
///
/// @param opcion
void subMenuModificar(int* opcion);
/// @brief despliega el menu de opciones a informar
///
/// @param opcion
void subMenuInformar(int* opcion);

#endif /* MENU_H_ */
