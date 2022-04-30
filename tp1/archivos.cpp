/*
 * archivos.cpp
 *
 *  Created on: 1 oct. 2021
 *      Author: jorge
 */

#include "archivos.h"

void escribir_archivo_materiales(Materiales* materiales_disponibles){

	ofstream archivo_salida(PATH_ARCHIVO_MATERIALES);

	for(int indice_materiales = 0; indice_materiales < materiales_disponibles -> cantidad_materiales; indice_materiales++){
		archivo_salida << materiales_disponibles -> materiales[indice_materiales] -> nombre << " " << materiales_disponibles -> materiales[indice_materiales] -> cantidad << endl;
	}
}


void escribir_archivo_edificios(Edificios* edificios_elegibles, Materiales* materiales_disponibles){

	ofstream archivo_salida(PATH_ARCHIVO_EDIFICIOS);

	for(int indice_edificios = 0; indice_edificios < edificios_elegibles -> cantidad_edificios; indice_edificios++){

		string nombre_edificio = edificios_elegibles -> edificios[indice_edificios] -> nombre;
		int cantidad_construida = edificios_elegibles -> edificios[indice_edificios] -> cantidad_construida;
		int max_permitido_edificio = edificios_elegibles -> edificios[indice_edificios] -> max_cantidad_permitida;
		archivo_salida << nombre_edificio << " ";

		for(int indice_materiales = 0; indice_materiales < materiales_disponibles -> cantidad_materiales; indice_materiales++){
			int cant_material = edificios_elegibles -> edificios[indice_edificios] -> materiales[indice_materiales] -> cantidad;
			archivo_salida << cant_material << " ";
		}
		archivo_salida << cantidad_construida << " " << max_permitido_edificio << endl;
     }
}

void procesar_archivo_materiales (Materiales* materiales_disponibles) {

	string nombre_material;
	string cantidad_material;

	Material* material;

	materiales_disponibles -> cantidad_materiales = 0;

	ifstream archivo(PATH_ARCHIVO_MATERIALES);

	while(archivo >> nombre_material){
		archivo >> cantidad_material;


		material = new Material;
		material -> nombre = nombre_material;
		material -> cantidad = stoi(cantidad_material);

		agregar_material(materiales_disponibles, material);

	}
    archivo.close();
    }

void procesar_archivo_edificios (Edificios* edificios_elegibles, Materiales* materiales_disponibles){

	string nombre_edificio;
	string cantidad_material;

	Material* material;
	Edificio* edificio;



	ifstream archivo(PATH_ARCHIVO_EDIFICIOS);

	edificios_elegibles -> cantidad_edificios = 0;

	while(archivo >> nombre_edificio){

		edificio = new Edificio;
		Materiales* materiales_requeridos = new Materiales;

		materiales_requeridos -> cantidad_materiales = 0;


		edificio -> nombre = nombre_edificio;

		for(int indice_materiales = 0; indice_materiales < materiales_disponibles -> cantidad_materiales + OTRAS_CATEGORIAS; indice_materiales++){

			archivo >> cantidad_material;

			if (indice_materiales < materiales_disponibles -> cantidad_materiales){
				material = new Material;
				material -> nombre	= materiales_disponibles -> materiales[indice_materiales] -> nombre;
				material -> cantidad = stoi(cantidad_material);
				agregar_material(materiales_requeridos, material);

			    }
			else
				if (indice_materiales == materiales_disponibles -> cantidad_materiales){
					edificio -> materiales = materiales_requeridos -> materiales;
					edificio -> cantidad_construida = stoi(cantidad_material);
				}
			else{
				edificio -> max_cantidad_permitida = stoi(cantidad_material);
				}

		    }

		agregar_edificio(edificios_elegibles, edificio);
		delete materiales_requeridos;


		}

	    archivo.close();
	    }

void agregar_material(Materiales* materiales_disponibles, Material* material){

	int tope_viejo = materiales_disponibles -> cantidad_materiales;

	Material** nuevo_vector_materiales = new Material*[tope_viejo + 1];

	for(int i = 0; i < materiales_disponibles -> cantidad_materiales; i++){
		nuevo_vector_materiales[i] = materiales_disponibles -> materiales[i];
		}
	nuevo_vector_materiales[tope_viejo] = material;

	if(materiales_disponibles -> cantidad_materiales != ZERO){
		delete[] materiales_disponibles -> materiales;
	}

	materiales_disponibles -> materiales = nuevo_vector_materiales;
	materiales_disponibles -> cantidad_materiales++;
}

void agregar_edificio(Edificios* edificios_elegibles, Edificio* edificio){

	int tope_viejo = edificios_elegibles -> cantidad_edificios;


	Edificio** nuevo_vector_edificios = new Edificio*[tope_viejo + 1];

	for(int indice_edificios = 0; indice_edificios < edificios_elegibles -> cantidad_edificios; indice_edificios++){
		nuevo_vector_edificios[indice_edificios] = edificios_elegibles -> edificios[indice_edificios];
		}
	nuevo_vector_edificios[tope_viejo] = edificio;

	if(edificios_elegibles -> cantidad_edificios != 0){
		delete[] edificios_elegibles -> edificios;
	}

	edificios_elegibles -> edificios = nuevo_vector_edificios;
	edificios_elegibles -> cantidad_edificios++;
}

void cerrar_materiales(Materiales* materiales_disponibles){

    int cantidad_de_materiales = materiales_disponibles -> cantidad_materiales;

    for(int indice_materiales = 0; indice_materiales < cantidad_de_materiales; indice_materiales++){
        delete materiales_disponibles -> materiales[indice_materiales];
        materiales_disponibles -> cantidad_materiales--;
    }

    delete[] materiales_disponibles -> materiales;
    materiales_disponibles -> materiales = nullptr;

}

void cerrar_edificios(Edificios* edificios_elegibles, Materiales* materiales_disponibles){

    int cantidad_edificios = edificios_elegibles -> cantidad_edificios;
    int cantidad_materiales = materiales_disponibles -> cantidad_materiales;

    for(int indice_edificios = 0; indice_edificios < cantidad_edificios; indice_edificios++){

    	for (int indice_materiales = 0; indice_materiales < cantidad_materiales; indice_materiales++){
        	delete edificios_elegibles -> edificios[indice_edificios] -> materiales[indice_materiales] ;

        }
    	delete[] edificios_elegibles -> edificios[indice_edificios] -> materiales;
        delete edificios_elegibles -> edificios[indice_edificios];

        edificios_elegibles -> cantidad_edificios--;
    }

    delete[] edificios_elegibles -> edificios;
    edificios_elegibles -> edificios = nullptr;

}
