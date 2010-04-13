#ifndef _DEF_OBJETVOLANT
#define _DEF_OBJETVOLANT


class ObjetVolant {

public:
	ObjetVolant(int, int);
	ObjetVolant(const ObjetVolant&);
	~ObjetVolant();
	ObjetVolant &operator=(const ObjetVolant&);
	
	virtual void avancer() = 0;
	virtual bool isColision() = 0;

protected:
	int tailleCote;
	int vitesse;

};

#endif
