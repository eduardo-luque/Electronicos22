#pragma once
#include "Pieza.h"

class Torre : public Pieza {
public:
	Torre() {}
	Torre(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual void dibuja(obj_t t) {
		switch (t) {
		case (Pieza::TORRE_NEGRA):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/howard.png").id);
			break;
		case (Pieza::TORRE_BLANCA):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/sheldon2.png").id);
			break;
		default:
			break;
		}
	}
	ostream& print(ostream& o = cout) const { o << "torre en "; cas.print(o); return o; }
};

