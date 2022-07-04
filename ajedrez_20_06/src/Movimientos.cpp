#include "Movimientos.h"
#include "math.h"
#include "Peon.h"
#include "Rey.h"
#include "Torre.h"
#include "Caballo.h"
#include "Reina.h"
#include "Alfil.h"

int Movimientos::is_legal(move_t m, const Master& t) {
	//CONDICIONES DE QUE SEA LEGAL EL MOVIMIENTO
	//A) nuestro origen tiene que ser una ficha
	Pieza* fo = t.peones[m.ori.x][m.ori.y];
	if (fo == NULL) { return 0; }
	//B) el destino tiene que ser  ficha contraria
	Pieza* fd = t.peones[m.dest.x][m.dest.y];
	if (fd) { //CASILLA DESTINO LLENA
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
		if ( fd->type() == Pieza::REY_BLANCO || fd->type() == Pieza::REY_NEGRO) {
			if ( fo->type() == Pieza::REY_BLANCO || fo->type() == Pieza::REY_NEGRO) { return 0; }
		}
	}
	//C)SI MATAMOS AL REY
	if (fd) {//CASILLA DESTINO LLENA
		if (fd->type() == Pieza::REY_NEGRO || fd->type() == Pieza::REY_BLANCO) {
			if (fo->type() == Pieza::PEON_NEGRO || fo->type() == Pieza::REINA_NEGRA || fo->type() == Pieza::REY_NEGRO || fo->type() == Pieza::TORRE_NEGRA || fo->type()==Pieza::ALFIL_NEGRO || fo->type() == Pieza::CABALLO_NEGRO || fo->type() == Pieza::PEON_BLANCO || fo->type() == Pieza::REINA_BLANCA || fo->type() == Pieza::REY_BLANCO || fo->type() == Pieza::TORRE_BLANCA || fo->type() == Pieza::ALFIL_BLANCO || fo->type() == Pieza::CABALLO_BLANCO) {
				cout << "SE ACABA LA PARTIDA" << endl; return 3;
			}
		}
	}
	//D) Movimiento permitido simple
	//Pieza p;
	Peon peon; Reina reina; Rey rey; Torre torre; Caballo caballo; Alfil alfil;
	if (!fd) { //CASILLA DESTINO VACIA
		switch (fo->type()) {
		case(Pieza::PEON_BLANCO)://está permitido que avance hacia abajo(sumarle 1 o 2 a la x)  
			return peon.movimiento(Pieza::PEON_BLANCO, m);
			break;
		case(Pieza::PEON_NEGRO)://está permitido que avance hacia arriba(resta 1 o 2 a la x) 
			return peon.movimiento(Pieza::PEON_NEGRO, m);
			break;
		case(Pieza::REINA_NEGRA):
			return reina.movimiento(Pieza::REINA_NEGRA, m);
			break; 
		case(Pieza::REINA_BLANCA):
			return reina.movimiento(Pieza::REINA_BLANCA, m);
			break;
		case(Pieza::REY_NEGRO):
			return rey.movimiento(Pieza::REY_NEGRO, m);
			break;
		case(Pieza::REY_BLANCO):
			return rey.movimiento(Pieza::REY_BLANCO, m);
			break;
		//movimientos horizontales
		case(Pieza::TORRE_NEGRA):
			return torre.movimiento(Pieza::TORRE_NEGRA, m);
			break;
		case(Pieza::TORRE_BLANCA):
			return torre.movimiento(Pieza::TORRE_BLANCA, m);
			break;
		//movimientos diagonales
		case(Pieza::ALFIL_BLANCO):
			return alfil.movimiento(Pieza::ALFIL_BLANCO, m);
			break;
		case(Pieza::ALFIL_NEGRO):
			return alfil.movimiento(Pieza::ALFIL_NEGRO, m);
			break;
		case(Pieza::CABALLO_NEGRO):
			return caballo.movimiento(Pieza::CABALLO_NEGRO, m);
			break;
		case(Pieza::CABALLO_BLANCO):
			return caballo.movimiento(Pieza::CABALLO_BLANCO, m);
			break;
		default: break;
		}
	}
	//E) Movimiento de comer, tiene que haber ficha en el destino
	if (fd) { //CASILLA DESTINO LLENA
		switch (fo->type()){
		case(Pieza::PEON_BLANCO):
			//distinguir si para la derecha o para la izquierda asegurando de que es para abajo
			return peon.mov_comer(Pieza::PEON_BLANCO, m);
			break;
		case(Pieza::PEON_NEGRO): //está permitido que coma hacia arriba  
			return peon.mov_comer(Pieza::PEON_NEGRO, m);
			break;
		case(Pieza::REINA_NEGRA):
			return reina.mov_comer(Pieza::REINA_NEGRA, m);
			break;
		case(Pieza::REINA_BLANCA):
			return reina.mov_comer(Pieza::REINA_BLANCA, m);
			break;
		case(Pieza::REY_NEGRO):
			return rey.mov_comer(Pieza::REY_NEGRO, m);
			break;
		case(Pieza::REY_BLANCO):
			return rey.mov_comer(Pieza::REY_BLANCO, m);
			break;
		case(Pieza::TORRE_NEGRA): 
			return torre.mov_comer(Pieza::TORRE_NEGRA, m);
			break;
		case(Pieza::TORRE_BLANCA):
			return torre.mov_comer(Pieza::TORRE_BLANCA, m);
			break;
		case(Pieza::ALFIL_BLANCO): 
			return alfil.mov_comer(Pieza::ALFIL_BLANCO, m);
			break;
		case(Pieza::ALFIL_NEGRO):
			return alfil.mov_comer(Pieza::ALFIL_NEGRO, m);
			break;
		case(Pieza::CABALLO_BLANCO):
			return caballo.mov_comer(Pieza::CABALLO_BLANCO, m);
			break;
		case(Pieza::CABALLO_NEGRO):
			return caballo.mov_comer(Pieza::CABALLO_NEGRO, m);
			break;
		default: break;
		}
	}
	return 0;
}

