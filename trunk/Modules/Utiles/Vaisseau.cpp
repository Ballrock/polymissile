#include "Vaisseau.h"


Vaisseau::Vaisseau(int tailleCote, int vitesse):ObjetVolant(tailleCote, vitesse) {

}

Vaisseau::Vaisseau(const Vaisseau &obj):ObjetVolant(obj.tailleCote, obj.vitesse) {

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
	 
