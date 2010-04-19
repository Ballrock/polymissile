/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "Gestion.h"
#include <typeinfo>

void newCollision(vector<int>* vec, ObjetVolant* cur, ObjetVolant* opp, int indcur, int indopp)
{
	if(typeid(*cur)!=typeid(*opp))
	{
		vec->push_back(indcur);
		vec->push_back(indopp);
	}
}

Gestion::Gestion(Coordonnees &posSilo)
{
	this->posSilo = new Coordonnees(posSilo);
	this->limSol = 20;
	this->score = 0;
}

Gestion::Gestion(const Gestion &obj) {
	this->posSilo = obj.posSilo;
	this->limSol = obj.limSol;
	this->score = obj.score;
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

vector<int> Gestion::gestionCollision()
{
	vector<int> vec;

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
						newCollision(&vec,this->obj[i],this->obj[j],i,j);
					}
					else
					{
						if((curCoord->getY()+curTaille > oppCoord->getY()-oppTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-oppTaille))
						{
							newCollision(&vec,this->obj[i],this->obj[j],i,j);
						}
					}
				}
				else
				{
					if((curCoord->getX()+curTaille > oppCoord->getX()-oppTaille) && (curCoord->getX()-curTaille < oppCoord->getX()-oppTaille))
					{
						if((curCoord->getY()-curTaille < oppCoord->getY() + oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
						{
							newCollision(&vec,this->obj[i],this->obj[j],i,j);
						}
						else
						{
							if((curCoord->getY()+curTaille > oppCoord->getY()-curTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-curTaille))
							{
								newCollision(&vec,this->obj[i],this->obj[j],i,j);
							}
						}
					}
				}
			}
		}
	}
	return vec;
}

bool Gestion::evoluer()
{

}

Gestion &Gestion::operator=(const Gestion &obj) {
	this->posSilo = obj.posSilo;
	this->limSol = obj.limSol;
	this->score = obj.score;
	return *this;
}

