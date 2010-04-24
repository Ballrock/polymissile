#ifndef _DEF_SILO
#define _DEF_SILO

#include "Affichable.h"
#include <SDL/SDL.h>
#include "../Utiles/Coordonnees.h"

/*!
 * \file Silo.h
 * \brief Classe gerant le silo
*/

/*!
 * \class Silo.h
 * \brief Classe gerant le silo
*/

class Silo : public Affichable {

public:
	/*!
 	 * \brief Constructeur
 	 *
 	 * Crée un silo a la coordonnée indiqué
	 * 
	 * \param Coordonnees & coordSilo : Référence sur la coordonée du silo
	*/
	Silo(Coordonnees &);

	/*!
 	 * \brief Constructeur par recopie
	*/
	Silo(const Silo &);

	/*!
 	 * \brief Destructeur
	*/
	~Silo();

	/*!
 	 * \brief Redefinition de l'opérateur =
	*/
	Silo &operator=(const Silo&);
	
	/*!
 	 * \brief getX
	 * 
	 * \return Retourne la coordonée X du silo
	*/
	inline int getX() { return this->coordSilo->getX(); }

	/*!
 	 * \brief getY
	 * 
	 * \return Retourne la coordonée Y du silo
	*/
	inline int getY() { return this->coordSilo->getY(); }

	/*!
 	 * \brief Dessiner
	 *
	 * Methode dessinant l'objet dans SDL_Surface 
	 * 
	 * \param SDL_Surface * : Pointeur vers la surface de dessin
	*/
	void paint(SDL_Surface *);

private:
	Coordonnees *coordSilo; /*!< Pointeur sur les Coordonnées du Silo*/
};

#endif
