#include "Alfil.h"

bool Alfil::movimiento(obj_t t, move_t m){
	int v[8] = { 1,2,3,4,5,6,7 };
	switch (t) {
	case Pieza::ALFIL_BLANCO: case Pieza::ALFIL_NEGRO:
		for (int i = 0; i < 8; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
			if (((m.dest.x == m.ori.x + v[i]) && (m.dest.y == m.ori.y + v[i])) || ((m.dest.x == m.ori.x + v[i]) && (m.dest.y == m.ori.y - v[i])) ||
				((m.dest.x == m.ori.x - v[i]) && (m.dest.y == m.ori.y - v[i])) || ((m.dest.x == m.ori.x - v[i]) && (m.dest.y == m.ori.y + v[i]))) {
				//cout << "movimiento valido " << endl;
				return 2;
			}
		}
		break;
	}
}

bool Alfil::mov_comer(obj_t t, move_t m) {
    switch (t) {
	case Pieza::ALFIL_BLANCO: case Pieza::ALFIL_NEGRO:
		for (int i = 0; i < 9; i++) { //este bucle cubre todos los posibles moVimientos diagonales del alfil, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) { //diagonal derecha inferior tantas posiciones como me permita el tablero
				if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; } //si me salgo del tablero no como obviamente
				cout << "ALFIL COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) { //diagonal izquierda inferior
				if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
				cout << "ALFIL  COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) { //diagonal derecha superior
				if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; } //si me salgo del tablero
				cout << "ALFIL COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i)) { //diagonal izquierda superior
				if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
				cout << "ALFIL COME" << endl; return true;
			}
		}
		break;
	default: 
		break;
    }
}


void Alfil::dibuja(obj_t t, int num) {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;

	switch (t) {
	case (Pieza::ALFIL_NEGRO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/musk.png").id);
		break;
	case (Pieza::ALFIL_BLANCO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/faraday.png").id);
		break;
	default:
		break;
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(-num1, +num2 * num); glTexCoord2d(0, 0);
	glVertex2f(+num1, +num2 * num); glTexCoord2d(0, 1);
	glVertex2f(+num1, -num2 * num); glTexCoord2d(1, 1);
	glVertex2f(-num1, -num2 * num); glTexCoord2d(1, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Alfil::dibuja2(obj_t t, int num) {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;

	switch (t) {
	case (Pieza::ALFIL_NEGRO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfilNegro.png").id);
		break;
	case (Pieza::ALFIL_BLANCO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfil.png").id);
		break;
	default:
		break;
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(-num1, +num2 * num); glTexCoord2d(0, 0);
	glVertex2f(+num1, +num2 * num); glTexCoord2d(0, 1);
	glVertex2f(+num1, -num2 * num); glTexCoord2d(1, 1);
	glVertex2f(-num1, -num2 * num); glTexCoord2d(1, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
