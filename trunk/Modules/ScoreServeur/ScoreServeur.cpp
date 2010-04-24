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
	FILE *f = fopen(Constante::PATHBESTSCORE, "r");
	if (f == NULL) {
		fclose(f);
		FILE *fout = fopen(Constante::PATHBESTSCORE, "w+");
		TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "", "");
		TiXmlElement *en = new TiXmlElement("enregistrements");
		this->doc.LinkEndChild(decl);
		this->doc.LinkEndChild(en);
		this->doc.SaveFile(fout);
		fclose(fout);
	}
	this->doc = TiXmlDocument(Constante::PATHBESTSCORE);
	this->doc.LoadFile();
	this->doc.Print();
}

void ScoreServeur::startServer() {
	istringstream is;
	ostringstream os;
	TiXmlDocument *docScore = new TiXmlDocument();

	is >> *docScore;

	ajouteScore(*docScore);

	cout << "Meilleurs Scores : " << this->doc;
}	

void ScoreServeur::ajouteScore(TiXmlNode &score) {
	TiXmlNode *child;
	int i = 0;
	/* 
	 * Parcours de tous les enregistrements de score et test du score courant avec le score à insérer, on l'insère lorsqu'on arrive à la bonne position
	 */
	while ((child = doc.LastChild()->IterateChildren( child )) && (atoi(score.LastChild()->LastChild()->FirstChild()->Value()) > atoi(child->LastChild()->LastChild()->FirstChild()->Value()))) {
		i++;	
	}

	/* 
	 * On n'est pas à la fin des scores, on ajoute alors le score 
	 */
	if (child || (!child && i<20)) {
		doc.LastChild()->LinkEndChild(&score);
	}

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
