#pragma once
#include "Pieza.h"

class tb : public Pieza {
public:
	tb() {}
	tb(cas_t c) :Pieza(TORRE_BLANCA, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/sheldon2.png").id);

	}
	ostream& print(ostream& o = cout) const { o << "torre blanca en "; cas.print(o); return o; }
};
