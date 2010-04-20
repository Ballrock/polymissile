#include "Sol.h"
#include "../Constante.h"
#include <SDL/SDL_draw.h>


Sol::Sol(Coordonnees &coordSol, int longueur, int largeur) : longueur(longueur), largeur(largeur) {
	this->coordSol = new Coordonnees(coordSol);
}

Sol::Sol(const Sol &obj) {
	this->coordSol = new Coordonnees(*(obj.coordSol));
}

Sol::~Sol() {
	delete(this->coordSol);
}

Sol &Sol::operator=(const Sol &obj) {
	this->coordSol = new Coordonnees(*(obj.coordSol));
}

void Sol::paint(SDL_Surface *ecran) {
	Draw_FillRect(ecran, this->coordSol->getX(), this->coordSol->getY(), this->longueur, this->largeur, SDL_MapRGB(ecran->format, 223, 175, 44));
}
	
