#ifndef _DEF_VAISSEAU
#define _DEF_VAISSEAU

#include "ObjetVolant.h"
#include <SDL/SDL.h>
#include "Coordonnees.h"

class Vaisseau : public ObjetVolant {

public:
	Vaisseau(int, int, Coordonnees &, Droite &);
	Vaisseau(const Vaisseau&);
	~Vaisseau();
	Vaisseau &operator=(const Vaisseau&);

	void paint(SDL_Surface *);
	void avancer();

};


#endif
