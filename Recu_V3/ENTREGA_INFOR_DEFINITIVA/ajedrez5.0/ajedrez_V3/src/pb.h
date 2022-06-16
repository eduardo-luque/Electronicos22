#pragma once
#include "Pieza.h"

class pb : public Pieza {
public:
	pb() {}
	pb(cas_t c) :Pieza(PEON_BLANCO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/atomo2.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

