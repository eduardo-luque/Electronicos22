#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
	Peon() {}
	Peon(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual void dibuja(obj_t t) {
		switch (t) {
		case (Pieza::PEON_NEGRO):
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/engranaje2.png").id);
			break;
		case (Pieza::PEON_BLANCO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/atomo2.png").id);
			break;
		default:
			break;
		}
	}
	ostream& print(ostream& o = cout) const { o << "peon en "; cas.print(o); return o; }
};
