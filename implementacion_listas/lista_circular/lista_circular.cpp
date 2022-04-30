/*
 * lista_circular.cpp
 *
 *  Created on: 23 ene. 2022
 *      Author: jorge
 */

#include "lista_circular.h"

Lista_circular::Lista_circular(){
	primero = 0;
	cantidad = 0;
}

bool Lista_circular::vacia(){
	return (cantidad == 0);
}

void Lista_circular::alta(Dato dato, int pos){
	Nodo* nuevo = new Nodo(dato);
	Nodo* siguiente = primero;


	if (pos == 1){
		primero = nuevo;
		Nodo* ultimo = obtener_nodo(cantidad);
		ultimo -> cambiar_siguiente(primero);
	}
	else {
		Nodo* anterior = obtener_nodo(pos - 1);
		siguiente = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(nuevo);
	}
	nuevo -> cambiar_siguiente(siguiente);
	cantidad++;
}

void Lista_circular::baja(int pos){
	Nodo*  baja = primero;
	if (pos == 1){
		Nodo* siguiente = baja -> obtener_siguiente();
		Nodo* ultimo = obtener_nodo(cantidad);
		ultimo -> cambiar_siguiente(siguiente);
		primero = siguiente;
	}
	else{
		Nodo* anterior = obtener_nodo(pos - 1);
		baja = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(baja -> obtener_siguiente());


	}
	delete baja;
	cantidad--;
}

Nodo* Lista_circular::obtener_nodo(int pos){
	Nodo* aux = primero;
	for (int i = 1; i < pos; i++){
		aux = aux -> obtener_siguiente();
	}

	return aux;
}

Lista_circular::~Lista_circular(){
	while(!vacia()){
		baja(1);
	}
}

void Lista_circular::mostrar() {
    Nodo* aux = primero;
    while (aux) {
        std::cout << aux -> obtener_dato() << " - ";
        aux = aux -> obtener_siguiente();
    }
}

Dato Lista_circular::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux -> obtener_dato();
}



