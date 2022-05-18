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
	void TurnoMultiplayer();
	void Raton(int b, int state, int x, int y);
	
protected:
	Mundo mundo;
	enum Estado { INICIO, GANA_B, GANA_N, SINGLEPLAYER, MULTIPLAYER,PAUSA };
	enum Turno { JUGADOR_B, JUGADOR_N };
	Estado estado;
	Turno turno;
};
