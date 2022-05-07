#include "Coordinador.h"
#include "ETSIDI.h"
#include "freeglut.h"

Coordinador::Coordinador() {  //empezamos en la pantalla de inicio

	estado = INICIO;

}

Coordinador::~Coordinador() {

}

void Coordinador::Inicializa() {
	mundo.Inicializa();
}


void Coordinador::Dibuja() {

	if (estado == INICIO) {   //dibujamos la pantalla de inicio
		glDisable(GL_LIGHTING);
		glColor3ub(255, 255, 255);
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 50);
		ETSIDI::printxy("AJEDREZ A309", -12, 10);
		ETSIDI::setTextColor(0.8, 0.8, 0.8);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("1. SINGLEPLAYER", -10, 7);
		ETSIDI::printxy("2. MULTIPLAYER", -10, 5);
		ETSIDI::printxy("S. SALIR", -10, 3);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
	}
	else if (estado == MULTIPLAYER) {
		mundo.Dibuja();

	}
}
void Coordinador::Tecla(unsigned char key) {

	if (estado == INICIO) {
			//if (key == '1') { Inicializa(); estado = SOLO}
		if (key == '2') { mundo.Inicializa(); estado = MULTIPLAYER; }
			//else if (key == 'S' || key == 's') { exit(0); }
		}
	}
