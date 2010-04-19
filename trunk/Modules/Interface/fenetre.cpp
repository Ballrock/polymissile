#include "fenetre.h"
#include <SDL/SDL.h>
#include <iostream>
#include <math.h>

using namespace std;

Fenetre::Fenetre(int longueur=600, int hauteur=400) : longueurFenetre(longueur), hauteurFenetre(hauteur)
{
	Coordonnees *temp = new Coordonnees(0, Constante::ySilo);
	this->sol = new Sol(*(temp));
	temp->setX(longueur/2);
	temp->setY(this->sol->getCoordonnees().getY());
	this->gestionJeu = new Gestion();
	delete(temp);
}

Fenetre::Fenetre(const Fenetre &obj) {
}

Fenetre::~Fenetre() {
	SDL_VideoQuit();
	delete(this->sol);
	delete(this->gestionJeu);
}

Fenetre &Fenetre::operator=(const Fenetre &obj) {
	
}

int Fenetre::newWindows()
{
	bool continuer = true;
	SDL_Surface *ecran = NULL, *silo = NULL, *sol = NULL;
	SDL_Event event;
	SDL_Rect position;
	Coordonnees *click;

	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(this->longueurFenetre, this->hauteurFenetre, 32, SDL_SWSURFACE);
	sol = SDL_CreateRGBSurface(SDL_SWSURFACE, this->longueurFenetre, this->hauteurFenetre - this->sol->getCoordonnees().getY(), 32, 0, 0, 0, 0);
	SDL_WM_SetCaption("PolyMissile", NULL);	


	while (continuer) {
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONUP:
				click = new Coordonnees(event.button.x, event.button.y);
				gestionJeu->tirer(*click);
				delete (click);
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						continuer = 0;
						break;
				}
				break;
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_FillRect(sol, NULL, SDL_MapRGB(ecran->format, 223, 175, 44));
		position.x = 0;
		position.y = this->sol->getCoordonnees().getY();
		SDL_BlitSurface(sol, NULL, ecran, &position); 
		SDL_Flip(ecran);
	}

	SDL_FreeSurface(sol);
	SDL_Quit();
	return this->gestionJeu->getScore();
}

