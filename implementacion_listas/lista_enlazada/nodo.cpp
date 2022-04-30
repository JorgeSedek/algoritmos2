/*
 * nodo.cpp
 *
 *  Created on: 22 ene. 2022
 *      Author: jorge
 */

#include "nodo.h"

Nodo::Nodo(Dato dato){

	this -> dato = dato;
	anterior = 0;
	siguiente = 0;
}

void Nodo::cambiar_dato(Dato dato){
	this -> dato = dato;
}

void Nodo::cambiar_siguiente(Nodo* siguiente){
	this -> siguiente = siguiente;
}

void Nodo::cambiar_anterior(Nodo* anterior){
	this -> anterior = anterior;
}

Dato Nodo::obtener_dato(){
	return dato;
}

Nodo* Nodo::obtener_siguiente(){
	return siguiente;
}

Nodo* Nodo::obtener_anterior(){
	return anterior;
}
