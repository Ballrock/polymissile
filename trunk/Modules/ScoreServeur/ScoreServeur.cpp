#include "ScoreServeur.h"
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;


ScoreServeur::ScoreServeur() {
	this->socket =	GestionSockets::creeSocketReception(Constante::PORT);
	chargeXml();
}	

ScoreServeur &ScoreServeur::getInstance() {
	static ScoreServeur *instance;
	if (instance == NULL)
		instance = new ScoreServeur();
	return *instance;
}

ScoreServeur::~ScoreServeur() {

}

int ScoreServeur::acceptClient() {
	socklen_t addrlen = sizeof(this->addr);
	return accept(this->socket, (struct sockaddr *)&(this->addr), &addrlen);
}

int ScoreServeur::listenSocket() {
	return listen(this->socket, 10);
}

void ScoreServeur::chargeXml() {
	this->doc = TiXmlDocument(Constante::PATHBESTSCORE);
	this->doc.LoadFile();
	this->doc.Print();
}

void ScoreServeur::startServer() {
	int socketEnvoi;
	char buff[1024];
	int charLu;
	int score;
	istringstream is;
	ostringstream os;
	TiXmlDocument doc;

	memset(buff, '\0', 1024);
	listenSocket();
	socketEnvoi = acceptClient();

	cout << "ok " << socketEnvoi << endl;
	charLu = recv(this->socket, buff, 1024, 0);	

	cout << buff <<endl;
	is.str(string(buff));
	is >> doc;

	//score = atoi(doc.LastChild()->LastChild()->FirstChild()->Value());
	
	cout << score << endl;

	os << score;
	send(socketEnvoi, os.str().c_str(), strlen(os.str().c_str()), 0); 


}	
