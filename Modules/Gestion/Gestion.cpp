/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "Gestion.h"
#include <typeinfo>
#include "../Constante.h"

void newCollision(vector<ObjetVolant*>* vec, vector<ObjetVolant*>::iterator cur, vector<ObjetVolant*>::iterator opp)
{
	if(typeid(*cur)!=typeid(*opp))
	{
		vec->erase(cur);
		vec->erase(opp);
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
	if (point.getY() < this->posSilo->getY()) {
		/* Le point est dans la zone de jeu (au dessus du sol) */
		Droite *tmp = new Droite(point, *(this->posSilo));
		ObjetVolant *nouv = new Missile(Constante::TAILLEMISSILE, Constante::VITESSE, *(this->posSilo), *tmp);
		this->addObjVol(nouv);
	}
}

void Gestion::gestionCollision(vector<ObjetVolant*>::iterator &curr)
{
	Coordonnees *curCoord = new Coordonnees((*curr)->getCentre());
	int curTaille = (*curr)->getTailleCote()/2;
	vector<ObjetVolant*>::iterator opp= this->obj.begin();
	while(opp!=this->obj.end())
	{
		Coordonnees *oppCoord = new Coordonnees((*opp)->getCentre());
		int oppTaille = (*opp)->getTailleCote()/2;
		if(curr!=opp)
		{
			if(curCoord->getX()-curTaille > oppCoord->getX()+oppTaille && curCoord->getX()+curTaille > oppCoord->getX()+oppTaille)
			{
				if((curCoord->getY()-curTaille < oppCoord->getY()+oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
				{
					newCollision(&this->obj,curr,opp);
				}
				else
				{
					if((curCoord->getY()+curTaille > oppCoord->getY()-oppTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-oppTaille))
					{
						newCollision(&this->obj,curr,opp);
					}
				}
			}
			else
			{
				if((curCoord->getX()+curTaille > oppCoord->getX()-oppTaille) && (curCoord->getX()-curTaille < oppCoord->getX()-oppTaille))
				{
					if((curCoord->getY()-curTaille < oppCoord->getY() + oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
					{
						newCollision(&this->obj,curr,opp);
					}
					else
					{
						if((curCoord->getY()+curTaille > oppCoord->getY()-curTaille) && (curCoord->getY()-curTaille < oppCoord->getY()-curTaille))
						{
							newCollision(&this->obj,curr,opp);
						}
					}
				}
			}
		}
	}
}

bool Gestion::evoluer()
{
	vector<ObjetVolant*>::iterator it;
	it = this->obj.begin();
	while(it != this->obj.end())
	{
		(*it)->avancer();
		if(typeid(*it)==typeid(Vaisseau))
		{
			if((*it)->getCentre().getY()+(*it)->getTailleCote()/2 <= this->posSilo->getY())
			{
				return true;
			}
		}
		else
		{
			this->gestionCollision(it);
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

