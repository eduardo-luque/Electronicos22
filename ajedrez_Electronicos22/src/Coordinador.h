#pragma once
#include "Mundo.h"

class Coordinador {
public:
	Coordinador();
	virtual ~Coordinador();

	void Tecla(unsigned char key);
	void Inicializa();
	void Dibuja();
	void TurnoMultiplayer();
	void Raton(int b, int state, int x, int y);

	int get_num() { return num; }
	void set_num(int n) { num = n; }
	char get_tipo() { return tipo; }
	void set_tipo(char t) { tipo = t; }

protected:
	Mundo mundo;
	enum Estado { INICIO, SELECCION, INICIO1, GANA_B, GANA_N, SINGLEPLAYER, MULTIPLAYER, PAUSA };
	enum Turno { JUGADOR_B, JUGADOR_N };
	Estado estado;
	Turno turno;
	int num;
	char tipo;
};
