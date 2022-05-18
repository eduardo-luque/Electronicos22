#pragma once
#include <iostream>
#include "Vector2D.h"
#include "freeglut.h"
#include "Pieza.h"

using namespace std;

class Master {
	//friend class Movimiento;

private:
	void nulify();

public:
	static const int n = 9;
	static const int dist = 2;
	int nFichas;
	Pieza* piezas[n][n]; //vector de fichas del tablero
	////////////

	Master(): nFichas(0){}
	virtual ~Master();
	Master(const Master&);
	void Inicializa();
	int number_of_pieces();
	//Master& operator =(const Master&); //SOBRECARGA PROHIBIDA SEGÚN LA TEORÍA
	/////////////
    
//LOS 2 METODOS SIGUIENTES SE USAN EN Movimientos.h
	Master& operator +=(const Pieza&);
	Master& operator -=(const Pieza&);

};