#ifndef _DEF_FENETRE
#define _DEF_FENETRE

#include "../Gestion/Gestion.h"
#include "Sol.h"

class Fenetre
{

public:
	Fenetre(int, int);
	Fenetre(const Fenetre&);
	~Fenetre();
	Fenetre &operator=(const Fenetre&);
	int newWindows();	

private:
	int longueurFenetre, hauteurFenetre;
	Gestion *gestionJeu;	
	Sol *sol;

};


#endif

	
