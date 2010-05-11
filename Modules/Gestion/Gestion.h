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
	Coordonnees *posSilo;
	int limSol;
	int score;
	int timer;
	float nbVpS;
	vector<ObjetVolant*> obj;
	void gestionCollision(vector<ObjetVolant*>::iterator &curr);
	void inline addObjVol(ObjetVolant *nouv) {this->obj.push_back(nouv);}; //méthode d'ajout d'un nouvel Objet Volant
	void ajoutVaisseau();
public:
	/*!
	 * \brief Constructeur
	 * Ce constructeur prend en paramètre des coordonnées qui serviront à attribuer la place du silo
	 */
	Gestion(Coordonnees &);
	/*!
	 * \brief Constructeur par recopie
	 */
	Gestion(const Gestion&);
	/*!
	 * \brief Redéfinition de l'opérateur égal
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
	
	vector<ObjetVolant *>::iterator supprimeObjVolant(int);

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


};


#endif /* GESTION_H_ */
