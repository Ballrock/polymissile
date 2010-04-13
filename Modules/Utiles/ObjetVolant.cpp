#include "ObjetVolant.h"


ObjetVolant::ObjetVolant(int tailleCote, int vitesse):tailleCote(tailleCote), vitesse(vitesse) {

}

ObjetVolant::ObjetVolant(const ObjetVolant &obj):tailleCote(obj.tailleCote), vitesse(obj.vitesse) {

}

ObjetVolant::~ObjetVolant() {

}

ObjetVolant &ObjetVolant::operator=(const ObjetVolant &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
}

