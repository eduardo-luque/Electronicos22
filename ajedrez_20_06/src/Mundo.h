#pragma once
#include "Tablero.h"
#include "Master.h"
#include "Movimientos.h"
#include "Pieza.h"


class Mundo
{
private:
	Master mast;//vector e piezas
	Tablero tabl;
	Pieza Piezas;
	Movimientos mo;

	int clic = 0;
	bool turno;
	cas_t destino_b = { 0,0 };
	cas_t destino_n = { 0,0 };
	cas_t origen_b = { 0,0 };
	cas_t origen_n = { 0,0 };
public:
	
	Mundo();
	virtual ~Mundo();

	void Inicializa();
	void Dibuja();
	void setMovimiento(cas_t ori, cas_t dest);
	void DibujaCasilla(cas_t& c);
	int MovimientoPlayer(char t);

	void Raton(int, int, int, bool, char t);
};
