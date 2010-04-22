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
	ScoreClient(int);
	ScoreClient(const ScoreClient&);
	~ScoreClient();
	ScoreClient &operator=(const ScoreClient &);
	void gereScoreJoueur();

private:
	int sock;
	TiXmlDocument doc;
	string *nomJoueur;	
	int score;
	void recuperationNomJoueur();
	void envoiScore();
	void recuperationTop(); 
	int initSocket();
	int ecrire(int, const char *);
	int lire(int, char *);
	sockaddr_in sin;

};


#endif
