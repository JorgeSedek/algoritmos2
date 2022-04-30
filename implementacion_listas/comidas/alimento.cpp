/*
 * alimento.cpp
 *
 *  Created on: 7 mar. 2022
 *      Author: jorge
 */

#include "alimento.h"



Alimento::Alimento (string nombre, unsigned int calorias, Lista<string>* ingredientes){
	this -> nombre = nombre;
	this -> calorias = calorias;
	this -> ingredientes = ingredientes;
}


string Alimento::obtener_nombre(){
	return nombre;
}

unsigned int Alimento::obtener_calorias (){
	return calorias;
}


Lista<string>* Alimento::obtener_ingredientes (){
	return ingredientes;
}

