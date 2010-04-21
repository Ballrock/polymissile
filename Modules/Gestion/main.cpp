/*
 * main.cpp
 *
 *  Created on: 21 avr. 2010
 *      Author: Pierre VIGREUX
 */
#include "Gestion.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	Coordonnees *posSilo = new Coordonnees(300,460);
	Coordonnees *tir = new Coordonnees(250,300);
	Gestion *gest = new Gestion(*posSilo);
	gest->tirer(*tir);
	cout << gest->getObjetVolant() <<endl;
}
