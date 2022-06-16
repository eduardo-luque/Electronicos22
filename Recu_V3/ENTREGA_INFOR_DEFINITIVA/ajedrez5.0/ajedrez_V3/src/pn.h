#pragma once
#include "Pieza.h"

class pn : public Pieza {
public:
	pn() { }
	pn(cas_t c) :Pieza(PEON_NEGRO, c) { }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/engranaje2.png").id);

	}
	ostream& print(ostream& o = cout) const { o << "peon negro en "; cas.print(o); return o; }
};