#include "Coordinador.h"
#include "ETSIDI.h"
#include "freeglut.h"


Coordinador::Coordinador() {  // empezamos en la pantalla de inicio
	// aqui definimos el estado inicial correspondiente al menú y el tema, que seguirá sonando hasta que cambiemod de estado
	estado = INICIO;
	ETSIDI::playMusica("sonidos/summer_nights.mp3",true);
}

Coordinador::~Coordinador() {

}

void Coordinador::Inicializa() {
	mundo.Inicializa();
}


void Coordinador::Dibuja() {

	if (estado == INICIO) {   //dibujamos la pantalla de inicio
		glDisable(GL_LIGHTING);
		glColor3ub(0, 0, 0);
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0.91, 0.74, 0.24);  //ORO
		ETSIDI::setFont("fuentes/Bitwise.ttf", 50);
		ETSIDI::printxy("AJEDREZ A309", -12, 11);

		ETSIDI::setTextColor(0.75, 0.75, 0.75);  //plata
		ETSIDI::setFont("fuentes/Bitwise.ttf", 40);
		ETSIDI::printxy("INGENIEROS VS FISICOS", -12, 7);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("PULSE 1 PARA COMENZAR", -10, 5);
		ETSIDI::printxy("PULSE S PARA SALIR", -10, 3);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		
	}
	else if (estado == MULTIPLAYER) { // dibujamos el tablero en modo multijugador
		mundo.Dibuja();
		
		
		if (turno == JUGADOR_B) {  //turno de los fisicos
			glDisable(GL_LIGHTING);
			glColor3ub(150, 150, 150);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("TURNO FISICOS", 0, 0);

		}
		if (turno == JUGADOR_N) {   //turno de los ingenieros
			glDisable(GL_LIGHTING);
			glColor3ub(50, 50, 50);
			glutSolidSphere(10, 10, 10);
			glEnable(GL_LIGHTING);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("TURNO INGENIEROS", 0, 0);

		}

	}
	else if (estado == GANA_B) {  //han ganado los fisicos

		glDisable(GL_LIGHTING);
		glColor3ub(192, 192, 192);  //plata
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0); 
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("HAN GANADO LOS FISICOS :(", -5, 10);
		ETSIDI::printxy("Pulsa C para continuar", -5, 9);
		glEnable(GL_LIGHTING);
	}
	else if (estado == GANA_N) {   //han ganado los ingenieros
		glDisable(GL_LIGHTING);
		glColor3ub(234, 190, 63);  //oro
		glutSolidSphere(10, 10, 10);
		glEnable(GL_LIGHTING);
		gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(0, 0, 0);  
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("HAN GANADO LOS INGENIEROS :)", -5, 10);
		ETSIDI::printxy("Pulsa C para continuar", -5, 9);
		glEnable(GL_LIGHTING);
		

	}
	else if (estado == PAUSA) {  //estamos en pausa
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
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/impacto.wav");
			ETSIDI::playMusica("sonidos/partida.mp3", true);
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
	else if (estado == GANA_B|| estado == GANA_N) {
		if (key == 'C' || key == 'c') { estado =INICIO; }

	}
}

void Coordinador::Raton(int b, int state, int x, int y) {

	if (estado == INICIO)
	{

		printf("%d %d %d %d\n", b, state, x, y);
		if (b == 0 && state == 1 && x >= 126 && x <= 470 && y >= 340 && y <= 367)
		{
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/impacto.wav");
			ETSIDI::playMusica("sonidos/partida.mp3");
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
			char n = 'N';
			int aux;  //creamos variable auxiliar
			aux = mundo.MovimientoPlayer('N'); //turno simple (sin cadena). Esta funcion nos devolvera un numero según lo ocurrido
			                                   //La N la forzamos nosotros en esta funcion, ya que nos encontramos en el turno de las negras

			switch (aux)
			{
			case 1:    //se mueve
				ETSIDI::play("sonidos/disparo.wav");
				turno = JUGADOR_B;
				mundo.setMovimiento({ 0,0 }, { 0,0 });  //para evitar error 
				break;
			case 2:
				ETSIDI::play("sonidos/win.mp3");
				estado=GANA_N;  //han ganado
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
			aux = mundo.MovimientoPlayer('B'); //turno simple (sin cadena). Esta funcion nos devolvera un numero según lo ocurrido
												//La B la forzamos nosotros en esta funcion, ya que nos encontramos en el turno de las blancas
			switch (aux)
			{
			case 1:   //se mueven
				ETSIDI::play("sonidos/disparo.wav");
				turno = JUGADOR_N;
				mundo.setMovimiento({ 0,0 }, { 0,0 });
				break;
			case 2:   //han ganado
				ETSIDI::play("sonidos/sonidos/win.mp3");
				estado = GANA_B;
				mundo.setMovimiento({ 0,0 }, { 0,0 });
				break;
			case 4://si me mete en 4 es porque viene de que el movimiento no ha sido valido
				turno = JUGADOR_B;
				break;
			}
		}


	}
	
}