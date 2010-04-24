#ifndef _DEF_OBJETVOLANT
#define _DEF_OBJETVOLANT

#include "Coordonnees.h"
#include "Droite.h"
#include "../Interface/Affichable.h"

/*!
 * \file ObjetVolant.h
 * \brief Classe définissant un objet volant de manière générale
 */

/*!
 * \brief Classe ObjetVolant
 * \class ObjetVolant
 */

class ObjetVolant : public Affichable {

public:
	/*!
	 * \brief Constructeur d'un nouvel ObjetVolant
	 * \param int : Taille de l'ObjetVolant
	 * \param int : Vitesse de l'ObjetVolant
	 * \param Coordonnees & : Coordonnées d'apparition de l'ObjetVolant
	 * \param Droite & : Pente de descente de l'ObjetVolant
	 */
	ObjetVolant(int, int, Coordonnees&, Droite&);
	/*!
	 * \brief Constructeur par recopie
	 */
	ObjetVolant(const ObjetVolant&);
	/*!
	 * \brief Destructeur
	 */
	~ObjetVolant();
	/*!
	 * \brief Getteur de l'attribut Centre
	 */
	inline Coordonnees& getCentre() { return this->centre;};
	/*!
	 * \brief Getteur de l'attribut TailleCote
	 */
	inline int getTailleCote() { return this->tailleCote;};
	/*!
	 * \brief Getteur de l'attribut Pente
	 */
	inline Droite getPente() { return this->pente;}
	/*!
	 * \brief Redéfinition de l'opérateur égal
	 */
	ObjetVolant &operator=(const ObjetVolant&);
	/*!
	 * \brief Fonction servant à déplacer l'ObjetVolant
	 * Cette fonction doit être redéfinie dans les classes filles
	 */
	virtual void avancer() = 0;

protected:
	int tailleCote; /*!< Taille de l'ObjetVolant*/
	int vitesse; /*!< Vitesse de l'ObjetVolant*/
	Coordonnees centre; /*!< Coordonnees du centre de l'ObjetVolant*/
	Droite pente; /*!< Pente de déplacement de l'ObjetVolant */
	float xRestant; /*!< Partie décimale du déplacement de l'ObjetVolant suivant x */
	float yRestant; /*!< Partie décimale du déplacement de l'ObjetVolant suivant y */

};

#endif
