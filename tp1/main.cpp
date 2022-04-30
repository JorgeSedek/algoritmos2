/*
 * main.cpp
 *
 *  Created on: 23 sep. 2021
 *      Author: jorge
 */


#include "archivos.h"
#include "menu.h"
#include "materiales.h"


int main(){

	Materiales* materiales_disponibles = new Materiales;
	Edificios* edificios_elegibles = new Edificios;


	procesar_archivo_materiales(materiales_disponibles);
	procesar_archivo_edificios(edificios_elegibles, materiales_disponibles);

   	mostrar_andypolis();
   	menu_opciones(edificios_elegibles, materiales_disponibles);

   	cerrar_edificios(edificios_elegibles, materiales_disponibles);
	cerrar_materiales(materiales_disponibles);

	delete materiales_disponibles;
    delete edificios_elegibles;


	return 0;
}




