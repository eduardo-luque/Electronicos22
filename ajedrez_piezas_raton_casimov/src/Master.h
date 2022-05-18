#pragma once
#include <iostream>
#include "Vector2D.h"
#include "freeglut.h"
#include "Peon.h"
#pragma once

using namespace std;

class Master {
	//friend class Movimiento;

private:
	void nulify();

public:
	static const int n = 9;
	static const int dist = 2;
	int nFichas;
	Peon* peones[n][n]; //vector de fichas del tablero
	////////////

	Master(): nFichas(0){}
	virtual ~Master();
	Master(const Master&);
	void Inicializa();
	int number_of_pieces();
	//Master& operator =(const Master&); //SOBRECARGA PROHIBIDA SEGÚN LA TEORÍA
	/////////////
    
//LOS 2 METODOS SIGUIENTES SE USAN EN Movimientos.h
	Master& operator +=(const Peon&);
	Master& operator -=(const Peon&);

};