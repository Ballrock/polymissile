#ifndef _DEF_VAISSEAU
#define _DEF_VAISSEAU

#include "ObjetVolant.h"

class Vaisseau : public ObjetVolant {

public:
	Vaisseau(int, int, Droite);
	Vaisseau(const Vaisseau&);
	~Vaisseau();
	Vaisseau &operator=(const Vaisseau&);

	void avancer();
	bool isColision();

};


#endif
