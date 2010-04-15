/*
 * gestion.h
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */

#ifndef GESTION_H_
#define GESTION_H_

#include <stdio.h>
#include </SDL/SDL.h>
#include "../Utiles/Coordonnees.h"
#include "../Utiles/ObjetVolant.h"

class gestion
{
protected:
	Coordonnees posSilo;
	int limSol;
	int score;
	static bool exist=false;	//résolution du singleton de la classe
	ObjetVolant Obj[];
public:
	gestion();
	~gestion();		//pas d'opérateur égal ou de constructeur par recopie car la class est unique
	Coordonnees inline GetposSilo() {return this->posSilo;};
	int inline GetlimSol() {return this->limSol;};
	int inline Getscore() {return this->score;};
	int* gestionCollision();
	Droite Tirer(Coordonnees point);
	bool evoluer();
};


#endif /* GESTION_H_ */
