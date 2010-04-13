#include "Coordonnees.h"


Coordonnees::Coordonees(int x, int y): x(x), y(y) {

}

Coordonnees::Coordonnees():x(0), y(0) {

}

Coordonnees::~Coordonnes() {

}

Coordonnees::Coordonnees(const Coordonnees &obj): x(obj.x), y(obj.y) {

}

Coordonnes::Coordonnees &operator=(const Coordonnees &obj) {
	this->x = obj.x;
	this->y = obj.y;
	return *this;
}



