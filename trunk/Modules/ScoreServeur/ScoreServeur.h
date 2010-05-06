#ifndef _DEF_SCORE_SERVEUR
#define _DEF_SCORE_SERVEUR

#include "../Constante.h"
#include "../TinyXml/tinyxml.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../Utiles/Communication.h"
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>


/*!
 * \file ScoreServeur.h
 * \brief Classe de gestion des scores (au niveau serveur)
 */

/*!
 * \class ScoreServeur
 * \brief Classe de gestion des scores
 */
class ScoreServeur {

public:
	~ScoreServeur();
	/*!
	 * \brief Retourne l'instance unique de la classe (Singleton)
	 * \return Reférence de l'instance de la classe
	 */ 
	static ScoreServeur &getInstance();

	/*!
	 * \brief Démarre le serveur
	 * Démarre le serveur en chargeant le fichier XML contenant les meilleurs scores puis se met en écoute d'un client.
	 * Lorsqu'un client se connecte, récupère le score du client puis l'ajoute aux meilleurs scores s'il le faut puis retourne les meilleurs scores.
	 */
	void startServer();

private:
	ScoreServeur();

	/*
	 * Charge le fichier XML des meilleurs scores
	 */
	void chargeXml();

	/*
	 * Ajoute un score (s'il fait parti des meilleurs)
	 */
	void ajouteScore(TiXmlNode &score);

	int initSocket();
	static int ecrire(int, const char*);
	static int lire(int, char *);

	TCPsocket server;
	TiXmlDocument doc; //Document XML

};

#endif

	
