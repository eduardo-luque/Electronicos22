#define _USE_MATH_DEFINES
#define DEG2RAD M_PI/180.0
#define numcasillas 8 //numero de casillas
#define anchocasilla 0.15  //ancho de cada casilla
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Master.h"
#include "freeglut.h"
#pragma once

class Tablero {
private:
	//VAriables para el ratón
	int xcell_sel, ycell_sel;
	bool leftButton;
	bool rightButton;
	bool midButton;
	
	friend class Mundo;

protected:
	enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };

public:

	void Dibuja(Master &);  //le meto la clase master
	//void DibujaRepaso();
	void DibujaEnCelda(Master&, int, int);
	//void BotonMouse(int, int, int, bool);
	//void DibujaMalla();
	void drawFilledCircle(GLfloat, GLfloat, GLfloat);
	void localizarcentro(int, int, float&, float&);
	void world2cell(double, double, int&, int&);
	void BotonMouse(int, int, int, bool);
};
