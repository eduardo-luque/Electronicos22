#pragma once
#include "Pieza.h"

class Rey : public Pieza {
public:
	Rey() {}
	Rey(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual void dibuja(obj_t t) {
		switch (t) {
		case (Pieza::REY_NEGRO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tesla.png").id);
			break;
		case (Pieza::REY_BLANCO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/einstein.png").id);
			break;
		default:
			break;
		}
	}
	ostream& print(ostream& o = cout) const { o << "rey en "; cas.print(o); return o; }
};
