#pragma once
#include "Pieza.h"

class reyb : public Pieza {
public:
	reyb() {}
	reyb(cas_t c) :Pieza(REY_BLANCO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/einstein.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "rey blanco en "; cas.print(o); return o; }
};