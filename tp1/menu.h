/*
 * menu.h
 *
 *  Created on: 23 sep. 2021
 *      Author: jorge
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <fstream>
#include "materiales.h"
#include "archivos.h"

using namespace std;


//pre: -
//post: Imprime por pantalla figura de texto
void mostrar_andypolis();

//pre: -
//post: Muestra menu.
void mostrar_menu() ;

//pre: -
//post: Almacena la opcion del usuario.
int pedir_opcion();

//pre: -
//post: Procesa la opcion ingresada por el usuario.
void procesar_opcion(int opcion_elegida, Edificios* edificios_elegibles, Materiales* materiales_disponibles);

//pre: -
//post: engloba todas las funciones que componen al menu de opciones.
void menu_opciones(Edificios* edificios_elegibles, Materiales* materiales_disponibles);

//pre: -
//post: espera hasta que el usuario presione alguna tecla.
void pedir_continuar();

#endif /* MENU_H_ */
