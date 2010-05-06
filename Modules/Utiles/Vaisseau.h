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
 	 * \brief Dessiner
	 *
	 * Methode dessinant le vaisseau dans SDL_Surface 
	 * 
	 * \param SDL_Surface * : Pointeur vers la surface de dessin
	*/
	void paint(SDL_Surface *);
	/*!
	 * \brief Avancer
	 * Fonction servant à déplacer le missile
	 */
	void avancer();

private:
	Uint32 couleurvaisseau;
	Uint32 couleurtrainee;
};


#endif
