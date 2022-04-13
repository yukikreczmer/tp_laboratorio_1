/*
 * operaciones.c
 *
 */

float AplicarInteres(int interes, float precioIn)
{
    float retorno;
    retorno=precioIn+(((float)interes/100)*precioIn);

    return retorno;
}
float AplicarDescuento(int descuento, float precioIn)
{
    float retorno;
    retorno=precioIn-(((float)descuento/100)*precioIn);

    return retorno;

}

float ConvertirPrecio(double precio1Destino, float origen)
//en precio1Destino le paso cuanto vale en la escala origen, 1 unidad de la escala destino. Ej convierto de peso a BTC (origen=peso, destino=BTC). Seria cuantos pesos vale 1 BTC
{
	float retorno;
	//precio1Destino = 1 destino en escala origen
	precio1Destino=1/precio1Destino;	//precio1Destino = 1 origen en escala destino
	retorno=origen*precio1Destino;

	return retorno;
}

float CalcularPrecioUnitario(float precio, float unidades)
{
	float retorno;
	retorno=precio/unidades;
	return retorno;
}
