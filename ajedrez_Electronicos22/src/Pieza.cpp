#include "Pieza.h"
#include "Peon.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "Reina.h"
#include "Alfil.h"

Pieza* Pieza::create(Pieza::obj_t t, cas_t c) {   //creamos las piezas con asignacion de memoria. Los argumentos vienen de t->tipo c->casilla del tablero
	switch (t) {
	case Pieza::PEON_NEGRO:
		return new Peon(c, Pieza::PEON_NEGRO);
	case Pieza::PEON_BLANCO:
		return new Peon(c, Pieza::PEON_BLANCO);
	case Pieza::TORRE_BLANCA:
		return new Torre(c, Pieza::TORRE_BLANCA);
	case Pieza::TORRE_NEGRA:
		return new Torre(c, Pieza::TORRE_NEGRA);
	case Pieza::CABALLO_BLANCO:
		return new Caballo(c, Pieza::CABALLO_BLANCO);
	case Pieza::CABALLO_NEGRO:
		return new Caballo(c, Pieza::CABALLO_NEGRO);
	case Pieza::ALFIL_BLANCO:
		return new Alfil(c, Pieza::ALFIL_BLANCO);
	case Pieza::ALFIL_NEGRO:
		return new Alfil(c, Pieza::ALFIL_NEGRO);
	case Pieza::REY_BLANCO:
		return new Rey(c, Pieza::REY_BLANCO);
	case Pieza::REY_NEGRO:
		return new Rey(c, Pieza::REY_NEGRO);
	case Pieza::REINA_BLANCA:
		return new Reina(c, Pieza::REINA_BLANCA);
	case Pieza::REINA_NEGRA:
		return new Reina(c, Pieza::REINA_NEGRA);
	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;
}


Pieza* Pieza::create(const Pieza& f)    //creamos las piezas con asignacion de memoria 
{
	switch (f.type()) {

	case Pieza::PEON_BLANCO:
		return new Peon(dynamic_cast<const Peon&>(f));

	case Pieza::PEON_NEGRO:
		return new Peon(dynamic_cast<const Peon&>(f));

	case Pieza::TORRE_BLANCA:
		return new Torre(dynamic_cast<const Torre&>(f));

	case Pieza::TORRE_NEGRA:
		return new Torre(dynamic_cast<const Torre&>(f));

	case Pieza::CABALLO_BLANCO:
		return new Caballo(dynamic_cast<const Caballo&>(f));

	case Pieza::CABALLO_NEGRO:
		return new Caballo(dynamic_cast<const Caballo&>(f));

	case Pieza::ALFIL_BLANCO:
		return new Alfil(dynamic_cast<const Alfil&>(f));

	case Pieza::ALFIL_NEGRO:
		return new Alfil(dynamic_cast<const Alfil&>(f));

	case Pieza::REY_BLANCO:
		return new Rey(dynamic_cast<const Rey&>(f));

	case Pieza::REY_NEGRO:
		return new Rey(dynamic_cast<const Rey&>(f));

	case Pieza::REINA_BLANCA:
		return new Reina(dynamic_cast<const Reina&>(f));

	case Pieza::REINA_NEGRA:
		return new Reina(dynamic_cast<const Reina&>(f));


	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;

}


