#pragma once
#include "vector2D.h"
#include <ETSIDI.h>

class Peon {
public:
	enum obj_t {
		FICHA = 0, PEON_NEGRO, PEON_BLANCO, TORRE_BLANCA, TORRE_NEGRA, REY_BLANCO, REY_NEGRO,
		CABALLO_BLANCO, CABALLO_NEGRO, ALFIL_BLANCO, ALFIL_NEGRO, REINA_BLANCA, REINA_NEGRA
	};
	virtual ~Peon() {};
	cas_t cas;
	obj_t rtt;
	Peon(obj_t t = FICHA, cas_t c = { -1, -1 }) :rtt(t), cas(c) { }
	void dibuja(obj_t t);
	obj_t type() const { return rtt; }
	cas_t square() const { return cas; }
};

class fabrica {
public:
	static Peon* create(Peon::obj_t, cas_t);		// constructor normal
	static Peon* create(const Peon& p);				// constructor copia
};

class pn : public Peon {
public:
	pn() { }
	pn(cas_t c) :Peon(PEON_NEGRO, c) { }
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/engranaje2.png").id);

	}
	//ostream& print(ostream& o = cout) const { o << "peon negro en "; cas.print(o); return o; }
};

class pb : public Peon {
public:
	pb() {}
	pb(cas_t c) :Peon(PEON_BLANCO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/atomo2.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class tb : public Peon {
public:
	tb() {}
	tb(cas_t c) :Peon(TORRE_BLANCA, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/sheldon2.png").id);

	}
	//ostream& print(ostream& o = cout) const { o << "torre blanca en "; cas.print(o); return o; }
};

class tn : public Peon {
public:
	tn() {}
	tn(cas_t c) :Peon(TORRE_NEGRA, c) {}
	virtual void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/howard.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "torre negra en "; cas.print(o); return o; }
};

class reyb : public Peon {
public:
	reyb() {}
	reyb(cas_t c) :Peon(REY_BLANCO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/einstein.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "rey blanco en "; cas.print(o); return o; }
};

class reyn : public Peon {
public:
	reyn() {}
	reyn(cas_t c) :Peon(REY_NEGRO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tesla.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "rey negro en "; cas.print(o); return o; }
};

class cabb : public Peon {
public:
	cabb() {}
	cabb(cas_t c) :Peon(CABALLO_BLANCO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/uamito2.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "caballo blanco en "; cas.print(o); return o; }
};

class cabn : public Peon {
public:
	cabn() {}
	cabn(cas_t c) :Peon(CABALLO_NEGRO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/oso.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "caballo negro en "; cas.print(o); return o; }
};

class alfb : public Peon {
public:
	alfb() {}
	alfb(cas_t c) :Peon(ALFIL_BLANCO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/faraday.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "alfil blanco en "; cas.print(o); return o; }
};

class alfn : public Peon {
public:
	alfn() {}
	alfn(cas_t c) :Peon(ALFIL_NEGRO, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/musk.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "alfil negro en "; cas.print(o); return o; }
};

class reinab : public Peon {
public:
	reinab() {}
	reinab(cas_t c) :Peon(REINA_BLANCA, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/curie.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "dama blanca en "; cas.print(o); return o; }
};

class reinan : public Peon {
public:
	reinan() {}
	reinan(cas_t c) :Peon(REINA_NEGRA, c) {}
	void dibuja() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/hedy.png").id);
	}
	//ostream& print(ostream& o = cout) const { o << "dama negra en "; cas.print(o); return o; }
};