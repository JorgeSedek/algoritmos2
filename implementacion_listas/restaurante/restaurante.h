/*
 * restaurante.h
 *
 *  Created on: 8 mar. 2022
 *      Author: jorge
 */

#ifndef RESTAURANTE_H_
#define RESTAURANTE_H_


#include "lista.h"


class Restaurante{
		//atributos
		private:
		string nombre;
		int precio_promedio;
		Lista<string>* platos;

		//metodos
		public:

		Restaurante (string nombre, int precio_promedio, Lista<string>* platos);

		//PRE:
		//POST: devuelve el nombre
		string obtener_nombre();


		int obtener_precio_promedio();


		Lista<string>* obtener_platos();


};




#endif /* RESTAURANTE_H_ */
