#include "Reina.h"

void Reina::dibuja(obj_t t) {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;

	switch (t) {
	case (Pieza::REINA_NEGRA):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/hedy.png").id);
		break;
	case (Pieza::REINA_BLANCA):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/curie.png").id);
		break;
	default:
		break;
	}

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

bool Reina::movimiento(obj_t t, move_t m) {
	switch (t) {
	case(Pieza::REINA_NEGRA): case(Pieza::REINA_BLANCA):
		for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
				(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i)) {
				cout << "movimiento valido " << endl; return true;
			}
			else { return false; }
			//este bucle cubre todos los posibles movimientos horizontales de la REINA
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
				(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
				cout << "movimiento valido " << endl; return true;
			}
			else { return false; }
		}
	default:
		break;
	}
}

bool Reina::mov_comer(obj_t t, move_t m) {
	switch (t) {
	case Pieza::REINA_BLANCA: case Pieza::REINA_NEGRA:
		for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles moVimientos diagonales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) { //diagonal derecha inferior tantas posiciones como me permita el tablero
				if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; } //si me salgo del tablero no como obviamente
				cout << "LA REINA COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) { //diagonal izquierda inferior
				if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
				cout << "LA REINA COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) { //diagonal derecha superior
				if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; } //si me salgo del tablero
				cout << "LA REINA COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i)) { //diagonal izquierda superior
				if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; } //si me salgo del tablero	
				cout << "LA REINA COME" << endl; return true;
			}
		}
		for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos verticales y horizontales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) { //vertical abajo, tantas posiciones como me permita el tablero
				if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; } //si me salgo del tablero no como obviamente
				cout << "LA REINA COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) { //vertical arriba
				if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
				cout << "LA REINA COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) { //horizontal a la derecha
				if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; } //si me salgo del tablero
				cout << "LA REINA COME" << endl; return true;
			}
			if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) { //horizontal a la izquierda
				if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; } //si me salgo del tablero
				cout << "LA REINA COME" << endl; return true;
			}
		}
	default:
		break;
	}
}
