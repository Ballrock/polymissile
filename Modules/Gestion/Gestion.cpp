/*
 * gestion.cpp
 *
 *  Created on: 12 avr. 2010
 *      Author: Pierre Vigreux
 */
#include "Gestion.h"
#include <typeinfo>
#include "../Constante.h"
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void newCollision(vector<ObjetVolant*>* vec, vector<ObjetVolant*>::iterator cur, vector<ObjetVolant*>::iterator opp)
{
	if(typeid(**cur)!=typeid(**opp))
	{
		vec->erase(cur);
		vec->erase(opp);
	}
}

Gestion::Gestion(Coordonnees &posSilo)
{
	srand(time(NULL));
	this->posSilo = new Coordonnees(posSilo);
	this->limSol = 20;
	this->score = 0;
	this->timer = 0;
	this->nbVpS = 1;
}

Gestion::Gestion(const Gestion &obj)
{
	srand(time(NULL));
	this->posSilo = obj.posSilo;
	this->limSol = obj.limSol;
	this->score = obj.score;
	this->timer = obj.timer;
}

Gestion::~Gestion()
{
	free(this->posSilo);
	this->obj.clear();
}

void Gestion::ajoutVaisseau()
{
	Coordonnees *debut = new Coordonnees((int)(((double)rand() / ((double)RAND_MAX + 1))*600), 0);
	Coordonnees *fin = new Coordonnees((int)((double)rand() / ((double)RAND_MAX + 1)*600), 400);
	Droite *pente = new Droite(*fin, *debut);
	this->addObjVol(new Vaisseau(Constante::TAILLEVAISSEAU, Constante::VITESSE, *debut, *pente));
}

void Gestion::tirer(Coordonnees& point)
{
	if (point.getY() < this->posSilo->getY()) {
		/* Le point est dans la zone de jeu (au dessus du sol) */
		Droite *tmp = new Droite(*(this->posSilo), point);
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
//			L'opposant est un autre objet que l'objet courant
			if ((((curCoord->getY() + curTaille > oppCoord->getY() - oppTaille)
					&& (curCoord->getY() - curTaille < oppCoord->getY() - oppTaille))
					&& ((curCoord->getX() + curTaille > oppCoord->getX() - oppTaille)
					&& (curCoord->getX() - curTaille < oppCoord->getX() - oppTaille)))
				|| 
					((( curCoord->getY() - curTaille < oppCoord->getY() - oppTaille)
					&& (curCoord->getY() + curTaille > oppCoord->getY() - oppTaille))
					&& ((curCoord->getX() - curTaille < oppCoord->getX() + oppTaille)
					&& (curCoord->getX() + curTaille > oppCoord->getX() + oppTaille)))
				||
					((( curCoord->getY() - curTaille < oppCoord->getY() + oppTaille)
					&& (curCoord->getY() + curTaille > oppCoord->getY() + oppTaille))
					&& ((curCoord->getX() - curTaille < oppCoord->getX() + oppTaille)
					&& (curCoord->getX() + curTaille > oppCoord->getX() + oppTaille)))
				||
					((( curCoord->getY() - curTaille < oppCoord->getY() + oppTaille)
					&& (curCoord->getY() + curTaille > oppCoord->getY() + oppTaille))
					&& ((curCoord->getX() - curTaille < oppCoord->getX() - oppTaille)
					&& (curCoord->getX() + curTaille > oppCoord->getX() - oppTaille))))
			{
				newCollision(&this->obj, curr, opp);
			}
		}
		opp++;
	}
}

bool Gestion::evoluer()
{
	this->timer += Constante::TIMETICK;
	if((this->timer - 1000)>0)
	{
		this->nbVpS += 0.1;
		this->timer -= 1000;
		for (int i = 0; i < floor(this->nbVpS); i++)
		{
			this->ajoutVaisseau();
		}
	}
	vector<ObjetVolant*>::iterator it;
	for (it = this->obj.begin(); it != this->obj.end(); it++)	
	{
		(*it)->avancer();
		if(typeid(**it)==typeid(Vaisseau))
		{
//			L'objet est un vaisseau il test donc une éventuelle collision avec le sol
			if((*it)->getCentre().getY()+(*it)->getTailleCote()/2 >= this->posSilo->getY())
			{
				std::cout << "Je suis un " << typeid(**it).name() << std::endl;
				std::cout << "Je rencontre le sol mon Y est " << (*it)->getCentre().getY() << std::endl;
				return true;
			}
		}
		if((*it)->getCentre().getY() < 0 || (*it)->getCentre().getX() <=0 || (*it)->getCentre().getX() >= 600)
		{
			cout << "\t Je ne suis plus sur l'écran je dois disparaitre et je suis un" << typeid(**it).name() << endl;
			cout << "X : " << (*it)->getCentre().getX() << " X : " << (*it)->getCentre().getY() << endl;
			std::cout << this->obj.size() << endl;
			this->obj.erase(it);
		}
		this->gestionCollision(it);
	}
	return false;
}

Gestion &Gestion::operator=(const Gestion &obj) {
	this->posSilo = obj.posSilo;
	this->limSol = obj.limSol;
	this->score = obj.score;
	return *this;
}

