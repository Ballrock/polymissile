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
	static void setTableColor(SDL_Surface *ecran);
	enum {
 		C_NOIR=0, C_BLEU_FONCE=1, C_VERT_FONCE=2, C_CYAN_FONCE=3, C_ROUGE_FONCE=4,
  		C_MAGENTA_FONCE=5, C_OCRE=6, C_GRIS_CLAIR=7, C_GRIS=8, C_BLEU=9, C_VERT=10,
  		C_CYAN=11, C_ROUGE=12, C_MAGENTA=13, C_JAUNE=14, C_BLANC=15,
		
		NB_COULEURS=16  	
	};
	static Uint32 couleurs[];
};


#endif /* CONSTANTE_H_ */
