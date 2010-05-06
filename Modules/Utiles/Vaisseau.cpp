#include "Vaisseau.h"
#include "../Constante.h"
#include "SDL/SDL_draw.h"
#include <math.h>
#include <time.h>

Vaisseau::Vaisseau(int tailleCote, int vitesse, Coordonnees &centre, Droite &pente):ObjetVolant(tailleCote, vitesse, centre, pente) {
	srand (time(NULL));
	int rdmcouleur = rand()%2;
	if (rdmcouleur == 0)
	{
		this->couleurvaisseau=Constante::couleurs[Constante::C_ROUGE];
		this->couleurtrainee=Constante::couleurs[Constante::C_ROUGE_FONCE];
	}
	else
	{
		this->couleurvaisseau=Constante::couleurs[Constante::C_VERT];
		this->couleurtrainee=Constante::couleurs[Constante::C_VERT_FONCE];
	}
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
	if (this->centre.getX() > this->tailleCote && this->centre.getY() > this->tailleCote && this->centre.getX() < 600 - this->tailleCote)
		Draw_FillRect(ecran, (this->centre.getX() - (this->tailleCote/2)), (this->centre.getY() - (this->tailleCote/2)), Constante::TAILLEVAISSEAU, Constante::TAILLEVAISSEAU, this->couleurvaisseau);
}
