#pragma once
#include "Mundo.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void Tecla(unsigned char key);
	void Inicializa();
	void Dibuja();

protected:
	Mundo mundo;
	enum Estado { INICIO, GANA_B, GANA_N, TABLAS, SINGLEPLAYER, MULTIPLAYER };
	enum Turno { JUGADOR_B, JUGADOR_N };
	Estado estado;
	Turno turno;

};
