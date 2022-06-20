#include "Alfil.h"

bool Alfil::movimiento(obj_t t, move_t m)
{
	switch (t) {
	case Pieza::ALFIL_BLANCO: case Pieza::ALFIL_NEGRO:
		for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
			if (((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) || ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) ||
				((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) || ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))) {
				cout << "movimiento valido " << endl; return 2;
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

void Alfil::dibuja(obj_t t) {
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
}