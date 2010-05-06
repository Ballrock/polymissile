#include "Interface/fenetre.h"
#include "ScoreClient/ScoreClient.h"
#include "SDL/SDL.h"
#include "SDL/SDL_main.h"
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	

	Fenetre *maFenetre = new Fenetre(600, 400);
	ScoreClient gestionScoreClient = ScoreClient(maFenetre->newWindows());
	
	gestionScoreClient.gereScoreJoueur();
	

	delete(maFenetre);

	
	return 0;


}
