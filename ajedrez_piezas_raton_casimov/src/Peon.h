#pragma once
#include "vector2D.h"

class Peon {
public:
	enum obj_t { FICHA = 0, PEON_NEGRO, PEON_BLANCO, TORRE_BLANCA, TORRE_NEGRA, REY_BLANCO, REY_NEGRO,
		CABALLO_BLANCO, CABALLO_NEGRO, ALFIL_BLANCO, ALFIL_NEGRO, DAMA_BLANCA, DAMA_NEGRA};
	virtual ~Peon() {};
	cas_t cas;
	obj_t rtt;
	Peon(obj_t t = FICHA, cas_t c = { -1, -1 }) :rtt(t), cas(c) {}
	
	obj_t type() const { return rtt; }
	cas_t square() const { return cas; }
	void setCas(cas_t dest) { cas = dest; }
};

class fabrica {
public:
	static Peon* create(Peon::obj_t, cas_t);		// constructor normal
	static Peon* create(const Peon& p);			// constructor copia
};


class pn : public Peon {
public:
	pn(cas_t c) :Peon(PEON_NEGRO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon negro en "; cas.print(o); return o; }
};

class pb : public Peon {
public:
	pb(cas_t c) :Peon(PEON_BLANCO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class tb: public Peon {
public:
	tb(cas_t c) :Peon(TORRE_BLANCA, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class tn : public Peon {
public:
	tn(cas_t c) :Peon(TORRE_NEGRA, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class reyb : public Peon {
public:
	reyb(cas_t c) :Peon(REY_BLANCO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class reyn : public Peon {
public:
	reyn(cas_t c) :Peon(REY_NEGRO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class cabb : public Peon {
public:
	cabb(cas_t c) :Peon(CABALLO_BLANCO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class cabn : public Peon {
public:
	cabn(cas_t c) :Peon(CABALLO_NEGRO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class alfb : public Peon {
public:
	alfb(cas_t c) :Peon(ALFIL_BLANCO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class alfn : public Peon {
public:
	alfn(cas_t c) :Peon(ALFIL_NEGRO, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class db : public Peon {
public:
	db(cas_t c) :Peon(DAMA_BLANCA, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};

class dn : public Peon {
public:
	dn(cas_t c) :Peon(DAMA_NEGRA, c) {}
	//ostream& print(ostream& o = cout) const { o << "peon blanco en "; cas.print(o); return o; }
};