#include "Missile.h"
#include "../Constante.h"
#include <SDL/SDL_draw.h>
#include <iostream>
#include <math.h>

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
	this->yRestant += (float)(this->vitesse)*((float)Constante::TIMETICK/1000.0);
	this->xRestant += this->pente.getXWithY(this->centre.getY()+this->yRestant);
	this->centre.setX(floor(this->xRestant));
	this->centre.setY(floor(this->centre.getY()-this->yRestant));
	this->xRestant -= floor(this->xRestant);
	this->yRestant -= floor(this->yRestant);
}

	 
void Missile::paint(SDL_Surface *ecran) {
	if (this->centre.getX() > this->tailleCote && this->centre.getY() > this->tailleCote && this->centre.getX() < 600 - this->tailleCote)
		Draw_FillCircle(ecran, this->centre.getX(), this->centre.getY(), Constante::TAILLEMISSILE, SDL_MapRGB(ecran->format, 255, 255, 255));
}
