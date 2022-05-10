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
	////////////

	Master();
	virtual ~Master();
	Master(const Master&);
	void Inicializa();

	Peon* peones[n][n];
};