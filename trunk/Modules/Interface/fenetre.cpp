#include "fenetre.h"
#include <SDL/SDL.h>

//-------------SINGLETON------------

Fenetre & Fenetre::getInstance()
{
 	if(window == NULL)
	{	 // instance unique cachée dans la fonction. Ne pas oublier le static !
		window = new Fenetre();    		
		return *window;
	}
}

Fenetre::Fenetre()
{
	sdlInit();
}

//--------------Methodes-----------
void Fenetre::sdlInit()
{
	SDL_Init(SDL_INIT_VIDEO);
}

Fenetre::~Fenetre() {
	SDL_VideoQuit();
}

void Fenetre::newWindows(int x=800, int y=600, int color=32)
{
	SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
}
