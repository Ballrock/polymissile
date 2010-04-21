#ifndef _DEF_SCORE_CLIENT
#define _DEF_SCORE_CLIENT

#include "../TinyXml/tinyxml.h
#include <string>
#include <iostream>

using namespace std;

class ScoreClient {

public:
	ScoreClient(int);
	ScoreClient(const ScoreClient&);
	~ScoreClient();
	ScoreClient &operator=(const ScoreClient &);
	void gereScoreJoueur();

private:
	int socket;
	TiXmlDocument doc;
	string *nomJoueur;	
	int score;
	void recuperationNomJoueur();
	void envoiScore();
	void recuperationTop(); 

};


#endif
