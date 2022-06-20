#include "Torre.h"

bool Torre::movimiento(obj_t t, move_t m) {
	switch (t) {
	case(Pieza::TORRE_NEGRA): case(Pieza::TORRE_BLANCA):
		for (int i = 1; i < 9; i++) {
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
				(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
				cout << "movimiento valido " << endl; return true;
			}
			return false; 
		}
		break;
	default:
		break;
	} 
}

bool Torre::mov_comer(obj_t t, move_t m) {
	switch (t) {
	case(Pieza::TORRE_NEGRA): case(Pieza::TORRE_BLANCA):
		for (int i = 1; i < 9; i++) {
			if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) {
				if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; }
				cout << "LA TORRE come" << endl; return true;
			}
			if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) {
				if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; }
				cout << "LA TORRE come" << endl; return true;
			}
			if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) {
				if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; }
				cout << "LA TORRE come" << endl; return true;
			}
			if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
				if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; }
				cout << "LA TORRE come" << endl; return true;
			}
		}
		break;
	default: 
		break;
	}
}

void Torre::dibuja(obj_t t) {
	switch (t) {
	case (Pieza::TORRE_NEGRA):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/howard.png").id);
		break;
	case (Pieza::TORRE_BLANCA):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/sheldon2.png").id);
		break;
	default:
		break;
	}
}
