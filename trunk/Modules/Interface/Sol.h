#ifndef _DEF_SOL
#define _DEF_SOL

#include "Affichable.h"
#include "../Utiles/Coordonnees.h"

class Sol : public Affichable {
public:
	Sol(Coordonnees &);
	Sol(const Sol&);
	~Sol();
	Sol &operator=(const Sol&);
	Coordonnees &getCoordonnees();
	void paint();

private:
	Coordonnees *coordSol;
};


#endif
