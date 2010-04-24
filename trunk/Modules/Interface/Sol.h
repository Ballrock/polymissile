#ifndef _DEF_SOL
#define _DEF_SOL

#include "Affichable.h"
#include "../Utiles/Coordonnees.h"
#include <SDL/SDL.h>

/*!
 * \file Sol.h
 * \brief Classe gerant le sol
*/

/*!
 * \class Sol.h
 * \brief Classe gerant le sol
*/

class Sol : public Affichable {
public:
	/*!
 	 * \brief Constructeur
 	 *
 	 * Crée un sol a la coordonnée et de la taille indiqué 
	 * 
	 * \param Coordonnees & coordSilo : Référence sur la coordonée du silo
	 * \param int longueur : Longueur du sol
	 * \param int largeur : Largueur du sol	
	*/
		
	Sol(Coordonnees &, int, int);
	
	/*!
 	 * \brief Constructeur par recopie
	*/	
	Sol(const Sol&);
	
	/*!
 	 * \brief Destructeur
	*/	
	~Sol();

	/*!
 	 * \brief Redefinition de l'opérateur =
	*/
	Sol &operator=(const Sol&);
	
	/*!
 	 * \brief getX
	 * 
	 * \return Retourne la coordonée X du sol
	*/
	inline int getX() { return this->coordSol->getX(); }

	/*!
 	 * \brief getY
	 * 
	 * \return Retourne la coordonée Y du sol
	*/
	inline int getY() { return this->coordSol->getY(); }

	/*!
 	 * \brief Dessiner
	 *
	 * Methode dessinant l'objet dans SDL_Surface 
	 * 
	 * \param SDL_Surface * : Pointeur vers la surface de dessin
	*/	
	void paint(SDL_Surface *);

private:
	Coordonnees *coordSol; /*!< Pointeur sur les Coordonnées du Silo*/
	int longueur, largeur; /*!< Longueur et Largueur du Silo*/
};


#endif
