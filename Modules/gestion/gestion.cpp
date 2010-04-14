/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "gestion.h"
#include "../Utiles/Coordonnees.h"
#include "../Utiles/Droite.h"

gestion::gestion()
{
	if(gestion.exist==false)
	{
	this->posSilo = new Coordonnees();  //il faut déterminer la position du silo
	this->limSol = new int(20);
	this->score = new int(0);
	gestion.exist=true;
	}
	else
	{
		printf("Erreur la class gestion existe déjà et doit être unique \n");
	}
}

gestion::~gestion()
{
	free(this->limSol);
	free(this->posSilo);
	free(this->score);
}

Droite gestion::Tirer(Coordonnees point)
{
	Coordonnees posSilo = new Coordonnees(this->GetposSilo());
	int a,b;
	a=(int) (point.getY()-posSilo.getY())/(point.getX()-posSilo.getX());
	b=(int) (point.getY()-a*point.getX());
	return new Droite(a,b);
}

bool gestion::gestionCollision()
{

}

