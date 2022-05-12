#pragma once
#include <iostream>
#include "Vector2D.h"
#include "Master.h"
#include "Peon.h"


//////////////////

class Movimientos {
public:
	static int is_legal(move_t m, const Master& t); //SE ASEGURA DE QUE LOS MOVIMIENTOS SEAN VALIDOS, TAMBIEN LOS DE COMER
	static int move(move_t m, Master& t);           //AQUI ESTAN TODOS LOS POSIBLES MOVIMIENTOS DE LAS DAMAS Y LOS PEONES
};
