#pragma once
#include <iostream>

//estructuras
//Una estructura dentro de otra. move_t utiliza cas_t para su movimiento creando un VECTOR 2D

using namespace std;

struct cas_t { //posicion
	int x, y;
	ostream& print(ostream& o = cout) const { o << "[" << x << "," << y << "]" << endl;  return o; }
};

struct move_t {  //movimiento
	cas_t ori, dest;  //casilla origen a casilla destino
	ostream& print(ostream& o = cout) const { ori.print(o);  o << "->"; dest.print(o) << endl;  return o; }
	int tipo; //`2` si es un movimiento normal y `1` si es un movimiento de comer
};