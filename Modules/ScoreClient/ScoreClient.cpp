#include "ScoreClient.h" 
#include "../Utiles/GestionSockets.h"
#include "../Constante.h"
#include <sstream>


ScoreClient::ScoreClient(int score) : score(score) {
	this->socket = GestionSockets::creeSocketEmission(Constante::ADRESSESERVEUR, Constante::PORT);
	this->nomJoueur = new string();
	
}

ScoreClient::~ScoreClient() {
	delete this->nomJoueur;
}

ScoreClient::ScoreClient(const ScoreClient &obj) : score(obj.score) {
	this->socket = GestionSockets::creeSocketEmission(Constante::ADRESSESERVEUR, Constante::PORT);
	this->nomJoueur = new string(*(obj.nomJoueur));
}

ScoreClient &ScoreClient::operator=(const ScoreClient &obj) {
	this->score = obj.score;
	this->socket = GestionSockets::creeSocketEmission(Constante::ADRESSESERVEUR, Constante::PORT);
	this->nomJoueur = new string(*(obj.nomJoueur));
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

void ScoreClient::envoiScore() {
	
	ostringstream os;

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

	os.flush();
	os << doc.ToElement();
	doc.Print();

}

void ScoreClient::recuperationTop() {

}
