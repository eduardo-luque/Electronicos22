#include "Rey.h"

void Rey::dibuja(obj_t t) {
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
}

bool Rey::movimiento(obj_t t, move_t m) {
    switch (t) {
    case Pieza::REY_BLANCO: case Pieza::REY_NEGRO:
		//movimientos diagonales
		if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) {
			cout << "movimiento valido " << endl; return true;
		}
		else { return false; }
		//movimientos horizontales
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
			(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1)) {
			cout << "movimiento valido " << endl; return true;
		}
		else { return false; }
		break;
	default:
		break;
    }
}

bool Rey::mov_comer(obj_t t, move_t m) {
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
	default: 
		break;
	}
}
