#ifndef _DEF_MISSILE
#define _DEF_MISSILE

#include "ObjetVolant.h"
#include <SDL/SDL.h>
#include "Coordonnees.h"

/*!
 * \file Missile.h
 * \brief Classe gerant les missiles
*/

/*!
 * \class Missile
 * \brief Classe gerant les missiles
*/

class Missile : public ObjetVolant {

public:
	/*!
	 * \brief Constructeur d'un nouveau Missile
	 * \param int : Taille du missile
	 * \param int : Vitesse du missile
	 * \param Coordonnees & : Coordonnées d'apparition du missile
	 * \param Droite & : Pente de ascentionnel du missile
	 */
	Missile(int, int, Coordonnees &, Droite &);
	
	/*!
	 * \brief Constructeur par recopie
	 */
	Missile(const Missile&);
	
	/*!
	 * \brief Destructeur
	 */
	~Missile();
	
	/*!
	 * \brief Redefinition de l'operateur =
	 */
	Missile &operator=(const Missile&);
	
	/*!
	 * \brief Avancer
	 * Fonction servant à déplacer le missile
	 */
	void avancer();
	
	/*!
 	 * \brief Dessiner
	 *
	 * Methode dessinant le missile dans SDL_Surface 
	 * 
	 * \param SDL_Surface * : Pointeur vers la surface de dessin
	*/
	void paint(SDL_Surface *);

};


#endif
