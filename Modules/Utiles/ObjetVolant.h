#ifndef _DEF_OBJETVOLANT
#define _DEF_OBJETVOLANT

#include "Coordonnees.h"
#include "Droite.h"
#include "../Interface/Affichable.h"

class ObjetVolant : public Affichable {

public:
	ObjetVolant(int, int, Coordonnees&, Droite&);
	ObjetVolant(const ObjetVolant&);
	~ObjetVolant();
	inline Coordonnees& getCentre() { return this->centre;};
	inline int getTailleCote() { return this->tailleCote;};
	inline Droite getPente() { return this->pente;}
	ObjetVolant &operator=(const ObjetVolant&);
	
	void avancer();

protected:
	int tailleCote;
	int vitesse;
	Coordonnees centre;
	Droite pente;
	float xRestant;
	float yRestant;

};

#endif
