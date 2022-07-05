#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
public:
	Alfil() {}
	Alfil(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual bool movimiento(obj_t t, move_t m);
	virtual bool mov_comer(obj_t t, move_t m);
	virtual void dibuja(obj_t t, int num);
	virtual void dibuja2(obj_t t, int num);
	ostream& print(ostream& o = cout) const { o << "alfil en "; cas.print(o); return o; }
};
