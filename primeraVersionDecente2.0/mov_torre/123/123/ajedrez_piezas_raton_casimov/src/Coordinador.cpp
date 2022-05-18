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
		ETSIDI::printxy("AJEDREZ A309", -12, 11);
		ETSIDI::setTextColor(0.8, 0.8, 0.8);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		
		ETSIDI::printxy("PULSE 1 PARA COMENZAR", -10, 5);
		ETSIDI::printxy("PULSE S PARA SALIR", -10, 3);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		
	}
	else if (estado == MULTIPLAYER) { // dibujamos el tablero
		mundo.Dibuja();
		
		
		if (turno == JUGADOR_B) {  //la pantalla de fondo cambia
			glDisable(GL_LIGHTING);
			glColor3ub(150, 150, 150);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("TURNO BLANCAS", 0, 0);

		}
		if (turno == JUGADOR_N) {   //la pantalla de fondo cambia
			glDisable(GL_LIGHTING);
			glColor3ub(50, 50, 50);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("TURNO NEGRAS", 0, 0);

		}

	}
	else if (estado == GANA_B) {
		glDisable(GL_LIGHTING);
		glColor3ub(192, 192, 192);  //plata
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
	}
	else if (estado == GANA_N) {
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 63);  //oro
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		

	}
	else if (estado == PAUSA) {
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 63);   //oro
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 50);
		ETSIDI::printxy("PAUSA", -3, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("PULSE -P- PARA CONTINUAR", -10, 7);
	}

}
void Coordinador::Tecla(unsigned char key) {

	if (estado == INICIO) {
		
		if (key == '1') {
			mundo.Inicializa(); estado = MULTIPLAYER;  turno = JUGADOR_B;  //Inicializamos coordinador, y le damos el turno al jugador B
		}
		else if (key == 'S' || key == 's') { exit(0); }
	}
	else if (estado == MULTIPLAYER) {
		if (key == 'P' || key == 'p') { estado = PAUSA; }
	}
	else if (estado == PAUSA) {
		if (key == 'P' || key == 'p') { estado = MULTIPLAYER; }

	}

}

void Coordinador::Raton(int b, int state, int x, int y) {

	if (estado == INICIO) 
	{

		printf("%d %d %d %d\n", b,state,x,y);
		if (b == 0 && state == 1 && x >= 126 && x <= 470 && y >= 340 && y <= 367)
		{
			
			mundo.Inicializa();
			turno = JUGADOR_B;
			estado = MULTIPLAYER;
			printf("raton pulsado en multiplayer\n");
		}
		if (b == 0 && state == 1 && x >= 126 && x <= 470 && y >= 397 && y <= 421)
		{
			printf("raton pulsado en salir\n");
			exit(0);
		}
	}
	
	//seleccion de turnos
	if (turno == JUGADOR_B)
	{
		mundo.Raton(x, y, b, state, 'b');
	}
	if (turno == JUGADOR_N)
	{
		mundo.Raton(x, y, b, state, 'n');
	}

}

void Coordinador::TurnoMultiplayer()
{
	if (estado == MULTIPLAYER)
	{
		if (turno == JUGADOR_N)
		{

			int aux;
			aux = mundo.MovimientoPlayer('N'); //turno simple 

			switch (aux)
			{
			case 1:

				turno = JUGADOR_B;
				mundo.setMovimiento({ 0,0 }, { 0,0 });
				break;
			case 2:

				estado=GANA_N;
				mundo.setMovimiento({ 0,0 }, { 0,0 });
				break;

			case 4://movimiento no valido
				turno = JUGADOR_N;
				break;
			}
		}

		if (turno == JUGADOR_B)
		{
			int aux;
			aux = mundo.MovimientoPlayer('B'); //turno simple 

			switch (aux)
			{
			case 1:

				turno = JUGADOR_N;
				mundo.setMovimiento({ 0,0 }, { 0,0 });
				break;
			case 2:

				estado = GANA_B;
				mundo.setMovimiento({ 0,0 }, { 0,0 });
				break;
			case 4:
				turno = JUGADOR_B;
				break;
			}
		}


	}
	
}