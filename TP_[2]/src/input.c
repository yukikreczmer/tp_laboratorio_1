/*
 * input.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int Confirmar(void)
{
	char charIngresado;
	do{
		printf("\n�Confirmar? S/N ");
		fflush(stdin);
		scanf("%c", &charIngresado);
		charIngresado=toupper(charIngresado);
	}while(charIngresado != 'S' && charIngresado != 'N');

	return charIngresado == 'S';
}
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
	stringIngresado[0]='\0';
    printf("%s \n", mensaje);
    fflush(stdin);
    scanf("%[^\n]", stringIngresado);
}

void PedirStringSinDigitos (char mensaje[], char stringIngresado[])
{
	int retornoDigit=1;
	int contadorIntentos=0;
	int i;
	int len;
	char aux[100];
	do
	{
		if(contadorIntentos>0)
		{
			printf("Error, en letras. ");
		}
		PedirString(mensaje, aux);

		len=strlen(aux);
		for(i=0;i<len;i++)
		{
			retornoDigit=isdigit(aux[i]);
			if(retornoDigit==1)
			{
				break;
			}
		}
		contadorIntentos++;
	}while(retornoDigit==1);
	strcpy(stringIngresado,aux);
}

void PedirStringPrimeraMayusc (char mensaje[], char stringIngresado[])
{
	char aux[100];
	int len;
	int i;

	do{
		PedirStringSinDigitos(mensaje, aux);
		len=strlen(aux);
		strlwr(aux);
		aux[0]=toupper(aux[0]);
		for(i=0;i<len;i++)
		{
			if(isspace(aux[i]))
			{
				aux[i+1]=toupper(aux[i+1]);
			}
		}

		strcpy(stringIngresado,aux);
	}while(len==0);
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


		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son n�meros
		{
			retornoValidacionNumero=isdigit(numeroIngresado[i]);
			if(i==0 && numeroIngresado[i]=='-')	//Si el primer caracter es un - tambien lo tomo como v�lido
			{
				retornoValidacionNumero=1;
			}
			if(numeroIngresado[i]== '.')	//Si hay un . para indicar la parte flotante tambien lo tomo como v�lido (incluyendo al inicio: .5 seria 0.5 ;y tambien al final: 5. seria 5.0)
			{
				retornoValidacionNumero=1;
			}
			if(retornoValidacionNumero==0)	//Si encuentra un caso no v�lido romper el for
			{
				break;
			}
		}
		contadorIntentos++;
		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea v�lido pido de nuevo el n�mero

		numeroIngresadoValidado=atof(numeroIngresado);
		return numeroIngresadoValidado;
	}
float PedirFlotantePositivoValidandoCaracteres(char mensaje[])
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


		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son n�meros
		{
			retornoValidacionNumero=isdigit(numeroIngresado[i]);
			if(numeroIngresado[i]== '.')	//Si hay un . para indicar la parte flotante tambien lo tomo como v�lido (incluyendo al inicio: .5 seria 0.5 ;y tambien al final: 5. seria 5.0)
			{
				retornoValidacionNumero=1;
			}
			if(retornoValidacionNumero==0)	//Si encuentra un caso no v�lido romper el for
			{
				break;
			}
		}
		contadorIntentos++;
		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea v�lido pido de nuevo el n�mero

		numeroIngresadoValidado=atof(numeroIngresado);
		return numeroIngresadoValidado;
	}

int PedirOpcionValidandoCaracteres (char mensaje[], int min, int max, char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para v�lido 0 para no v�lido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son n�meros
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if(opcionIngresada[i]=='-')
			{
				retornoValidacionNumero=1;
			}
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

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea v�lido pido de nuevo el n�mero

		return opcionValidada;
}

int PedirEnteroPositivoValidandoCaracteres (char mensaje[], char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para v�lido 0 para no v�lido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son n�meros
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if (retornoValidacionNumero==0)
			{
				break;
			}
		}
		if(retornoValidacionNumero)	//si todos los caracteres son digitos los convierto a entero
		{
			opcionValidada=atoi(opcionIngresada);
		}

		contadorIntentos++;

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea v�lido pido de nuevo el n�mero

		return opcionValidada;
}
int PedirEnteroValidandoCaracteres (char mensaje[], char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para v�lido 0 para no v�lido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son n�meros
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if(opcionIngresada[i]=='-')
			{
				retornoValidacionNumero=1;
			}
			if (retornoValidacionNumero==0)
			{
				break;
			}
		}
		if(retornoValidacionNumero)	//si todos los caracteres son digitos los convierto a entero
		{
			opcionValidada=atoi(opcionIngresada);
		}

		contadorIntentos++;

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea v�lido pido de nuevo el n�mero

		return opcionValidada;
}


