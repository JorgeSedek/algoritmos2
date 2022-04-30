#include "nodo.h"

//Constructor
Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

void Nodo::cambiar_dato(Dato d) {
    dato = d;
}

void Nodo::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}

Dato Nodo::obtener_dato() {
    return dato;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}


