#include "buscador_universidades.h"

Lista<Universidad *>* recomendar_universidades (Lista<Universidad *>*
universidades, Lista<string>* vocaciones, int ranking_minimo){
	universidades -> reiniciar();
	Lista<Universidad*>* universidades_recomendadas = new Lista<Universidad*>();

	while(universidades -> hay_siguiente()){
		Universidad* universidad = universidades -> siguiente();
		if (alguna_carrera_en(universidad -> obtener_carreras(), vocaciones) && universidad -> obtener_ranking() < ranking_minimo){
			universidades_recomendadas -> insertar(universidad,1);
		}
	}

	return universidades_recomendadas;
}

bool esta_carrera_en(string carrera, Lista<string>* vocaciones){
	vocaciones -> reiniciar();
	string vocacion = vocaciones -> obtener_dato(1);

	while(vocaciones -> hay_siguiente() && vocacion != carrera){
		vocacion = vocaciones -> siguiente();
	}

	return vocacion == carrera;
}

bool alguna_carrera_en(Lista<string>* carreras, Lista<string>* vocaciones){
	string carrera = carreras -> obtener_dato(1);

	while(carreras -> hay_siguiente() && not esta_carrera_en(carrera, vocaciones)){
		string carrera = carreras -> siguiente();
	}

	return esta_carrera_en(carrera, vocaciones);
}
