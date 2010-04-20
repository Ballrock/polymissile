#include "fenetre.h"
#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_draw.h>
#include <vector>
#include "../Utiles/ObjetVolant.h"

using namespace std;

Fenetre::Fenetre(int longueur=600, int hauteur=400) : longueurFenetre(longueur), hauteurFenetre(hauteur)
{
	Coordonnees *temp = new Coordonnees(0, hauteur - Constante::TAILLESOL);
	this->sol = new Sol(*(temp), longueur, Constante::TAILLESOL);
	temp->setX(longueur/2);
	temp->setY(hauteur - Constante::TAILLESOL);
	this->silo = new Silo(*(temp));
	this->gestionJeu = new Gestion(*(temp));
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
	SDL_Surface *ecran = NULL;
	SDL_Event event;
	SDL_Rect position;
	Coordonnees *click;

	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(this->longueurFenetre, this->hauteurFenetre, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("PolyMissile", NULL);	


	while (continuer) {
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONUP:
				cout << "tir : " << event.button.x << " " << event.button.y << endl;
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
		/*
		 * Effacement de la fenetre
		 */
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		dessineAll(ecran);
		SDL_Flip(ecran);
	}

	SDL_Quit();
	return this->gestionJeu->getScore();
}

void Fenetre::dessineAll(SDL_Surface *ecran) {
	vector<ObjetVolant*> *vectObj = this->gestionJeu->getObjetVolant();
	vector<ObjetVolant*>::const_iterator it;
	this->silo->paint(ecran);
	this->sol->paint(ecran);
	for (it = vectObj->begin(); it != vectObj->end(); it++) {
		(*it)->paint(ecran);	
	}
}
