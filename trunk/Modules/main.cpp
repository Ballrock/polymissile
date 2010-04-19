#include "Interface/fenetre.h"
#include "SDL/SDL.h"
#include "SDL/SDL_main.h"
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	
	char* nomJoueur = (char*) malloc(sizeof(char)*50);
	int scoreFinal;

	Fenetre *maFenetre = new Fenetre(600, 400);
	scoreFinal = maFenetre->newWindows();
	

	delete(maFenetre);

	cout << "Partie terminée !" << endl << "Votre score est de : " << scoreFinal << endl << endl << "Veuillez saisir votre nom" << endl;
	
	cin >> nomJoueur;

	cout << endl << "Votre nom est : " << nomJoueur << endl;
	return 0;


}
