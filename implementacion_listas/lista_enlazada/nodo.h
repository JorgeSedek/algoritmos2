/*
 * nodo.h
 *
 *  Created on: 22 ene. 2022
 *      Author: jorge
 */

#ifndef NODO_H_
#define NODO_H_

typedef int Dato;

class Nodo{

	//atributo
	private:
		Dato dato;
		Nodo* anterior;
		Nodo* siguiente;

	//metodos
	public:
		//constructor
		//PRE: -
		//POST: Construte un nodo con una entrada de dato.
		Nodo(Dato dato);

		//PRE:-
		//POST: cambia el dato almacenado
		void cambiar_dato(Dato dato);

		//PRE:-
		//POST:cambia el nodo siguiente
		void cambiar_siguiente(Nodo* siguiente);

		//PRE:
		//POST: cambia el nodo anterior
		void cambiar_anterior(Nodo* anterior);

		//PRE:
		//POST: Devuelve el dato almancenado.
		Dato obtener_dato();

		//PRE:
		//POST: Obtiene el puntero del nodo siguiente.
		Nodo* obtener_siguiente();

		//PRE:
		//POST: Obtiene el puntero del nodo anterior.
		Nodo* obtener_anterior();


};



#endif /* NODO_H_ */
