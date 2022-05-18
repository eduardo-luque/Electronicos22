#include "Master.h"

void Master::nulify()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			peones[i][j] = NULL;
		}
	}
}


Master::Master(const Master& rhs) :nFichas(rhs.nFichas) {
	nulify();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Peon* f = rhs.peones[i][j];
			if (f != NULL) {
				peones[i][j] = fabrica::create(*f);
			}
		}
	}
}

/*
Master::Master() :nFichas(0)
{
	nulify();

	/////////////////////////
	//configuraci�n inicial//

		//fichas blancas

	for (int j = 0; j < n; j += 2) {
		peones[1][j] = fabrica::create(Peon::PEON_BLANCO, cas_t{ 1,j });
		nFichas++;
	}
	peones[0][3] = fabrica::create(Peon::REINA_BLANCA, cas_t{ 0,3 });
	nFichas++;
	//fichas negras

	for (int j = 1; j < n; j += 2) {
		peones[6][j] = fabrica::create(Peon::PEON_NEGRO, cas_t{ 6,j });
		nFichas++;
	}
	peones[7][4] = fabrica::create(Peon::REY_NEGRO, cas_t{ 7,4 });
	nFichas++;
}
*/


void Master::Inicializa() {  //creamos los peones blancos y negros. tambien torres

	nulify();

	//creamos fichas blancas
	for (int j = 1; j < n; j += 1) { //vamos creando los peones blancos casilla a casilla
		peones[2][j] = fabrica::create(Peon::PEON_BLANCO, cas_t{ 2,j });
		nFichas++;
	}

	//creamos torres blancas
		peones[1][1] = fabrica::create(Peon::TORRE_BLANCA, cas_t{ 1,1 }); //TORRE ARRIBA IZQ
		peones[1][8] = fabrica::create(Peon::TORRE_BLANCA, cas_t{ 1,8 }); //TORRE ARRIBA DRCH

	//creamos caballos blancos
		peones[1][2] = fabrica::create(Peon::CABALLO_BLANCO, cas_t{ 1,2 }); 
		peones[1][7] = fabrica::create(Peon::CABALLO_BLANCO, cas_t{ 1,7 }); 
	
	//creamos alfiles blancos
		peones[1][3] = fabrica::create(Peon::ALFIL_BLANCO, cas_t{ 1,3 });
		peones[1][6] = fabrica::create(Peon::ALFIL_BLANCO, cas_t{ 1,6 });

	//creamos reina blanca
		peones[1][4] = fabrica::create(Peon::REINA_BLANCA, cas_t{ 1,4 });
		nFichas++;
	//creamos rey blanco
		peones[1][5] = fabrica::create(Peon::REY_BLANCO, cas_t{ 1,5 });
		nFichas++;

	//creamos fichas negras
	for (int j = 1; j < n; j += 1) { //vamos creando los peones negros casilla a casilla
		peones[7][j] = fabrica::create(Peon::PEON_NEGRO, cas_t{ 7,j });
		nFichas++;
	}

	//creamos torres negras
		peones[8][1] = fabrica::create(Peon::TORRE_NEGRA, cas_t{ 8,1 });//TORRE ABAJO IZQ
		peones[8][8] = fabrica::create(Peon::TORRE_NEGRA, cas_t{ 8,8 });//TORRE ABAJO DRCH
	
	//creamos caballos negros
		peones[8][2] = fabrica::create(Peon::CABALLO_NEGRO, cas_t{ 8,2 });
		peones[8][7] = fabrica::create(Peon::CABALLO_NEGRO, cas_t{ 8,7 });
		
	//creamos alfiles negros
		peones[8][3] = fabrica::create(Peon::ALFIL_NEGRO, cas_t{ 8,3 });
		peones[8][6] = fabrica::create(Peon::ALFIL_NEGRO, cas_t{ 8,6 });

	//creamos REINA negra
		peones[8][4] = fabrica::create(Peon::REINA_NEGRA, cas_t{ 8,4 });
		nFichas++;
	//creamos rey negro
		peones[8][5] = fabrica::create(Peon::REY_NEGRO, cas_t{ 8,5 });
		nFichas++;
}


int Master::number_of_pieces()
{
	nFichas = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (peones[i][j] != NULL) { nFichas++; }
		}
	}

	return nFichas;
}

Master::~Master() {
	////////////////////////////////////////////////////////////////////////////////////////////
	//Destructor que tiene las responsabilidad de eliminar los objetos creados por la factor�a//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (peones[i][j] != NULL) 
			{ delete peones[i][j]; }
		}
	}
}

//QUE YO SEPA EL OPERADOR IGUAL UNCA SE DEBE SOBREECARGAR
/*
Master& Master::operator=(const Master& rhs)
{
	if (this != &rhs) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Peon* f = rhs.peones[i][j];
				if (f != NULL) {
					peones[i][j] = fabrica::create(*f);
				}
				else {
					peones[i][j] = NULL;
				}
			}
		}
	}
	return *this;
   
}
*/

Master& Master::operator-=(const Peon& f)
{
	//remove the object which occupies the square 
	cas_t c = f.square();
	if (peones[c.x][c.y] != NULL) {  //
		delete peones[c.x][c.y];
		peones[c.x][c.y] = NULL;

	}
	nFichas--;
	return *this;
}

Master& Master::operator +=(const Peon& f) {

	//remove the object which occupies the square 
	cas_t c = f.square();

	if (peones[c.x][c.y] != NULL) {
		delete peones[c.x][c.y];
		peones[c.x][c.y] = NULL;
	}
	//create a new object copying the original one (uses explicit DOWNCAST)
	peones[c.x][c.y] = fabrica::create(f);
	nFichas++;
	return *this;
}