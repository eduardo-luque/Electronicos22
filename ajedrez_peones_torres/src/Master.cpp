#include "Master.h"

Master::Master()
{
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
}
*/

void Master::Inicializa() {  //creamos los peones blancos y negros. tambien torres

	//nulify();

	//creamos fichas blancas
	for (int j = 0; j < n; j += 1) { //vamos creando los peones casilla a casilla
		peones[1][j] = fabrica::create(Peon::PEON_BLANCO, cas_t{ 1,j });
		nFichas++;
	}
	//creamos fichas negras
	for (int j = 0; j < n; j += 1) { //vamos creando los peones casilla a casilla
		peones[6][j] = fabrica::create(Peon::PEON_NEGRO, cas_t{ 6,j });
		nFichas++;
	}
	//creamos torres blancas
	//for (int j = 0; j < n; j += 7) { //vamos creando los peones casilla a casilla
		peones[0][0] = fabrica::create(Peon::TORRE, cas_t{ 0,0 }); //TORRE ARRIBA IZQ
		peones[0][7] = fabrica::create(Peon::TORRE, cas_t{ 0,7 }); //TORRE ARRIBA DRCH
		//nFichas++;
	
	//creamos torres negras
	//for (int j = 0; j < n; j += 7) { //vamos creando los peones casilla a casilla
		peones[7][0] = fabrica::create(Peon::TORRE, cas_t{ 7,0 });//TORRE ABAJO IZQ
		peones[7][7] = fabrica::create(Peon::TORRE, cas_t{ 7,7 });//TORRE ABAJO DRCH
		//nFichas++;
	
}
