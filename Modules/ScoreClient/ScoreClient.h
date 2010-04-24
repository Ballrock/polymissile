#ifndef _DEF_SCORE_CLIENT
#define _DEF_SCORE_CLIENT

#include "../TinyXml/tinyxml.h"
#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

class ScoreClient {

public:
	/*!
	 * \brief Constructeur de l'objet de gestion du score
	 * Construit un objet de gestion du score au niveau du client du jeu
	 * \param Le score obtenu par le joueur
	 */
	ScoreClient(int);

	/*!
	 * \brief Constructeur par recopie
	 */
	ScoreClient(const ScoreClient&);

	~ScoreClient();
	ScoreClient &operator=(const ScoreClient &);
	
	/*!
	 * \brief Gère tout le processus d'envoie du score du joueur sur le serveur, puis affiche le top 20 des scores
	 * Récupère le nom du joueur sur la console (après la fermeture de la fenêtre) puis envoie le score au serveur et récupère le top score depuis le serveur.
	 */
	void gereScoreJoueur();

private:
	int sock; //Socket pour l'intégration
	TiXmlDocument doc; //Document XML
	string *nomJoueur;
	int score;

	/*
	 * Permet de récupérer le nom du joueur
	 */
	void recuperationNomJoueur();

	/*
	 * Envoie le score du joueur au serveur sous format XML
	 */
	void envoiScore();

	/*
	 * Récupère le top score depuis le serveur
	 */
	void recuperationTop(); 

	/*
	 * Diverses fonctions gérant les sockets (pour l'intégration)
	 */
	int initSocket();
	int ecrire(int, const char *);
	int lire(int, char *);
	sockaddr_in sin;

};


#endif
