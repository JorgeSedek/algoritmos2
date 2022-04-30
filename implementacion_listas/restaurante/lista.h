#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

template <class Dato>

class Lista {

private:
    // atributos
    Nodo<Dato>* primero;
    Nodo<Dato>* actual;
    int longitud;

public:
    // Constructor sin parametros
    // PRE:
    // POS: crea una Lista de longitud 0 y primero apunta a NULL
    Lista ( );

    // Constructor de copia
    // PRE: lista es una Lista valida
    // POS: crea una Lista igual a lista
    Lista (const Lista& lista);

    // Destructor
    // PRE:
    // POS: libera la memoria solicitada
    ~Lista ( );

    // Lista vacia?
    // PRE:
    // POS: devuelve verdadero si la lista esta vacia, falso de lo contrario
    bool vacia( );

    // obtener longitud de la lista
    // PRE:
    // POS: devuelve la longitud de la lista
    int obtener_longitud( );

    // insertar un dato en cierta posicion
    // PRE: d dato valido y 0 < pos <= longitud + 1
    // POS: inserta el Dato d en la posicion pos (la 1 es la primera),
    //      inrementa en 1 la longitud
    void insertar (Dato d, int pos);

    // eliminar un Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: elimina el Nodo en la posicion pos (la 1 es la primera),
    //      libera memoria y decrementa en uno la longitud
    void eliminar (int pos);

    // obtiene el DAto en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve el dato que esta en la posicion pos (la 1 es la primera)
    Dato obtener_dato (int pos);

    // cambia el DAto que esta en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: cambia el dato que esta en la posicion pos (la 1 es la primera)
    void cambiar_dato (Dato d, int pos);

    //PRE:
    //POST: devuelve si true si el siguiente a actual es distinto de null
    bool hay_siguiente();

    //PRE:
    //POST: devuelve el dato actual y cambia actual por el siguiente
    Dato siguiente();

    //PRE:
    //POST: cambia el valor de actual por el de primero
    void reiniciar();

private:
    // devuelve un puntero al Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve un puntero al Nodo que esta en la posicion pos (la 1 es la primera)
    Nodo<Dato>* obtener_nodo (int pos);

};



template <class Dato>

Lista<Dato>::Lista ( ){
	this -> primero = 0;
	this -> actual = 0;
	this -> longitud =  0;
}

template <class Dato>

Lista<Dato>::Lista (const Lista<Dato>& lista){ //el & pasa del objeto al puntero
	longitud = lista.longitud;
	primero = new Nodo<Dato>(lista.primero -> obtener_dato());
	Nodo<Dato>* anterior_original = lista.primero;
	Nodo<Dato>* anterior = primero;
	reiniciar();
	if (longitud != 1){

		for(int i = 1; i < longitud; i++){

			Nodo<Dato>* siguiente = new Nodo<Dato>(anterior_original -> obtener_siguiente() -> obtener_dato());
			anterior -> cambiar_siguiente(siguiente);
			anterior = anterior -> obtener_siguiente();
			anterior_original = anterior_original -> obtener_siguiente();
		}
	}
	cout << "constructor de copia" << endl;
	reiniciar();
}

template <class Dato>

bool Lista<Dato>::hay_siguiente(){

	return actual;
}

template <class Dato>

void Lista<Dato>::reiniciar(){
	actual = primero;

}

template <class Dato>

Dato Lista<Dato>::siguiente(){
	Dato dato = actual -> obtener_dato();
	actual = actual -> obtener_siguiente();

	return dato;
}

template <class Dato>

Lista<Dato>::~Lista ( ){
	while(hay_siguiente()){
		eliminar(1);
	}
}

template <class Dato>

bool Lista<Dato>::vacia( ){

	return (longitud == 0);
}

template <class Dato>

int Lista<Dato>::obtener_longitud( ){
	return longitud;
}

template <class Dato>

void Lista<Dato>::insertar (Dato d, int pos){
	Nodo<Dato>* nodo_nuevo = new Nodo<Dato>(d);
	Nodo<Dato>* siguiente = primero;


	if (pos == 1){
		primero = nodo_nuevo;
		reiniciar();

	}
	else{
		Nodo<Dato>* anterior = obtener_nodo(pos - 1);
		siguiente = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(nodo_nuevo);
	}
	nodo_nuevo -> cambiar_siguiente(siguiente);

	longitud++;
}

template <class Dato>

void Lista<Dato>::eliminar (int pos){
	Nodo<Dato>* baja = primero;
	if (pos == 1){
		primero = baja -> obtener_siguiente();
		reiniciar();
	}
	else{
		Nodo<Dato>* anterior = obtener_nodo(pos - 1);
		baja = anterior -> obtener_siguiente();
		anterior -> cambiar_siguiente(baja -> obtener_siguiente());
	}
	delete baja;
	longitud--;
}

template <class Dato>

Dato Lista<Dato>::obtener_dato (int pos){
	Dato dato = obtener_nodo(pos) -> obtener_dato();
	return dato;
}

template <class Dato>

void Lista<Dato>::cambiar_dato (Dato d, int pos){
	obtener_nodo(pos) -> cambiar_dato(d);
}

template <class Dato>

Nodo<Dato>* Lista<Dato>::obtener_nodo (int pos){
	Nodo<Dato>* nodo = primero;
	for(int i = 1; i < pos; i++){
		nodo = nodo -> obtener_siguiente();
	}
	return nodo;
}


#endif // LISTA_H_INCLUDED
