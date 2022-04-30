/*
 * lista_circular.h
 *
 *  Created on: 23 ene. 2022
 *      Author: jorge
 */

#ifndef LISTA_CIRCULAR_H_
#define LISTA_CIRCULAR_H_

#include "nodo.h"


class Lista_circular{
	//ATRIBUTOS
	private:
		Nodo* primero;
		int cantidad;

	//METODOS
	public:

		//CONSTRUCTOR
		//PRE:
		//POST:
		Lista_circular();

		//PRE:
		//POST:
		void alta(Dato dato, int pos);

		//PRE:
		//POST:
		void baja(int pos);

		//PRE:
		//POST:
		Dato consulta(int pos);

		//PRE:
		//POST:
		bool vacia();

		//DESTRUCTOR
		//PRE:
		//POST:
		~Lista_circular();

	private:
		Nodo* obtener_nodo(int pos);
};




#endif /* LISTA_CIRCULAR_H_ */
