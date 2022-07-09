#pragma once
#include <iostream>
#include "EstructurasMov.h"
#include "Master.h"
#include "Pieza.h"

class Movimientos {
public:
	
	int jaque = 0;
	static int is_legal(move_t m, const Master& t); //SE ASEGURA DE QUE LOS MOVIMIENTOS SEAN VALIDOS, TAMBIEN LOS DE COMER
	static int move(move_t m, Master& t);           //AQUI ESTAN TODOS LOS POSIBLES MOVIMIENTOS

	// jaque y jaque mate //
	bool jaque_negro(move_t ma,Master& ta);
	bool jaque_blanco(move_t ma, Master& ta);
	bool jaquemate_blanco(move_t ma, Master& ta);
	bool jaquemate_negro(move_t ma, Master& ta);
	//static bool detectar_jaque_mate(Pieza::obj_t tipo, cas_t casilla, Master& t);
};
