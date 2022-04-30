#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

template <class Dato>

class Nodo {
private:
    // atributos
    Dato dato;
    Nodo<Dato>* siguiente;

public:
    // Constructor con parametro
    // PRE: d es un Dato valido
    // POS: crea un Nodo con d como dato y NULL en siguiente
    Nodo<Dato> (Dato d);

    Nodo<Dato> (const Nodo &nodo);

    // Cambia el dato
    // PRE: d es un Dato valido
    // POS: cambia el dato actual por d
    void cambiar_dato (Dato d);

    // Cambia el siguiente
    // PRE: s es un puntero a Nodo valido
    // POS: cambia el siguiente por s
    void cambiar_siguiente (Nodo* s);

    // Obtiene el dato
    // PRE:
    // POS: devuelve el dato
    Dato obtener_dato( );

    // Obtiene el siguiente
    // PRE:
    // POS: devuelve el puntero siguiente
    Nodo<Dato>* obtener_siguiente( );

};

template <class Dato>

Nodo<Dato>::Nodo(Dato d){
	this -> dato = d;
	siguiente = 0;

}

template <class Dato>

Nodo<Dato>::Nodo(const Nodo &nodo){
	dato = nodo.dato;
	siguiente = new Nodo(nodo.siguiente ->obtener_dato());
	cout << "contructor de nodo" << endl;
}

template <class Dato>

void Nodo<Dato>::cambiar_dato (Dato d){
	this -> dato = d;
}

template <class Dato>

void Nodo<Dato>::cambiar_siguiente (Nodo* s){
	this -> siguiente = s;
}

template <class Dato>

Dato Nodo<Dato>::obtener_dato( ){
	return dato;
}

template <class Dato>

Nodo<Dato>* Nodo<Dato>::obtener_siguiente( ){
	return siguiente;
}



#endif // NODO_H_INCLUDED
