#include "Master.h"

Master::Master()
{//incializamos el vector
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			peones[i][j] = NULL;
		}
	}
}

Master::~Master()
{
}

Master::Master(const Master&)
{
}

/*void Master::nulify()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			peones[i][j] = NULL;
		}
	}
}*/


void Master::Inicializa() {  //creamos los peones blancos y negros. tambien torres

	//nulify();

	//creamos fichas blancas
	for (int j = 0; j < n; j += 1) { //vamos creando los peones blancos casilla a casilla
		peones[1][j] = fabrica::create(Peon::PEON_BLANCO, cas_t{ 1,j });
		nFichas++;
	}

	//creamos torres blancas
		peones[0][0] = fabrica::create(Peon::TORRE_BLANCA, cas_t{ 0,0 }); //TORRE ARRIBA IZQ
		peones[0][7] = fabrica::create(Peon::TORRE_BLANCA, cas_t{ 0,7 }); //TORRE ARRIBA DRCH

	//creamos caballos blancos
		peones[0][1] = fabrica::create(Peon::CABALLO_BLANCO, cas_t{ 0,1 }); 
		peones[0][6] = fabrica::create(Peon::CABALLO_BLANCO, cas_t{ 0,6 }); 
	
	//creamos alfiles blancos
		peones[0][2] = fabrica::create(Peon::ALFIL_BLANCO, cas_t{ 0,2 });
		peones[0][5] = fabrica::create(Peon::ALFIL_BLANCO, cas_t{ 0,5 });

	//creamos dama blanca
		peones[0][3] = fabrica::create(Peon::DAMA_BLANCA, cas_t{ 0,3 });

	//creamos rey blanco
		peones[0][4] = fabrica::create(Peon::REY_BLANCO, cas_t{ 0,4 });

	//creamos fichas negras
	for (int j = 0; j < n; j += 1) { //vamos creando los peones negros casilla a casilla
		peones[6][j] = fabrica::create(Peon::PEON_NEGRO, cas_t{ 6,j });
		nFichas++;
	}

	//creamos torres negras
		peones[7][0] = fabrica::create(Peon::TORRE_NEGRA, cas_t{ 7,0 });//TORRE ABAJO IZQ
		peones[7][7] = fabrica::create(Peon::TORRE_NEGRA, cas_t{ 7,7 });//TORRE ABAJO DRCH
	
	//creamos caballos negros
		peones[7][1] = fabrica::create(Peon::CABALLO_NEGRO, cas_t{ 7,1 });
		peones[7][6] = fabrica::create(Peon::CABALLO_NEGRO, cas_t{ 7,6 });
		
	//creamos alfiles negros
		peones[7][2] = fabrica::create(Peon::ALFIL_NEGRO, cas_t{ 7,2 });
		peones[7][5] = fabrica::create(Peon::ALFIL_NEGRO, cas_t{ 7,5 });

	//creamos dama negra
		peones[7][3] = fabrica::create(Peon::DAMA_NEGRA, cas_t{ 7,3 });
		
	//creamos rey negro
		peones[7][4] = fabrica::create(Peon::REY_NEGRO, cas_t{ 7,4 });
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

Master& Master::operator-=(const Peon& f)
{
	//remove the object which occupies the square 
	cas_t c = f.square();
	if (peones[c.x][c.y] != NULL) {
		delete peones[c.x][c.y];
		peones[c.x][c.y] = NULL;
		nFichas--;
	}
	return *this;
}


//QUE YO SEPA EL OPERADOR IGUAL UNCA SE DEBE SOBREECARGAR
/*Master& Master::operator=(const Master& rhs)
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
   
}*/
