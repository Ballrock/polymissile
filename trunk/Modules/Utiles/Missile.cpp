#include "Missile.h"


Missile::Missile(int tailleCote, int vitesse):ObjetVolant(tailleCote, vitesse) {

}

Missile::Missile(const Missile &obj):ObjetVolant(obj.tailleCote, obj.vitesse) {

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
	 
