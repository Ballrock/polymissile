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
	TiXmlNode *child = NULL;
	int scoreInt, scoreInt2 = 0;
	int i = 0;
	TiXmlDocument doci;
   
   ostringstream os;

   TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "", "");
   TiXmlElement *enreg = new TiXmlElement ("enregistrement");
   TiXmlElement *nom = new TiXmlElement ("nom");
   TiXmlElement *scorei = new TiXmlElement ("score");
   
   TiXmlText *txtNom = new TiXmlText ("doubi");
   os << 3000;
   TiXmlText *txtScore = new TiXmlText(os.str().c_str());

   scorei->LinkEndChild(txtScore);
   nom->LinkEndChild(txtNom);

   enreg->LinkEndChild(nom);
   enreg->LinkEndChild(scorei);
   
   doci.LinkEndChild(decl);
   doci.LinkEndChild(enreg);

   os.str("");
   os << doci;

	/* 
	 * Parcours de tous les enregistrements de score et test du score courant avec le score à insérer, on l'insère lorsqu'on arrive à la bonne position
	 */
	os.str("");
	os << *(doci.LastChild()->LastChild()->FirstChild());
	scoreInt = atoi(os.str().c_str());
	if (this->doc.LastChild()->FirstChild()) {
		while( child = this->doc.LastChild()->IterateChildren( child ) ) {
			os.str("");
			os << *(child->LastChild()->FirstChild());
			scoreInt2 = atoi(os.str().c_str());
			cout << "sc 1 : " << scoreInt << " sc 2 : " << scoreInt2 << endl;
			if (scoreInt > scoreInt2) {
				break;
			}
			i++;
		}

	}
	if (child)
		doc.LastChild()->InsertBeforeChild(child, *(doci.LastChild()));	
	else
		doc.LastChild()->InsertEndChild(*(doci.LastChild()));
	this->doc.SaveFile();

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
