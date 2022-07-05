#include "Master.h"

void Master::nulify()  //hacemos nulo toda la matriz tablero
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			peones[i][j] = NULL;
		}
	}
}

Master::Master(const Master& rhs) :nFichas(rhs.nFichas) {  //creamos las fichas necesarias
	nulify();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Pieza* f = rhs.peones[i][j];   //aunque ponga peones, es enrealidad el tablero
			if (f != NULL) {
				peones[i][j] = Pieza::create(*f);
			}
		}
	}
}

void Master::Inicializa() {  //creamos los peones blancos y negros. tambien torres

	nulify();

	//creamos fichas blancas
	for (int j = 1; j < n; j += 1) { //vamos creando los peones blancos casilla a casilla
		peones[2][j] = Pieza::create(Pieza::PEON_BLANCO, cas_t{ 2,j });
		//nFichas++;
	}

	//creamos torres blancas
		peones[1][1] = Pieza::create(Pieza::TORRE_BLANCA, cas_t{ 1,1 }); //TORRE ARRIBA IZQ
		peones[1][8] = Pieza::create(Pieza::TORRE_BLANCA, cas_t{ 1,8 }); //TORRE ARRIBA DRCH

	//creamos caballos blancos
		peones[1][2] = Pieza::create(Pieza::CABALLO_BLANCO, cas_t{ 1,2 }); 
		peones[1][7] = Pieza::create(Pieza::CABALLO_BLANCO, cas_t{ 1,7 });
	
	//creamos alfiles blancos
		peones[1][3] = Pieza::create(Pieza::ALFIL_BLANCO, cas_t{ 1,3 });
		peones[1][6] = Pieza::create(Pieza::ALFIL_BLANCO, cas_t{ 1,6 });

	//creamos reina blanca
		peones[1][4] = Pieza::create(Pieza::REINA_BLANCA, cas_t{ 1,4 });
		//nFichas++;
	//creamos rey blanco
		peones[1][5] = Pieza::create(Pieza::REY_BLANCO, cas_t{ 1,5 });
		//nFichas++;

	//creamos fichas negras
	for (int j = 1; j < n; j += 1) { //vamos creando los peones negros casilla a casilla
		peones[7][j] = Pieza::create(Pieza::PEON_NEGRO, cas_t{ 7,j });
		//nFichas++;
	}

	//creamos torres negras
		peones[8][1] = Pieza::create(Pieza::TORRE_NEGRA, cas_t{ 8,1 });//TORRE ABAJO IZQ
		peones[8][8] = Pieza::create(Pieza::TORRE_NEGRA, cas_t{ 8,8 });//TORRE ABAJO DRCH
	
	//creamos caballos negros
		peones[8][2] = Pieza::create(Pieza::CABALLO_NEGRO, cas_t{ 8,2 });
		peones[8][7] = Pieza::create(Pieza::CABALLO_NEGRO, cas_t{ 8,7 });
		
	//creamos alfiles negros
		peones[8][3] = Pieza::create(Pieza::ALFIL_NEGRO, cas_t{ 8,3 });
		peones[8][6] = Pieza::create(Pieza::ALFIL_NEGRO, cas_t{ 8,6 });

	//creamos REINA negra
		peones[8][4] = Pieza::create(Pieza::REINA_NEGRA, cas_t{ 8,4 });
		//nFichas++;
	//creamos rey negro
		peones[8][5] = Pieza::create(Pieza::REY_NEGRO, cas_t{ 8,5 });
		//nFichas++;
}

int Master::number_of_pieces()   //contamos las piezas que hay
{
	nFichas = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (peones[i][j] != NULL) { nFichas++; }
		}
	}
	return nFichas;
}

Master::~Master() { }

//OPERADORES SOBRECARGADOS PARA CREAR Y DESTRUIR FICHAS EN EL TABLERO. LO UTILIZAMOS EN MOVIMIENTOS
Master& Master::operator-=(const Pieza& f) {
	cas_t c = f.square();
	if (peones[c.x][c.y] != NULL) {  //
		delete peones[c.x][c.y];
		peones[c.x][c.y] = NULL;
	}
	nFichas--;
	return *this;
}

Master& Master::operator +=(const Pieza& f) {
	cas_t c = f.square();
	if (peones[c.x][c.y] != NULL) {
		delete peones[c.x][c.y];
		peones[c.x][c.y] = NULL;
	}
	peones[c.x][c.y] = Pieza::create(f);
	nFichas++;
	return *this;
}


// jaque  //
/*
bool Master::detectar_jaque(Pieza::obj_t tipo, cas_t casilla) {//argumentos:rey del color negro o blanco, casilla del rey,vector de piezas

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (peones[i][j] != NULL) { 
				Pieza* f = peones[i][j];
				if (f->type() == Pieza::PEON_NEGRO || f->type() == Pieza::REINA_NEGRA || f->type() == Pieza::REY_NEGRO || f->type() == Pieza::TORRE_NEGRA || f->type() == Pieza::ALFIL_NEGRO || f->type() == Pieza::CABALLO_NEGRO) {
					//comprobamos todos sus movimientos legales, y si alguno de ellos coincide con la casilla del rey
					move_t casillas;
					casillas.dest = casilla;
					if (f->movimiento(Pieza::PEON_NEGRO, casillas) == true && casilla = Pieza::REY_NEGRO) { return true; };//si es un movimiento 
					//legal permitido entonces hay jaque









					if (f->movimiento(Pieza::REINA_NEGRA, casillas) == true) { return true; };
					if (f->movimiento(Pieza::TORRE_NEGRA, casillas) == true) { return true; };
					if (f->movimiento(Pieza::ALFIL_NEGRO, casillas) == true) { return true; };
					if (f->movimiento(Pieza::CABALLO_NEGRO, casillas) == true) { return true; };
				}
			}
		}
	}
}
*/

