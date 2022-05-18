#include "Master.h"
#include "Tablero.h"
#include "freeglut.h"
#include "Vector2D.h"
#include "Peon.h"

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

	//DibujaRepaso();  
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

//Dibuja las lineas que recuadran el tablero para adornarlo
//void Tablero::DibujaRepaso() {  (No es necesario)
	/*float dist = anchocasilla;
	glColor3ub(0, 255, 0);

	for (int i = 0; i <= numcasillas; i++) {
		if (i % numcasillas == 0) glLineWidth(4);
		else glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(i * anchocasilla, 0, 0);
		glVertex3f(i * anchocasilla, -marco, 0);
		glVertex3f(0, -i * anchocasilla, 0);
		glVertex3f(marco, -i * anchocasilla, 0);
		glEnd();
	}
	}
	*/

void Tablero::DibujaEnCelda(Master& t, int x, int y) {
	float glx, gly;

	cas_t pos = t.peones[x][y]->square();
	int i = pos.x, j = pos.y;

	switch (t.peones[x][y]->type()) {
	case (Peon::PEON_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(192, 192, 192);  //color plata rgb
		glTranslatef(glx, gly, 0.001f);
		//drawFilledCircle(0.0f, 0.0f, anchocasilla * 0.45f);
		p.dibuja(Peon::PEON_BLANCO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001f);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::PEON_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 63);   //color oro rgb
		glTranslatef(glx, gly, 0.001f);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::PEON_NEGRO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001f);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::TORRE_BLANCA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 250);   //color TORRE blanca
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::TORRE_BLANCA);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::TORRE_NEGRA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 250);   //color TORRE negra
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::TORRE_NEGRA);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::CABALLO_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(192, 190, 250);   //color CABALLO blanco
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::CABALLO_BLANCO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::CABALLO_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(192, 190, 250);   //color CABALLO negro
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::CABALLO_NEGRO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::ALFIL_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 190, 0);   //color ALFIL blanco
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::ALFIL_BLANCO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::ALFIL_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 190, 0);   //color ALFIL negro
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::ALFIL_NEGRO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::REY_BLANCO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 0, 255);   //color REY blanco
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::REY_BLANCO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::REY_NEGRO):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(0, 0, 255);   //color REY negro
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::REY_NEGRO);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::REINA_BLANCA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(255, 0, 0);   //color DAMA blanca
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::REINA_BLANCA);
		drawsquare();
		glTranslatef(-glx, -gly, -0.001);
		glEnable(GL_LIGHTING);
		break;

	case (Peon::REINA_NEGRA):
		localizarcentro(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glColor3ub(255, 0, 0);   //color DAMA negra
		glTranslatef(glx, gly, 0.001);
		//drawFilledCircle(0.0f, 0.0f, (anchocasilla / 2.0f) * 0.9f);
		p.dibuja(Peon::REINA_NEGRA);
		drawsquare();
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

	//finally cell coordinates
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

void Tablero::drawsquare() {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(-num1, +num2); glTexCoord2d(0, 0);
	glVertex2f(+num1, +num2); glTexCoord2d(0, 1);
	glVertex2f(+num1, -num2); glTexCoord2d(1, 1);
	glVertex2f(-num1, -num2); glTexCoord2d(1, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

/*
void Tablero::drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {   //funcion sacada de internet
	int i;
	int triangleAmount = 100; //Numero de triangulos usados para dibujar un circulo

	GLfloat twicePi = 2.0f * M_PI;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // Centro del circulo
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}
*/
//Dibuja la malla donde va el tablero
/*
void Tablero::DibujaRepaso() {
	float dist = anchocasilla;
	glColor3ub(250, 0, 0);
	float marco = (numcasillas-1) * anchocasilla;
	for (int i = 0; i <= (numcasillas-1); i++) {
		if (i % (numcasillas-1) == 0) glLineWidth(4);
		else glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(i * anchocasilla, 0, 0);
		glVertex3f(i * anchocasilla, -marco, 0);
		glVertex3f(0, -i * anchocasilla, 0);
		glVertex3f(marco, -i * anchocasilla, 0);
		glEnd();
	}

}

*/