int Movimientos::move(move_t m, Master& t) { //en esta funcion, crearemos la pieza en la casilla de destino. Si hemos comido, tendremos que eliminar la pieza comida.
	if (Movimientos::is_legal(m, t) != 0) {
		Pieza* fo = t.peones[m.ori.x][m.ori.y];  //ficha origen
		Pieza* fd = t.peones[m.dest.x][m.dest.y];  //ficha destino
		cas_t aux;
		if (fd) {  //si hay pieza en el destino!! es decir, comemos
			switch (fo->type()) {
			case(Pieza::PEON_BLANCO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1)) { //diagonal derecha
					aux = { m.dest.x ,m.dest.y  };
					if (aux.x == 8) {//creamos reina al haber llegado al final
						t += Reina({ aux }, Pieza::REINA_BLANCA); t -= *fo; cout << "dama blanca se convierte" << endl; 
					}
					else { t += Peon({ aux }, Pieza::PEON_BLANCO); t -= *fo; }
				}
				if ((m.dest.y == m.ori.y - 1)) { //diagonal izquierda
					aux = { m.dest.x ,m.dest.y };
					if (aux.x == 8) { t += Reina({ aux }, Pieza::REINA_BLANCA); t -= *fo; cout << "dama blanca se convierte" << endl; }
					else { t += Peon({ aux }, Pieza::PEON_BLANCO); t -= *fo; }
				}
				break;
			case(Pieza::PEON_NEGRO): //elegir diagonal para mover fo
				if ((m.dest.y == m.ori.y + 1)) { //diagonal derecha
					aux = { m.dest.x ,m.dest.y };
					if (aux.x == 0) { t += Reina({ aux }, Pieza::REINA_NEGRA); t -= *fo; cout << "dama negra se convierte" << endl; }
					else { t += Peon({ aux }, Pieza::PEON_NEGRO); t -= *fo; }
				}
				if ((m.dest.y == m.ori.y - 1)) { //diagonal izquierda
					aux = { m.dest.x ,m.dest.y  };
					if (aux.x == 0) { t += Reina({ aux }, Pieza::REINA_NEGRA); t -= *fo; cout << "dama negra se convierte" << endl; }
					else { t += Peon({ aux }, Pieza::PEON_NEGRO); t -= *fo; }
				}
				break;
			case(Pieza::REINA_NEGRA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) {
						t += Reina({ aux }, Pieza::REINA_NEGRA); t -= *fo;
					}
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
						t += Reina({ aux }, Pieza::REINA_NEGRA); t -= *fo;
					}
				}
				break;
			case(Pieza::REINA_BLANCA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 8; i++) { //este bucle cubre todos los posibles movimientos diagonales de la REINA
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i)) {
						t += Reina({ aux }, Pieza::REINA_BLANCA); t -= *fo;
					}
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
						t += Reina({ aux }, Pieza::REINA_BLANCA); t -= *fo;
					}
				}
				break;
			case(Pieza::REY_BLANCO): //elegir diagonal para mover fo
				aux = { m.dest.x ,m.dest.y };
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha inferior
					t += Rey({ aux }, Pieza::REY_BLANCO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda inferior
					t += Rey({ aux }, Pieza::REY_BLANCO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha superior
					t += Rey({ aux }, Pieza::REY_BLANCO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda superior
					t += Rey({ aux }, Pieza::REY_BLANCO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1)) {
					t += Rey({ aux }, Pieza::REY_BLANCO); t -= *fo;
				}
				break;
			case(Pieza::REY_NEGRO): //elegir diagonal para mover fo
				aux = { m.dest.x ,m.dest.y };
				if ((m.dest.x == m.ori.x) && (m.dest.y == m.ori.y)) { //diagonal derecha inferior
					t += Rey({ aux }, Pieza::REY_NEGRO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda inferior
					t += Rey({ aux }, Pieza::REY_NEGRO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y + 1)) { //diagonal derecha superior
					t += Rey({ aux }, Pieza::REY_NEGRO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y - 1)) { //diagonal izquierda superior
					t += Rey({ aux }, Pieza::REY_NEGRO); t -= *fo;
				}
				if ((m.dest.x == m.ori.x + 1) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - 1) && (m.dest.y == m.ori.y) ||
					(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + 1) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - 1)) {
					t += Rey({ aux }, Pieza::REY_NEGRO); t -= *fo;
				}
				break;
			case(Pieza::TORRE_NEGRA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) {
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
						t += Torre({ aux },Pieza::TORRE_NEGRA); t -= *fo;
					}
				}
				break;
			case(Pieza::TORRE_BLANCA):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) {
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y) ||
						(m.dest.x == m.ori.x) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x) && (m.dest.y == m.ori.y - i)) {
						t += Torre({ aux }, Pieza::TORRE_BLANCA); t -= *fo;
					}
				}
				break;
			case(Pieza::ALFIL_BLANCO):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) { //este bucle cubre todos los posibles movimientos diagonales deL alfil
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i)) {
						t += Alfil({ aux }, Pieza::ALFIL_BLANCO); t -= *fo;
					}
				}
				break;
			case(Pieza::ALFIL_NEGRO):
				aux = { m.dest.x ,m.dest.y };
				for (int i = 1; i < 9; i++) { 
					if ((m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x + i) && (m.dest.y == m.ori.y - i) ||
						(m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y + i) || (m.dest.x == m.ori.x - i) && (m.dest.y == m.ori.y - i)) {
						t += Alfil({ aux }, Pieza::ALFIL_NEGRO); t -= *fo;
					}
				}
				break;
			case(Pieza::CABALLO_BLANCO):
				aux = { m.dest.x ,m.dest.y };
				if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2) {
					t += Caballo({ aux }, Pieza::CABALLO_BLANCO); t -= *fo;
				}
				break;
			case(Pieza::CABALLO_NEGRO):
				aux = { m.dest.x, m.dest.y };
				if (abs(m.ori.x - m.dest.x) == 2 && abs(m.ori.y - m.dest.y) == 1 || abs(m.ori.x - m.dest.x) == 1 && abs(m.ori.y - m.dest.y) == 2) {
					t += Caballo({ aux }, Pieza::CABALLO_NEGRO); t -= *fo;
				}
				break;
			default: break;
			}
		}
		else { //no comemos, destruimos pieza en origen y creamos en destino
			fd = fo;
			switch (fd->type()){
			case(Pieza::PEON_BLANCO):
				if (m.dest.x == 8) { t += Reina(m.dest, Pieza::REINA_BLANCA); t -= *fd; cout << "se convierte en reina blanca" << endl; }
				else { t -= *fo; t += Peon({ m.dest }, Pieza::PEON_BLANCO); }
				break;
			case(Pieza::PEON_NEGRO):
				if (m.dest.x == 0) { t += Reina(m.dest, Pieza::REINA_NEGRA); t -= *fd; cout << "se convierte en reina negra" << endl; }
				else { t -= *fo; t += Peon({ m.dest }, Pieza::PEON_NEGRO); }
				break;
			case(Pieza::REINA_BLANCA): t -= *fo; t += Reina({ m.dest }, Pieza::REINA_BLANCA); break;
			case(Pieza::REINA_NEGRA): t -= *fo; t += Reina({ m.dest }, Pieza::REINA_NEGRA); break;
			case(Pieza::REY_BLANCO): t -= *fo; t += Rey({ m.dest }, Pieza::REY_BLANCO); break;
			case(Pieza::REY_NEGRO): t -= *fo; t += Rey({ m.dest }, Pieza::REY_NEGRO); break;
			case(Pieza::TORRE_BLANCA): t -= *fo; t += Torre({ m.dest }, Pieza::TORRE_BLANCA); break;
			case(Pieza::TORRE_NEGRA): t -= *fo; t += Torre({ m.dest }, Pieza::TORRE_NEGRA); break;
			case(Pieza::ALFIL_BLANCO): t -= *fo; t += Alfil({ m.dest }, Pieza::ALFIL_BLANCO); break;
			case(Pieza::ALFIL_NEGRO): t -= *fo; t += Alfil({ m.dest }, Pieza::ALFIL_NEGRO); break;
			case(Pieza::CABALLO_BLANCO): t -= *fo; t += Caballo({ m.dest }, Pieza::CABALLO_BLANCO); break;
			case(Pieza::CABALLO_NEGRO): t -= *fo; t += Caballo({ m.dest }, Pieza::CABALLO_NEGRO); break;
			default: break;
			}
		}
		return 0;
	}
	return -1;
}

