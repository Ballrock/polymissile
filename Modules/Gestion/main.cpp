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
	Coordonnees *tir2 = new Coordonnees(300,10);
	Gestion *gest = new Gestion(*posSilo);
	bool perdu=false;
	gest->tirer(*tir);
	gest->tirer(*tir2);
	std::cout << gest->getObjetVolant()->front()->getCentre().getX() << endl;
	while(!perdu)
	{
		perdu = gest->evoluer();
		cout << "tailleVect : " << gest->getObjetVolant()->size() << endl;
		sleep(1);
	}
	cout << "Vous avez perdu" << endl;
}
