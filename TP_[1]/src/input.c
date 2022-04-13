/*
 * input.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int PedirEntero(char mensaje[])
{
	int retorno;
	printf("%s",mensaje);
	scanf("%d",&retorno);

	return retorno;
}

float PedirFlotante(char mensaje[])
{
	float retorno;
	printf("%s", mensaje);
	scanf("%f", &retorno);

	return retorno;
}

void PedirString (char mensaje[], char stringIngresado[])
{
    printf("%s \n", mensaje);
    fflush(stdin);
    scanf("%[^\n]", stringIngresado);
}

int PedirEnteroMinMax (char mensaje[], int min, int max, char mensajeError[])
{
	int numeroValidado;
	char numeroIngresado[100];
	int retornoExtension;
	int i;
	int rtnIsDigit; // 1 para válido 0 para no válido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,numeroIngresado);

		retornoExtension=strlen(numeroIngresado);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			rtnIsDigit=isdigit(numeroIngresado[i]);
			if (rtnIsDigit==0)
			{
				break;
			}
		}
		if(rtnIsDigit)	//si todos los caracteres son digitos los convierto a entero y valido con max y minimo
		{
			numeroValidado=atoi(numeroIngresado);
			if(numeroValidado<min || numeroValidado>max)
			{
				rtnIsDigit=0;
			}
		}

		contadorIntentos++;

		}while(rtnIsDigit==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		return numeroValidado;
}

float PedirFlotanteMinMax(char mensaje[], int min, int max)
	{

	char numeroIngresado[100];
	int rtnLen;
	int i;
	int rtnIsDigit;
	float floatValidado;
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("Error. ");
		}
		PedirString(mensaje,numeroIngresado);

		rtnLen=strlen(numeroIngresado);

		for(i=0;i<rtnLen;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			rtnIsDigit=isdigit(numeroIngresado[i]);
			if(numeroIngresado[i]== '.')	//Si hay un . para indicar la parte flotante tambien lo tomo como válido (incluyendo al inicio: .5 seria 0.5 ;y tambien al final: 5. seria 5.0)
			{
				rtnIsDigit=1;
			}

			if(rtnIsDigit==0)	//Si encuentra un caso no válido romper el for
			{
				break;
			}
		}
		if(rtnIsDigit)
		{
			floatValidado=atof(numeroIngresado);
			if(floatValidado < min || floatValidado > max)
			{
				rtnIsDigit=0;
			}
		}
		contadorIntentos++;
		}while(rtnIsDigit==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		return floatValidado;
	}
