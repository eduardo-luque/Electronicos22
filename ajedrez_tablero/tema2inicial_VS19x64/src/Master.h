#pragma once
#include <iostream>
//#include "Ficha.h"
#include "Vector2D.h"
#include "freeglut.h"
#pragma once

using namespace std;

class Master {
	//friend class Engine;
public:
	static const int n = 8;
	static const int dist = 2;
	
private:
public:
	////////////
	//forma canónica
	Master();
	virtual ~Master();
	Master(const Master&);
	void Inicializa();
};