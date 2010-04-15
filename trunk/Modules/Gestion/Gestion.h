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

class Gestion
{
protected:
	Coordonnees *posSilo;
	int limSol;
	int score;
	// Je te conseil d'utiliser la classe Vector de la STL, tu auras ainsi un tableau non contraint en taille et tu pourras facilement le parcourir :-)
	ObjetVolant *obj;
public:
	Gestion &getInstance(); //méthode retournant l'instance de la classe (le singleton)
	Gestion &operator=(const Gestion &); //Il faut que l'operateur égale renvoie la classe singleton sinon comportement indéfini...
	~Gestion();		
	inline Coordonnees* getposSilo() { return this->posSilo; }
	int inline getlimSol() { return this->limSol; }
	int inline getscore() { return this->score; }
	int* gestionCollision();
	Droite &tirer(Coordonnees point);
	bool evoluer();

private:
	Gestion();
	Gestion *instance;

};


#endif /* GESTION_H_ */
