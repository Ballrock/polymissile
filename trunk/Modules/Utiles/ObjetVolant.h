#ifndef _DEF_OBJETVOLANT
#define _DEF_OBJETVOLANT

#include "Coordonnees.h"
#include "Droite.h"
#include "../Interface/Affichable.h"

static int idTotal = 0;

class ObjetVolant : public Affichable {

public:
	ObjetVolant(int, int, Droite);
	ObjetVolant(const ObjetVolant&);
	~ObjetVolant();
	inline Coordonnees& getCentre() { return this->centre;};
	inline int getTailleCote() { return this->tailleCote;};
	ObjetVolant &operator=(const ObjetVolant&);
	inline int getId() { return this->id;};
	
	virtual void avancer() = 0;
	virtual bool isColision() = 0;

protected:
	int tailleCote;
	int vitesse;
	int id;
	Coordonnees centre;
	Droite pente;

};

#endif
