#ifndef _DEF_SOL
#define _DEF_SOL

#include "Affichable.h"
#include "../Utiles/Coordonnees.h"
#include <SDL/SDL.h>

class Sol : public Affichable {
public:
	Sol(Coordonnees &, int, int);
	Sol(const Sol&);
	~Sol();
	Sol &operator=(const Sol&);
	inline int getX() { return this->coordSol->getX(); }
	inline int getY() { return this->coordSol->getY(); }
	void paint(SDL_Surface *);

private:
	Coordonnees *coordSol;
	int longueur, largeur;
};


#endif
