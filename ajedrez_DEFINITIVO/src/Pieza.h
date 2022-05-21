#pragma once
#include "vector2D.h"
#include <ETSIDI.h>

class Pieza {
public:
	enum obj_t {
		FICHA = 0, PEON_NEGRO, PEON_BLANCO, TORRE_BLANCA, TORRE_NEGRA, REY_BLANCO, REY_NEGRO,
		CABALLO_BLANCO, CABALLO_NEGRO, ALFIL_BLANCO, ALFIL_NEGRO, REINA_BLANCA, REINA_NEGRA
	};
	virtual ~Pieza() {};
	cas_t cas;
	obj_t rtt;
	Pieza(obj_t t = FICHA, cas_t c = { -1, -1 }) :rtt(t), cas(c) { }
	void dibuja(obj_t t);
	obj_t type() const { return rtt; }
	cas_t square() const { return cas; }
};

class fabrica {
public:
	static Pieza* create(Pieza::obj_t, cas_t);		// Funcion creadora de piezas con argumentos tipo de pieza y casilla
	static Pieza* create(const Pieza& p);			// Funcion creadora de piezas con argumento referencia a pieza
};

// gracias a que habilitamos el alpha test y la funcion correspondiente, el programa nos permite retirar el fondo de las imagenes
// debido a que no activamos la funcion disable, no necesitamos activar el canal alpha en todas las piezas


//CLASES DE LOS OBJETOS DERIVADAS DE LA CLASE PIEZA UTILIZANDO POLIMORFISMO O HERENCIA
class pn : public Pieza {
public:
	pn() { }
	pn(cas_t c) :Pieza(PEON_NEGRO, c) { }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/engranaje2.png").id);

	}
	ostream& print(ostream& o = cout) const { o << "peon negro en "; cas.print(o); return o; }
};

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

class tn : public Pieza {
public:
	tn() {}
	tn(cas_t c) :Pieza(TORRE_NEGRA, c) { print(); }
	virtual void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/howard.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "torre negra en "; cas.print(o); return o; }
};

class reyb : public Pieza {
public:
	reyb() {}
	reyb(cas_t c) :Pieza(REY_BLANCO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/einstein.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "rey blanco en "; cas.print(o); return o; }
};

class reyn : public Pieza {
public:
	reyn() {}
	reyn(cas_t c) :Pieza(REY_NEGRO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tesla.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "rey negro en "; cas.print(o); return o; }
};

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

class cabn : public Pieza {
public:
	cabn() {}
	cabn(cas_t c) :Pieza(CABALLO_NEGRO, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/oso.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "caballo negro en "; cas.print(o); return o; }
};

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

class reinab : public Pieza {
public:
	reinab() { }
	reinab(cas_t c) :Pieza(REINA_BLANCA, c) { print(); }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/curie.png").id);
	}
	ostream& print(ostream& o = cout) const { o << "dama blanca en "; cas.print(o); return o; }
};

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