/*
 * lista_enlazada.cpp
 *
 *  Created on: 22 ene. 2022
 *      Author: jorge
 */

#include "lista_enlazada.h"

Lista_enlazada::Lista_enlazada(){
	primero = 0;
	ultimo = 0;
	cantidad = 0;
}

bool Lista_enlazada::vacia(){
	return(cantidad == 0);
}

void Lista_enlazada::alta(Dato dato, int pos){

	Nodo* nuevo = new Nodo(dato);
	Nodo* siguiente = primero;


	if (pos == cantidad - 1){
		ultimo = nuevo;
	}
	if (pos == 1){
			primero = nuevo;
		}
	else{
		Nodo* anterior = obtener_nodo(pos - 1);
		siguiente = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(nuevo);
		nuevo -> cambiar_anterior(anterior);
	}

	nuevo -> cambiar_siguiente(siguiente);
}

void Lista_enlazada::baja(int pos){
	Nodo* baja = primero;

	if (pos == cantidad){
		baja = ultimo;
		Nodo* anterior = baja -> obtener_anterior();
		ultimo = anterior;
		anterior -> cambiar_siguiente(baja -> obtener_siguiente());
	}
	else if (pos == 1){
		Nodo* siguiente = baja -> obtener_siguiente();
		primero = siguiente;
		siguiente -> cambiar_anterior(baja -> obtener_anterior());
	}
	else{
		Nodo* anterior = obtener_nodo(pos - 1);
		Nodo* siguiente = obtener_nodo(pos + 1);
		baja = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(baja -> obtener_siguiente());
		siguiente -> cambiar_anterior(baja -> obtener_anterior());


	}
	cantidad--;
	delete baja;

}

Dato Lista_enlazada::consulta(int pos){
	Nodo* aux = obtener_nodo(pos);
	return (aux -> obtener_dato());
}

Lista_enlazada::~Lista_enlazada(){
	while(!vacia()){
		baja(1);
	}
}

Nodo* Lista_enlazada::obtener_nodo(int pos){
	int mitad = cantidad / 2 ;
	Nodo* aux = primero;
	if (pos <= mitad){
		for(int i = 1; i < pos; i++){
			aux = aux -> obtener_siguiente();
		}
	}
	else {
		aux = ultimo;
		for(int j = 1; j <= (cantidad - pos);  j++){
			aux = aux -> obtener_anterior();
		}
	}

	return aux;
}

void Lista_enlazada::mostrar() {
    Nodo* aux = primero;
    while (aux) {
        std::cout << aux -> obtener_dato() << " - ";
        aux = aux -> obtener_siguiente();
    }
}
