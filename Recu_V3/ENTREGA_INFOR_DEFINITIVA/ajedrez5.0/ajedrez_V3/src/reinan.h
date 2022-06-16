#pragma once
#include "Pieza.h"

class reinan : public Pieza {
public:
	reinan() {}
	reinan(cas_t c) :Pieza(REINA_NEGRA, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/hedy.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "dama negra en "; cas.print(o); return o; }
};
