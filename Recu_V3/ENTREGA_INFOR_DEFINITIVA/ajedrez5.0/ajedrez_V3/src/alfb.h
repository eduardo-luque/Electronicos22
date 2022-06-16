#pragma once
#include "Pieza.h"

class alfb : public Pieza {
public:
	alfb() {}
	alfb(cas_t c) :Pieza(ALFIL_BLANCO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/faraday.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "alfil blanco en "; cas.print(o); return o; }
};