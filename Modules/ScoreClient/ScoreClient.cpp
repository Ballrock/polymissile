#include "ScoreClient.h" 
#include "../Constante.h"
#include <sstream>
#include <arpa/inet.h>
#include <vector>
#include <string>
#include <math.h>


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
	IPaddress ip;
	char *buff;
	int numready;
	SDLNet_SocketSet set;
	fd_set fdset;
	int result;
	/* initialize SDL_net */
	if(SDLNet_Init()==-1)
	{
		printf("SDLNet_Init: %s\n",SDLNet_GetError());
		SDL_Quit();
		exit(3);
	}

	set=SDLNet_AllocSocketSet(1);
	if(!set)
	{
		printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(4); /*most of the time this is a major error, but do what you want. */
	}

	
	/* Resolve the argument into an IPaddress type */
	if(SDLNet_ResolveHost(&ip,Constante::ADRESSESERVEUR,Constante::PORT)==-1)
	{
		printf("SDLNet_ResolveHost: %s\n",SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(5);
	}

	/* open the server socket */
	sock=SDLNet_TCP_Open(&ip);
	if(!sock)
	{
		printf("SDLNet_TCP_Open: %s\n",SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(6);
	}
	
	if(SDLNet_TCP_AddSocket(set,sock)==-1)
	{
		printf("SDLNet_TCP_AddSocket: %s\n",SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(7);
	}
}

void ScoreClient::gereScoreJoueur() {
	envoiScore();
	recuperationTop();
}

void ScoreClient::recuperationNomJoueur() {
	cout << "Entre votre pseudo : ";
	cin >> *(this->nomJoueur);
}

void ScoreClient::envoiScore() {
	
	ostringstream os;
	istringstream is;
	char *buff = (char *) malloc(sizeof(char)*1024);
	int charLu;
	TiXmlNode *child;
	int maxLengthName = 0;
	int maxLengthScore = 0;
	vector<string> names;
	vector<string> scores;
	string buffName;
	string buffScore;
	vector<string>::iterator it;
	vector<string>::iterator it2;
	

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

	cout << "La partie est terminée, votre score est de : " << this->score << endl << endl;

	recuperationNomJoueur();
	cout << endl;
	initSocket();
	Communication::ecrire(sock, os.str().c_str());
	Communication::lire(sock, &buff);
	cout << "Top 20 des scores : " << endl << endl;

	is.str(string(buff));
	is >> doc;
	
	
	for (child = doc.LastChild()->FirstChild(); child != 0; child = child->NextSibling()) {
		os.str("");
		os << *(child->FirstChild()->FirstChild());
		buffName = os.str();
		os.str("");
		os << *(child->LastChild()->FirstChild());
		buffScore = os.str();
		if (buffName.size() > maxLengthName)
			maxLengthName = buffName.size();
		if (buffScore.size() > maxLengthScore)
			maxLengthScore = buffScore.size();
		names.push_back(buffName);
		scores.push_back(buffScore);
	}

	cout << "    Noms   ";
	for (int i=0; i < (maxLengthName - 4); i++)
		cout << " ";
	cout << "   Scores  ";
	for (int i=0; i < (maxLengthName - 5); i++)
		cout << " ";
	cout << " " << endl << endl;
	for (int i=0; i < maxLengthName + 8; i++)
		cout << "_";
	for (int i=0; i < maxLengthScore + 8; i++)
		cout << "_";
	cout << endl;
	for (it = names.begin(), it2 = scores.begin(); it != names.end(); it++, it2++) {
		cout << "|   ";
		cout << *it << "   ";
		for (int i=0; i < (maxLengthName - (*it).size()); i++)
			cout << " ";
		cout << "|  ";
		for (int i=0; i < (maxLengthScore - (floor)((*it2).size())/2); i++)
			cout << " ";
		cout << *it2 << "  ";
		for (int i=0; i < (maxLengthScore - (floor)((*it2).size())/2); i++) 
			cout << " ";
		cout << "|" << endl;
	}
	
	for (int i=0; i < maxLengthName + 8; i++)
		cout << "_";
	for (int i=0; i < maxLengthScore + 8; i++)
		cout << "_";
	cout << endl;

	free(buff);
//	cout << is.str() << endl;
}

void ScoreClient::recuperationTop() {

}
