#include "ScoreServeur.h"


int main() {
	ScoreServeur gestionScore = ScoreServeur::getInstance();
	gestionScore.startServer();

	return 0;
}
