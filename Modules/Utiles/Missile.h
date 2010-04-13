#ifndef _DEF_MISSILE
#define _DEF_MISSILE

#include "ObjetVolant.h"

class Missile : public ObjetVolant {

public:
	Missile(int, int);
	Missile(const Missile&);
	~Missile();
	Missile &operator=(const Missile&);

	void avancer();
	bool isColision();

};


#endif
