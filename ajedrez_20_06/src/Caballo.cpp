#include "Caballo.h"

bool Caballo::movimiento(obj_t t, move_t m)
{
    switch (t) {
	case(Pieza::CABALLO_NEGRO):
		//movs caballo
		if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2) {
			cout << "movimiento valido " << endl; return true;
		}
		else { return false; }
		break;
	case(Pieza::CABALLO_BLANCO):
		//movs caballo
		if ((m.dest.x < 9) && (m.dest.x > 0) && (m.dest.y < 9) && (m.dest.y > 0)) {
			if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2) {
				cout << "movimiento valido " << endl; return true;
			}
		}
		else { return false; }
		break;
	default:
		break;
   }
}

bool Caballo::mov_comer(obj_t t, move_t m)
{
	switch (t) {
	case(Pieza::CABALLO_BLANCO):
		if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y - 1)) { //salto vertical arriba derecha
			if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y + 1)) { //salto vertical arriba izqda
			if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y - 1)) { //salto vertical abajo dcha
			if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y + 1)) { //salto vertical abajo izqda
			if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 2)) { //salto horizontal arriba izquierda
			if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 2)) { //salto horizontal arriba derecha
			if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 2)) { //salto horizontal abajo derecha
			if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 2)) { //salto horizontal abajo izqda
			if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO BLANCO COME" << endl; return true;
		}
		break;
	case(Pieza::CABALLO_NEGRO):
		if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y + 1)) { //salto arriba derecha
			if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y - 1)) { //salto vertical arriba izqda
			if ((m.dest.x < 0) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y + 1)) { //salto vertical abajo derecha
			if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y - 1)) { //salto vertical abajo izqda
			if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 2)) { //salto horizontal arriba derecha
			if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 2)) { //salto horizontal arriba izquierda
			if ((m.dest.x < 0) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 2)) { //salto horizontal abajo derecha
			if ((m.dest.x > 9) || (m.dest.y > 9)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 2)) { //salto horizontal abajo izquierda
			if ((m.dest.x > 9) || (m.dest.y < 0)) { return false; }
			cout << "CABALLO NEGRO COME" << endl; return true;
		}
		break;
	default:
		break;
	}
}

void Caballo::dibuja(obj_t t) {
	switch (t) {
	case (Pieza::CABALLO_NEGRO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/oso.png").id);
		break;
	case (Pieza::CABALLO_BLANCO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/uamito2.png").id);
		break;
	default:
		break;
	}
}
