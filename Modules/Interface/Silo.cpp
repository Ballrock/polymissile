#include "Silo.h"
#include "../Constante.h"
#include <SDL/SDL_draw.h>

Silo::Silo(Coordonnees &coordSilo) {
	this->coordSilo = new Coordonnees(coordSilo);
}

Silo::Silo(const Silo &obj) {
	this->coordSilo = new Coordonnees(*(obj.coordSilo));
}

Silo::~Silo() {
	delete this->coordSilo;
}

Silo &Silo::operator=(const Silo &obj) {
	this->coordSilo = new Coordonnees(*(obj.coordSilo));
}

void Silo::paint(SDL_Surface *ecran) {
	Draw_FillCircle(ecran, this->getX(), this->getY(), Constante::TAILLESILO, SDL_MapRGB(ecran->format, 255, 0, 0));	
}
