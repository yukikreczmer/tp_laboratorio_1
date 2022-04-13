/*
 ============================================================================
 Name        : TP_1.c
	Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
	para ofrecerlos a sus clientes.
	Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
	El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "operaciones.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;

	//Datos Ingresados
	float kilometrosIn=0;
	float precioInAero;
	float precioInLatam;

	//Flags
	int flagKilometros=0;
	int flagPrecios=0;
	int flagCalcular=0;

	//Descuentos e intereses
	int descuentoDebito=10;
	int interesCredito=25;
	double precioBTC=4606954.55; //4771394.27;

	//Costos finales calculados Aerolineas Argentinas
	float costoDebitoAero;
	float costoCreditoAero;
	float costoBTCAero;
	float precioUnitarioAero;

	//Costos finales calculados Latam
	float costoDebitoLatam;
	float costoCreditoLatam;
	float costoBTCLatam;
	float precioUnitarioLatam;
	//
	float diferenciaPreciosIngresados;

	do{
		printf("\n--------MENU DE OPCIONES--------\n");
		//OPCION 1
		if(flagKilometros == 0)
		{
			printf("1. Ingresar Kil%cmetros: (km = x)\n",162);
		}
		else
		{
			printf("1. Ingresar Kil%cmetros: (km = %.2f)\n",162,kilometrosIn);
		}
		//OPCION 2
		if(flagPrecios == 0)
		{
			printf("2. Ingresar Precio de Vuelos: (Aerolineas = y, Latam = z)\n");
		}
		else
		{
			printf("2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)\n", precioInAero, precioInLatam);
		}
		//OPCION 3
		printf("3. Calcular todos los costos: \n");
		printf("\ta) Tarjeta de d%cbito (descuento %d%c)\n",130,descuentoDebito,37);
		printf("\tb) Tarjeta de cr%cdito (inter%cs %d%c)\n",130,130,interesCredito,37);
		printf("\tc) Bitcoin (1 BTC -> %.2lf)\n",precioBTC);
		printf("\td) Precio por km (precio unitario)\n");
		printf("\te) Diferencia de precio ingresada (Latam - Aerolineas)\n");
		//OPCION 4
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");

		opcion=PedirEnteroMinMax("\nIngrese una opcion entre 1 y 6: ", 1, 6, "Error. ");

		switch(opcion)
		{
		case 1:
			kilometrosIn=PedirFlotanteMinMax("Cantidad de Kilometros: ", 1, 50000);
			flagKilometros=1;
		break;
		case 2:
			precioInAero=PedirFlotanteMinMax("Ingrese el precio del vuelo en Aerolineas: ", 1, 2000000);
			precioInLatam=PedirFlotanteMinMax("Ingrese el precio del vuelo en Latam: ", 1, 2000000);
			flagPrecios=1;
		break;
		case 3:
			if(flagKilometros == 0 || flagPrecios == 0)
			{
				printf("\nPara realizar los c%clculos es necesario cargar los kil%cmetros (Opcion 1) y precios del vuelo en ambas aerolineas (Opcion 2).\n\n",160,162);
			}
			else
			{
				//Opcion 3.
				//Calcular: Aero
				costoDebitoAero=AplicarDescuento(descuentoDebito, precioInAero);
				costoCreditoAero=AplicarInteres(interesCredito, precioInAero);
				costoBTCAero=ConvertirPrecio(precioBTC, precioInAero);
				precioUnitarioAero=CalcularPrecioUnitario(precioInAero, kilometrosIn);
				//Calcular: Latam
				costoDebitoLatam=AplicarDescuento(descuentoDebito, precioInLatam);
				costoCreditoLatam=AplicarInteres(interesCredito, precioInLatam);
				costoBTCLatam=ConvertirPrecio(precioBTC, precioInLatam);
				precioUnitarioLatam=CalcularPrecioUnitario(precioInLatam, kilometrosIn);

				diferenciaPreciosIngresados=precioInLatam-precioInAero;

				flagCalcular=1;
			}
		break;
		case 4:
			if(!flagCalcular)
			{
				printf("\nPrimero deben Realizarse los c%clculos para luego informarlos.\n",160);
			}
			else
			{
				printf("\nPrecio Latam: %.2f\n",precioInLatam);
				printf("a) Precio con tarjeta de d%cbito: %.2f\n",130,costoDebitoLatam);
				printf("b) Precio con tarjeta de cr%cdito: %.2f\n",130, costoCreditoLatam);
				printf("c) Precio pagando con Bitcoin: %.6f\n", costoBTCLatam);
				printf("d) Precio unitario: %.2f\n", precioUnitarioLatam);
				printf("\nPrecio Aerolineas: %.2f\n", precioInAero);
				printf("a) Precio con tarjeta de d%cbito: %.2f\n",130,costoDebitoAero);
				printf("b) Precio con tarjeta de cr%cdito: %.2f\n",130, costoCreditoAero);
				printf("c) Precio pagando con Bitcoin: %.6f\n", costoBTCAero);
				printf("d) Precio unitario: %.2f\n", precioUnitarioAero);
				if(diferenciaPreciosIngresados<0)
				{
					diferenciaPreciosIngresados=diferenciaPreciosIngresados*-1;
					printf("\nLa diferencia de precio es: %.2f. Teniendo Latam un precio menor.\n", diferenciaPreciosIngresados);
				}
				else
				{
					if(diferenciaPreciosIngresados>0)
					{
						printf("\nLa diferencia de precio es: %.2f. Teniendo Aerolineas Argentinas un precio menor.\n", diferenciaPreciosIngresados);
					}
					else
					{
						printf("\nLa diferencia de precio es: %.2f\n", diferenciaPreciosIngresados);
					}
				}
			}
		break;
		case 5:
			kilometrosIn=7090;
			precioInAero=162965;
			precioInLatam=159339;
			//Calcular: Aero
			costoDebitoAero=AplicarDescuento(descuentoDebito, precioInAero);
			costoCreditoAero=AplicarInteres(interesCredito, precioInAero);
			costoBTCAero=ConvertirPrecio(precioBTC, precioInAero);
			precioUnitarioAero=CalcularPrecioUnitario(precioInAero, kilometrosIn);
			//Calcular: Latam
			costoDebitoLatam=AplicarDescuento(descuentoDebito, precioInLatam);
			costoCreditoLatam=AplicarInteres(interesCredito, precioInLatam);
			costoBTCLatam=ConvertirPrecio(precioBTC, precioInLatam);
			precioUnitarioLatam=CalcularPrecioUnitario(precioInLatam, kilometrosIn);

			diferenciaPreciosIngresados=precioInLatam-precioInAero;

			printf("\nPrecio Aerolineas: %.2f\n", precioInAero);
			printf("a) Precio con tarjeta de d%cbito: %.2f\n", 130, costoDebitoAero);
			printf("b) Precio con tarjeta de cr%cdito: %.2f\n", 130, costoCreditoAero);
			printf("c) Precio pagando con Bitcoin: %.6f\n", costoBTCAero);
			printf("d) Precio unitario: %.2f\n", precioUnitarioAero);
			printf("\nPrecio Latam: %.2f\n",precioInLatam);
			printf("a) Precio con tarjeta de d%cbito: %.2f\n", 130, costoDebitoLatam);
			printf("b) Precio con tarjeta de cr%cdito: %.2f\n", 130, costoCreditoLatam);
			printf("c) Precio pagando con Bitcoin: %.6f\n", costoBTCLatam);
			printf("d) Precio unitario: %.2f\n", precioUnitarioLatam);
			if(diferenciaPreciosIngresados<0)
			{
				diferenciaPreciosIngresados=diferenciaPreciosIngresados*-1;
				printf("\nLa diferencia de precio es: %.2f. Teniendo Latam un precio menor.\n", diferenciaPreciosIngresados);
			}
			else
			{
				if(diferenciaPreciosIngresados>0)
				{
					printf("\nLa diferencia de precio es: %.2f. Teniendo Aerolineas Argentinas un precio menor.\n", diferenciaPreciosIngresados);
				}
				else
				{
					printf("\nLa diferencia de precio es: %.2f\n", diferenciaPreciosIngresados);
				}
			}

		break;

		}


	}while(opcion != 6);





	return EXIT_SUCCESS;
}
