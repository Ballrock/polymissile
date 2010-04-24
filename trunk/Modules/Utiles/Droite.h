#ifndef _DEF_DROITE
#define _DEF_DROITE

#include "Coordonnees.h"
#include <iostream>

using namespace std;

class Droite {

public:
	Droite(float, float);
	Droite(Coordonnees &, Coordonnees&);
	Droite(int, int, int, int);
	Droite(const Droite &);
	~Droite();
	Droite &operator=(const Droite&);
	float inline getXWithY(float y) { cout << "y : " << y << " a : " << this->a << endl;return ((this->a!=0) ? ((y - this->b) / this->a) : this->b); }
	float inline getA() {return this->a;}
	float inline getB() {return this->b;}

private:
	float a;
	float b;
};

#endif
