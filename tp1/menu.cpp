/*
 * menu.cpp
 *
 *  Created on: 23 sep. 2021
 *      Author: jorge
 */

#include "menu.h"


void mostrar_andypolis(){

	cout << "           ___    ____________________   ___________     "<< endl;
	cout << " ----------|-|-   ||                ||  /_/_/_/_/_//|    " << endl;
	cout << " |  _     _   |   ||  BIENVENIDO A  ||  | ___ ___ | |    " << endl;
	cout << " | |_|   |_|  |   ||     ANDYPOLIS  ||  | |_| |_| | |    "<< endl;
	cout << " |  _     _   |   ||________________||  |         | |    " << endl;
	cout << " | |_|   |_|  |                         | ___ ___ | |    " << endl;
	cout << " |    ____    |         °      °        | |_| |_| | |    " << endl;
	cout << " |    |  |    |_______ °°°___ °°° _____ |   ___   | |    " << endl;
    cout << "_|____|  |____|_______°°|°°  °°|°°______|___|_|___|/     " << endl ;

}

void mostrar_menu(){

	cout << " ______________________________________________________  " << endl;
	cout << " |  _______________________________________________   |  " << endl;
	cout << " |  |                                              |  |  " << endl;
	cout << " |  |   1)  Listar materiales de construccion.     |  |  " << endl;
    cout << " |  |                                              |  |  " << endl;
	cout << " |  |   2)  Construir edificio por nombre.         |  |  " << endl;
	cout << " |  |                                              |  |  " << endl;
	cout << " |  |   3) Listar los edificios construidos.       |  |  " << endl;
	cout << " |  |                                              |  |  " << endl;
	cout << " |  |   4)  Listar todos los edificios.            |  |  " << endl;
    cout << " |  |                                              |  |  " << endl;
    cout << " |  |   5)   Demoler un edificio por nombre.       |  |  " << endl;
	cout << " |  |                                              |  |  " << endl;
	cout << " |  |   6)  Guardar y salir.                       |  |  " << endl;
	cout << " |  |                                              |  |  " << endl;
	cout << " |  |______________________________________________|  |  " << endl;
    cout << " |____________________________________________________|  " << endl;


}

int pedir_opcion(){
    int opcion_elegida = ERROR;
    cout << "Ingrese una de las opciones : ";
    cin >> opcion_elegida;

    return opcion_elegida;
}



void procesar_opcion(int opcion_elegida, Edificios* edificios_elegibles, Materiales* materiales_disponibles){
	string nombre_ingresado;

	switch (opcion_elegida) {
        case LISTAR_MATERIALES:
        	mostrar_materiales(materiales_disponibles);
            break;

        case CONSTRUIR_EDIFICIO:
        	cout << "Ingrese el nombre del edificio que desea construir: " << endl;
        	cin >> nombre_ingresado;
        	construir_edificio(edificios_elegibles, materiales_disponibles, nombre_ingresado);
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
        	mostrar_edificios_construidos(edificios_elegibles);
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS:
        	mostrar_edificios(edificios_elegibles, materiales_disponibles);
        	break;

        case DEMOLER_EDIFICIO:
        	 cout << "Ingrese el nombre del edificio que desea eliminar: " << endl;
        	 cin >> nombre_ingresado;
        	 demoler_edificio(edificios_elegibles, materiales_disponibles, nombre_ingresado);
             break;

        case GUARDAR_SALIR:
        	 escribir_archivo_materiales(materiales_disponibles);
        	 escribir_archivo_edificios(edificios_elegibles, materiales_disponibles);

        	 break;

        default: cout << "Usted ha ingresado una opción incorrecta";
        		 break;
	}
}

void pedir_continuar(){
	char seguir = 'n';
	cout << "Presione la tecla 's' si desea continuar." << endl;
	while (seguir != 's'){
		cin >> seguir;
		cout << "Presione la tecla 's' si desea continuar." << endl;
	}
	}

void menu_opciones(Edificios* edificios_elegibles, Materiales* materiales_disponibles){

	int opcion_elegida = ERROR;

	while(opcion_elegida != GUARDAR_SALIR){
		mostrar_menu();
		opcion_elegida = pedir_opcion();
		procesar_opcion(opcion_elegida, edificios_elegibles, materiales_disponibles);

		if (opcion_elegida != GUARDAR_SALIR){
			pedir_continuar();
		}
	}

}
