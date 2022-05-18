#include "Movimientos.h"



int Movimientos::is_legal(move_t m, const Master& t)
{
	//CONDICIONES DE QUE SEA LEGAL EL MOVIMIENTO


	//A) nuestro origen tiene que ser una ficha
	Peon* fo = t.peones[m.ori.x][m.ori.y];

	if (fo == NULL) { cout << "is_legal FALSE NULL" << endl; return 0; }


	//B) el destino tiene que ser  ficha contraria
	Peon* fd = t.peones[m.dest.x][m.dest.y];

	if (fd) {//CASILLA DESTINO LLENA
		if (fd->type() == Peon::PEON_NEGRO || fd->type() == Peon::REINA_NEGRA || fd->type() == Peon::REY_NEGRO || fd->type() == Peon::TORRE_NEGRA) {
			if (fo->type() == Peon::PEON_NEGRO || fo->type() == Peon::REINA_NEGRA || fd->type() == Peon::REY_NEGRO || fd->type() == Peon::TORRE_NEGRA) {
				cout << "is_legal FALSE" << endl; return 0;
			}
		}
		if (fd->type() == Peon::PEON_BLANCO || fd->type() == Peon::REINA_BLANCA || fd->type() == Peon::REY_BLANCO || fd->type() == Peon::TORRE_BLANCA) {
			if (fo->type() == Peon::PEON_BLANCO || fo->type() == Peon::REINA_BLANCA || fd->type() == Peon::REY_BLANCO || fd->type() == Peon::TORRE_BLANCA) { cout << "is_legal FALSE" << endl; return 0; }
		}
	}

	//C) Movimiento permitido simple
	if (!fd) { //CASILLA DESTINO VACIA
		switch (fo->type())
		{
		case(Peon::PEON_BLANCO)://está permitido que avance hacia abajo(sumarle 1 o 2 a la x)  
			if ((m.dest.x == m.ori.x + 1) || m.dest.x == m.ori.x + 2) { cout << "is_legal TRUE " << endl; return 2; }
			break;
		case(Peon::PEON_NEGRO)://está permitido que avance hacia arriba(resta 1 o 2 a la x) 
			if ((m.dest.x == m.ori.x - 1) || (m.dest.x == m.ori.x - 2)) { cout << "is_legal TRUE " << endl; return 2; }
			break;
		case(Peon::REINA_NEGRA)://hay que evitar que salte!!!
			for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
					(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))
				{
					cout << "is_legal TRUE " << endl; return 2;
				}

				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))
				{
					cout << "is_legal TRUE " << endl; return 2;
				}
			}
			break;
		case(Peon::REINA_BLANCA):
			for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
					(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))
				{
					cout << "is_legal TRUE " << endl; return 2;
				}

				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))
				{
					cout << "is_legal TRUE " << endl; return 2;
				}
			}
			break;
		case(Peon::REY_NEGRO):
			if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) { 
				cout << "is_legal TRUE " << endl; return 2; 
			}
			break;
		case(Peon::REY_BLANCO):
			if ((m.dest.x == m.ori.x - 1 || m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1 || m.dest.y == m.ori.y - 1)) { 
				cout << "is_legal TRUE " << endl; return 2; 
			}
			break;
		case(Peon::TORRE_NEGRA):
			for (int i = 1; i < 8; i++) {
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
					cout << "is_legal TRUE " << endl; return 2;
				}
			}
			break;
		case(Peon::TORRE_BLANCA):
			for (int i = 1; i < 8; i++) {
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
					cout << "is_legal TRUE " << endl; return 2;
				}
			}
			break;
		default:
			break;
		}
	}

	//D) Movimiento de comer, tiene que haber ficha en el destino
	if (fd) { //CASILLA DESTINO LLENA
		Peon* fs; //ficha salto auxiliar
		switch (fo->type())
		{
		case(Peon::PEON_BLANCO):

			//distinguir si para la derecha o para la izquierda asegurando de que es para abajo

			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha
			{
	

				if ((m.dest.x + 1 > 7) || (m.dest.y + 1 > 7)) { return 0; }

					cout << "el peon blanco come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) //diagonal izquierda
			{
				

				if ((m.dest.x + 1 > 7) || (m.dest.y - 1 < 0)) { return 0; }

					
					cout << "el peon blanco come" << endl;
					return 1;
				
			}
			break;
		case(Peon::PEON_NEGRO): //está permitido que coma hacia arriba  
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 7)) { return 0; }

				
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
		case(Peon::REINA_NEGRA):
			for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles moVimientos diagonales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) //diagonal derecha inferior tantas posiciones como me permita el tablero
				{
				

					if ((m.dest.x > 7) || (m.dest.y > 7)) { return 0; } //si me salgo del tablero no como obviamente

					
						cout << "LA REINA NEGRA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) //diagonal izquierda inferior
				{
				

					if ((m.dest.x > 7) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						
						cout << "LA REINA NEGRA COME" << endl;
					return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) //diagonal derecha superior
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 7)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA NEGRA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))//diagonal izquierda superior
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA NEGRA COME" << endl;
						return 1;
					
				}
			}
			for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos verticales y horizontales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) //vertical abajo, tantas posiciones como me permita el tablero
				{
					

					if ((m.dest.x > 7) || (m.dest.y > 7)) { return 0; } //si me salgo del tablero no como obviamente

					
						cout << "LA REINA NEGRA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) //vertical arriba
				{
					

					if ((m.dest.x > 7) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

						cout << "LA REINA NEGRA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) //horizontal a la derecha
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 7)) { return 0; }//si me salgo del tablero

						cout << "LA REINA NEGRA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))//horizontal a la izquierda
				{
					
					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA NEGRA COME" << endl;
						return 1;
				
				}
			}
			break;
		case(Peon::REINA_BLANCA):
			for (int i = 0; i < 8; i++) { //este bucle cubre todos los posibles moVimientos diagonales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i)) //diagonal derecha inferior tantas posiciones como me permita el tablero
				{
					

					if ((m.dest.x > 7) || (m.dest.y > 7)) { return 0; } //si me salgo del tablero no como obviamente

						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) //diagonal izquierda inferior
				{
					

					if ((m.dest.x > 7) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i)) //diagonal derecha superior
				{
					

					if ((m.dest.x < 0) || (m.dest.y> 7)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i))//diagonal izquierda superior
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}
			}
			for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos verticales y horizontales de la REINA, asegurándonos siempre dentro de cada if que no nos salgamos del tablero
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) //vertical abajo, tantas posiciones como me permita el tablero
				{
					

					if ((m.dest.x > 7) || (m.dest.y > 7)) { return 0; } //si me salgo del tablero no como obviamente

					
						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) //vertical arriba
				{
					

					if ((m.dest.x > 7) || (m.dest.y < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) //horizontal a la derecha
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 7)) { return 0; }//si me salgo del tablero

				
						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))//horizontal a la izquierda
				{
					

					if ((m.dest.x < 0) || (m.dest.y  < 0)) { return 0; }//si me salgo del tablero

					
						cout << "LA REINA BLANCA COME" << endl;
						return 1;
					
				}
			}
			break;

		case(Peon::REY_NEGRO):
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha inferior
			{
				

				if ((m.dest.x + 1 > 7) || (m.dest.y + 1 > 7)) { return 0; }

					cout << "el REY negro come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) //diagonal izquierda inferior
			{
				

				if ((m.dest.x + 1 > 7) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el REY negro come" << endl;
					return 1;
				
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) //diagonal derecha superior
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 7)) { return 0; }

				
					cout << "el REY negro come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el REY negro come" << endl;
					return 1;
				
			}
			break;
		case(Peon::REY_BLANCO):
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha inferior
			{
				

				if ((m.dest.x + 1 > 7) || (m.dest.y + 1 > 7)) { return 0; }

				
					cout << "el REY blanco come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda inferior
			{
				

				if ((m.dest.x + 1 > 7) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el REY blanco come" << endl;
					return 1;
				
			}

			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1))//diagonal derecha superior
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y + 1 > 7)) { return 0; }

				
					cout << "el REY blanco come" << endl;
					return 1;
				
			}
			if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1))//diagonal izquierda superior
			{
				

				if ((m.dest.x - 1 < 0) || (m.dest.y - 1 < 0)) { return 0; }

				
					cout << "el REY blanco come" << endl;
					return 1;
				
			}
			break;
		case(Peon::TORRE_NEGRA):
			for (int i = 1; i < 8; i++) {
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y)) //
				{
					

					if ((m.dest.x > 7) || (m.dest.y > 7)) { return 0; }//

					
						cout << "LA TORRE NEGRA come" << endl;
						return 1;
					
				}
				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y)) //
				{
					

					if ((m.dest.x > 7) || (m.dest.y < 0)) { return 0; }

					
						cout << "LA TORRE NEGRA come" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i)) 
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 7)) { return 0; }

					
						cout << "LA TORRE NEGRA come" << endl;
						return 1;
					
				}
				if ((m.dest.x == m.ori.x ) && (m.dest.y == m.ori.y - i))
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }

					
						cout << "LA TORRE NEGRA come" << endl;
						return 1;
					
				}
			}
			break;
		case(Peon::TORRE_BLANCA):
			for (int i = 1; i < 8; i++) {
				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i))
				{
				

					if ((m.dest.x > 7) || (m.dest.y > 7)) { return 0; }

					
						cout << "LA TORRE BLANCA come" << endl;
						return 1;
					
				}
				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i))
				{
					

					if ((m.dest.x > 7) || (m.dest.y < 0)) { return 0; }

						cout << "LA TORRE BLANCA come" << endl;
						return 1;
					
				}

				if ((m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y))
				{
					

					if ((m.dest.x < 0) || (m.dest.y > 7)) { return 0; }

					
						cout << "LA TORRE BLANCA come" << endl;
						return 1;
					
				}
				if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y))
				{
					

					if ((m.dest.x < 0) || (m.dest.y < 0)) { return 0; }

					
						cout << "LA TORRE BLANCA come" << endl;
						return 1;
					
				}

			}
			break;
		
		default:
				break;
		}
	}
	return 0;
}

