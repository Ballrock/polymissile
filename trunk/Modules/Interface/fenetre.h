#ifndef _DEF_FENETRE
#define _DEF_FENETRE

#include "../Gestion/Gestion.h"
#include "Sol.h"
#include "../Constante.h"
#include "Silo.h"

class Fenetre
{

public:
	Fenetre(int, int);
	Fenetre(const Fenetre&);
	~Fenetre();
	Fenetre &operator=(const Fenetre&);
	int newWindows();	
	void dessineAll(SDL_Surface *);

private:
	int longueurFenetre, hauteurFenetre;
	Gestion *gestionJeu;	
	Sol *sol;
	Silo *silo;

};


#endif

	
