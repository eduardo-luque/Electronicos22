#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
	Peon() {}
	Peon(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual bool movimiento(obj_t t, move_t m);
	virtual bool mov_comer(obj_t t, move_t m);
	virtual void dibuja(obj_t t);
	ostream& print(ostream& o = cout) const { o << "peon en "; cas.print(o); return o; }
};