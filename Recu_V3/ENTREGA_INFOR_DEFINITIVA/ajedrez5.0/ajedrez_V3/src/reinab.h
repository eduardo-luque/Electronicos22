#pragma once
#include "Pieza.h"

class reinab : public Pieza {
public:
	reinab() { }
	reinab(cas_t c) :Pieza(REINA_BLANCA, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/curie.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "dama blanca en "; cas.print(o); return o; }
};