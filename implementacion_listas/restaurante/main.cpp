/*
 * main.cpp
 *
 *  Created on: 6 mar. 2022
 *      Author: jorge
 */

#include "Buscador_comidas.h"

int main(){

	Lista<string>* ingredientes1 = new Lista<string>();
	Lista<string>* ingredientes2 = new Lista<string>();
	Lista<string>* ingredientes3 = new Lista<string>();

	ingredientes1 -> insertar("queso",1);
	ingredientes1 -> insertar("tomate",1);
	ingredientes1 -> insertar("fiambre",1);
	ingredientes1 -> insertar("anana",1);
	ingredientes1 -> insertar("ojo",1);
	ingredientes2 -> insertar("mayonesa",1);
	ingredientes3-> insertar("queso",1);

	Alimento* arroz = new Alimento("arroz", 1, ingredientes2);
	Alimento* bife = new Alimento("bife",1, ingredientes1);

	Lista<Alimento*>* comidas = new Lista<Alimento*>();



	comidas -> insertar(arroz,1);
	comidas -> insertar(bife,1);

	Alimento* comida = comidas -> obtener_dato(1);
	while(comidas -> hay_siguiente()){
			comida = comidas -> siguiente();
			cout << comida -> obtener_nombre() << endl;

		}


	Lista<Alimento*> comidas2 = comidas[0];

	Alimento* comida2 = comidas2.obtener_dato(1);
	while(comidas2.hay_siguiente()){
			comida2 = comidas2.siguiente();
			cout << comida2 -> obtener_nombre() << endl;

		}



	Lista<Alimento*>* comidas_recomendadas = comidas_para_celiacos(comidas, ingredientes3, ingredientes2, 12);

	while(comidas_recomendadas -> hay_siguiente()){
		cout << comidas_recomendadas -> siguiente() -> obtener_nombre() << endl;
	}


	cout << comidas_recomendadas -> obtener_longitud() << endl;
	cout << "Hola" << endl;

	return 0;
}
