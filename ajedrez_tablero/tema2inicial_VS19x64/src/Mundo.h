#pragma once
#include "Tablero.h"
#include "Master.h"

class Mundo
{
private:
	Master mast;
	Tablero tabl;
public:
	Mundo();
	virtual ~Mundo();

	void Inicializa();
	void Dibuja();

};
