/*
 * input.c
 *
 *  Created on: 7 sep. 2021
 *      Author: YUKI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int PedirEntero(char mensaje[])
{
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d",&numeroIngresado);

	return numeroIngresado;
}

int ValidarEntero(int numeroIngresado, int minimo , int maximo, char mensaje[])
{
	while (numeroIngresado<minimo || numeroIngresado>maximo)
		{
			printf("%s", mensaje);
			scanf("%d",&numeroIngresado);
		}
	return numeroIngresado;
}
void PedirString (char mensaje[], char stringIngresado[])
{
    printf("%s \n", mensaje);
    fflush(stdin);
    scanf("%[^\n]", stringIngresado);
}

float PedirFlotanteValidandoCaracteres(char mensaje[])
	{

	char numeroIngresado[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero;
	float numeroIngresadoValidado;
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("Error. ");
		}
		PedirString(mensaje,numeroIngresado);

		retornoExtension=strlen(numeroIngresado);


		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(numeroIngresado[i]);
			if(i==0 && numeroIngresado[i]=='-')	//Si el primer caracter es un - tambien lo tomo como válido
			{
				retornoValidacionNumero=1;
			}
			if(numeroIngresado[i]== '.')	//Si hay un . para indicar la parte flotante tambien lo tomo como válido (incluyendo al inicio: .5 seria 0.5 ;y tambien al final: 5. seria 5.0)
			{
				retornoValidacionNumero=1;
			}
			if(retornoValidacionNumero==0)	//Si encuentra un caso no válido romper el for
			{
				break;
			}
		}
		contadorIntentos++;
		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		numeroIngresadoValidado=atof(numeroIngresado);
		return numeroIngresadoValidado;
	}

int PedirOpcionValidandoCaracteres (char mensaje[], int min, int max, char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para válido 0 para no válido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if (retornoValidacionNumero==0)
			{
				break;
			}
		}
		if(retornoValidacionNumero)	//si todos los caracteres son digitos los convierto a entero y valido con max y minimo
		{
			opcionValidada=atoi(opcionIngresada);
			if(opcionValidada<min || opcionValidada>max)
			{
				retornoValidacionNumero=0;
			}
		}

		contadorIntentos++;

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		return opcionValidada;
}



