#include "Movimientos.h"
#include "math.h"


int Movimientos::is_legal(move_t m, const Master& t)
{
	//CONDICIONES DE QUE SEA LEGAL EL MOVIMIENTO

	//A) nuestro origen tiene que ser una ficha
	Pieza* fo = t.peones[m.ori.x][m.ori.y];

	if (fo == NULL) { 
		
		return 0; }


	//B) el destino tiene que ser  ficha contraria
	Pieza* fd = t.peones[m.dest.x][m.dest.y];

	if (fd) {//CASILLA DESTINO LLENA
		if (fd->type() == Pieza::PEON_NEGRO || fd->type() == Pieza::REINA_NEGRA || fd->type() == Pieza::REY_NEGRO || fd->type() == Pieza::TORRE_NEGRA || fd->type()==Pieza::ALFIL_NEGRO || fd->type()==Pieza::CABALLO_NEGRO) {
			if (fo->type() == Pieza::PEON_NEGRO || fo->type() == Pieza::REINA_NEGRA || fo->type() == Pieza::REY_NEGRO || fo->type() == Pieza::TORRE_NEGRA || fo->type()==Pieza::ALFIL_NEGRO || fo->type()==Pieza::CABALLO_NEGRO) {
			   
				return 0;
			}
		}
		if (fd->type() == Pieza::PEON_BLANCO || fd->type() == Pieza::REINA_BLANCA || fd->type() == Pieza::REY_BLANCO || fd->type() == Pieza::TORRE_BLANCA || fd->type() == Pieza::ALFIL_BLANCO|| fd->type() == Pieza::CABALLO_BLANCO) {
			if (fo->type() == Pieza::PEON_BLANCO || fo->type() == Pieza::REINA_BLANCA || fo->type() == Pieza::REY_BLANCO || fo->type() == Pieza::TORRE_BLANCA || fo->type()==Pieza::ALFIL_BLANCO || fo->type()== Pieza::CABALLO_BLANCO) {
				
				return 0;
			}
		}
		//los reyes no se pueden comer entre si (regla ajedrez)
		if ( fd->type() == Pieza::REY_BLANCO || fd->type() == Pieza::REY_NEGRO) 
		{
			if ( fo->type() == Pieza::REY_BLANCO || fo->type() == Pieza::REY_NEGRO) {
				
				return 0;
			}
		}
	}

	//C)SI MATAMOS AL REY
	// 
	if (fd) {//CASILLA DESTINO LLENA
		if (fd->type() == Pieza::REY_NEGRO || fd->type() == Pieza::REY_BLANCO) {
			if (fo->type() == Pieza::PEON_NEGRO || fo->type() == Pieza::REINA_NEGRA || fo->type() == Pieza::REY_NEGRO || fo->type() == Pieza::TORRE_NEGRA || fo->type()==Pieza::ALFIL_NEGRO || fo->type() == Pieza::CABALLO_NEGRO || fo->type() == Pieza::PEON_BLANCO || fo->type() == Pieza::REINA_BLANCA || fo->type() == Pieza::REY_BLANCO || fo->type() == Pieza::TORRE_BLANCA || fo->type() == Pieza::ALFIL_BLANCO || fo->type() == Pieza::CABALLO_BLANCO) {
				cout << "SE ACABA LA PARTIDA" << endl;
				return 3;
			}
		}
	}
	//
	//D) Movimiento permitido simple
	if (!fd) { //CASILLA DESTINO VACIA
		switch (fo->type())
		{
		case(Pieza::PEON_BLANCO)://está permitido que avance hacia abajo(sumarle 1 o 2 a la x)  
			if (m.ori.x == 2) {
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y)) { cout << "movimiento valido" << endl; return 2; }
				else { return 0; }
			}
			else{
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y)) { cout << "movimiento valido" << endl; return 2; }
				else { return 0; }
			}
			break;
		case(Pieza::PEON_NEGRO)://está permitido que avance hacia arriba(resta 1 o 2 a la x) 
			if (m.ori.x == 7) {
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y)) { cout << "movimiento valido" << endl; return 2; }
				else { return 0; }
			}
			else {
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y)) { cout << "movimiento valido" << endl; return 2; }
				else { return 0; }
			}
			break;
		case(Pieza::REINA_NEGRA):case(Pieza::REINA_BLANCA):
			for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
					(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))
				{
				
					cout << "movimiento valido " << endl; return 2;
				}
				//este bucle cubre todos los posibles movimientos horizontales de la REINA
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))
				{
				
					cout << "movimiento valido " << endl; return 2;
				}
			}
			break;
		
		case(Pieza::REY_NEGRO):case(Pieza::REY_BLANCO):
			//movimientos diagonales
			if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) {
				cout << "movimiento valido " << endl; return 2;
			}
			//movimientos horizontales
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
				(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1))
			{
				cout << "movimiento valido " << endl; return 2;
			}

			break;
		//movimientos horizontales
		case(Pieza::TORRE_NEGRA):case(Pieza::TORRE_BLANCA):
			for (int i = 1; i < 9; i++) {
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
					cout << "movimiento valido " << endl; return 2;
				}
			}
			break;
		//movimientos diagonales
		case(Pieza::ALFIL_BLANCO):case(Pieza::ALFIL_NEGRO):
			for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
				if (((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) || ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) ||
					((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) || ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i)))
				{
					cout << "movimiento valido " << endl; return 2;
				}
			}
			break;
		
		case(Pieza::CABALLO_NEGRO):
			//movs caballo
			if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2)
			{
				cout << "movimiento valido " << endl; return 2;
			}
			else { return 0; }
			break;
		case(Pieza::CABALLO_BLANCO):
			//movs caballo
			if ((m.dest.x < 9) && (m.dest.x > 0) && (m.dest.y < 9) && (m.dest.y > 0)) {
				if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2)
				{
					cout << "movimiento valido " << endl; return 2;
				}
			}
			else { return 0; }
			break;

		default:
			break;
		}

		

	}

	//E) Movimiento de comer, tiene que haber ficha en el destino
	if (fd) { //CASILLA DESTINO LLENA
	
		switch (fo->type())
		{
		case(Pieza::PEON_BLANCO):

			//distinguir si para la derecha o para la izquierda asegurando de que es para abajo

			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha
			{
				

				if ((m.dest.x + 1 > 9) || (m.dest.y + 1 > 9)) { return 0; }

				
					cout << "el peon blanco come" << endl;
					return 1;
			
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) //diagonal izquierda
			{
				

				if ((m.dest.x + 1 > 9) || (m.dest.y - 1 < 0)) { return 0; }

			
					cout << "el peon blanco come" << endl;
					return 1;
				
			}
			break;
		case(Pieza::PEON_NEGRO): //está permitido que coma hacia arriba  
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 9)) { return 0; }

				
					cout << "el peon negro come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1)) //diagonal izquierda
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el peon negro come" << endl;
					return 1;
				
			}
			break;
		case(Pieza::REINA_NEGRA):case(Pieza::REINA_BLANCA):
			for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles moVimientos diagonales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) //diagonal derecha inferior tantas posiciones como me permita el tablero
				{
					

					if ((m.dest.x > 9) || (m.dest.y > 9)) { return 0; } //si me salgo del tablero no como obviamente

					
						cout << "LA REINA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) //diagonal izquierda inferior
				{
					

					if ((m.dest.x > 9) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) //diagonal derecha superior
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 9)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))//diagonal izquierda superior
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA COME" << endl;
						return 1;
					
				}
			}
			for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos verticales y horizontales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) //vertical abajo, tantas posiciones como me permita el tablero
				{
					

					if ((m.dest.x > 9) || (m.dest.y > 9)) { return 0; } //si me salgo del tablero no como obviamente

				
						cout << "LA REINA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) //vertical arriba
				{
					

					if ((m.dest.x > 9) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) //horizontal a la derecha
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 9)) { return 0; }//si me salgo del tablero

				
						cout << "LA REINA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))//horizontal a la izquierda
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

						cout << "LA REINA COME" << endl;
						return 1;
					
				}
			}
			break;

		case(Pieza::REY_NEGRO):	case(Pieza::REY_BLANCO):
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha inferior
			{
				
				if ((m.dest.x + 1 > 9) || (m.dest.y + 1 > 9)) { return 0; }

				
					cout << "el REY come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) //diagonal izquierda inferior
			{
				

				if ((m.dest.x + 1 > 9) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el REY come" << endl;
					return 1;
				
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha superior
			{
				
				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 9)) { return 0; }

			
					cout << "el REY come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el REY come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y)) //vertical abajo
			{


				if ((m.dest.x > 9) || (m.dest.y > 9)) { return 0; } //si me salgo del tablero no como obviamente


				cout << "el rey COME" << endl;
				return 1;

			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y)) //vertical arriba
			{


				if ((m.dest.x > 9) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero


				cout << "el rey COME" << endl;
				return 1;

			}

			if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1)) //horizontal a la derecha
			{


				if ((m.dest.x < 0) || (m.dest.y > 9)) { return 0; }//si me salgo del tablero


				cout << "el rey come" << endl;
				return 1;

			}

			if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1))//horizontal a la izquierda
			{


				if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

				cout << "el rey COME" << endl;
				return 1;

			}
			
			break;
		
		case(Pieza::TORRE_NEGRA):case(Pieza::TORRE_BLANCA):
			for (int i = 1; i < 9; i++) {
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) 
				{
					
					if ((m.dest.x > 9) || (m.dest.y > 9)) { return 0; }

					
						cout << "LA TORRE come" << endl;
						return 1;
					
				}
				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) 
				{
					

					if ((m.dest.x > 9) || (m.dest.y < 0)) { return 0; }

					
						cout << "LA TORRE come" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) 
				{
					
					if ((m.dest.x < 0) || (m.dest.y > 9)) { return 0; }

					
						cout << "LA TORRE come" << endl;
						return 1;
					
				}
				if ((m.dest.x == m.ori.x ) && (m.dest.y == m.ori.y - i))
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }

			
						cout << "LA TORRE come" << endl;
						return 1;
					
				}
			}
			break;
		
		case(Pieza::ALFIL_BLANCO):case(Pieza::ALFIL_NEGRO):
			for (int i = 0; i < 9; i++) { //este bucle cubre todos los posibles moVimientos diagonales del alfil, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) //diagonal derecha inferior tantas posiciones como me permita el tablero
				{


					if ((m.dest.x > 9) || (m.dest.y > 9)) { return 0; } //si me salgo del tablero no como obviamente

					cout << "ALFIL COME" << endl;
					return 1;

				}

				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) //diagonal izquierda inferior
				{


					if ((m.dest.x > 9) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero


					cout << "ALFIL  COME" << endl;
					return 1;

				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) //diagonal derecha superior
				{


					if ((m.dest.x < 0) || (m.dest.y > 9)) { return 0; }//si me salgo del tablero


					cout << "ALFIL COME" << endl;
					return 1;

				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))//diagonal izquierda superior
				{


					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero


					cout << "ALFIL COME" << endl;
					return 1;

				}
			}
			break;
		
		case(Pieza::CABALLO_BLANCO):
			if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y - 1))//salto vertical arriba derecha
			{
				if ((m.dest.x > 9) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y + 1))//salto vertical arriba izqda
			{
				if ((m.dest.x > 9) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y - 1))//salto vertical abajo dcha
			{
				if ((m.dest.x < 0) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y + 1))//salto vertical abajo izqda
			{
				if ((m.dest.x < 0) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 2))//salto horizontal arriba izquierda
			{
				if ((m.dest.x < 0) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 2))//salto horizontal arriba derecha
			{
				if ((m.dest.x < 0) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 2))//salto horizontal abajo derecha
			{
				if ((m.dest.x > 9) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 2))//salto horizontal abajo izqda
			{
				if ((m.dest.x > 9) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO BLANCO COME" << endl;
				return 1;
			}
			
			break;

		case(Pieza::CABALLO_NEGRO):
			if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y + 1))//salto arriba derecha
			{
				if ((m.dest.x < 0) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x - 2) && (m.dest.y == m.ori.y - 1))//salto vertical arriba izqda
			{
				if ((m.dest.x < 0) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y + 1))//salto vertical abajo derecha
			{
				if ((m.dest.x > 9) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x + 2) && (m.dest.y == m.ori.y - 1))//salto vertical abajo izqda
			{
				if ((m.dest.x > 9) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 2))//salto horizontal arriba derecha
			{
				if ((m.dest.x < 0) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 2))//salto horizontal arriba izquierda
			{
				if ((m.dest.x < 0) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 2))//salto horizontal abajo derecha
			{
				if ((m.dest.x > 9) || (m.dest.y > 9))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 2))//salto horizontal abajo izquierda
			{
				if ((m.dest.x > 9) || (m.dest.y < 0))
				{
					return 0;
				}
				cout << "CABALLO NEGRO COME" << endl;
				return 1;
			}

			break;


		default:
				break;
		}
	}
	return 0;
}

