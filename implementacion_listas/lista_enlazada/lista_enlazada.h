/*
 * lista_enlazada.h
 *
 *  Created on: 22 ene. 2022
 *      Author: jorge
 */

const int PRIMER_POS = 1;
const int PRIMER_NEG = -1;



#ifndef LISTA_ENLAZADA_H_
#define LISTA_ENLAZADA_H_

#include "nodo.h"
#include <iostream>


using namespace std;

class Lista_enlazada{
	//atributos
	private:
		Nodo* primero;
		Nodo* ultimo;
		int cantidad;

	//metodos
	public:

		//constructor
		//PRE:
		//POST: tope = 0
		Lista_enlazada();

		//PRE:
		//POST:
		void alta(Dato dato, int pos);

		//PRE:
		//POST:
		Dato consulta(int pos);

		//PRE:
		//POST:
		void baja(int pos);

		//PRE:
		//POST:
		bool vacia();

		//DESTRUCTOR
		~Lista_enlazada();

		void mostrar();

	private:

		//PRE: pos >= 1 y pos <= -1
		//POST: devuelve el nodo de la posicion
		Nodo* obtener_nodo(int pos);

};




#endif /* LISTA_ENLAZADA_H_ */
