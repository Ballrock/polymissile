#include "Coordonnees.h"


Coordonnees::Coordonnees(int x, int y): x(x), y(y) {

}

Coordonnees::Coordonnees():x(0), y(0) {

}

Coordonnees::~Coordonnees() {

}

Coordonnees::Coordonnees(const Coordonnees &obj): x(obj.x), y(obj.y) {

}

Coordonnees &Coordonnees::operator=(const Coordonnees &obj) {
	this->x = obj.x;
	this->y = obj.y;
	return *this;
}



