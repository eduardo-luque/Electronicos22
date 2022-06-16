#pragma once
#include "Pieza.h"

class tn : public Pieza {
public:
	tn() {}
	tn(cas_t c) :Pieza(TORRE_NEGRA, c) { print(); }
	virtual void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/howard.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "torre negra en "; cas.print(o); return o; }
};