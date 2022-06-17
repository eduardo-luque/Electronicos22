#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
public:
	Alfil() {}
	Alfil(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual void dibuja(obj_t t) {
		switch (t) {
		case (Pieza::ALFIL_NEGRO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/musk.png").id);
			break;
		case (Pieza::ALFIL_BLANCO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/faraday.png").id);
			break;
		default:
			break;
		}
	}
	ostream& print(ostream& o = cout) const { o << "alfil en "; cas.print(o); return o; }
};
