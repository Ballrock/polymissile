#include "Droite.h"
#include <iostream>

using namespace std;

Droite::Droite(float a, float b):a(a), b(b) {

}

Droite::Droite(int x1, int y1, int x2, int y2) {
	this->a = ((float)(y2 - y1)) / ((float)(x2 - x1));
	this->b = (float)y1 - this->a * (float)x1;
}

Droite::Droite(Coordonnees &c1, Coordonnees &c2) { 
	this->a = ((float)(c2.getY() - c1.getY())) / ((float)(c2.getX() - c1.getX()));
	this->b = (float)(c1.getY()) - this->a * (float)(c1.getX());
}

Droite::Droite(const Droite &obj):a(obj.a), b(obj.b) {
	
}

Droite::~Droite() {

}

Droite &Droite::operator=(const Droite &obj) {
	this->a = obj.a;
	this->b = obj.b;
	return *this;
}


