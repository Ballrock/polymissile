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
#include "../Constante.h"
#include <vector>

using namespace std;

class Gestion
{
protected:
	Coordonnees *posSilo;
	int limSol;
	int score;
	vector<ObjetVolant*> obj;
public:
	Gestion();
	Gestion(const Gestion&);
	Gestion &operator=(const Gestion &);
	~Gestion();		
	inline Coordonnees* getPosSilo() { return this->posSilo; }
	int inline getLimSol() { return this->limSol; }
	int inline getScore() { return this->score; }
	vector<int> gestionCollision();
	void inline addObjVol(ObjetVolant *nouv) {this->obj.push_back(nouv);}; //méthode d'ajout d'un nouvel Objet Volant
	void tirer(Coordonnees& point);
	bool evoluer();

private:

};


#endif /* GESTION_H_ */
