#include "ObjetVolant.h"
#include "../Constante.h"
#include <math.h>
#include <iostream>


using namespace std;

ObjetVolant::ObjetVolant(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):tailleCote(tailleCote), vitesse(vitesse), pente(pente), centre(centre), xRestant(0.0), yRestant(0.0)
{

}

ObjetVolant::ObjetVolant(const ObjetVolant &obj):tailleCote(obj.tailleCote), vitesse(obj.vitesse), centre(obj.centre), pente(obj.pente)
{

}

ObjetVolant::~ObjetVolant() {

}

void ObjetVolant::avancer()
{
	this->yRestant += (float)(this->vitesse)*((float)Constante::TIMETICK/1000.0);
	this->xRestant += this->pente.getXWithY(this->centre.getY()+this->yRestant);
	cout << "xRestant : " << xRestant << " y restant : " << yRestant << endl;
//	std::cout << "L'objet avance suivant x -> " << this->xRestant << std::endl;
//	std::cout << "L'objet avance suivant y -> " << this->yRestant << std::endl;
	this->centre.setX(floor(this->xRestant));
	this->centre.setY(floor(this->centre.getY()-this->yRestant));
	this->xRestant -= floor(this->xRestant);
	this->yRestant -= floor(this->yRestant);
}

ObjetVolant &ObjetVolant::operator=(const ObjetVolant &obj) {
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
	this->centre = obj.centre;
	this->pente = obj.pente;
	return *this;
}

