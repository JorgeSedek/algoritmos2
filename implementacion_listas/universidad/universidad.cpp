/*
 * universidad.cpp
 *
 *  Created on: 8 mar. 2022
 *      Author: jorge
 */


#include "universidad.h"



Universidad::Universidad (string nombre, int ranking, Lista<string>* carreras){
	this -> nombre = nombre;
	this -> ranking = ranking;
	this -> carreras = carreras;
}


string Universidad::obtener_nombre(){
	return nombre;
}

int Universidad::obtener_ranking(){
	return ranking;
}


Lista<string>* Universidad::obtener_carreras(){
	return carreras;
}


