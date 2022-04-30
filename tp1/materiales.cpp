/*
 * materiales.cpp
 *
 *  Created on: 25 sep. 2021
 *      Author: jorge
 */

#include "materiales.h"


void mostrar_materiales(Materiales* materiales_disponibles){

	for(int i = 0; i < materiales_disponibles -> cantidad_materiales ; i++) {

		cout << "____________________________________________________" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "\t\t\t" << materiales_disponibles -> materiales[i] -> nombre << "" << endl;
		cout << "\t\t\t " << materiales_disponibles -> materiales[i] -> cantidad << "" << endl;
		cout << "" << endl;
		cout << "____________________________________________________" << endl;
	}
}

void mostrar_edificios_construidos(Edificios* edificios_elegibles){

	for(int indice_edificio = 0; indice_edificio < edificios_elegibles -> cantidad_edificios  ; indice_edificio++) {

		if (esta_edificio_construido(indice_edificio, edificios_elegibles)){

			cout << "----------------------------------------------------" << endl;
			cout << "" << endl;
			cout << "\t\t" << edificios_elegibles -> edificios[indice_edificio] -> nombre << "" << endl;
			cout << "hay construidos:" << edificios_elegibles -> edificios[indice_edificio] -> cantidad_construida << "" << endl;
			cout << "" << endl;
			cout << "----------------------------------------------------" << endl;
		}
	}
}

void mostrar_edificios(Edificios* edificios_elegibles, Materiales* materiales_disponibles){

	int cantidad_materiales = materiales_disponibles -> cantidad_materiales;

	for(int indice_edificio = 0; indice_edificio < edificios_elegibles -> cantidad_edificios ; indice_edificio++) {

		int cantidad_construida = edificios_elegibles -> edificios[indice_edificio] -> cantidad_construida;
		int max_permitido_edificios = edificios_elegibles -> edificios[indice_edificio] -> max_cantidad_permitida;

		cout << "----------------------------------------------------" << endl;
		cout << "" << endl;
		cout << "\t\t\t " << edificios_elegibles -> edificios[indice_edificio] -> nombre << " " << endl;
		cout << "" << endl;
		cout << "\t\t\t MATERIALES " << endl;
		cout << "" << endl;
		for (int indice_materiales = 0; indice_materiales < cantidad_materiales; indice_materiales++){


			cout << "\t\t\t"<< edificios_elegibles -> edificios[indice_edificio] -> materiales[indice_materiales] -> nombre << ":    " ;
			cout << edificios_elegibles -> edificios[indice_edificio] -> materiales[indice_materiales] -> cantidad << endl;

		}
		cout << "" << endl;
		cout << "\t hay construidos: " << edificios_elegibles -> edificios[indice_edificio] -> cantidad_construida << " edificios." << endl;
		cout << "\t Se pueden construir: " << max_permitido_edificios - cantidad_construida << " edificios antes de llegar al maximo permitido." << endl;
		cout << "" << endl;
		cout << "----------------------------------------------------" << endl;

	}
}



bool esta_edificio_construido(int indice, Edificios* edificios_elegibles){

	bool edificio_construido;

	if (edificios_elegibles -> edificios[indice] -> cantidad_construida == SIN_CONSTRUIR){
		edificio_construido = false;
    }
	else{
		edificio_construido = true;
	}

    return edificio_construido;
}



bool tiene__materiales_necesarios(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio){

	int indice_materiales = 0;

	bool tiene_materiales = true;
	int cant_materiales_requeridos;
	int cant_materiales_disponibles;

	while(tiene_materiales && indice_materiales < materiales_disponibles -> cantidad_materiales){

		cant_materiales_requeridos = edificios_elegibles -> edificios[indice_edificio] -> materiales[indice_materiales] -> cantidad;
		cant_materiales_disponibles = materiales_disponibles -> materiales[indice_materiales] -> cantidad;

		if(cant_materiales_requeridos > cant_materiales_disponibles){
			tiene_materiales = false;
		}
	indice_materiales++;
	}

	return tiene_materiales;
}

bool sobrepaso_maximo_permitido_edificios(Edificios* edificios_elegibles, int indice_edificio){

	bool sobrepaso = true;

	int edificios_construidos = edificios_elegibles -> edificios[indice_edificio] -> cantidad_construida;
	int max_permitido_edificio = edificios_elegibles -> edificios[indice_edificio] -> max_cantidad_permitida;

	if (edificios_construidos < max_permitido_edificio){
		sobrepaso = false;
	}

	return sobrepaso;
}

bool esta_edificio_opciones(int indice_edificio){

		return indice_edificio != ERROR;
}

bool edificio_cumple_condiciones(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio){

	bool cumple_condiciones = true;

	if (esta_edificio_opciones(indice_edificio)){
		if (sobrepaso_maximo_permitido_edificios(edificios_elegibles, indice_edificio)){
			cumple_condiciones = false;
		}
		else{
			if(not tiene__materiales_necesarios(edificios_elegibles, materiales_disponibles, indice_edificio)){
				cumple_condiciones = false;
			}
		}
	}
	else{
		cumple_condiciones = false;
	}

	return cumple_condiciones;
}

