#pragma once
#include "vector2D.h"
#include <ETSIDI.h>


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
	virtual void dibuja(){}
	obj_t type() const { return rtt; }
	cas_t square() const { return cas; }
};

class fabrica {
public:
	static Pieza* create(Pieza::obj_t, cas_t);		// Funcion creadora de piezas con argumentos tipo de pieza y casilla
	static Pieza* create(const Pieza& p);			// Funcion creadora de piezas con argumento referencia a pieza
};

// gracias a que habilitamos el alpha test y la funcion correspondiente, el programa nos permite retirar el fondo de las imagenes
// debido a que no activamos la funcion disable, no necesitamos activar el canal alpha en todas las piezas


//CLASES DE LOS OBJETOS DERIVADAS DE LA CLASE PIEZA UTILIZANDO POLIMORFISMO O HERENCIA
/*estas clases van a ser las denominadas pb, pn, cabb, cabn, tb, tn, reyb, reyn ,reinab y reinan que hacen referencia a las piezas que van a representar*/
