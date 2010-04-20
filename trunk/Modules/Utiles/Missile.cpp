#include "Missile.h"
#include "../Constante.h"
#include <SDL/SDL_draw.h>
#include <iostream>

using namespace std;

Missile::Missile(int tailleCote, int vitesse, Droite pente):ObjetVolant(tailleCote, vitesse, pente) {

}

Missile::Missile(const Missile &obj):ObjetVolant(obj.tailleCote, obj.vitesse, obj.pente) {

}

Missile::~Missile() {

}

Missile &Missile::operator=(const Missile &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
}


void Missile::avancer() {
	/*
	 * TODO
	 */
}

bool Missile::isColision() {
	/*
	 * TODO
	 */
	return false;
}
	 
void Missile::paint(SDL_Surface *ecran) {
	//TODO : voir paint() de Vaisseau
	cout << this->centre.getX() << " " << this->centre.getY() << endl;
	Draw_FillCircle(ecran, this->centre.getX(), this->centre.getY(), Constante::TAILLEMISSILE, SDL_MapRGB(ecran->format, 255, 255, 255));
}
