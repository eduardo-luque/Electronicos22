#pragma once
#include <iostream>
#include "EstructurasMov.h"
#include "freeglut.h"
#include "Pieza.h"
#pragma once

using namespace std;

class Master {
private:
	void nulify();

public:
	static const int n = 9;
	static const int dist = 2;
	int nFichas;
	Pieza* peones[n][n]; //vector de fichas del tablero
	

	Master(): nFichas(0){}
	virtual ~Master();
	Master(const Master&);
	void Inicializa();
	int number_of_pieces();
	//bool detectar_jaque(Pieza::obj_t tipo, cas_t casilla);
	 

//LOS 2 OPERADORES SIGUIENTES SE USAN EN Movimientos.h
	Master& operator +=(const Pieza&);
	Master& operator -=(const Pieza&);

};