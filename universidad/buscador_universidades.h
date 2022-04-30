#include "lista.h"
#include "universidad.h"

Lista<Universidad *>* recomendar_universidades (Lista<Universidad *>*
universidades, Lista<string>* vocaciones, int ranking_minimo);

bool esta_carrera_en(string carrera, Lista<string>* vocaciones);

bool alguna_carrera_en(Lista<string>* carreras, Lista<string>* vocaciones);
