/*
 * universidad.h
 *
 *  Created on: 8 mar. 2022
 *      Author: jorge
 */

#ifndef UNIVERSIDAD_H_
#define UNIVERSIDAD_H_



#include "lista.h"


class Universidad{
		//atributos
		private:
		string nombre;
		int ranking;
		Lista<string>* carreras;

		//metodos
		public:

		Universidad (string nombre, int ranking, Lista<string>* carreras);

		//PRE:
		//POST: devuelve el nombre
		string obtener_nombre();

		//PRE:
		//POST: devuelve la cantidad de calorias
		int obtener_ranking();

		//PRE:
		//POST: devuelve un puntero a la lista de ingredientes
		Lista<string>* obtener_carreras();


};

#endif /* UNIVERSIDAD_H_ */
