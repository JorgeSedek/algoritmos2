/*
 * Buscador_comidas.cpp
 *
 *  Created on: 7 mar. 2022
 *      Author: jorge
 */

#include "Buscador_comidas.h"



Lista<Alimento *>* comidas_para_celiacos (Lista<Alimento *>* comidas,	Lista<string>* ingredientes_permitidos, Lista<string>* 	ingredientes_no_permitidos, unsigned int caloria_maxima){
	Lista<Alimento*>* comidas_celiacos = new Lista<Alimento*>();

	ingredientes_permitidos -> reiniciar();
	ingredientes_no_permitidos -> reiniciar();
	comidas -> reiniciar();

	while(comidas -> hay_siguiente()){
		Alimento* comida = comidas -> siguiente();

		if (comida -> obtener_calorias() < caloria_maxima){
			if (hay_algun_ingrediente(comida -> obtener_ingredientes(), ingredientes_permitidos) && not hay_algun_ingrediente(comida -> obtener_ingredientes(), ingredientes_no_permitidos)){
				comidas_celiacos -> insertar(comida, 1);
			}
		}
	}
	return comidas_celiacos;
}

bool esta_ingrediente_en(string ingrediente, Lista<string>* ingredientes_requeridos){
	string ingrediente_requerido = ingredientes_requeridos -> obtener_dato(1);

	while(ingredientes_requeridos -> hay_siguiente() && ingrediente != ingrediente_requerido){
		ingrediente_requerido = ingredientes_requeridos -> siguiente();
	}

	ingredientes_requeridos -> reiniciar();

	return ingrediente == ingrediente_requerido;
}

bool hay_algun_ingrediente(Lista<string>* ingredientes_comida, Lista<string>* lista_ingredientes){
	string ingrediente_comida = ingredientes_comida -> obtener_dato(1);

	while(ingredientes_comida -> hay_siguiente() && not esta_ingrediente_en(ingrediente_comida,lista_ingredientes)){
		ingrediente_comida = ingredientes_comida -> siguiente();
	}

	ingredientes_comida -> reiniciar();

	return esta_ingrediente_en(ingrediente_comida, lista_ingredientes);
}
