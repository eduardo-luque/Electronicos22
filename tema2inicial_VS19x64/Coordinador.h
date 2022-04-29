#pragma once

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();


	void Inicializa();
	void Dibuja();

	enum Estado { INICIO, GANA_B, GANA_N, TABLAS, SINGLEPLAYER, MULTIPLAYER };
	enum Turno { JUGADOR_BLANCAS, JUGADOR_NEGRAS };
	Estado estado;

};
