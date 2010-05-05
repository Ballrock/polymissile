#include "Vaisseau.h"
#include "../Constante.h"
#include "SDL/SDL_draw.h"
#include <math.h>


Vaisseau::Vaisseau(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):ObjetVolant(tailleCote, vitesse, centre, pente) {

}

Vaisseau::Vaisseau(const Vaisseau &obj):ObjetVolant(obj)
{

}

Vaisseau::~Vaisseau()
{

}

void Vaisseau::avancer()
{
	this->yRestant += (float)(this->vitesse)*((float)Constante::TIMETICK/1000.0);
	this->xRestant += this->pente.getXWithY(this->centre.getY()+this->yRestant);
	this->centre.setX(floor(this->xRestant));
	this->centre.setY(floor(this->centre.getY()+this->yRestant));
	this->xRestant -= floor(this->xRestant);
	this->yRestant -= floor(this->yRestant);
}

Vaisseau &Vaisseau::operator=(const Vaisseau &obj)
{
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
	return *this;
}

void Vaisseau::paint(SDL_Surface *ecran) {
	//TODO : couleur ALEA (avec tableau de toutes les couleurs utilisées quelque part !
	if (this->centre.getX() > this->tailleCote && this->centre.getY() > this->tailleCote && this->centre.getX() < 600 - this->tailleCote)
		Draw_FillRect(ecran, (this->centre.getX() - (this->tailleCote/2)), (this->centre.getY() - (this->tailleCote/2)), Constante::TAILLEVAISSEAU, Constante::TAILLEVAISSEAU, SDL_MapRGB(ecran->format, 255, 0, 0));
}
