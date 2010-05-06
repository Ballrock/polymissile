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
	IPaddress ip;
	TCPsocket sock;
	SDLNet_SocketSet set;
	char *message=NULL;
	const char *host=NULL;
	Uint32 ipaddr;
	Uint16 port;

	if(SDLNet_Init()==-1)
	{
		printf("SDLNet_Init: %s\n",SDLNet_GetError());
		exit(2);
	}

	/* get the port from the commandline */
	port=(Uint16)Constante::PORT;

	/* Resolve the argument into an IPaddress type */
	if(SDLNet_ResolveHost(&ip,NULL,port)==-1)
	{
		printf("SDLNet_ResolveHost: %s\n",SDLNet_GetError());
		SDLNet_Quit();
		exit(3);
	}

	/* perform a byte endianess correction for the next printf */
	ipaddr=SDL_SwapBE32(ip.host);

	/* output the IP address nicely */
	printf("IP Address : %d.%d.%d.%d\n",
			ipaddr>>24,
			(ipaddr>>16)&0xff,
			(ipaddr>>8)&0xff,
			ipaddr&0xff);

	/* resolve the hostname for the IPaddress */
	host=SDLNet_ResolveIP(&ip);

	/* print out the hostname we got */
	if(host)
		printf("Hostname   : %s\n",host);
	else
		printf("Hostname   : N/A\n");

	/* output the port number */
	printf("Port       : %d\n",port);

	/* open the server socket */
	server=SDLNet_TCP_Open(&ip);
	if(!server)
	{
		printf("SDLNet_TCP_Open: %s\n",SDLNet_GetError());
		SDLNet_Quit();
		exit(4);
	}
	return 0;
}


ScoreServeur::~ScoreServeur() {
	SDLNet_TCP_Close(this->server);
	SDLNet_Quit();
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
	SDLNet_SocketSet set;
	TCPSocket sock;
	ostringstream os = ostringstream("");
	char *buff;
	TiXmlDocument *docScore = new TiXmlDocument();

	while(1)
	{
		int numready,i;
		set=create_sockset();
		numready=SDLNet_CheckSockets(set, (Uint32)-1);
		if(numready==-1)
		{
			printf("SDLNet_CheckSockets: %s\n",SDLNet_GetError());
			break;
		}
		if(!numready)
			continue;
		if(SDLNet_SocketReady(server))
		{
			numready--;
			/*printf("Connection...\n"); */
			sock=SDLNet_TCP_Accept(server);
			if(sock)
			{
				if(lire(sock, &buff))
				{
					os << buff;	
					cout << os << endl;
					is << os;
					is >> *docScore;
					ajouteScore(*docScore);
					os.str("");
					os << *docScore;
					if (!ecrire(sock, os.str().c_str())) {
						cout << "Erreur d'écriture !" << endl;
					}
				}
				else
					SDLNet_TCP_Close(sock);
			}
		}
	
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

