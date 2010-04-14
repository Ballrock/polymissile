#include "Fenetre.h"
#include <SDL/SDL.h>

//-------------SINGLETON------------

Fenetre & Fenetre::GetInstance()
{
 	if(window == NULL)
	{	 // instance unique cachée dans la fonction. Ne pas oublier le static !
		window = new Fenetre();    		
		return *window;
	}
}

Fenetre::Fenetre()
{
}

//--------------Methodes-----------
Fenetre::void SdlInit()
{
	SDL_Init(SDL_INIT_VIDEO);
}
Fenetre::void NewWindows(int x=800, int y=600, int color=32)
{
	SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
}
