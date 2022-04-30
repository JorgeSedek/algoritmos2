#include "buscador_restaurantes.h"


Lista<Restaurante *>* recomendar_restaurantes (Lista<Restaurante *>*
restaurantes, Lista<string>* platos_deseados, int precio_maximo){
	restaurantes -> reiniciar();
	Lista<Restaurante*>* restaurantes_recomendados = new Lista<Restaurante*>();

	while(restaurantes -> hay_siguiente()){
		Restaurante* restaurante = restaurantes -> siguiente();

		if (hay_x_platos_en(restaurante -> obtener_platos(), platos_deseados,2) && restaurante -> obtener_precio_promedio() < precio_maximo){
			restaurantes_recomendados -> insertar(restaurante, 1);
		}
	}
	restaurantes -> reiniciar();

	return restaurantes_recomendados;
}

bool esta_plato_en(string plato, Lista<string>* platos_deseados){
	platos_deseados -> reiniciar();
	string plato_deseado = "inicio";

	while(platos_deseados -> hay_siguiente() && plato_deseado != plato){
		plato_deseado = platos_deseados -> siguiente();
	}
	platos_deseados -> reiniciar();

	return plato_deseado == plato;
}

bool hay_algun_plato_en(Lista<string>* platos, Lista<string>* platos_deseados){

	string plato = "inicio";

	while(platos -> hay_siguiente() && not esta_plato_en(plato, platos_deseados)){
		plato = platos -> siguiente();
	}

	return esta_plato_en(plato, platos_deseados);
}

bool hay_x_platos_en(Lista<string>* platos, Lista<string>* platos_deseados, int coincidencias){
	int contador = 0;
	platos -> reiniciar();
	platos_deseados -> reiniciar();
	while(platos -> hay_siguiente() && coincidencias != contador){
		if (hay_algun_plato_en(platos, platos_deseados)){
			contador++;
			platos_deseados -> reiniciar();
		}
	}
	platos -> reiniciar();
	platos_deseados -> reiniciar();

	return contador == coincidencias;

}


