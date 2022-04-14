/*
 * operaciones.h
 *
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/// @brief aplica un interes (int) a un precio/valor (float) y lo retorna
///
/// @param interes en numero entero (int)
/// @param precioIn precio/valor a aplicar el interes (float)
/// @return Precio/valor con el interes aplicado
float AplicarInteres(int interes, float precioIn);

/// @brief aplica un descuento (int) a un precio/valor (float) y lo retorna
///
/// @param descuento en numero entero (int)
/// @param precioIn precio/valor a aplicar el descuento (float)
/// @return Precio/valor con el descuento aplicado
float AplicarDescuento(int descuento, float precioIn);

/// @brief  Convierte un precio o unidad de medida en otro
///
/// @param precio1Destino Relacion entre escalas. Cuanto vale en la escala origen, 1 unidad de la escala destino. Ej convierto de peso a BTC (origen=peso, destino=BTC). Seria cuantos pesos vale 1 BTC
/// @param origen valor a convertir
/// @return valor convertido a la escala destino
float ConvertirPrecio(double precio1Destino, float origen);

/// @brief
///
/// @param precio
/// @param unidades
/// @return
float CalcularPrecioUnitario(float precio, float unidades);



#endif /* OPERACIONES_H_ */
