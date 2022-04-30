/*
 * Buscador_comidas.h
 *
 *  Created on: 7 mar. 2022
 *      Author: jorge
 */

#ifndef BUSCADOR_COMIDAS_H_
#define BUSCADOR_COMIDAS_H_


#include "alimento.h"



	// Post: busca en “comidas” aquellas que tienen algún ingrediente de la
	// lista “ingredientes_permitidos” y ninguno de la lista “ingredientes_no_permitidos”
	// y tienen una caloria menor a “caloría_maxima”.
	// Devuelve una lista con los alimentos que cumplen con estas características.
	Lista<Alimento *>* comidas_para_celiacos (Lista<Alimento *>* comidas, Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos, unsigned int caloria_maxima);

	//PRE:
	//POST: devuelve true si ingrediente esta en la lista_ingredientes
	bool esta_ingrediente_en(string ingrediente, Lista<string>* lista_ingredientes);

	//PRE:
	//POST: devueve true si algun ingrediente de ingredietes_comida esta en lista de ingredientes
	bool hay_algun_ingrediente(Lista<string>* ingredientes_comida, Lista<string>* lista_ingredientes);







#endif /* BUSCADOR_COMIDAS_H_ */
