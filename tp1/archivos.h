/*
 * archivo.h
 *
 *  Created on: 1 oct. 2021
 *      Author: jorge
 */

#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

#include <iostream>
#include <fstream>
#include "materiales.h"

const string PATH_ARCHIVO_MATERIALES = "materiales.txt";
const string PATH_ARCHIVO_EDIFICIOS = "edificios.txt";

//pre: -
//post: procesa el archivo de materiales y carga el vector de materiales.
void procesar_archivo_materiales(Materiales* materiales_disponibles);

//pre: -
//post: procesa el archivo de edificios y carga el vector de edificio.
void procesar_archivo_edificios (Edificios* edificios, Materiales* materiales_disponibles);

//pre: -
//post: agrega material al vector materiales disponibles.
void agregar_material(Materiales* materiales_disponibles, Material* material);

//pre: -
//post: agrega edificio al vector edificios elegibles.
void agregar_edificio(Edificios* edificios_elegibles, Edificio* edificio);

//pre: -
//post:escribe el archivo de materiales.
void escribir_archivo_materiales(Materiales* materiales_disponibles);

//pre: -
//post:escribe el archivo de edificios.
void escribir_archivo_edificios(Edificios* edificios_elegibles, Materiales* materiales_disponibles);

//pre: -
//post:elimina el registro de materiales.
void cerrar_materiales(Materiales* materiales_disponibles);

//pre: -
//post:elimina el registro de edificios.
void cerrar_edificios(Edificios* edificios_elegibles, Materiales* materiales_disponibles);

#endif /* ARCHIVOS_H_ */
