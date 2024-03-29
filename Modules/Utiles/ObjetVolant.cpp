#include "ObjetVolant.h"
#include "../Constante.h"
#include <math.h>
#include <iostream>


using namespace std;

int ObjetVolant::idTotal = 0;

ObjetVolant::ObjetVolant(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):tailleCote(tailleCote), vitesse(vitesse), pente(pente), centre(centre), xRestant(0.0), yRestant(0.0)
{
	this->id = ObjetVolant::idTotal;
	ObjetVolant::idTotal++;
}

ObjetVolant::ObjetVolant(const ObjetVolant &obj):tailleCote(obj.tailleCote), vitesse(obj.vitesse), centre(obj.centre), pente(obj.pente)
{

}

ObjetVolant::~ObjetVolant() {

}

ObjetVolant &ObjetVolant::operator=(const ObjetVolant &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
	this->centre = obj.centre;
	this->pente = obj.pente;
	return *this;
}

