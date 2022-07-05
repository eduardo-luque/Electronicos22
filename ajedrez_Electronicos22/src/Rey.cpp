#include "Rey.h"

bool Rey::movimiento(obj_t t, move_t m) {
	switch (t) {
	case Pieza::REY_BLANCO: case Pieza::REY_NEGRO:
		//movimientos diagonales
		if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) {
			//cout << "movimiento valido " << endl; 
			return true;
		}
		//movimientos horizontales
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
			(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1)) {
			//cout << "movimiento valido " << endl; 
			return true;
		}
		break;
	default:
		break;
	}
}

bool Rey::mov_comer(obj_t t, move_t m)
{
	switch (t) {
	case Pieza::REY_NEGRO: case Pieza::REY_BLANCO:
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha inferior
			if ((m.dest.x + 1 > 9) || (m.dest.y + 1 > 9)) { return false; }
			cout << "el REY come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda inferior
			if ((m.dest.x + 1 > 9) || (m.dest.y - 1 < 0)) { return false; }
			cout << "el REY come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha superior
			if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 9)) { return false; }
			cout << "el REY come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda superior
			if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return false; }
			cout << "el REY come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y)) { //vertical abajo
			if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; } //si me salgo del tablero no como obviamente
			cout << "el rey COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y)) { //vertical arriba
			if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
			cout << "el rey COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1)) { //horizontal a la derecha
			if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; } //si me salgo del tablero
			cout << "el rey come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1)) { //horizontal a la izquierda
			if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
			cout << "el rey COME" << endl; return true;
		}
		break;
	default: break;
	}
}


void Rey::dibuja(obj_t t, int num) {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;

	switch (t) {
	case (Pieza::REY_NEGRO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tesla.png").id);
		break;
	case (Pieza::REY_BLANCO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/einstein.png").id);
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

void Rey::dibuja2(obj_t t, int num) {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;

	switch (t) {
	case (Pieza::REY_NEGRO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyNegro.png").id);
		break;
	case (Pieza::REY_BLANCO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey.png").id);
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