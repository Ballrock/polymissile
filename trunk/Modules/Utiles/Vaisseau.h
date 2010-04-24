#ifndef _DEF_VAISSEAU
#define _DEF_VAISSEAU

#include "ObjetVolant.h"
#include <SDL/SDL.h>
#include "Coordonnees.h"
/*!
 * \file Vaisseau.h
 * \brief Classe Vaisseau
 */

/*!
 * \brief Classe de l'objet volant Vaisseau
 * \class Vaisseau
 */

class Vaisseau : public ObjetVolant {

public:
	/*!
	 * \brief Constructeur d'un nouveau Vaisseau
	 * \param int : Taille du vaisseau
	 * \param int : Vitesse du vaisseau
	 * \param Coordonnees & : Coordonnées d'apparition du vaisseau
	 * \param Droite & : Pente de descente du Vaisseau
	 */
	Vaisseau(int, int, Coordonnees &, Droite &);
	/*!
	 * \brief Constructeur par recopie
	 */
	Vaisseau(const Vaisseau&);
	/*!
	 * \brief Destructeur
	 */
	~Vaisseau();
	/*!
	 * \brief Redéfinition de l'opérateur égale
	 */
	Vaisseau &operator=(const Vaisseau&);
	/*!
	 * \brief Fonction d'affichage du vaisseau
	 * \param SDL_Surface * : surface de destination de l'affichage
	 */
	void paint(SDL_Surface *);
	/*!
	 * \brief Fonction servant à déplacer le vaisseau
	 */
	void avancer();

};


#endif
