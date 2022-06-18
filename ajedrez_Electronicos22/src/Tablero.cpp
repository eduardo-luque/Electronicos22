#include "Master.h"
#include "Tablero.h"
#include "freeglut.h"
#include "EstructurasMov.h"
#include "Pieza.h"
#include "Peon.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "Reina.h"
#include "Alfil.h"
//Funcion principal para dibujar el tablero

void Tablero::Dibuja(Master& t) {
	float centro_x = numcasillas * anchocasilla / 2;   //situamos un centro en la x
	float centro_y = -numcasillas * anchocasilla / 2;  //situamos un centro en la x
	float centro_z = 0;
	int c = 1;
	float width = anchocasilla;

	//Borrar pantalla
	glClearColor(0.8, 1, 0.8, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Nos aseguramos de mirar al centro
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(centro_x, centro_y, t.dist, centro_x, centro_y, centro_z, 0, 1, 0);
	glEnable(GL_LIGHTING);

 
	for (int i = 1; i < numcasillas; i++)
	{
		for (int j = 1; j < numcasillas; j++)

			if (t.peones[i][j] != NULL)
				DibujaEnCelda(t, i, j);
	}

	for (int i = 1; i < numcasillas; i++)  //Hacemos bucle segun casillas
	{
		c = i % 2;  //para ir alternando el color de las casillas
		for (int j = 1; j < numcasillas; j++)
		{

			if (c == 0)
			{
				glColor3ub(250, 250, 250);//blancas 
				c = 1;
			}
			else
			{
				glColor3ub(0, 0, 0);//negras
				c = 0;
			}
			glDisable(GL_LIGHTING);

			glTranslatef(i * width, -j * width, 0);
			glBegin(GL_POLYGON);  //creamos un cuadrado para hacer cada casilla
			glVertex2f(0, 0);
			glVertex2f(width, 0);
			glVertex2f(width, -width);
			glVertex2f(0, -width);
			glEnd();
			glTranslatef(-i * width, +j * width, 0);
			glEnable(GL_LIGHTING);

		}

	}

}

void Tablero::DibujaEnCelda(Master& t, int x, int y) {
	float glx, gly;

	cas_t pos = t.peones[x][y]->square();
	int i = pos.x, j = pos.y;
	Torre torre; Caballo caballo; Reina reina; Alfil alfil; Rey rey; Peon peon;
	switch (t.peones[x][y]->type()) {
	case (Pieza::PEON_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(192, 192, 192);  //color plata rgb
		glTranslatef(glx, gly, 0.001f);
		peon.dibuja(Pieza::PEON_BLANCO);
		glTranslatef(-glx, -gly, -0.001f);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::PEON_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 63);   //color oro rgb
		glTranslatef(glx, gly, 0.001f);
		peon.dibuja(Pieza::PEON_NEGRO);
		glTranslatef(-glx, -gly, -0.001f);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::TORRE_BLANCA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 250);   //color TORRE blanca
		glTranslatef(glx, gly, 0.001);
		torre.dibuja(Pieza::TORRE_BLANCA);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::TORRE_NEGRA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 250);   //color TORRE negra
		glTranslatef(glx, gly, 0.001);
		torre.dibuja(Pieza::TORRE_NEGRA);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::CABALLO_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(192, 190, 250);   //color CABALLO blanco
		glTranslatef(glx, gly, 0.001);
		caballo.dibuja(Pieza::CABALLO_BLANCO);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::CABALLO_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(192, 190, 250);   //color CABALLO negro
		glTranslatef(glx, gly, 0.001);
		caballo.dibuja(Pieza::CABALLO_NEGRO);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::ALFIL_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 190, 0);   //color ALFIL blanco
		glTranslatef(glx, gly, 0.001);
		alfil.dibuja(Pieza::ALFIL_BLANCO);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::ALFIL_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 190, 0);   //color ALFIL negro
		glTranslatef(glx, gly, 0.001);
		alfil.dibuja(Pieza::ALFIL_NEGRO);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::REY_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 0, 255);   //color REY blanco
		glTranslatef(glx, gly, 0.001);
		rey.dibuja(Pieza::REY_BLANCO);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::REY_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 0, 255);   //color REY negro
		glTranslatef(glx, gly, 0.001);
		rey.dibuja(Pieza::REY_NEGRO);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::REINA_BLANCA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(255, 0, 0);   //color DAMA blanca
		glTranslatef(glx, gly, 0.001);
		reina.dibuja(Pieza::REINA_BLANCA);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Pieza::REINA_NEGRA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(255, 0, 0);   //color DAMA negra
		glTranslatef(glx, gly, 0.001);
		reina.dibuja(Pieza::REINA_NEGRA);
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
	default:
		break;
	}

}

//Centro de la celda
//Importante para dibujar el circulo desde el centro de la celda
void Tablero::localizarcentro(int cell_x, int cell_y, float& glx, float& gly) {
	glx = cell_y * anchocasilla + anchocasilla / 2.0f;
	gly = -cell_x * anchocasilla - anchocasilla / 2.0f;

}

void Tablero::world2cell(double x, double y, int& cell_x, int& cell_y) {
	//Coordinacion entre mundo y celda
	cell_x = (int)(abs(y / anchocasilla));
	cell_y = (int)(x / anchocasilla);
}

void Tablero::BotonMouse(int x, int y, int button, bool down) {  //funcion que maneja el raton

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);


	world2cell(posX, posY, xcell_sel, ycell_sel);

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	if (down) {
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;
	}
}