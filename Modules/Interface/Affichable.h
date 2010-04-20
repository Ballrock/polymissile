#ifndef _DEF_AFFICHABLE
#define _DEF_AFFICHABLE

#include <SDL.h>

class Affichable {
	
public:
	virtual void paint(SDL_Surface *) = 0;

};

#endif
