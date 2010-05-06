#include "ScoreServeur.h"
#include <SDL/SDL_main.h>


int main(int argc, char *argv[]) {
	ScoreServeur gestionScore = ScoreServeur::getInstance();
	gestionScore.startServer();

	return 0;
}
