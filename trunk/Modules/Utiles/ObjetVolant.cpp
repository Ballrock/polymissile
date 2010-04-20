#include "ObjetVolant.h"


ObjetVolant::ObjetVolant(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):tailleCote(tailleCote), vitesse(vitesse), pente(pente), id(idTotal), centre(centre)
{
	idTotal++;
}

ObjetVolant::ObjetVolant(const ObjetVolant &obj):tailleCote(obj.tailleCote), vitesse(obj.vitesse), centre(obj.centre), pente(obj.pente), id(idTotal)
{
	idTotal++;
}

ObjetVolant::~ObjetVolant() {

}

ObjetVolant &ObjetVolant::operator=(const ObjetVolant &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
}