void construir_edificio(Edificios* edificios_elegibles, Materiales* materiales_disponibles, string nombre_ingresado){

	int indice_edificio = encontrar_indice_edificio(edificios_elegibles, nombre_ingresado);

	if (edificio_cumple_condiciones(edificios_elegibles, materiales_disponibles, indice_edificio)){
			char seguir;

			cout << "desea construir el edificio(s/n): " << endl;
			cin  >> seguir;

			if (seguir != 'n'){
					edificios_elegibles -> edificios[indice_edificio] -> cantidad_construida++;
					restar_materiales_utilizados(edificios_elegibles, materiales_disponibles, indice_edificio);
				}
	}
	else{
		mostrar_mensaje_no_cumple_condiciones(edificios_elegibles, materiales_disponibles, indice_edificio);
	}
}

void mostrar_edificio_no_es_una_opcion(){

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "" << endl;
	cout << "\t\t\t El edificio que elegiste " << endl;
	cout << "\t\t no forma parte de la lista de" << endl;
	cout << "\t\t\t      edificios   " << endl;
	cout << "" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}

void mostrar_sobrepaso_maximo_permitido_edificios(){

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "" << endl;
	cout << "\t\t se sobrepaso el maximo permitido " << endl;
	cout << "\t\t\t de edificios" << endl;
	cout << "\t\t que se pueden construir   " << endl;
	cout << "" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

void mostrar_no_se_tienen_los_materiales_requeridos(){

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "" << endl;
	cout << "\t\t no se disponen los " << endl;
	cout << "\t\t materiales necesarios" << endl;
	cout << "\t\t para construir el edificio   " << endl;
	cout << "" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

void mostrar_mensaje_no_cumple_condiciones(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio){

	if (not esta_edificio_opciones(indice_edificio)){

		mostrar_edificio_no_es_una_opcion();
	}
	else{
		if (sobrepaso_maximo_permitido_edificios(edificios_elegibles, indice_edificio)){

			mostrar_sobrepaso_maximo_permitido_edificios();

		}

		if (not tiene__materiales_necesarios(edificios_elegibles, materiales_disponibles, indice_edificio)){

			mostrar_no_se_tienen_los_materiales_requeridos();

		}
	}
}

int encontrar_indice_edificio(Edificios* edificios_elegibles, string nombre_ingresado){

	int indice_edificio = 0;

	string nombre_edificio = edificios_elegibles -> edificios[indice_edificio] -> nombre;
    int cantidad_edificios = edificios_elegibles -> cantidad_edificios;

	while(nombre_edificio != nombre_ingresado && indice_edificio < cantidad_edificios){

		 nombre_edificio = edificios_elegibles -> edificios[indice_edificio] -> nombre;
		 indice_edificio++;

		}
	if (nombre_edificio != nombre_ingresado){
		indice_edificio = ERROR;
	}
	else {
		if (indice_edificio != ZERO){
			indice_edificio = indice_edificio - 1;
		}
	}

	return (indice_edificio);
}

void restar_materiales_utilizados(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio){

	int cantidad_disponible, cantidad_requerida;

	for(int indice_materiales = 0; indice_materiales < materiales_disponibles -> cantidad_materiales; indice_materiales++){
		cantidad_disponible = materiales_disponibles -> materiales[indice_materiales] -> cantidad;
		cantidad_requerida = edificios_elegibles -> edificios[indice_edificio] -> materiales[indice_materiales] -> cantidad;
		materiales_disponibles -> materiales[indice_materiales] -> cantidad =  cantidad_disponible - cantidad_requerida;
	    }
}

void demoler_edificio(Edificios* edificios_elegibles, Materiales* materiales_disponibles, string nombre_ingresado){

	int indice_edificio = encontrar_indice_edificio(edificios_elegibles, nombre_ingresado);

	if (indice_edificio != ERROR){
		bool esta_construido = esta_edificio_construido(indice_edificio, edificios_elegibles);

		if (esta_edificio_opciones(indice_edificio) && esta_construido){

			edificios_elegibles -> edificios[indice_edificio] -> cantidad_construida--;
			devolver_materiales_recuperados(edificios_elegibles, materiales_disponibles, indice_edificio);
		}
	}
	else
		cout << "El edificio que se quiere demoler no forma parte de las opciones o no fue construido" << endl;
}

void devolver_materiales_recuperados(Edificios* edificios_elegibles, Materiales* materiales_disponibles, int indice_edificio){

	int cantidad_disponible, cantidad_requerida;

	for(int indice_materiales = 0; indice_materiales < materiales_disponibles -> cantidad_materiales; indice_materiales++){
		cantidad_disponible = materiales_disponibles -> materiales[indice_materiales] -> cantidad;
		cantidad_requerida = edificios_elegibles -> edificios[indice_edificio] -> materiales[indice_materiales] -> cantidad;
		materiales_disponibles -> materiales[indice_materiales] -> cantidad =  cantidad_disponible + ( cantidad_requerida / 2 );
		    }

}
