#pragma once
#include "Pieza.h"

class Caballo : public Pieza {
public:
	Caballo() {}
	Caballo(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual void dibuja(obj_t t) {
		switch (t) {
		case (Pieza::CABALLO_NEGRO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/oso.png").id);
			break;
		case (Pieza::CABALLO_BLANCO):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/uamito2.png").id);
			break;
		default:
			break;
		}
	}
	ostream& print(ostream& o = cout) const { o << "caballo en "; cas.print(o); return o; }
};
