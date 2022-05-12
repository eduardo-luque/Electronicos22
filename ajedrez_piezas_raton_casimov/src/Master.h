#pragma once
#include <iostream>
//#include "Ficha.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Peon.h"
#pragma once

using namespace std;

class Master {
	//friend class Engine;

private:
	//void nulify();
public:
	static const int n = 8;
	static const int dist = 2;
	int nFichas;
	Peon* peones[n][n];//vector de fichas
	////////////

	Master();
	virtual ~Master();
	Master(const Master&);
	void Inicializa();
	//Master& operator =(const Master&); //SOBRECARGA PROHIBIDA SEGÚN LA TEORÍA
	/////////////
    
//LOS 2 METODOS SIGUIENTES SE USAN EN Movimientos.h
	Master& operator +=(const Peon&);
	Master& operator -=(const Peon&);


};