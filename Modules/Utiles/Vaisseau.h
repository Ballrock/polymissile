#ifndef _DEF_MISSILE
#define _DEF_MISSILE

#include "ObjetVolant.h"

class Vaisseau : public ObjetVolant {

public:
	Vaisseau(int, int);
	Vaisseau(const Vaisseau&);
	~Vaisseau();
	Vaisseau &operator=(const Vaisseau&);

	void avancer();
	bool isColision();

};


#endif
