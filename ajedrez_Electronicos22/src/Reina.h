#pragma once
#include "Pieza.h"

class Reina : public Pieza {
public:
	Reina() {}
	Reina(cas_t c, obj_t t) :Pieza(t, c) { print(); }
	virtual void dibuja(obj_t t) {
		switch (t) {
		case (Pieza::REINA_NEGRA):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/hedy.png").id);
			break;
		case (Pieza::REINA_BLANCA):
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/curie.png").id);
			break;
		default:
			break;
		}
	}
	ostream& print(ostream& o = cout) const { o << "reina en "; cas.print(o); return o; }
};
