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
		ETSIDI::printxy("1. ", -10, 7);
		ETSIDI::printxy("2. MULTIPLAYER", -10, 5);
		ETSIDI::printxy("S. SALIR", -10, 3);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		
	}
	else if (estado == MULTIPLAYER) { // dibujamos el tablero
		mundo.Dibuja();
		if (turno == JUGADOR_B) {  //la pantalla de fondo cambia
			glDisable(GL_LIGHTING);
			glColor3ub(100, 100, 100);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
		}
		if (turno == JUGADOR_N) {   //la pantalla de fondo cambia
			glDisable(GL_LIGHTING);
			glColor3ub(100, 100, 100);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
		}

	}
}
void Coordinador::Tecla(unsigned char key) {

	if (estado == INICIO) {
			//if (key == '1') { Inicializa(); estado = SOLO}
		if (key == '2') {
			mundo.Inicializa(); estado = MULTIPLAYER;  turno = JUGADOR_B;  //Inicializamos coordinador, y le damos el turno al jugador B
		}
		//else if (key == 'S' || key == 's') { exit(0); }
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
		//mundo.setMovimiento({ 0,0 }, { 0,0 });
		if (turno == JUGADOR_N)
		{
			int aux;
			aux = mundo.MovimientoHumano('N', 's'); //turno simple negra(sin cadena)
			mundo.setMovimiento({ 0,0 }, { 5,5 });  //con esta funcion puedo forzar el movimiento
		}

		else if (turno == JUGADOR_B)
		{
			int aux;
			aux = mundo.MovimientoHumano('B', 's'); //turno simple blanca(sin cadena)

			mundo.setMovimiento({ mundo.origen_b }, { mundo.destino_b });  //con esta funcion puedo forzar el movimiento

			//turno = JUGADOR_N;
			//mundo.setMovimiento({ 0,0 }, { 3,3});  //con esta funcion puedo forzar el movimiento
		}
	}

}
