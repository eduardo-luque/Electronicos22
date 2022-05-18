#include "Master.h"

void Master::nulify()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			piezas[i][j] = NULL;
		}
	}
}


Master::Master(const Master& rhs) :nFichas(rhs.nFichas) {
	nulify();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Pieza* f = rhs.piezas[i][j];
			if (f != NULL) {
				piezas[i][j] = fabrica::create(*f);
			}
		}
	}
}

/*
Master::Master() :nFichas(0)
{
	nulify();

	/////////////////////////
	//configuración inicial//

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
		piezas[2][j] = fabrica::create(Pieza::PEON_BLANCO, cas_t{ 2,j });
		nFichas++;
	}

	//creamos torres blancas
		piezas[1][1] = fabrica::create(Pieza::TORRE_BLANCA, cas_t{ 1,1 }); //TORRE ARRIBA IZQ
		piezas[1][8] = fabrica::create(Pieza::TORRE_BLANCA, cas_t{ 1,8 }); //TORRE ARRIBA DRCH

	//creamos caballos blancos		
		piezas[1][2] = fabrica::create(Pieza::CABALLO_BLANCO, cas_t{ 1,2 }); 
		piezas[1][7] = fabrica::create(Pieza::CABALLO_BLANCO, cas_t{ 1,7 }); 

	//creamos alfiles blancos
		piezas[1][3] = fabrica::create(Pieza::ALFIL_BLANCO, cas_t{ 1,3 });
		piezas[1][6] = fabrica::create(Pieza::ALFIL_BLANCO, cas_t{ 1,6 });

	//creamos reina blanca
		piezas[1][4] = fabrica::create(Pieza::REINA_BLANCA, cas_t{ 1,4 });
		nFichas++;
	//creamos rey blanco
		piezas[1][5] = fabrica::create(Pieza::REY_BLANCO, cas_t{ 1,5 });
		nFichas++;

	//creamos fichas negras
	for (int j = 1; j < n; j += 1) { //vamos creando los peones negros casilla a casilla
		piezas[7][j] = fabrica::create(Pieza::PEON_NEGRO, cas_t{ 7,j });
		nFichas++;
	}

	//creamos torres negras
		piezas[8][1] = fabrica::create(Pieza::TORRE_NEGRA, cas_t{ 8,1 });//TORRE ABAJO IZQ
		piezas[8][8] = fabrica::create(Pieza::TORRE_NEGRA, cas_t{ 8,8 });//TORRE ABAJO DRCH
	
	//creamos caballos negros
		piezas[8][2] = fabrica::create(Pieza::CABALLO_NEGRO, cas_t{ 8,2 });
		piezas[8][7] = fabrica::create(Pieza::CABALLO_NEGRO, cas_t{ 8,7 });
		
	//creamos alfiles negros
		piezas[8][3] = fabrica::create(Pieza::ALFIL_NEGRO, cas_t{ 8,3 });
		piezas[8][6] = fabrica::create(Pieza::ALFIL_NEGRO, cas_t{ 8,6 });

	//creamos REINA negra
		piezas[8][4] = fabrica::create(Pieza::REINA_NEGRA, cas_t{ 8,4 });
		nFichas++;
	//creamos rey negro
		piezas[8][5] = fabrica::create(Pieza::REY_NEGRO, cas_t{ 8,5 });
		nFichas++;
}


int Master::number_of_pieces()
{
	nFichas = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (piezas[i][j] != NULL) { nFichas++; }
		}
	}
	return nFichas;
}

Master::~Master() {
	////////////////////////////////////////////////////////////////////////////////////////////
	//Destructor que tiene las responsabilidad de eliminar los objetos creados por la factoría//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (piezas[i][j] != NULL) 
			{ 
				delete piezas[i][j]; 
			}
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

Master& Master::operator-=(const Pieza& f)
{
	//remove the object which occupies the square 
	cas_t c = f.square();
	if (piezas[c.x][c.y] != NULL) {  //
		delete piezas[c.x][c.y];
		piezas[c.x][c.y] = NULL;

	}
	nFichas--;
	return *this;
}

Master& Master::operator +=(const Pieza& f) {

	//remove the object which occupies the square 
	cas_t c = f.square();

	if (piezas[c.x][c.y] != NULL) {
		delete piezas[c.x][c.y];
		piezas[c.x][c.y] = NULL;
	}
	//create a new object copying the original one (uses explicit DOWNCAST)
	piezas[c.x][c.y] = fabrica::create(f);
	nFichas++;
	return *this;
}
