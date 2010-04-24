/*
 * gestion.h
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */

#ifndef GESTION_H_
#define GESTION_H_

#include <SDL/SDL.h>
#include "../Utiles/Coordonnees.h"
#include "../Utiles/ObjetVolant.h"
#include "../Utiles/Droite.h"
#include "../Utiles/Missile.h"
#include "../Utiles/Vaisseau.h"
#include "../Interface/Affichable.h"
#include <vector>

using namespace std;
/*!
 * \file Gestion.h
 * \brief Classe de gestion des règles du jeu
 */

/*!
 * \brief Classe de gestion des règles du jeu
 */
class Gestion
{
protected:
	Coordonnees *posSilo; /*!<Coordonnees du silo */
	int limSol; /*!< Epaisseur du sol */
	int score; /*!< Score du joueur */
	int timer; /*!< Compte du temps écoulé */
	float nbVpS;  /*!< Nombre de vaisseau apparraissant par seconde */
	vector<ObjetVolant*> obj; /*!< Vecteur contenant les objets volants */
	/*!
	 * \brief Fonction de gestion des collisions
	 * La fonction test les collisions entre l'objet référencé par l'itérateur et les autres objets du vector
	 * \param vector<ObjetVolant*>::iterator &curr : itérateur sur l'objet courant
	 */
	void gestionCollision(vector<ObjetVolant*>::iterator &curr);
	/*!
	 * \brief Fonction d'ajout d'objet volant
	 * La fonction reçoit un pointeur vers un objet volant et l'ajoute de le vector de la classe gestion
	 */
	void inline addObjVol(ObjetVolant *nouv) {this->obj.push_back(nouv);}; //méthode d'ajout d'un nouvel Objet Volant
	/*!
	 * \brief Fonction d'ajout de vaisseau
	 * La fonction est appelé par la fonction evoluer et génére un nouveau vaisseau avec une pente tiré aléatoirement
	 */
	void ajoutVaisseau();
public:
	/*!
	 * \brief Constructeur
	 * Ce constructeur prend en paramètre des coordonnées qui serviront à attribué la place du silo
	 */
	Gestion(Coordonnees &);
	/*!
	 * \brief Constructeur par recopie
	 */
	Gestion(const Gestion&);
	/*!
	 * \brief Redéfinition de l'opérateur égale
	 */
	Gestion &operator=(const Gestion &);
	/*!
	 * \brief Destructeur
	 */
	~Gestion();
	int inline getLimSol() { return this->limSol; }
	int inline getScore() { return this->score; }
	int inline getTimer() { return this->timer; }
	inline Coordonnees* getPosSilo() { return this->posSilo; }
	inline vector<ObjetVolant*> *getObjetVolant() { return &(this->obj); }
	/*!
	 * \brief Fonction de tir
	 * La fonction reçoit en paramétres les coordonnées du clic et construit avec un nouvel objet missile
	 */
	void tirer(Coordonnees& point);
	/*!
	 * \brief Fonction principale
	 * Cette fonction s'occupe de la gestion globale du jeu elle vérifie les collisions et fait apparraitre les nouveaux vaisseaux
	 */
	bool evoluer();

private:

};


#endif /* GESTION_H_ */
