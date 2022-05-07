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

void Master::Inicializa() {  //creamos los peones blancos y negros

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

}

