/*
 * buscador_restaurantes.h
 *
 *  Created on: 8 mar. 2022
 *      Author: jorge
 */

#ifndef BUSCADOR_RESTAURANTES_H_
#define BUSCADOR_RESTAURANTES_H_

#include "restaurante.h"

Lista<Restaurante *>* recomendar_restaurantes (Lista<Restaurante *>*
restaurantes, Lista<string>* platos_deseados, int precio_maximo);

bool esta_plato_en(string plato, Lista<string>* platos_deseados);

bool hay_algun_plato_en(Lista<string>* platos, Lista<string>* platos_deseados);

bool hay_x_platos_en(Lista<string>* platos, Lista<string>* platos_deseados, int coincidencias);

#endif /* BUSCADOR_RESTAURANTES_H_ */
