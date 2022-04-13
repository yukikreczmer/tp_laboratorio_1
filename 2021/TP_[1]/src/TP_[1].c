/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Kreczmer Nakasone Ezequiel Yukio
 Version     :
 Copyright   : Your copyright notice
 Description : 	TP1
	Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
	1. Ingresar 1er operando (A=x)
	2. Ingresar 2do operando (B=y)
	3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
	4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "calculadora.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;

	float primerOperando;
	float segundoOperando;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;

	int hayCero;
	int flagPrimerOperando;
	int flagSegundoOperando;
	int flagTerceraOpcion;

	hayCero=0;
	flagPrimerOperando=0;
	flagSegundoOperando=0;
	flagTerceraOpcion=0;

	int retornoValidacionFactorialPrimero;
	int retornoValidacionFactorialSegundo;
	int resultadoFactorialPrimero;
	int resultadoFactorialSegundo;


	printf("--BIENVENIDO/A A LA CALCULADORA--\n\n");
	do
	{
		printf("--------MENU DE OPCIONES--------\n");
		if(flagPrimerOperando==0)
		{
			printf("1. Ingresar primer operando (A=x)\n");
		}
		else
		{
			printf("1. Ingresar primer operando (A=%.2f)\n",primerOperando);
		}
		if(flagSegundoOperando==0)
		{
			printf("2. Ingresar segundo operando (B=y)\n");
		}
		else
		{
			printf("2. Ingresar segundo operando (B=%.2f)\n",segundoOperando);
		}
		printf("3. Calcular todas las operaciones:\n"
				"	a) Calcular la suma (A+B)\n"
				"	b) Calcular la resta (A-B)\n"
				"	c) Calcular la division (A/B)\n"
				"	d) Calcular la multiplicacion (A*B)\n"
				"	e) Calcular el factorial (A!) y (B!)\n");
		printf("4. Ver resultados\n");
		printf("5. Salir\n");
		opcion=PedirOpcionValidandoCaracteres ("Ingrese una opcion: ", 0, 5,"Error. ");

		switch(opcion)
		{
			case 1:
				primerOperando=PedirFlotanteValidandoCaracteres("Primer operando: \n");
				flagPrimerOperando=1;
			break;
			case 2:
				segundoOperando=PedirFlotanteValidandoCaracteres("Segundo operando: \n");
				flagSegundoOperando=1;
			break;
			case 3:
				if(flagPrimerOperando==0 || flagSegundoOperando==0)
				{
					printf("Primero debe ingresar los 2 operandos (A y B)\n\n");
				}
				else
				{
					resultadoSuma=SumarDosNumeros(primerOperando, segundoOperando);
					resultadoResta=RestarDosNumeros(primerOperando, segundoOperando);
					hayCero=DividirDosNumeros(primerOperando, segundoOperando, &resultadoDivision);
					resultadoMultiplicacion=MultiplicarDosNumeros(primerOperando, segundoOperando);
					retornoValidacionFactorialPrimero=FactorearNumero(primerOperando, &resultadoFactorialPrimero);
					retornoValidacionFactorialSegundo=FactorearNumero(segundoOperando, &resultadoFactorialSegundo);
					flagTerceraOpcion=1;
				}
			break;
			case 4:

				if(flagPrimerOperando==0 || flagSegundoOperando==0)
				{
					printf("Primero debe ingresar los 2 operandos (A y B)\n\n");
				}
				else if(flagTerceraOpcion==0)
				{
					printf("Antes de mostrar los resultados se deben realizar todas las operaciones marcando la opcion 3\n\n");
				}
				else
				{
					printf("\nEl resultado de A+B es: %.2f\n",resultadoSuma);
					printf("El resultado de A-B es: %.2f\n", resultadoResta);
					if(hayCero==0)
					{
						printf("El resultado de A/B es: %.2f\n", resultadoDivision);
					}
					else
					{
						printf("No es posible dividir por cero\n");
					}
					printf("El resultado de A*B es %.2f\n", resultadoMultiplicacion);

					if(retornoValidacionFactorialPrimero==0)
					{
						printf("El factorial de A es: %d y ",resultadoFactorialPrimero);
					}
					else
					{
						printf("No es posible factorear un número negativo o decimal (A) y ");
					}
					if(retornoValidacionFactorialSegundo==0)
					{
						printf("el factorial de B es: %d\n\n",resultadoFactorialSegundo);
					}
					else
					{
						printf("no es posible factorear un número negativo o decimal (B)\n\n");
					}

				}


			break;
		}

	}while(opcion!=5);



	return EXIT_SUCCESS;
}
