#ifndef _DEF_SCORE_SERVEUR
#define _DEF_SCORE_SERVEUR

#include "../Constante.h"
#include "../TinyXml/tinyxml.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


class ScoreServeur {

public:
	~ScoreServeur();
	static ScoreServeur &getInstance();
	void startServer();

private:
	ScoreServeur();
	void chargeXml();
	int acceptClient();
	int initSocket();
	int ecrire(int, const char*);
	int lire(int, char *);

	int sock;
	struct sockaddr_in addr;
	struct sockaddr_in sin;
	socklen_t addrlen;
	TiXmlDocument doc;

};

#endif

	
