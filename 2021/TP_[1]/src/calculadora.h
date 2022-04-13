/*
 * calculadora.h
 *
 *  Created on: 25 sep. 2021
 *      Author: YUKI III THE GREAT
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_


/// @brief Suma 2 números flotantes
///
/// @param Operando 1
/// @param Operando 2
/// @return Resultado de la suma
float SumarDosNumeros(float, float);

/// @brief Resta 2 números flotantes
///
/// @param Operando 1
/// @param Operando 2
/// @return Resultado de la resta
float RestarDosNumeros(float, float);

/// @brief Divide 2 numeros flotantes si el segundo operando es diferente a cero
///
/// @param	Operando 1
/// @param	Operando 2
/// @param	Direccion de memoria del resultado de la division
/// @return	1 o 0. 1 si el Operando 2 es 0. 0 si el Operando 2 no es 0 (true o false)
int DividirDosNumeros(float, float, float*);

/// @brief	Multiplica 2 números flotantes
///
/// @param Operando 1
/// @param Operando 2
/// @return	Resultado de la multiplicación
float MultiplicarDosNumeros(float, float);

/// @brief Factorea 1 número pasado como flotante, solo si es positivo y no tiene parte flotante
///
/// @param Operando
/// @param Dirección de memoria del resultado del factorial (entero)
/// @return	1 o 0. 1 si el Operando es (Negativo o flotante). 0 si es entero positivo (true o false)
int FactorearNumero(float,int*);

#endif /* CALCULADORA_H_ */
