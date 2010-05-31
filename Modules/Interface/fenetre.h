#ifndef _DEF_FENETRE
#define _DEF_FENETRE

#include "../Gestion/Gestion.h"
#include "Sol.h"
#include "../Constante.h"
#include "Silo.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>

/*!
 * \file Fenetre.h
 * \brief Classe gerant la fenetre. Initialise, cree la fenetre et dessine tous les objets dedans
*/

/*!
 * \class Fenetre.h
 * \brief Classe gerant la fenetre. Initialise, cree la fenetre et dessine tous les objets dedans
*/

class Fenetre
{

public:
	/*!
 	 * \brief Constructeur
 	 *
 	 * Initialise les objets Silo et Sol à partir de la longueur et de la hauteur de la Fenetre
	 * 
	 * \param int longueur : Longueur de la Fenetre 
	 * \param int hauteur : Hauteur de la Fenetre
	*/
	Fenetre(int, int);
	
	/*!
 	 * \brief Constructeur par recopie
	*/	
	Fenetre(const Fenetre&);

	/*!
 	 * \brief Destructeur
	*/	
	~Fenetre();

	/*!
 	 * \brief Redefinition de l'opérateur =
	*/	
	Fenetre &operator=(const Fenetre&);
	
	/*!
 	 * \brief Nouvelle Fenetre
	 * Cree la fenêtre qui contiendra le jeu et l'affiche à l'écran
	*/	
	int newWindows();

	/*!
 	 * \brief Tout dessiner
	 * Dessine tous les objets affichables
	 * \param SDL_Surface * : Pointeur vers la surface de dessin
	 * \return Retourne le score final du joueur 
	*/	
	void dessineAll(SDL_Surface *);

private:
		
	int longueurFenetre, hauteurFenetre;
	Gestion *gestionJeu; 
	Sol *sol;
	Silo *silo;
	
	//TTF
	SDL_Surface *texte;
	SDL_Rect position;
	TTF_Font *police;
	char *scoretext;
	
};


#endif

	
