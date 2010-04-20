#ifndef _DEF_SILO
#define _DEF_SILO

#include "Affichable.h"
#include <SDL/SDL.h>
#include "../Utiles/Coordonnees.h"

class Silo : public Affichable {

public:
	Silo(Coordonnees &);
	Silo(const Silo &);
	~Silo();
	Silo &operator=(const Silo&);
	inline int getX() { return this->coordSilo->getX(); }
	inline int getY() { return this->coordSilo->getY(); }
	void paint(SDL_Surface *);

private:
	Coordonnees *coordSilo;
};

#endif
