#include "Sol.h"


Sol::Sol(Coordonnees &coordSol) {
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

Coordonnees &Sol::getCoordonnees() {
	return *(this->coordSol);
}

void Sol::paint() {

}
	
