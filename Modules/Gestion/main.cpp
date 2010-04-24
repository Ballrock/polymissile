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
	Coordonnees *posSilo = new Coordonnees(300,380);
//	Coordonnees *tir = new Coordonnees(10,370);
	Coordonnees *tir2 = new Coordonnees(400,10);
	Gestion *gest = new Gestion(*posSilo);
	int nb =0;
	bool perdu=false;
//	gest->tirer(*tir);
	gest->tirer(*tir2);
	while(!perdu)
	{
		perdu = gest->evoluer();
		nb++;
//		cout << "TailleVect : " << gest->getObjetVolant()->size() << endl;
		sleep(1);
//		cout << "ci-dessous le X du premier tir" << endl;
//		cout << gest->getObjetVolant()->front()->getCentre().getX() << endl;
	}
//	cout << "Vous avez perdu et il y a eu "<< nb <<" appel de évoluer" << endl;
}
