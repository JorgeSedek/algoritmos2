/*
 * alimento.h
 *
 *  Created on: 7 mar. 2022
 *      Author: jorge
 */

#ifndef ALIMENTO_H_
#define ALIMENTO_H_


#include "lista.h"




class Alimento{
	//atributos
	private:
	string nombre;
	unsigned int calorias;
	Lista<string>*  ingredientes;

	//metodos
	public:
	//constructor
	//PRE: calorias > 0
	//POST: crea un alimento
	Alimento (string nombre, unsigned int calorias, Lista<string>* ingredientes);

	//PRE:
	//POST: devuelve el nombre
	string obtener_nombre();

	//PRE:
	//POST: devuelve la cantidad de calorias
	unsigned int obtener_calorias ();

	//PRE:
	//POST: devuelve un puntero a la lista de ingredientes
	Lista<string>* obtener_ingredientes ();
};









#endif /* ALIMENTO_H_ */
