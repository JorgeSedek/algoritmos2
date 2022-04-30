#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef int Dato;

class Nodo {
//Atributos
private:
    Dato dato;
    Nodo* siguiente;

//Metodos
public:
    //constructor
    //PRE:
    //POS:
    Nodo(Dato d);

    //PRE:
    //POS:
    void cambiar_dato(Dato d);

    //PRE:
    //POS:
    void cambiar_siguiente(Nodo* pn);

    //PRE:
    //POS:
    Dato obtener_dato();

    //PRE:
    //POS:
    Nodo* obtener_siguiente();
};


#endif // NODO_H_INCLUDED
