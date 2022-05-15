#include "Peon.h"

//Crear peones con asignacion de memoria como pb y pn

Peon* fabrica::create(Peon::obj_t t, cas_t c) {
	switch (t) {
	case Peon::PEON_NEGRO:
		return new pn(c);
	case Peon::PEON_BLANCO:
		return new pb(c);
	case Peon::TORRE_BLANCA:
		return new tb(c);
	case Peon::TORRE_NEGRA:
		return new tn(c);
	case Peon::CABALLO_BLANCO:
		return new cabb(c);
	case Peon::CABALLO_NEGRO:
		return new cabn(c);
	case Peon::ALFIL_BLANCO:
		return new alfb(c);
	case Peon::ALFIL_NEGRO:
		return new alfn(c);
	case Peon::REY_BLANCO:
		return new reyb(c);
	case Peon::REY_NEGRO:
		return new reyn(c);
	case Peon::REINA_BLANCA:
		return new reinab(c);
	case Peon::REINA_NEGRA:
		return new reinan(c);
	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;
}

//NSTRUCTOR COPIA (Alo mejor no es necesario) dice victor
Peon* fabrica::create(const Peon& f)
{
	switch (f.type()) {

	case Peon::PEON_BLANCO:
		return new pb(dynamic_cast<const pb&>(f));  

	case Peon::PEON_NEGRO:
		return new pn(dynamic_cast<const pn&>(f));

	case Peon::TORRE_BLANCA:
		return new tb(dynamic_cast<const tb&>(f));

	case Peon::TORRE_NEGRA:
		return new tn(dynamic_cast<const tn&>(f));

	case Peon::CABALLO_BLANCO:
		return new cabb(dynamic_cast<const cabb&>(f));

	case Peon::CABALLO_NEGRO:
		return new cabn(dynamic_cast<const cabn&>(f));

	case Peon::ALFIL_BLANCO:
		return new alfb(dynamic_cast<const alfb&>(f));

	case Peon::ALFIL_NEGRO:
		return new alfn(dynamic_cast<const alfn&>(f));


	case Peon::REY_BLANCO:
		return new reyb(dynamic_cast<const reyb&>(f));

	case Peon::REY_NEGRO:
		return new reyn(dynamic_cast<const reyn&>(f));

	case Peon::REINA_BLANCA:
		return new reinab(dynamic_cast<const reinab&>(f));

	case Peon::REINA_NEGRA:
		return new reinan(dynamic_cast<const reinan&>(f));


	default:
		cerr << "incorrect type-factory::create()" << endl;
		return NULL;
	}
	return NULL;

}

