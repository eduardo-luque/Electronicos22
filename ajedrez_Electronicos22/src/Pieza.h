#pragma once
#include "EstructurasMov.h"
#include <ETSIDI.h>
#define anchocasilla 0.15

class Pieza {
public:
	enum obj_t {
		FICHA = 0, PEON_NEGRO, PEON_BLANCO, TORRE_BLANCA, TORRE_NEGRA, REY_BLANCO, REY_NEGRO,
		CABALLO_BLANCO, CABALLO_NEGRO, ALFIL_BLANCO, ALFIL_NEGRO, REINA_BLANCA, REINA_NEGRA
	};
	virtual ~Pieza() {};
	cas_t cas;
	obj_t rtt;
	Pieza(obj_t t = FICHA, cas_t c = { -1, -1 }) :rtt(t), cas(c) { }
	virtual void dibuja(obj_t t) {}
	virtual bool movimiento(obj_t t, move_t m);
	virtual bool mov_comer(obj_t t, move_t m);
	obj_t type() const { return rtt; }
	cas_t square() const { return cas; }
	static Pieza* create(Pieza::obj_t, cas_t);		// Funcion creadora de piezas con argumentos tipo de pieza y casilla
	static Pieza* create(const Pieza& p);			// Funcion creadora de piezas con argumento referencia a pieza
};


// gracias a que habilitamos el alpha test y la funcion correspondiente, el programa nos permite retirar el fondo de las imagenes
// debido a que no activamos la funcion disable, no necesitamos activar el canal alpha en todas las piezas


