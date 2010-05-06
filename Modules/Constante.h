/*
 * Constante.h
 *
 *  Created on: 19 avr. 2010
 *      Author: belgarion
 */

#ifndef CONSTANTE_H_
#define CONSTANTE_H_

#include "Utiles/Coordonnees.h"
#include "SDL/SDL_draw.h"
#include <SDL/SDL.h>


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
	enum {
 		C_NOIR, C_BLEU_FONCE, C_VERT_FONCE, C_CYAN_FONCE, C_ROUGE_FONCE,
  		C_MAGENTA_FONCE, C_OCRE, C_GRIS_CLAIR, C_GRIS, C_BLEU, C_VERT,
  		C_CYAN, C_ROUGE, C_MAGENTA, C_JAUNE, C_BLANC,
		
		NB_COULEURS  	
	};
	static Uint32 couleurs[NB_COULEURS];
	static void setTableColor(SDL_Surface*);
};


#endif /* CONSTANTE_H_ */
