#pragma once
#include "Pieza.h"

class cabb : public Pieza {
public:
	cabb() {}
	cabb(cas_t c) :Pieza(CABALLO_BLANCO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/uamito2.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "caballo blanco en "; cas.print(o); return o; }
};