#include "Missile.h"
#include "../Constante.h"
#include <SDL/SDL_draw.h>
#include <iostream>

using namespace std;

Missile::Missile(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):ObjetVolant(tailleCote, vitesse, centre, pente) {

}

Missile::Missile(const Missile &obj):ObjetVolant(obj) {

}

Missile::~Missile() {

}

Missile &Missile::operator=(const Missile &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
	return *this;
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
	Draw_FillCircle(ecran, this->centre.getX(), this->centre.getY(), Constante::TAILLEMISSILE, SDL_MapRGB(ecran->format, 255, 255, 255));
}
