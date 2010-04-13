#ifndef _DEF_COORDONNEES
#define _DEF_COORDONNEES


class Coordonnees {

public:
	Coordonnees();
	Coordonnees(int, int);
	~Coordonnees();
	Coordonnees(const Coordonnees&);
	Coordonnees &operator=(const Coordonnees &);

	int inline getX() { return this->x; }
	int inline getY() { return this->y; }
	void inline setX(int x) { if (x > 0) this->x = x; }
	void inline setY(int y) { if (y > 0) this->y = y; }

private:

	int x;
	int y;


};


#endif
