#ifndef _DEF_DROITE
#define _DEF_DROITE

#include "Coordonnees.h"
#include <iostream>

/*!
 * \file Droite.h
 * \brief Classe gerant les droites
*/

/*!
 * \class Droite
 * \brief Classe gerant les droites
*/
using namespace std;

class Droite {

public:
	/*!
 	 * \brief Constructeur
	 *
	 * Crée une droite a partir de a et b (y=ax+b)
	 *
	 * \param float a : Variable a de l'equation de droite
	 * \param float b : Variable b de l'equation de droite
	*/	
	Droite(float, float);
	
	/*!
 	 * \brief Constructeur
	 *
	 * Crée une droite a partir de deux Coordonnée
	 *
	 * \param Coordonnees &c1 : Reference vers les coordonnées du point 1
	 * \param Coordonnees &c2 : Reference vers les coordonnées du point 2
	*/	
	Droite(Coordonnees &, Coordonnees&);
	
	/*!
 	 * \brief Constructeur
	 *
	 * Crée une droite à partir de 4 valeur
	 *
	 * \param int x1 : X du point 1 de la droite
	 * \param int y1 : Y du point 1 de la droite
	 * \param int x2 : X du point 2 de la droite
	 * \param int y2 : Y du point 2 de la droite
	*/	
	Droite(int, int, int, int);
	
	/*!
 	 * \brief Constructeur par recopie
	*/
	Droite(const Droite &);
	
	/*!
 	 * \brief Destructeur
	*/
	~Droite();

	/*!
 	 * \brief Operateur par recopie
	*/
	Droite &operator=(const Droite&);
	
	/*!
 	 * \brief getXWithY
	 *
	 * Obtenir x à partir de y
	 * \return Retourne x pour le y donnée avec cette equation de droite 
	*/	
	float inline getXWithY(float y) { cout << "y : " << y << " a : " << this->a << endl;return ((this->a!=0) ? ((y - this->b) / this->a) : this->b); }
	
	/*!
 	 * \brief getA
	 * 
	 * \return Retourne le a de l'equation de la droite
	*/	
	float inline getA() {return this->a;}
	
	/*!
 	 * \brief getB
	 * 
	 * \return Retourne le b de l'equation de la droite
	*/
	float inline getB() {return this->b;}

private:
	float a; /*!< A de l'equation de la droite*/
	float b; /*!< B de l'equation de la droite*/
};

#endif
