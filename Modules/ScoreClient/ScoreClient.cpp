#include "ScoreClient.h" 
#include "../Constante.h"
#include <sstream>
#include <arpa/inet.h>


ScoreClient::ScoreClient(int score) : score(score) {
	this->nomJoueur = new string();
}

ScoreClient::~ScoreClient() {
	delete this->nomJoueur;
	
}

ScoreClient::ScoreClient(const ScoreClient &obj) : score(obj.score) {
	this->nomJoueur = new string(*(obj.nomJoueur));
}

ScoreClient &ScoreClient::operator=(const ScoreClient &obj) {
	this->score = obj.score;
	this->nomJoueur = new string(*(obj.nomJoueur));
}

int ScoreClient::initSocket() {
	char buff[1024] = { '\0' };
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
 
   sin.sin_addr.s_addr = inet_addr(Constante::ADRESSESERVEUR);
   sin.sin_family = AF_INET;
   sin.sin_port = htons(Constante::PORT);

	memset(buff, '\0', 1024);
 
   if(connect(this->sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
		return -1;

	return 0;
}

void ScoreClient::gereScoreJoueur() {
	recuperationNomJoueur();
	envoiScore();
	recuperationTop();
}

void ScoreClient::recuperationNomJoueur() {
	cout << "Entre votre pseudo : ";
	cin >> *(this->nomJoueur);
}

int ScoreClient::ecrire(int sock, const char *buff) {
	return send(sock, buff, strlen(buff), 0);
}

int ScoreClient::lire(int sock, char *buff) {
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

void ScoreClient::envoiScore() {
	
	ostringstream os;
	istringstream is;
	char buff[1024];
	int charLu;

	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "", "");
	TiXmlElement *enreg = new TiXmlElement ("enregistrement");
	TiXmlElement *nom = new TiXmlElement ("nom");
	TiXmlElement *score = new TiXmlElement ("score");
	
	TiXmlText *txtNom = new TiXmlText (this->nomJoueur->c_str());
	os << this->score;
	TiXmlText *txtScore = new TiXmlText(os.str().c_str());

	score->LinkEndChild(txtScore);
	nom->LinkEndChild(txtNom);

	enreg->LinkEndChild(nom);
	enreg->LinkEndChild(score);
	
	doc.LinkEndChild(decl);
	doc.LinkEndChild(enreg);

	os.str("");
	os << doc;
	doc.Print();

	is.str(string(buff));

//	cout << is.str() << endl;
}

void ScoreClient::recuperationTop() {

}