bool Movimientos::jaque_negro(move_t ma, Master& ta) {
	Peon peon; Reina reina; Rey rey; Torre torre; Caballo caballo; Alfil alfil;
	bool pb, ab, tb, cb, reinab, reyb;
	int reyn_x = 0, reyn_y = 0;
	int i, ocupada = 0;

	for (int i = 1; i < 9; i++) {   //detectar posicion rey negro en todo momento
		for (int j = 1; j < 9; j++) {
			if (ta.peones[i][j] != NULL) {
				if (ta.peones[i][j]->type() == Pieza::REY_NEGRO) {
					cout << "Rey negro esta en la casilla " << i << ", " << j << endl;
					reyn_x = i;  reyn_y = j;
				}

				if (ta.peones[i][j]->type() == Pieza::PEON_BLANCO) {
					pb = peon.movimiento(Pieza::PEON_BLANCO, ma);
					if (pb) {
						//cout << "Hay jaque negras de peon? " << endl;
						if (((ma.dest.x == reyn_x + 1) && (ma.dest.y == reyn_y + 1)) || ((ma.dest.x == reyn_x + 1) && (ma.dest.y == reyn_y + 1))) {
							cout << "Hay jaque a negras peon" << endl; return true;
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::ALFIL_BLANCO) {
					ab = alfil.movimiento(Pieza::ALFIL_BLANCO, ma);
					if (ab) {
						for (int k = 0; k < 9; k++) {
							//cout << "Hay jaque negras de alfil? " << endl;
							if (((ma.dest.x == reyn_x + k) && (ma.dest.y == reyn_y + k)) || ((ma.dest.x == reyn_x + k) && (ma.dest.y == reyn_y - k)) ||
								((ma.dest.x == reyn_x - k) && (ma.dest.y == reyn_y + k)) || ((ma.dest.x == reyn_x - k) && (ma.dest.y == reyn_y - k))) {
								cout << "Hay jaque a negras alfil" << endl; return true;
							}
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::TORRE_BLANCA) {
					tb = torre.movimiento(Pieza::TORRE_BLANCA, ma);
					if (tb) {
						for (int k = 0; k < 9; k++) {
							//cout << "Hay jaque negras de torre? " << endl;
							if (((ma.dest.x == reyn_x) && (ma.dest.y == reyn_y + k)) || ((ma.dest.x == reyn_x) && (ma.dest.y == reyn_y - k)) ||
								((ma.dest.x == reyn_x + k) && (ma.dest.y == reyn_y)) || ((ma.dest.x == reyn_x - k) && (ma.dest.y == reyn_y))) {
								cout << "Hay jaque a negras torre" << endl; return true;
							}
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::CABALLO_BLANCO) {
					cb = caballo.movimiento(Pieza::CABALLO_BLANCO, ma);
					if (cb) {
						//cout << "Hay jaque negras de caballo? " << endl;
						if (((ma.dest.x == reyn_x + 2) && (ma.dest.y == reyn_y - 1)) || ((ma.dest.x == reyn_x + 2) && (ma.dest.y == reyn_y + 1)) || 
							((ma.dest.x == reyn_x - 2) && (ma.dest.y == reyn_y - 1)) || ((ma.dest.x == reyn_x - 2) && (ma.dest.y == reyn_y + 1)) ||
							((ma.dest.x == reyn_x + 1) && (ma.dest.y == reyn_y - 2)) || ((ma.dest.x == reyn_x + 1) && (ma.dest.y == reyn_y + 2)) ||
							((ma.dest.x == reyn_x - 1) && (ma.dest.y == reyn_y - 2)) || ((ma.dest.x == reyn_x - 1) && (ma.dest.y == reyn_y + 2))) {
							cout << "Hay jaque a negras caballo" << endl; return true;
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::REINA_BLANCA) { //pruebo jaque con la reina blanca
					reinab = reina.movimiento(Pieza::REINA_BLANCA, ma);
					if (reinab) {
						for (int k = 0; k < 9; k++) {
							//cout << "Hay jaque negras de reina? " << endl;
							if (((ma.dest.x == reyn_x) && (ma.dest.y == reyn_y + k)) || ((ma.dest.x == reyn_x) && (ma.dest.y == reyn_y - k)) ||
								((ma.dest.x == reyn_x + k) && (ma.dest.y == reyn_y)) || ((ma.dest.x == reyn_x - k) && (ma.dest.y == reyn_y)) ||
								((ma.dest.x == reyn_x + k) && (ma.dest.y == reyn_y + k)) || ((ma.dest.x == reyn_x + k) && (ma.dest.y == reyn_y - k)) ||
								((ma.dest.x == reyn_x - k) && (ma.dest.y == reyn_y + k)) || ((ma.dest.x == reyn_x - k) && (ma.dest.y == reyn_y - k))) {
								cout << "Hay jaque a negras reina" << endl; return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool Movimientos::jaque_blanco(move_t ma, Master& ta) {
	Peon peon; Reina reina; Rey rey; Torre torre; Caballo caballo; Alfil alfil;
	bool pn, an, tn, cn, reinan, reyn;
	int reyb_x = 0, reyb_y = 0;
	int i, ocupada = 0;

	for (int i = 1; i < 9; i++) {   //detectar posicion rey negro en todo momento
		for (int j = 1; j < 9; j++) {
			if (ta.peones[i][j] != NULL) {
				if (ta.peones[i][j]->type() == Pieza::REY_BLANCO) {
					cout << "Rey blanco esta en la casilla " << i << ", " << j << endl;
					reyb_x = i;  reyb_y = j;
				}
			
				if (ta.peones[i][j]->type() == Pieza::PEON_NEGRO) {
					pn = peon.movimiento(Pieza::PEON_NEGRO, ma);
					if (pn) {
						//cout << "Hay jaque negras de peon? " << endl;
						if (((ma.dest.x == reyb_x - 1) && (ma.dest.y == reyb_y - 1)) || ((ma.dest.x == reyb_x - 1) && (ma.dest.y == reyb_y - 1))) {
							cout << "Hay jaque a blanco peon" << endl; return true;
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::ALFIL_NEGRO) {
					an = alfil.movimiento(Pieza::ALFIL_NEGRO, ma);
					if (an) {
						for (int k = 0; k < 9; k++) {
							//cout << "Hay jaque negras de alfil? " << endl;
							if (((ma.dest.x == reyb_x + k) && (ma.dest.y == reyb_y + k)) || ((ma.dest.x == reyb_x + k) && (ma.dest.y == reyb_y - k)) ||
								((ma.dest.x == reyb_x - k) && (ma.dest.y == reyb_y + k)) || ((ma.dest.x == reyb_x - k) && (ma.dest.y == reyb_y - k))) {
								cout << "Hay jaque a blanco alfil" << endl; return true;
							}
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::TORRE_NEGRA) {
					tn = torre.movimiento(Pieza::TORRE_NEGRA, ma);
					if (tn) {
						for (int k = 0; k < 9; k++) {
							//cout << "Hay jaque negras de torre? " << endl;
							if (((ma.dest.x == reyb_x) && (ma.dest.y == reyb_y + k)) || ((ma.dest.x == reyb_x) && (ma.dest.y == reyb_y - k)) ||
								((ma.dest.x == reyb_x + k) && (ma.dest.y == reyb_y)) || ((ma.dest.x == reyb_x - k) && (ma.dest.y == reyb_y))) {
								cout << "Hay jaque a blanco torre" << endl; return true;
							}
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::CABALLO_NEGRO) {
					cn = caballo.movimiento(Pieza::CABALLO_NEGRO, ma);
					if (cn) {
						//cout << "Hay jaque negras de caballo? " << endl;
						if (((ma.dest.x == reyb_x + 2) && (ma.dest.y == reyb_y - 1)) || ((ma.dest.x == reyb_x + 2) && (ma.dest.y == reyb_y + 1)) ||
							((ma.dest.x == reyb_x - 2) && (ma.dest.y == reyb_y - 1)) || ((ma.dest.x == reyb_x - 2) && (ma.dest.y == reyb_y + 1)) ||
							((ma.dest.x == reyb_x + 1) && (ma.dest.y == reyb_y - 2)) || ((ma.dest.x == reyb_x + 1) && (ma.dest.y == reyb_y + 2)) ||
							((ma.dest.x == reyb_x - 1) && (ma.dest.y == reyb_y - 2)) || ((ma.dest.x == reyb_x - 1) && (ma.dest.y == reyb_y + 2))) {
							cout << "Hay jaque a blanco caballo" << endl; return true;
						}
					}
				}
				if (ta.peones[i][j]->type() == Pieza::REINA_NEGRA) { //pruebo jaque con la reina blanca
					reinan = reina.movimiento(Pieza::REINA_NEGRA, ma);
					if (reinan) {
						for (int k = 0; k < 9; k++) {
							//cout << "Hay jaque negras de reina? " << endl;
							if (((ma.dest.x == reyb_x) && (ma.dest.y == reyb_y + k)) || ((ma.dest.x == reyb_x) && (ma.dest.y == reyb_y - k)) ||
								((ma.dest.x == reyb_x + k) && (ma.dest.y == reyb_y)) || ((ma.dest.x == reyb_x - k) && (ma.dest.y == reyb_y)) ||
								((ma.dest.x == reyb_x + k) && (ma.dest.y == reyb_y + k)) || ((ma.dest.x == reyb_x + k) && (ma.dest.y == reyb_y - k)) ||
								((ma.dest.x == reyb_x - k) && (ma.dest.y == reyb_y + k)) || ((ma.dest.x == reyb_x - k) && (ma.dest.y == reyb_y - k))) {
								cout << "Hay jaque a blanco reina" << endl; return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
//jaque mate//
/*
bool Movimientos::detectar_jaque_mate(Pieza::obj_t tipo, cas_t casilla, Master& t) {
	switch (tipo) {
	case Pieza::REY_BLANCO:case Pieza::REY_NEGRO:
		//evaluamos que si rey está en los limites del tablero
		if (casilla.x == 1 || casilla.x == 8 || casilla.y == 1 || casilla.y == 8) {
			//entonces en principio hay 5/3 casilla posibles para moverse(laterales/vertices)
			//veamos si estan ocupadas o vacías

			//-----VERTICES-----//
			if (casilla.x == 1 && casilla.y == 1) {//vertice superior izquierdo
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x+1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x ][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y + 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x + 1][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y + 1 }, t)) { bandera2++; }
				}
				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			else if (casilla.x == 8 && casilla.y == 8) {//vertice inferior derecho
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x - 1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x -1][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y - 1 }, t)) { bandera2++; }
				}

				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			else if (casilla.x == 1 && casilla.y == 8) {//vertice superior derecho
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x + 1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x + 1][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y - 1 }, t)) { bandera2++; }
				}

				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			else if (casilla.x == 8 && casilla.y == 1) {//vertice inferior izquierdo
				if (detectar_jaque(tipo, { casilla.x + 1,casilla.y }, t) && detectar_jaque(tipo, { casilla.x,casilla.y + 1 }, t) && detectar_jaque(tipo, { casilla.x - 1,casilla.y + 1 }, t))
				{return true;}
			}

			else if (casilla.x == 8 && casilla.y == 1) {//vertice inferior izquierdo
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x + 1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y + 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x -1][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x-1,casilla.y + 1 }, t)) { bandera2++; }
				}

				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			//-----LATERALES-----//
			else if (casilla.x == 1 && casilla.y > 1 && casilla.y < 8) {//lateral horizontal superior -----
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x + 1][casilla.y];
				if (fd==NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x +1][casilla.y+1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y+1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x + 1][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x ][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y + 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y - 1 }, t)) { bandera2++; }
				}
				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			else if (casilla.x == 8 && casilla.y > 1 && casilla.y < 8) {//lateral horizontal inferior ---------
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x - 1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x - 1][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y + 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x - 1][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y + 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y - 1 }, t)) { bandera2++; }
				}
				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			else if (casilla.x >1 && casilla.x < 8 && casilla.y == 1) {//lateral vertical izquierdo |
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x + 1][casilla.y+1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y+1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x ][casilla.y + 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y + 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x - 1][casilla.y+1 ];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y+1  }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x+1][casilla.y ];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x+1 ,casilla.y  }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x-1][casilla.y ];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x -1,casilla.y }, t)) { bandera2++; }
				}
				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}

			else if (casilla.x > 1 && casilla.x < 8 && casilla.y == 8) {//lateral vertical derceho |
				int bandera1 = 0;
				int bandera2 = 0;
				Pieza* fd = t.peones[casilla.x + 1][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x ,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x - 1][casilla.y - 1];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y - 1 }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x + 1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x + 1 ,casilla.y }, t)) { bandera2++; }
				}

				fd = t.peones[casilla.x - 1][casilla.y];
				if (fd == NULL) {
					bandera1++;
					if (detectar_jaque(tipo, { casilla.x - 1,casilla.y }, t)) { bandera2++; }
				}
				//CONCUSION//
				if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
			}
		}

		//-----DENTRO DEL TABLERO-----//
		else{//estoy dentro del tablero->8 posibilidades en principio
		//primero evaluamos si se pueden hacer esas 8 posibilidades
		//luego recién evaluamos las que se puedan
		int bandera1 = 0;
		int bandera2 = 0;
		Pieza* fd = t.peones[casilla.x + 1][casilla.y];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x + 1,casilla.y }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x - 1][casilla.y];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x - 1,casilla.y }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x][casilla.y + 1];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x ,casilla.y + 1 }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x][casilla.y - 1];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x ,casilla.y - 1 }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x + 1][casilla.y + 1];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x + 1,casilla.y + 1 }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x + 1][casilla.y - 1];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x + 1,casilla.y - 1 }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x - 1][casilla.y + 1];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x - 1,casilla.y + 1 }, t)) { bandera2++; }
		}

		fd = t.peones[casilla.x - 1][casilla.y - 1];
		if (fd == NULL) {
			bandera1++;
			if (detectar_jaque(tipo, { casilla.x - 1,casilla.y - 1 }, t)) { bandera2++; }
		}
		//CONCUSION//
		if (bandera1 == bandera2) { return true; }//HAY JAQUE MATE
        }

	}
}

*/