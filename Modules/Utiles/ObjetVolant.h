#ifndef _DEF_OBJETVOLANT
#define _DEF_OBJETVOLANT

#include "Coordonnees.h"

class ObjetVolant {

public:
	ObjetVolant(int, int);
	ObjetVolant(const ObjetVolant&);
	~ObjetVolant();
	Coordonnees inline GetCentre() {return this->centre;};
	int inline GetTailleCote() {return this->tailleCote;};
	ObjetVolant &operator=(const ObjetVolant&);
	
	virtual void avancer() = 0;
	virtual bool isColision() = 0;

protected:
	int tailleCote;
	int vitesse;
	Coordonnees centre;

};

#endif
