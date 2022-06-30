#include "Mundo.h"
#include "Tablero.h"
#include "ETSIDI.h"
#include <freeglut.h>
#include "Master.h"
#include "Movimientos.h"
#include "Pieza.h"

Mundo::Mundo() {}
Mundo::~Mundo() {}

void Mundo::Inicializa() {
	mast.Inicializa();
}

void Mundo::Dibuja() {   //llamamos al tablero para dibujarlo. 

	tabl.Dibuja(mast); 
	DibujaCasilla(origen_n);
	DibujaCasilla(origen_b);
}

void Mundo::Raton(int x, int y, int b, bool state, char t) {

	//CON ESTA FUNCION UTILIZAREMOS EL MOUSE

	bool down = (state == GLUT_DOWN);
	int button;
	if (b == GLUT_LEFT_BUTTON) {

		button = tabl.MOUSE_LEFT_BUTTON;
		clic++;


		if ((tabl.xcell_sel <= 8) && (tabl.xcell_sel >= 0) && (tabl.ycell_sel <= 8) && (tabl.ycell_sel >= 0))
		{
			if (mast.peones[tabl.xcell_sel][tabl.ycell_sel] && clic == 2)
			{

				cout << "ORIGEN!!" << endl;
				switch (mast.peones[tabl.xcell_sel][tabl.ycell_sel]->type())
				{

				case(Pieza::PEON_NEGRO):
					cout << "peon negro!!" << endl;
					origen_n.x = tabl.xcell_sel;
					origen_n.y = tabl.ycell_sel;
					break;

				case(Pieza::PEON_BLANCO):
					cout << "peon blanco!!" << endl;
					origen_b.x = tabl.xcell_sel;
					origen_b.y = tabl.ycell_sel;
					break;

				case(Pieza::REINA_NEGRA):
					cout << "reina negra!!" << endl;
					origen_n.x = tabl.xcell_sel;
					origen_n.y = tabl.ycell_sel;
					break;
				case(Pieza::REINA_BLANCA):
					cout << "reina blanca!!" << endl;
					origen_b.x = tabl.xcell_sel;
					origen_b.y = tabl.ycell_sel;
					break;

				case(Pieza::REY_NEGRO):
					cout << "rey negro!!" << endl;
					origen_n.x = tabl.xcell_sel;
					origen_n.y = tabl.ycell_sel;
					break;
				case(Pieza::REY_BLANCO):
					cout << "rey blanco!!" << endl;
					origen_b.x = tabl.xcell_sel;
					origen_b.y = tabl.ycell_sel;
					break;

				case(Pieza::TORRE_NEGRA):
					cout << "torre negra!!" << endl;
					origen_n.x = tabl.xcell_sel;
					origen_n.y = tabl.ycell_sel;
					break;
				case(Pieza::TORRE_BLANCA):
					cout << "torre blanca!!" << endl;
					origen_b.x = tabl.xcell_sel;
					origen_b.y = tabl.ycell_sel;
					break;
				case(Pieza::ALFIL_BLANCO):
					cout << "alfil blanco!!" << endl;
					origen_b.x = tabl.xcell_sel;
					origen_b.y = tabl.ycell_sel;
					break;
				case(Pieza::ALFIL_NEGRO):
					cout << "alfil negro!!" << endl;
					origen_n.x = tabl.xcell_sel;
					origen_n.y = tabl.ycell_sel;
					break;
				case(Pieza::CABALLO_BLANCO):
					cout << "caballo blanco!!" << endl;
					origen_b.x = tabl.xcell_sel;
					origen_b.y = tabl.ycell_sel;
					break;
				case(Pieza::CABALLO_NEGRO):
					cout << "caballo negro!!" << endl;
					origen_n.x = tabl.xcell_sel;
					origen_n.y = tabl.ycell_sel;
					break;

				}
			}

			if (clic == 4)
			{
				if (mast.peones[origen_n.x][origen_n.y]) 
				{
					destino_n.x = tabl.xcell_sel;
					destino_n.y = tabl.ycell_sel;
					clic = 0;
				}

				if (mast.peones[origen_b.x][origen_b.y]) 
				{
					destino_b.x = tabl.xcell_sel;
					destino_b.y = tabl.ycell_sel;
					clic = 0;
				}
				cout << "DESTINO!!" << endl;
			}


			if (clic > 5)clic = 0;

		}
	}
	if (b == GLUT_RIGHT_BUTTON) {

		button = tabl.MOUSE_RIGHT_BUTTON;

	}

	tabl.BotonMouse(x, y, b, down);

}

void Mundo::DibujaCasilla(cas_t& c) { //dibujamos la casilla del que tocamos 
	if (c.x != 0 || c.y != 0) {
		glDisable(GL_LIGHTING);
		glColor3ub(130, 0, 0);
		glTranslatef(0.15 * c.y, -0.15 * c.x, 0.0001);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.15, 0);
		glVertex2f(0.15, -0.15);
		glVertex2f(0, -0.15);
		glEnd();
		glTranslatef(-0.15 * c.y, 0.15 * c.x, -0.0001);
		glEnable(GL_LIGHTING);
	}
}

void Mundo::setMovimiento(cas_t ori, cas_t dest)
{
	origen_n = ori;
	origen_b = ori;
	destino_n = dest;
	destino_b = dest;
}

int Mundo::MovimientoPlayer(char t)
{

	if (t == 'N')   //si son negras
	{   //para evitar llamar tres veces a la función solo la llamamos una única vez y evaluamos su resultado:
		int resultadoNegras = mo.is_legal({ origen_n, destino_n }, mast);
		if (resultadoNegras == 2)//movimiento simple sin comer
		{
			mo.move({ origen_n, destino_n }, mast);
			mo.jaque_negro({ origen_n, destino_n },mast);
			return 1;	//pasamos al turno del otro
		}

		else if (resultadoNegras == 1)  //movimiento comer
		{
			mo.move({ origen_n, destino_n }, mast);
			mo.jaque_negro({ origen_n, destino_n },mast);
			return 1;
		}

		//si matamos al rey blanco
		else if (resultadoNegras == 3)
		{

			return 2;
		}

		else return 4;//movimiento no valido con lo cual continuo con mi turno
	}
	if (t == 'B') //si son blancas
	{    //para evitar llamar tres veces a la función solo la llamamos una única vez y evaluamos su resultado:
		int resultadoBlancas = mo.is_legal({ origen_b, destino_b }, mast);
		if (resultadoBlancas == 2)//movimiento simple sin comer
		{
			mo.move({ origen_b, destino_b }, mast);
			return 1;	//pasamos al turno del otro
		}

		else if (resultadoBlancas == 1)  //movimiento comer
		{
			mo.move({ origen_b, destino_b }, mast);
			return 1;
		}

		//si matamos al rey negro
		else if (resultadoBlancas == 3)
		{

			return 2;
		}

		else return 4;//movimiento no valido con lo cual continuo con mi turno
	}
}