int Movimientos::move(move_t m, Master& t)
{

	if (Movimientos::is_legal(m, t) != 0) {
		Peon* fo = t.peones[m.ori.x][m.ori.y];
		Peon* fd = t.peones[m.dest.x][m.dest.y];
		cas_t aux;
		if (fd) {  //si hay pieza en el destino!!
			switch (fo->type())
			{
			case(Peon::PEON_BLANCO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1))//diagonal derecha
				{
					aux = { m.dest.x ,m.dest.y  };
					if (aux.x == 7)
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
				if ((m.dest.y == m.ori.y - 1))//diagonal izquierda
				{
					aux = { m.dest.x ,m.dest.y };
					if (aux.x == 7)
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
			case(Peon::PEON_NEGRO): //elegir diagonal para mover fo
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
			case(Peon::REINA_NEGRA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
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
			case(Peon::REINA_BLANCA):
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

			case(Peon::REY_BLANCO): //elegir diagonal para mover fo
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
				break;

			case(Peon::REY_NEGRO): //elegir diagonal para mover fo

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
				break;

			case(Peon::TORRE_NEGRA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 8; i++) {
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) 
					{
						t += tn({ aux });
						t -= *fo;
					}
				}
				break;
			case(Peon::TORRE_BLANCA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 8; i++) {
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) 
					{
						t += tb({ aux });
						t -= *fo;
					}
				}
				break;
		
			default:
				break;
			}
			//t.operator-=(*fd); //borramos la ficha comida   he comentado esto para que me funcione
		}
		else
		{
			//move piece in original square
			fd = fo;
			switch (fd->type())
			{
			case(Peon::PEON_BLANCO):
				if (m.dest.x == 7)
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
			case(Peon::PEON_NEGRO):
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
			case(Peon::REINA_BLANCA):
				t -= *fo;
				t += reinab({ m.dest });
				break;
			case(Peon::REINA_NEGRA):
				t -= *fo;
				t += reinan({ m.dest });
				break;
			case(Peon::REY_BLANCO):
				t -= *fo;
				t += reyb({ m.dest });
				break;
			case(Peon::REY_NEGRO):
				t -= *fo;
				t += reyn({ m.dest });
				break;
			case(Peon::TORRE_BLANCA):
				t -= *fo;
				t += tb({ m.dest });
				break;
			case(Peon::TORRE_NEGRA):
				t -= *fo;
				t += tn({ m.dest });
				break;
			default:
				break;
			}

		}

		return 0;

	}
	return -1;

}