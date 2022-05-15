#include "BotLegal.h"
#include "src/Movimientos.h"


move_t BotLegal::blancaMueve(Master t)
{
	//primero busca una ficha blanca
	//despues segun si es una ficha pregunta por sus movimentos haciendo uso del is_legal

	Peon* fp;
	move_t aux;
	move_t bloqueado = { -1,-1,-1,-1 };	//movimiento que se devuelve si ha perdido porque ya no puede mover

		///////////////////////////////////////////////////////////////////////////////////
		//se pregunta por el movimiento de mover
		for (int i = 0; i < t.n; i++) {
			for (int j = 0; j < t.n; j++) {
				fp = t.peones[i][j];
				if (fp) {
					if (fp->type() == Peon::PEON_BLANCO) //preguntar por los movimientos que pueden hacer los peones blanos
					{
						aux.ori = fp->square();
						//preguntar por el movimiento hacia la izquierda
						aux.dest.x = aux.ori.x + 1;
						aux.dest.y = aux.ori.y - 1;
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la derecha si el de la izquierda no es valido
						else { aux.dest.y = aux.ori.y + 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					}
					/*
					if (fp->type() == Peon::REINA_BLANCA) //preguntar por los movimientos que pueden hacer las damas negras
					{
						aux.ori = fp->square();
						//preguntar por el movimiento hacia la izquierda abajo
						aux.dest.x = aux.ori.x + 1;
						aux.dest.y = aux.ori.y - 1;
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
						else { aux.dest.y = aux.ori.y + 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
						else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
						else { aux.dest.y = aux.ori.y + 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					}
					*/
					/*
					if (fp->type() == Peon::REY_BLANCO) //preguntar por los movimientos que pueden hacer las damas negras
					{
						aux.ori = fp->square();
						//preguntar por el movimiento hacia la izquierda abajo
						aux.dest.x = aux.ori.x + 1;
						aux.dest.y = aux.ori.y - 1;
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
						else { aux.dest.y = aux.ori.y + 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
						else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
						//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
						else { aux.dest.y = aux.ori.y + 1; }
						if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					}
					*/
					//HAY QUE HACER LO MISMO CON LAS DEMÁS. NO SE SI SON NECESARIAS O NO, PERO DE MOMENTO FUNCIONA SIN ELLAS
				}
			}
		}
	

	return bloqueado;
}


move_t BotLegal::negraMueve(Master t)
{
	//primero busca una ficha negra
	//despues segun si es un peon o una dama pregunta por sus movimentos haciendo uso del is_legal

	Peon* fp;
	move_t aux;
	move_t bloqueado = { -1,-1,-1,-1 };	//movimiento que se devuelve si la máquina ha perdido porque ya no puede mover
		
	//se pregunta por el movimiento de mover 
	for (int i = 0; i < t.n; i++) {
		for (int j = 0; j < t.n; j++) {
			fp = t.peones[i][j];
			if (fp) {
				if (fp->type() == Peon::PEON_NEGRO) //preguntar por los movimientos que pueden hacer los peones negros
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda
					aux.dest.x = aux.ori.x - 1;
					aux.dest.y = aux.ori.y - 1;
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha si el de la izquierda no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
				}
				/*
				if (fp->type() == Peon::REINA_NEGRA) //preguntar por los movimientos que pueden hacer las damas negras
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda abajo
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
					else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
				}
				*/
				/*
				if (fp->type() == Peon::REY_NEGRO) //preguntar por los movimientos que pueden hacer las damas negras
				{
					aux.ori = fp->square();
					//preguntar por el movimiento hacia la izquierda abajo
					aux.dest.x = aux.ori.x + 1;
					aux.dest.y = aux.ori.y - 1;
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha abajo si el de la izquierda abajo no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la izquierda arriba si el de la derecha abajo no es valido
					else { aux.dest.x = aux.ori.x - 1; aux.dest.y = aux.ori.y - 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
					//pregunta por el movimiento a la derecha arriba si el de la izquierda arriba no es valido
					else { aux.dest.y = aux.ori.y + 1; }
					if (Movimientos::is_legal(aux, t) == 2) { aux.tipo = 2; return aux; }
				}
				*/
				//HAY QUE HACER LO MISMO CON LAS DEMÁS. NO SE SI SON NECESARIAS O NO, PERO DE MOMENTO FUNCIONA SIN ELLAS
			}
		}
	}
	return bloqueado;
}