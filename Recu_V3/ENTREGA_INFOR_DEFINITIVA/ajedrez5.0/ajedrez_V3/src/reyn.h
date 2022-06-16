#pragma once
#include "Pieza.h"

class reyn : public Pieza {
public:
	reyn() {}
	reyn(cas_t c) :Pieza(REY_NEGRO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tesla.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "rey negro en "; cas.print(o); return o; }
};