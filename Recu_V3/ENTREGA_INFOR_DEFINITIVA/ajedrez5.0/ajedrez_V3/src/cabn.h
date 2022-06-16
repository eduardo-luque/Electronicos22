#pragma once
#include "Pieza.h"

class cabn : public Pieza {
public:
	cabn() {}
	cabn(cas_t c) :Pieza(CABALLO_NEGRO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/oso.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "caballo negro en "; cas.print(o); return o; }
};