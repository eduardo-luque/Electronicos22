#pragma once
#include <iostream>
#include "EstructurasMov.h"
#include "Master.h"
#include "Pieza.h"



class Movimientos {
public:
	static int is_legal(move_t m, const Master& t); //SE ASEGURA DE QUE LOS MOVIMIENTOS SEAN VALIDOS, TAMBIEN LOS DE COMER
	static int move(move_t m, Master& t);           //AQUI ESTAN TODOS LOS POSIBLES MOVIMIENTOS
};
