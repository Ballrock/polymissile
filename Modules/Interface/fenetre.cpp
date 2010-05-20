#include "fenetre.h"
#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_draw.h>
#include <SDL/SDL_ttf.h>
#include <vector>
#include "../Utiles/ObjetVolant.h"

using namespace std;
int continuer = 1;

/*
 * Prototype de la fonction evoluer pour le timer (obligation d'etre en C donc pas membre de Fenetre)
 */
Uint32 evoluer(Uint32 interval, void *param);

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
	SDL_Quit();
	delete(this->sol);
	delete(this->gestionJeu);
}

Fenetre &Fenetre::operator=(const Fenetre &obj) {
	
}

int Fenetre::newWindows()
{
	SDL_Surface *ecran = NULL;
	SDL_Event event;
	Coordonnees *click;
	bool mouseClick = false;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	TTF_Init();
	this->police = TTF_OpenFont("arial.ttf", 14);	
	TTF_SetFontStyle(this->police, TTF_STYLE_BOLD);
	SDL_TimerID timer;

	ecran = SDL_SetVideoMode(this->longueurFenetre, this->hauteurFenetre, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("PolyMissile", NULL);	

	Constante::setTableColor(ecran);

	timer = SDL_AddTimer(Constante::TIMETICK, evoluer, this->gestionJeu);

	while (continuer) {
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseClick = true;
				break;
			case SDL_MOUSEBUTTONUP:
				if (mouseClick) {
					click = new Coordonnees(event.button.x, event.button.y);
					gestionJeu->tirer(*click);
					delete (click);
					mouseClick = false;
				}
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
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		dessineAll(ecran);
		SDL_Flip(ecran);
	}

	SDL_RemoveTimer(timer);
	TTF_CloseFont(this->police);
	TTF_Quit();
	SDL_Quit();
	return this->gestionJeu->getScore();
}

void Fenetre::dessineAll(SDL_Surface *ecran) {
	
	vector<ObjetVolant*> *vectObj = this->gestionJeu->getObjetVolant();
	vector<ObjetVolant*>::const_iterator it;
	for (it = vectObj->begin(); it != vectObj->end(); it++) {
		(*it)->paint(ecran);	
	}
	this->silo->paint(ecran);
	this->sol->paint(ecran);
	//AFFICHAGE DU TEXTE	
	
	SDL_Color couleurTexte = {0, 0, 0};
	sprintf(this->scoretext, "Score : %d", this->gestionJeu->getScore());
	texte = TTF_RenderText_Blended(police, this->scoretext, couleurTexte);
	this->position.x = 490;
   this->position.y = 382;
	SDL_BlitSurface(texte, NULL, ecran, &position);
	
}


Uint32 evoluer(Uint32 interval, void *param) {
	continuer = !(reinterpret_cast<Gestion *>(param)->evoluer());
	return interval;
}
