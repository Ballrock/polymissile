#include "ObjetVolant.h"


ObjetVolant::ObjetVolant(int tailleCote, int vitesse, Droite pente):tailleCote(tailleCote), vitesse(vitesse), pente(pente), id(idTotal)
{
	idTotal++;
}

ObjetVolant::ObjetVolant(const ObjetVolant &obj):tailleCote(obj.tailleCote), vitesse(obj.vitesse), pente(obj.pente), id(idTotal)
{
	idTotal++;
}

ObjetVolant::~ObjetVolant() {

}

ObjetVolant &ObjetVolant::operator=(const ObjetVolant &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
}

