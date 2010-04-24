#ifndef _DEF_AFFICHABLE
#define _DEF_AFFICHABLE

#include <SDL/SDL.h>

/*!
 * \file Affichable.h
 * \brief Interface pour tous les objets affichables dans la fenetre.
*/

/*!
 * \class Affichable
 * \brief Interface pour tous les objets affichables dans la fenetre
*/

class Affichable {
	
public:
	/*!
 	 * \brief Dessine l'objet
 	 *
 	 * Methode dessinant l'objet dans SDL_Surface
	 * 
	 * \param SDL_Surface * : Pointeur vers la surface de dessin
	*/

	virtual void paint(SDL_Surface *) = 0;

};

#endif
