#include "Vaisseau.h"


Vaisseau::Vaisseau(int tailleCote, int vitesse, Droite pente):ObjetVolant(tailleCote, vitesse, pente) {

}

Vaisseau::Vaisseau(const Vaisseau &obj):ObjetVolant(obj.tailleCote, obj.vitesse, obj.pente) {

}

Vaisseau::~Vaisseau() {

}

Vaisseau &Vaisseau::operator=(const Vaisseau &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
}


void Vaisseau::avancer() {
	/*
	 * TODO
	 */
}

bool Vaisseau::isColision() {
	/*
	 * TODO
	 */
	return false;
}
	 
