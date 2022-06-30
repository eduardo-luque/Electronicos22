#include "Peon.h"

bool Peon::movimiento(obj_t t, move_t m) {
	switch (t) {
	case(Pieza::PEON_BLANCO)://está permitido que avance hacia abajo(sumarle 1 o 2 a la x)  
		if (m.ori.x == 2) {
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y)) { 
				//cout << "movimiento valido" << endl;
				return true;
			}
			else { return false; }
		}
		else {
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y)) { 
				//cout << "movimiento valido" << endl; 
				return true; 
			}
			else { return false; }
		}
		break;
	case(Pieza::PEON_NEGRO)://está permitido que avance hacia arriba(resta 1 o 2 a la x) 
		if (m.ori.x == 7) {
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y)) { 
				//cout << "movimiento valido" << endl;
				return true; 
			}
			else { return false; }
		}
		else {
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y)) { 
				//cout << "movimiento valido" << endl;
				return true;
			}
			else { return false; }
		}
		break;
	default: break;
	}
	
}

bool Peon::mov_comer(obj_t t, move_t m) {
	switch (t) {
	case(Pieza::PEON_BLANCO):
		//distinguir si para la derecha o para la izquierda asegurando de que es para abajo
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha
			if ((m.dest.x + 1 > 9) || (m.dest.y + 1 > 9)) { return false; }
			cout << "el peon blanco come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda
			if ((m.dest.x + 1 > 9) || (m.dest.y - 1 < 0)) { return false; }
			cout << "el peon blanco come" << endl; return true;
		}
		break;
	case(Pieza::PEON_NEGRO): //está permitido que coma hacia arriba  
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha
			if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 9)) { return false; }
			cout << "el peon negro come" << endl; return true;
		}
		if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda
			if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return false; }
			cout << "el peon negro come" << endl; return true;
		}
		break;
	default: break;
	}
}


void Peon::dibuja(obj_t t) {
	float num1 = 0.0f, num2 = 0.0f;
	num1 = +anchocasilla * 0.45f;
	num2 = +anchocasilla * 0.45f;

	switch (t) {
	case (Pieza::PEON_NEGRO):
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/engranaje2.png").id);
		break;
	case (Pieza::PEON_BLANCO):
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/atomo2.png").id);
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