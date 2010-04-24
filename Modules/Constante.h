/*
 * Constante.h
 *
 *  Created on: 19 avr. 2010
 *      Author: belgarion
 */

#ifndef CONSTANTE_H_
#define CONSTANTE_H_

#include "Utiles/Coordonnees.h"


/*!
 * \file Constante.h
 * \brief Définie les constantes du programme
 */

/*!
 * \class Constante
 * \brief Définie les constantes du programme
 */

class Constante
{
public:
	static const int VITESSE = 30;
	static const int TAILLEMISSILE = 5;
	static const int TAILLEVAISSEAU = 10;
	static const int TAILLESILO = 20;
	static const int TAILLESOL = 20;
	static const char ADRESSESERVEUR[];
	static const int PORT = 5321;
	static const char PATHBESTSCORE[];
	static const int TIMETICK = 30;
};


#endif /* CONSTANTE_H_ */
