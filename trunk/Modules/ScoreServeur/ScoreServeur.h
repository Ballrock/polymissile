#ifndef _DEF_SCORE_SERVEUR
#define _DEF_SCORE_SERVEUR

#include "../Constante.h"
#include "../Utiles/GestionSockets.h"
#include "../TinyXml/tinyxml.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 


class ScoreServeur {

public:
	~ScoreServeur();
	static ScoreServeur &getInstance();
	void startServer();

private:
	ScoreServeur();
	void chargeXml();
	int acceptClient();
	int listenSocket();

	SOCKET socket;
	TiXmlDocument doc;

};

#endif

	
