/*
 * implementacion.h
 *
 *  Created on: 8 mar. 2022
 *      Author: jorge
 */

#ifndef IMPLEMENTACION_H_
#define IMPLEMENTACION_H_

void Lista::intercambiar(int pos_a, int pos_b){
	Dato aux = obtener_dato(pos_a);
	cambiar_dato(obtener_dato(pos_b), pos_a);
	cambia_dato(aux,pos_b);
}

void Lista::unir_con(Lista lista){
	int pos = 1;
	while(lista.obtener_nodo(pos)){
		insertar(obtener_dato(pos),obtener_longitud());
	}
}

Lista* Lista::unir_con(Lista lista){
	int longitud = obtener_longitud();
	Lista* lista_nueva = new Lista(lista);

	for(int i = longitud;i > 0;i--){
		lista_nueva -> insertar(obtener_dato(pos), pos);
	}
	return lista_nueva;
}

void Lista::revertir(){
	revertir(1);
}

void Lista::revertir(int pos){
	if (pos == obtener_longitud()/2 + 1){

	}
	intecambiar(pos,obtener_longitud() + 1 - pos);
	return revertir(pos + 1);
}

Lista* Lista::revertir(){
	Lista* lista_revertida = new Lista();
	int longitud = obtener_longitud();

	for(int i = 1; i <= longitud ; i++){
		lista_revertida -> insertar(obtener_dato(longitud + 1 - i),i);
	}

	return lista_revertida;
}

void merge(Lista lista){
	int pos = 1;
	int pos_parametro = 1;

	int longitud = obtener_longitud();

	Dato dato_parametro = lista.obtener_dato(pos_parametro);
	while(obtener_nodo(pos) && lista.obtener_nodo(pos_parametro)){
		if (obtener_dato(pos).comparar_con(dato_parametro) > NULO){
			insertar(dato_parametro,pos);
		}
		else if (obtener_dato(pos).comparar_con(dato_parametro) < NULO){
			insertar(dato_parametro,pos + 1);
		}
		pos = pos + 2;
		pos_parametro++;
		dato_parametro = lista.obtener_dato(pos_parametro);
	}
	unir(pos_parametro,lista);
}

void unir(int pos_parametro, Lista lista){
	Nodo* nodo = obtener_nodo(1);
	while(nodo){
		insertar(dato_parametro, pos_parametro);
		pos_parametro++;
		nodo = nodo -> obtener_siguiente();
	}
}

void eliminar_ocurrencias(Dato dato){
	int pos = 1;
	Nodo* nodo = obtener_nodo(pos);
	eliminar_1er_ocurrencia(dato, nodo, pos);
}

void eliminar_ocurrencias(Dato dato, Nodo* nodo, int pos){
	if (nodo){
		if ((nodo -> obtener_dato()).comparar_con(dato) == NULO){
			eliminar(pos);
		}
		return eliminar_ocurrencias(dato, nodo -> obtener_siguiente(), pos + 1);
	}

}

void eliminar_1er_ocurrencia(Dato dato){
	Nodo* nodo = obtener_nodo(pos);
	int pos = 1;

	eliminar_1er_ocurrencia(dato,nodo,pos);
}



void eliminar_1er_ocurrencia(Dato dato, Nodo* nodo, int pos){
	if (nodo && (nodo -> obtener_dato()).comparar_con(dato) != NULO){
		return eliminar_1er_ocurrencia(dato, nodo -> obtener_siguiente(), pos + 1);
	}
	eliminar(pos);
}

Lista* eliminar_lista_de(Lista lista){
	Nodo* nodo = obtener_nodo(1);
	int pos = 1;
	Nodo* nodo_parametro = lista.obtener_nodo(1);
	Lista* lista_nueva = new Lista(lista);
	eliminar_lista_de(lista_nueva, nodo_parametro, pos);

	return lista_nueva;
}

Lista* eliminar_lista_de(Lista lista_nueva,  Nodo* nodo_parametro, int pos){
	if (nodo_parametro){
		nodo = obtener_nodo(1);
		while (nodo && (nodo -> obtener_dato()).comparar_con(nodo_parametro -> obtener_dato()) != NULO)){

			nodo = nodo -> obtener_siguiente();

		}
		if (nodo){
			lista_nueva.eliminar(pos);
			pos--;
		}
		return eliminar_lista_de(lista_nueva, nodo_parametro -> obtener_siguiente(), pos++);
	}
	return lista_nueva;
}
#endif /* IMPLEMENTACION_H_ */
