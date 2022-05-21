#include "Pieza.h"



Pieza* fabrica::create(Pieza::obj_t t, cas_t c) {   //creamos las piezas con asignacion de memoria. Los argumentos vienen de t->tipo c->casilla del tablero
	switch (t) {
	case Pieza::PEON_NEGRO:
		return new pn(c);
	case Pieza::PEON_BLANCO:
		return new pb(c);
	case Pieza::TORRE_BLANCA:
		return new tb(c);
	case Pieza::TORRE_NEGRA:
		return new tn(c);
	case Pieza::CABALLO_BLANCO:
		return new cabb(c);
	case Pieza::CABALLO_NEGRO:
		return new cabn(c);
	case Pieza::ALFIL_BLANCO:
		return new alfb(c);
	case Pieza::ALFIL_NEGRO:
		return new alfn(c);
	case Pieza::REY_BLANCO:
		return new reyb(c);
	case Pieza::REY_NEGRO:
		return new reyn(c);
	case Pieza::REINA_BLANCA:
		return new reinab(c);
	case Pieza::REINA_NEGRA:
		return new reinan(c);
	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;
}


Pieza* fabrica::create(const Pieza& f)    //creamos las piezas con asignacion de memoria 
{
	switch (f.type()) {

	case Pieza::PEON_BLANCO:
		return new pb(dynamic_cast<const pb&>(f));  

	case Pieza::PEON_NEGRO:
		return new pn(dynamic_cast<const pn&>(f));

	case Pieza::TORRE_BLANCA:
		return new tb(dynamic_cast<const tb&>(f));

	case Pieza::TORRE_NEGRA:
		return new tn(dynamic_cast<const tn&>(f));

	case Pieza::CABALLO_BLANCO:
		return new cabb(dynamic_cast<const cabb&>(f));

	case Pieza::CABALLO_NEGRO:
		return new cabn(dynamic_cast<const cabn&>(f));

	case Pieza::ALFIL_BLANCO:
		return new alfb(dynamic_cast<const alfb&>(f));

	case Pieza::ALFIL_NEGRO:
		return new alfn(dynamic_cast<const alfn&>(f));


	case Pieza::REY_BLANCO:
		return new reyb(dynamic_cast<const reyb&>(f));

	case Pieza::REY_NEGRO:
		return new reyn(dynamic_cast<const reyn&>(f));

	case Pieza::REINA_BLANCA:
		return new reinab(dynamic_cast<const reinab&>(f));

	case Pieza::REINA_NEGRA:
		return new reinan(dynamic_cast<const reinan&>(f));


	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;

}

void Pieza::dibuja(obj_t t) {   //dibujamos las piezas
	pb pb; pn pn; cabn cabn; cabb cabb; alfn alfn; alfb alfb; tn tn; tb tb; reinan reinan; reinab reinab; reyn reyn; reyb reyb;
	switch (t) {
	case Pieza::PEON_NEGRO: pn.dibuja(); break;
	case Pieza::PEON_BLANCO: pb.dibuja(); break;
	case Pieza::CABALLO_NEGRO: cabn.dibuja(); break;
	case Pieza::CABALLO_BLANCO: cabb.dibuja(); break;
	case Pieza::ALFIL_NEGRO: alfn.dibuja(); break;
	case Pieza::ALFIL_BLANCO: alfb.dibuja(); break;
	case Pieza::TORRE_NEGRA: tn.dibuja(); break;
	case Pieza::TORRE_BLANCA: tb.dibuja(); break;
	case Pieza::REINA_NEGRA: reinan.dibuja(); break;
	case Pieza::REINA_BLANCA: reinab.dibuja(); break;
	case Pieza::REY_NEGRO: reyn.dibuja(); break;
	case Pieza::REY_BLANCO: reyb.dibuja(); break;
	}
}
