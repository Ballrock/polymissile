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
#include <c++/4.3/vector>

using namespace std;

class Gestion
{
protected:
	Coordonnees *posSilo;
	int limSol;
	int score;
	vector<ObjetVolant*> obj;
public:
	Gestion &getInstance(); //méthode retournant l'instance de la classe (le singleton)
	Gestion &operator=(const Gestion &); //Il faut que l'operateur égale renvoie la classe singleton sinon comportement indéfini...
	~Gestion();		
	inline Coordonnees* getposSilo() { return this->posSilo; }
	int inline getlimSol() { return this->limSol; }
	int inline getscore() { return this->score; }
	int* gestionCollision();
	void inline addObjVol(ObjetVolant *nouv) {this->obj.push_back(nouv);}; //méthode d'ajout d'un nouvel Objet Volant
	Droite &tirer(Coordonnees point);
	bool evoluer();

private:
	Gestion();
	Gestion *instance;

};


#endif /* GESTION_H_ */
