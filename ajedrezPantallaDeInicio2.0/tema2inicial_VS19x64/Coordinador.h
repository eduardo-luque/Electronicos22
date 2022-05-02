#pragma once
#include "Mundo.h"


class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();


	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
	void TurnoMulti();

protected:
	Mundo mundo;

	enum Estado { INICIO, GANA_B, GANA_N, TABLAS, SOLO, MULTI, PAUSASOLO, PAUSAMULTI };
	enum Turno { JUGADOR_B, JUGADOR_N };
	Estado estado;
	Turno turno;

};
