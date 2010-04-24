#include "ScoreServeur.h"
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;


ScoreServeur::ScoreServeur() {
	if (initSocket() == -1) {
		cout << "Erreur d'initialisation du socket serveur" << endl;
		throw(new int(-1));
	}
	chargeXml();
}	

ScoreServeur &ScoreServeur::getInstance() {
	static ScoreServeur *instance;
	if (instance == NULL)
		instance = new ScoreServeur();
	return *instance;
}

int ScoreServeur::initSocket() {
	int sock_err;
	this->sock = socket(AF_INET, SOCK_STREAM, 0);

	if(this->sock == -1)
	{
		return -1;
	}
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(Constante::PORT);
	sock_err = bind(sock, (sockaddr*)&sin, sizeof(sin));

	if(sock_err == -1)
	{
 		return -1;
	}
	sock_err = listen(this->sock, 5);
	cout << "Serveur en écoute ..." << endl;
	return 0;
}


ScoreServeur::~ScoreServeur() {
	close(this->sock);
}

int ScoreServeur::acceptClient() {
	this->addrlen = sizeof(this->addr);
	return accept(this->sock, (struct sockaddr *)&(this->addr), &addrlen);
}

void ScoreServeur::chargeXml() {
	this->doc = TiXmlDocument(Constante::PATHBESTSCORE);
	this->doc.LoadFile();
	this->doc.Print();
}

void ScoreServeur::startServer() {
	int score;
	istringstream is;
	ostringstream os;
	TiXmlDocument doc;

	is >> doc;

	score = atoi(doc.LastChild()->LastChild()->FirstChild()->Value());
	
	cout << score << endl;

	os << score;

}	

int ScoreServeur::ecrire(int sock, const char *buff) {
	return send(sock, buff, strlen(buff), 0);
}

int ScoreServeur::lire(int sock, char *buff) {
	char c;
	int i=0;
	recv(sock, &c, 1, 0);
	while (c != '\0') {
		recv(sock, &c, 1, 0);
		buff[i];
		i++;
	}
	return 0;
}
