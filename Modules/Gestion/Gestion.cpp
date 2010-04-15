/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "gestion.h"
#include "../Utiles/Coordonnees.h"
#include "../Utiles/Droite.h"
#include "../Utiles/ObjetVolant.h"

gestion::gestion()
{
	if(gestion.exist==false)
	{
	this->posSilo = new Coordonnees();  //il faut déterminer la position du silo
	this->limSol = new int(20);
	this->score = new int(0);
	this->Obj = NULL;
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
	free(this->Obj);
}

Droite gestion::Tirer(Coordonnees point)
{
	Coordonnees posSilo = new Coordonnees(this->GetposSilo());
	int a,b;
	a=(int) (point.getY()-posSilo.getY())/(point.getX()-posSilo.getX());
	b=(int) (point.getY()-a*point.getX());
	return new Droite(a,b);
}

int* gestion::gestionCollision()
{
	int tab[];
	for(int i=0; this->Obj[i]; i++)
	{
		Coordonnees curCoord = new Coordonnees(this->Obj[i].GetCentre());
		int curTaille = new int(this->Obj[i].GetTailleCote()/2);
		for(int j=0; this->Obj[j]; j++)
		{
			Coordonnees oppCoord = new Coordonnees(this->Obj[j].GetCentre());
			int oppTaille = new int(this->Obj[i].GetTailleCote()/2);
			if(i!=j)
			{
				if(curCoord.getX()-curTaille>oppCoord.getX()+oppTaille)
				{
					if(curCoord.getY()-curTaille<oppCoord.getY()+oppTaille || curCoord.getY()+curTaille>oppCoord.getY()-oppTaille)
					{
						tab = new int(i);
						tab = new int(j);
					}
				}
				else
				{
					if(curCoord.getX()+curTaille>oppCoord.getX()-oppTaille)
					{
						if(curCoord.getY()-curTaille<oppCoord.getY()+oppTaille || curCoord.getY()+curTaille>oppCoord.getY()-oppTaille)
						{
							tab = new int(i);
							tab = new int(j);
						}
					}
				}
			}
		}
	}
	return tab;
}

bool gestion::evoluer()
{

}
