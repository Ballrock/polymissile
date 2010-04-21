/*
 * main.cpp
 *
 *  Created on: 21 avr. 2010
 *      Author: Pierre VIGREUX
 */
#include "Gestion.h"


int main(int argc, char **argv)
{
	Coordonnees *posSilo = new Coordonnees(20,480);
	Gestion *gest = new Gestion(*posSilo);
}
