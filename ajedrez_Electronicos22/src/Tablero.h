#pragma once
#define numcasillas 9  //numero de casillas
#define anchocasilla 0.15  //ancho de cada casilla
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Master.h"
#include "freeglut.h"


class Tablero {
private:
	//Variables para el ratón
	int xcell_sel, ycell_sel;
	bool leftButton;
	bool rightButton;
	bool midButton;
	
	friend class Mundo;

protected:
	enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

public:
	Pieza p;
	void Dibuja(Master &, int, char);  //Paso la clase master como referencia
	void DibujaEnCelda(Master&, int, int, char, int);
	void localizarcentro(int, int, float&, float&);
	void world2cell(double, double, int&, int&);
	void BotonMouse(int, int, int, bool);
};
