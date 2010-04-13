#ifndef _DEF_DROITE
#define _DEF_DROITE


class Droite {

public:
	Droite(int, int);
	Droite(const Droite &);
	~Droite();
	Droite &operator=(const Droite&);
	int inline getXWithY(int y) { return ((y - this->b) / a); }

private:
	int a;
	int b;
};

#endif
