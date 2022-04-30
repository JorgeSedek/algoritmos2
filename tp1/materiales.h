/*
 * materiales.h
 *
 *  Created on: 25 sep. 2021
 *      Author: jorge
 */

#ifndef MATERIALES_H_
#define MATERIALES_H_

#include <string>
#include <iostream>
#include "materiales.h"

using namespace std;

const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_LOS_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int GUARDAR_SALIR = 6;
const int ERROR = -1;

const int ZERO = 0;

const int OTRAS_CATEGORIAS = 2;

const int SIN_CONSTRUIR = 0;

struct Material{
    string nombre;
    int cantidad;
};

struct Materiales{
	Material** materiales;
	int cantidad_materiales;
};

struct Edificio{
	string nombre;
	Material** materiales;
	int cantidad_construida;
	int max_cantidad_permitida;
};

struct Edificios{
	Edificio** edificios;
	int cantidad_edificios;
};


//pre: -
//post: Muestra los edificios que han sido construidos y cuantos hay de cada uno.
void mostrar_edificios_construidos(Edificios* edificios_elegibles);

//pre: -
//post: devuelve la posicion en la que esta el edificio ingresado si existe, si no devuelve la ultima posicion.
int encontrar_indice_edificio(Edificios* edificios_elegibles, string nombre_ingresado);

//pre: -
//post: verifica si la edificio que se quiere construir forma parte de las opciones disponibles de edificios.
bool esta_edificio_opciones(int indice_edificio);

//pre: el edificio debe formar parte de las opciones para elegir.
//post: verifica si se sobrepasa el maximo de edificios permitidos al construir uno nuevo.
bool sobrepaso_maximo_permitido_edificios(Edificios* edificios_elegibles, int indice_edificio);

//pre: el edificio debe formar parte de las opciones para elegir.
//post: verifica si un edificio tiene todos los materiales requeridos.
bool tiene__materiales_necesarios(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio);

//pre:
//post: verifica si se cumplen todas las condiciones para construir el edificio.
bool edificio_cumple_condiciones(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio);

//pre: indice debe ser > 0.
//post: verifica que la posicion del vector edificios corresponde con un edificio construido.
bool esta_edificio_construido(int indice, Edificios* edificios_elegibles);

//pre: -
//post: muestra la lista de materiales.
void mostrar_materiales(Materiales* materiales_disponibles);

//pre: -
//post: muestra la lista de edificios.
void mostrar_edificios(Edificios* edificios_elegibles, Materiales* materiales_disponibles);

//pre: -
//post: construye un edificio si cumple con las condiciones.
void construir_edificio(Edificios* edificios_elegibles, Materiales* materiales_disponibles, string nombre_ingresado);

//pre: -
//post: resta los materiales requeridos al vector de materiales disponibles.
void restar_materiales_utilizados(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio);

//pre: -
//post: devuelve la mitad de los materiales de un edificio destruido a los materiales disponibles.
void devolver_materiales_recuperados(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio);

//pre: -
//post: demuele un edificio.
void demoler_edificio(Edificios* edificios_elegibles, Materiales* materiales_disponibles, string nombre_ingresado);

//pre: -
//post: avisa por pantalla al usuario que el edificio no forma parte de las opciones.
void mostrar_edificio_no_es_una_opcion();

//pre: -
//post: avisa por pantalla al usuario que se sobrepaso el maximo permitido.
void mostrar_sobrepaso_maximo_permitido_edificios();

//pre: -
//post: avisa por pantalla al usuario que no se tienen los materiales requeridos.
void mostrar_no_se_tienen_los_materiales_requeridos();

//pre: -
//post: le avisa al usuario por pantalla la razon por la cual el edificio no cumple con las condiciones.
void mostrar_mensaje_no_cumple_condiciones(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio);

#endif /* MATERIALES_H_ */
