#pragma once
#include <iostream>

using namespace std;

struct cas_t {
	int x;
	int y;
	ostream& print(ostream& o = cout) const { o << "[" << x << "," << y << "]" << endl;  return o; }
};

struct move_t {
	cas_t ori;
	cas_t dest;
	ostream& print(ostream& o = cout) const { ori.print(o);  o << "->"; dest.print(o) << endl;  return o; }
	int tipo; //`2` si es un movimiento normal y `1` si es un movimiento de comer
};