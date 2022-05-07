#include "Master.h"
#include "Tablero.h"
#include "freeglut.h"


//Funcion principal
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

	DibujaRepaso();
	/*for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j < numero; j++)

			if (t.tab[i][j] != NULL)
				DibujaEnCelda(t, i, j);
	}
*/
	for (int i = 0; i < numcasillas; i++)  //Hacemos bucle segun casillas
	{
		c = i % 2;  //para ir alternando el color de las casillas
		for (int j = 0; j < numcasillas; j++)
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
void Tablero::DibujaRepaso() {
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
	*/

}