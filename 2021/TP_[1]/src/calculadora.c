/*
 * calculadora.c
 *
 *  Created on: 25 sep. 2021
 *      Author: YUKI III THE GREAT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float SumarDosNumeros(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado=primerNumero+segundoNumero;
	return resultado;
}

float RestarDosNumeros(float primeroNumero, float segundoNumero)
{
	float resultado;
	resultado=primeroNumero-segundoNumero;
	return resultado;
}
int DividirDosNumeros(float primerOperando, float segundoOperando, float* refResultado)
{
	int hayCero;
	hayCero=1;// 1 = verdadero = el segundo operando es 0
	if(segundoOperando!=0)
	{
		*refResultado=primerOperando/segundoOperando;
		hayCero=0;
	}

	return hayCero;
}
float MultiplicarDosNumeros(float primerOperando, float segundoOperando)
{
	float resultado;
	resultado=primerOperando*segundoOperando;
	return resultado;
}
int FactorearNumero(float numeroIngresado,int* refResultado)
{
	int retornoValidacionNegativoOFlotante=1; //verdadero, solo lo cambio si compruebo que el numero ingresado es positivo y entero, preguntando una vez
	int auxiliarFactoreo;
	int numeroFactorial=1;
	int i;

	auxiliarFactoreo=numeroIngresado;
	if(numeroIngresado>0 && numeroIngresado-auxiliarFactoreo==0)
	{
		retornoValidacionNegativoOFlotante=0;
		for(i=auxiliarFactoreo;i>0;i--)
			{
				numeroFactorial=numeroFactorial*i;
			}
		*refResultado=numeroFactorial;
	}
	return retornoValidacionNegativoOFlotante;
}
