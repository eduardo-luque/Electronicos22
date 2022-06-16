#pragma once
#include "Pieza.h"

class alfn : public Pieza {
public:
	alfn() {}
	alfn(cas_t c) :Pieza(ALFIL_NEGRO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/musk.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "alfil negro en "; cas.print(o); return o; }
};