int Movimientos::move(move_t m, Master& t) //en esta funcion, crearemos la pieza en la casilla de destino. Si hemos comido, tendremos que eliminar la pieza comida.
{

	if (Movimientos::is_legal(m, t) != 0) {
		Pieza* fo = t.peones[m.ori.x][m.ori.y];  //ficha origen
		Pieza* fd = t.peones[m.dest.x][m.dest.y];  //ficha destino
		cas_t aux;
		if (fd) {  //si hay pieza en el destino!! es decir, comemos
			switch (fo->type())
			{
			case(Pieza::PEON_BLANCO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1))//diagonal derecha
				{
					aux = { m.dest.x ,m.dest.y  };
					if (aux.x == 8)
					{
						t += reinab({ aux });  //creamos reina al haber llegado al final
						t -= *fo;
						cout << "dama blanca se convierte" << endl;
					}
					else
					{
						t += pb({ aux });
						t -= *fo;
					}
				}
				if ((m.dest.y == m.ori.y - 1))//diagonal izquierda
				{
					aux = { m.dest.x ,m.dest.y };
					if (aux.x == 8)
					{
						t += reinab({ aux });
						t -= *fo;
						cout << "dama blanca se convierte" << endl;
					}
					else
					{
						t += pb({ aux });
						t -= *fo;
					}
				}
				break;
			case(Pieza::PEON_NEGRO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1))//diagonal derecha
				{
					aux = { m.dest.x ,m.dest.y };
					if (aux.x == 0)
					{
						t += reinan({ aux });
						t -= *fo;
						cout << "dama negra se convierte" << endl;
					}
					else
					{
						t += pn({ aux });
						t -= *fo;
					}
				}
				if ((m.dest.y == m.ori.y - 1))//diagonal izquierda
				{
					aux = { m.dest.x ,m.dest.y  };
					if (aux.x == 0)
					{
						t += reinan({ aux });
						t -= *fo;
						cout << "dama negra se convierte" << endl;
					}
					else
					{
						t += pn({ aux });
						t -= *fo;
					}
				}
				break;
			case(Pieza::REINA_NEGRA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i))
					{
						t += reinan({ aux });
						t -= *fo;
						
					}

					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))
					{
						t += reinan({ aux });
						t -= *fo;
					
					}
				}
				break;
			case(Pieza::REINA_BLANCA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i))
					{
						t += reinab({ aux });
						t -= *fo;
						
					}

					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))
					{
						t += reinab({ aux });
						t -= *fo;
					
					}
				}
				break;

			case(Pieza::REY_BLANCO): //elegir diagonal para mover fo
				aux = { m.dest.x ,m.dest.y };
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha inferior
				{

					t += reyb({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
				{

					t += reyb({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
				{

					t += reyb({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
				{

					t += reyb({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1))
				{
					t += reyb({ aux });
					t -= *fo;

				}
				break;

			case(Pieza::REY_NEGRO): //elegir diagonal para mover fo

				aux = { m.dest.x ,m.dest.y };
				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y))//diagonal derecha inferior
				{

					t += reyn({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
				{

					t += reyn({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
				{

					t += reyn({ aux });
					t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
				{

					t += reyn({ aux });
					t -= *fo;
				}
				
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1))
				{
					t += reyn({ aux });
					t -= *fo;

				}
				break;

			case(Pieza::TORRE_NEGRA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) {
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) 
					{
						t += tn({ aux });
						t -= *fo;
					}
				}
				break;
			case(Pieza::TORRE_BLANCA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) {
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) 
					{
						t += tb({ aux });
						t -= *fo;
					}
				}
				break;

			case(Pieza::ALFIL_BLANCO):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales deL alfil
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))
					{
						t += alfb({ aux });
						t -= *fo;

					}
				}
				break;

			case(Pieza::ALFIL_NEGRO):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) { 
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))
					{
						t += alfn({ aux });
						t -= *fo;

					}
				}
				break;
			case(Pieza::CABALLO_BLANCO):
				aux = { m.dest.x ,m.dest.y };
		
				if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2)
				{
					t += cabb({ aux });
					t -= *fo;
				}
				break;

			case(Pieza::CABALLO_NEGRO):
				aux = { m.dest.x, m.dest.y };
				
				if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2)
				{
					t += cabn({ aux });
					t -= *fo;
				}
				break;

		
			default:
				break;
			}
		}
		else  //no comemos, destruimos pieza en origen y creamos en destino
		{

			fd = fo;
			switch (fd->type())
			{
			case(Pieza::PEON_BLANCO):
				if (m.dest.x == 8)
				{
					t += reinab(m.dest);
					t -= *fd;
					cout << "se convierte en reina blanca" << endl;
				}
				else
				{
					t -= *fo;
					t += pb({ m.dest });
				}
				break;
			case(Pieza::PEON_NEGRO):
				if (m.dest.x == 0)
				{
					t += reinan(m.dest);
					t -= *fd;
					cout << "se convierte en reina negra" << endl;
				}
				else
				{
					t -= *fo;
					t += pn({ m.dest });
				}
				break;
			case(Pieza::REINA_BLANCA):
				t -= *fo;
				t += reinab({ m.dest });
				break;
			case(Pieza::REINA_NEGRA):
				t -= *fo;
				t += reinan({ m.dest });
				break;
			case(Pieza::REY_BLANCO):
				t -= *fo;
				t += reyb({ m.dest });
				break;
			case(Pieza::REY_NEGRO):
				t -= *fo;
				t += reyn({ m.dest });
				break;
			case(Pieza::TORRE_BLANCA):
				t -= *fo;
				t += tb({ m.dest });
				break;
			case(Pieza::TORRE_NEGRA):
				t -= *fo;
				t += tn({ m.dest });
				break;
			case(Pieza::ALFIL_BLANCO):
				t -= *fo;
				t += alfb({ m.dest });
				break;
			case(Pieza::ALFIL_NEGRO):
				t -= *fo;
				t += alfn({ m.dest });
				break;
			case(Pieza::CABALLO_BLANCO):
				t -= *fo;
				t += cabb({ m.dest });
				break;
			case(Pieza::CABALLO_NEGRO):
				t -= *fo;
				t += cabn({ m.dest });
				break;

				
			default:
				break;
			}

		}

		return 0;

	}
	return -1;

}