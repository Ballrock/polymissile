#include "Droite.h"


Droite::Droite(int a, int b):a(a), b(b) {

}

Droite::Droite(const Droite &obj):a(obj.a), b(obj.b) {

}

Droite::~Droite() {

}

Droite &Droite::operator=(const Droite &obj) {
	this->a = obj.a;
	this->b = obj.b;
}


