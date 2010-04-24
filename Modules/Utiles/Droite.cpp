#include "Droite.h"
#include <iostream>

using namespace std;

Droite::Droite(float a, float b):a(a), b(b) {

}

Droite::Droite(int x1, int y1, int x2, int y2)
{
cout << "x1 : " << x1 << " x2 : " << x2 << " y1 " << y1 << " y2 " << y2 << endl;
	/*
	 * On test si les X sont différents, sinon division par 0...
    */ 
	if(x1!=x2)
	{
		this->a = ((float)(y2 - y1)) / ((float)(x2 - x1));
		this->b = (float)(y1+y2- this->a*(x1+x2))/2;
	}
	else
	{
		this->a = 0;
		this->b = x1;
	}
	cout << "a : " << a << " b : " << b << endl;
}

Droite::Droite(Coordonnees &c1, Coordonnees &c2) { 
	Droite(c1.getX(), c1.getY(), c2.getX(), c2.getY());
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


