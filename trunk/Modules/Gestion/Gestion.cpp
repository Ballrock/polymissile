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
	cout << "\t Ceci est un ajout de vaisseau" << endl;
	cout << "Debut X= " << debut->getX() << "fin X= " << fin->getX() << endl;
	cout << "Valeur des coef a : " << pente->getA() << " b : " << pente->getB() << endl;
	this->addObjVol(new Vaisseau(Constante::TAILLEVAISSEAU, Constante::VITESSE, *debut, *pente));
}

void Gestion::tirer(Coordonnees& point)
{
	if (point.getY() < this->posSilo->getY()) {
		/* Le point est dans la zone de jeu (au dessus du sol) */
		Droite *tmp = new Droite(*(this->posSilo), point);
		std::cout << "\tVoici un tir sa pente est :" << std::endl;
		std::cout << "a= " << tmp->getA() << " b= " << tmp->getB() << std::endl;
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
			if(curCoord->getX()-curTaille > oppCoord->getX()+oppTaille && curCoord->getX()+curTaille > oppCoord->getX()+oppTaille)
			{
				if((curCoord->getY()-curTaille > oppCoord->getY()+oppTaille) && (curCoord->getY()-curTaille > oppCoord->getY()+oppTaille))
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
		opp++;
	}
}

bool Gestion::evoluer()
{
//	std::cout << "evoluer" << std::endl;
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
//		std::cout << "Je suis l'objet " << i << " de type " << typeid(**it).name() << std::endl;
//		std::cout << "Mes coordonnees sont X= " << (*it)->getCentre().getX() << " Y=" << (*it)->getCentre().getY() << endl;
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
		this->gestionCollision(it);
//		std::cout << "L'objet a-t-il disparu ?" << endl;
//		std::cout << "Y=" << (*it)->getCentre().getY() << " X=" << (*it)->getCentre().getX() << endl;
		if((*it)->getCentre().getY() < 0 || (*it)->getCentre().getX() <=0 || (*it)->getCentre().getX() >= 600)
		{
			cout << "\t Je ne suis plus sur l'écran je dois disparaitre et je suis un" << typeid(**it).name() << endl;
			cout << "X : " << (*it)->getCentre().getX() << " X : " << (*it)->getCentre().getY() << endl;
			std::cout << this->obj.size() << endl;
			this->obj.erase(it);
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

