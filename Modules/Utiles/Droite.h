#ifndef _DEF_DROITE
#define _DEF_DROITE

#include "Coordonnees.h"

class Droite {

public:
	Droite(float, float);
	Droite(Coordonnees &, Coordonnees&);
	Droite(int, int, int, int);
	Droite(const Droite &);
	~Droite();
	Droite &operator=(const Droite&);
	float inline getXWithY(float y) { return ((this->a!=0) ? ((y - this->b) / a) : 0); }
	float inline getA() {return a;}
	float inline getB() {return b;}

private:
	float a;
	float b;
};

#endif
