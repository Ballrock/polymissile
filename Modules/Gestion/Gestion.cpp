/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "Gestion.h"
#include <typeinfo>
#include "../Constante.h"

void newCollision(vector<int>* vec, ObjetVolant* cur, ObjetVolant* opp)
{
	if(typeid(*cur)!=typeid(*opp))
	{
		vec->push_back(cur->getId());
		vec->push_back(opp->getId());
	}
}

Gestion::Gestion(Coordonnees &posSilo)
{
	this->posSilo = new Coordonnees(posSilo);
	this->limSol = 20;
	this->score = 0;
}

Gestion::Gestion(const Gestion &obj)
{
	this->posSilo = obj.posSilo;
	this->limSol = obj.limSol;
	this->score = obj.score;
}

Gestion::~Gestion()
{
	free(this->posSilo);
}

void Gestion::tirer(Coordonnees& point)
{
	Droite *tmp = new Droite(point, *(this->posSilo));
	ObjetVolant *nouv = new Missile(Constante::TAILLEMISSILE, Constante::VITESSE, point, *tmp);
	this->addObjVol(nouv);
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
						newCollision(&vec,this->obj[i],this->obj[j]);
					}
					else
					{
						if((curCoord->getY()+curTaille > oppCoord->getY()-oppTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-oppTaille))
						{
							newCollision(&vec,this->obj[i],this->obj[j]);
						}
					}
				}
				else
				{
					if((curCoord->getX()+curTaille > oppCoord->getX()-oppTaille) && (curCoord->getX()-curTaille < oppCoord->getX()-oppTaille))
					{
						if((curCoord->getY()-curTaille < oppCoord->getY() + oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
						{
							newCollision(&vec,this->obj[i],this->obj[j]);
						}
						else
						{
							if((curCoord->getY()+curTaille > oppCoord->getY()-curTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-curTaille))
							{
								newCollision(&vec,this->obj[i],this->obj[j]);
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
	for (unsigned int var = 0; var < this->obj.size(); ++var)
	{
		this->obj[var]->avancer();
		if(typeid(this->obj[var])==typeid(Vaisseau))
		{
			if(this->obj[var]->getCentre().getY() + this->obj[var]->getTailleCote()/2 <= this->posSilo->getY())
			{
				return true;
			}
		}
	}

	return false;
}

Gestion &Gestion::operator=(const Gestion &obj) {
	this->posSilo = obj.posSilo;
	this->limSol = obj.limSol;
	this->score = obj.score;
	return *this;
}

