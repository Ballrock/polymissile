#ifndef _DEF_OBJETVOLANT
#define _DEF_OBJETVOLANT

#include "Coordonnees.h"

static int idTotal = 0;

class ObjetVolant {

public:
	ObjetVolant(int, int);
	ObjetVolant(const ObjetVolant&);
	~ObjetVolant();
	inline Coordonnees& getCentre() { return this->centre; }
	inline int getTailleCote() { return this->tailleCote; }
	ObjetVolant &operator=(const ObjetVolant&);
	
	virtual void avancer() = 0;
	virtual bool isColision() = 0;

protected:
	int tailleCote;
	int vitesse;
	Coordonnees centre;
	int id;
};

#endif
