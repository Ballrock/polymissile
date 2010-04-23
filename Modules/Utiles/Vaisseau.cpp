#include "Vaisseau.h"
#include "../Constante.h"
#include "SDL/SDL_draw.h"


Vaisseau::Vaisseau(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):ObjetVolant(tailleCote, vitesse, centre, pente) {

}

Vaisseau::Vaisseau(const Vaisseau &obj):ObjetVolant(obj)
{

}

Vaisseau::~Vaisseau()
{

}

Vaisseau &Vaisseau::operator=(const Vaisseau &obj)
{
	this->tailleCote = obj.tailleCote;
	this->vitesse = obj.vitesse;
	return *this;
}

void Vaisseau::paint(SDL_Surface *ecran) {
	//TODO : couleur ALEA (avec tableau de toutes les couleurs utilisées quelque part !
	Draw_FillRect(ecran, (this->centre.getX() - (this->tailleCote/2)), (this->centre.getY() - (this->tailleCote/2)), Constante::TAILLEVAISSEAU, Constante::TAILLEVAISSEAU, SDL_MapRGB(ecran->format, 255, 0, 0));
}
