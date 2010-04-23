/*
 * main.cpp
 *
 *  Created on: 21 avr. 2010
 *      Author: Pierre VIGREUX
 */
#include "Gestion.h"
#include "../Constante.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	Coordonnees *posSilo = new Coordonnees(300,460);
	Coordonnees *tir = new Coordonnees(250,300);
	Coordonnees *tmp = new Coordonnees(30, 50);
	Coordonnees *tmp21 = new Coordonnees(300, 430);
	Coordonnees *tmp22 = new Coordonnees(320, 480);
	Droite *tmpd2 = new Droite(*tmp21, *tmp22);
	Droite *tmpd = new Droite(*tir, *tmp);
	Gestion *gest = new Gestion(*posSilo);
	bool perdu=false;
	gest->tirer(*tir);
	gest->addObjVol(new Vaisseau(Constante::TAILLEVAISSEAU, Constante::VITESSE, *tmp, *tmpd));
	gest->addObjVol(new Vaisseau(Constante::TAILLEVAISSEAU, Constante::VITESSE, *tmp21, *tmpd2));
	while(!perdu)
	{
		perdu = gest->evoluer();
		cout << gest->getObjetVolant()->size() << endl;
	}
	cout << "Vous avez perdu" << endl;
	cout << gest->getObjetVolant() <<endl;
}
