#ifndef _DEF_COORDONNEES
#define _DEF_COORDONNEES

/*!
 * \file Coordonees.h
 * \brief Classe gerant les coordonnees des objets
*/

/*!
 * \class Coordonees.h
 * \brief Classe gerant les coordonnees des objets
*/
class Coordonnees {

public:
	/*!
 	 * \brief Constructeur
	 *
	 * Crée une coordonée
	*/	
	Coordonnees();

	/*!
 	 * \brief Constructeur
 	 *
 	 * Crée une coordonée grace à x et à y
	 * 
	 * \param int x : X de la coordonnée
	 * \param int y : Y de la coordonnée
	*/
	Coordonnees(int, int);
	
	/*!
 	 * \brief Destructeur
	*/
	~Coordonnees();
	
	/*!
 	 * \brief Constructeur par recopie
	*/
	Coordonnees(const Coordonnees&);

	/*!
 	 * \brief Operateur par recopie
	*/
	Coordonnees &operator=(const Coordonnees &);
	
	/*!
 	 * \brief getX
	 * 
	 * \return Retourne la coordonée X de la coordonnée
	*/
	int inline getX() { return this->x; }

	/*!
 	 * \brief getY
	 * 
	 * \return Retourne la coordonée Y de la coordonnée
	*/
	int inline getY() { return this->y; }

	/*!
 	 * \brief setX
	 *
	 * Change la valeur du X de la coordonée
	 * 
	 * \param int x : X de la coordonnée
	*/
	void inline setX(int x) { if (x > 0) this->x = x; }
	
	/*!
 	 * \brief setY
	 *
	 * Change la valeur du Y de la coordonée
	 * 
	 * \param int y : Y de la coordonnée
	*/
	void inline setY(int y) { if (y > 0) this->y = y; }

private:

	int x; /*!< X de la coordonnée*/
	int y; /*!< Y de la coordonnée*/


};


#endif
