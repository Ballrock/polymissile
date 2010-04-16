/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "Gestion.h"

Gestion::Gestion()
{
	this->posSilo = new Coordonnees();  //il faut déterminer la position du silo
	this->limSol = 20;
	this->score = 0;
}

Gestion &Gestion::getInstance() {
	if (instance == NULL) {
		instance = new Gestion();
	}
	return *instance;
}

Gestion::~Gestion()
{
	free(this->posSilo);
}

Droite &Gestion::tirer(Coordonnees point)
{
	int a,b;
	a=(int) (point.getY()-this->posSilo->getY())/(point.getX()-this->posSilo->getX());
	b=(int) (point.getY()-a*point.getX());
	return *(new Droite(a,b));
}

int* Gestion::gestionCollision()
{
	int *tab;
	int ind=0;
	for(int i=0; i < 0; i++)
	{
		Coordonnees *curCoord = new Coordonnees(this->obj[i]->getCentre());
		int curTaille = this->obj[i]->getTailleCote()/2;
		for(int j=0; i < 0; j++)
		{
			Coordonnees *oppCoord = new Coordonnees(this->obj[j]->getCentre());
			int oppTaille = this->obj[i]->getTailleCote()/2;
			if(i!=j)
			{
				if(curCoord->getX()-curTaille > oppCoord->getX()+oppTaille && curCoord->getX()+curTaille > oppCoord->getX()+oppTaille)
				{
					if((curCoord->getY()-curTaille < oppCoord->getY()+oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
					{
						/* Comm de Benjamin :  
						 *????? tu as voulu faire un table d'int et mettre les indices des objets qui se touchent ? 
						 * pk faire des "new int" a chaque fois ???
						 */
						tab[ind] = i;
						ind++;
						tab[ind] = j;
						ind++;
					}
					else
					{
						if((curCoord->getY()+curTaille > oppCoord->getY()-oppTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-oppTaille))
						{
							tab[ind] = i;
							ind++;
							tab[ind] = j;
							ind++;
						}
					}
				}
				else
				{
					if((curCoord->getX()+curTaille > oppCoord->getX()-oppTaille) && (curCoord->getX()-curTaille < oppCoord->getX()-oppTaille))
					{
						if((curCoord->getY()-curTaille < oppCoord->getY() + oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
						{
							tab[ind] = i;
							ind++;
							tab[ind] = j;
							ind++;
						}
						else
						{
							if((curCoord->getY()+curTaille > oppCoord->getY()-curTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-curTaille))
							{
								tab[ind] = i;
								ind++;
								tab[ind] = j;
								ind++;
							}
						}
					}
				}
			}
		}
	}
	return tab;
}

bool Gestion::evoluer()
{

}

Gestion &Gestion::operator=(const Gestion &obj) {
	return const_cast<Gestion&>(obj);
}
