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
	TCPsocket sock;
	ostringstream os;
	char *buff = (char *) malloc(sizeof(char)*1024);
	TiXmlDocument *docScore = new TiXmlDocument();

	while(1)
	{
		int numready,i;
		set=SDLNet_AllocSocketSet(1);
		SDLNet_TCP_AddSocket(set, server);
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
			printf("Connection...\n"); 
			sock=SDLNet_TCP_Accept(server);
			if(sock)
			{
				cout << "oksock" << endl;
				if(Communication::lire(sock, &buff))
				{
					os.str("");
					os << buff;	
					cout << os.str() << endl;
					is.str(os.str());
					is >> *docScore;
					ajouteScore(*docScore);
					os.str("");
					os << doc;
					if (!Communication::ecrire(sock, os.str().c_str())) {
						cout << "Erreur d'écriture !" << endl;
					}
				}
				else
					SDLNet_TCP_Close(sock);
			}
		}
	}
	
	free(buff);
}	

void ScoreServeur::ajouteScore(TiXmlNode &score) {
	TiXmlNode *child = NULL;
	int scoreInt, scoreInt2 = 0;
	int i = 0;
   
   ostringstream os;

	/* 
	 * Parcours de tous les enregistrements de score et test du score courant avec le score à insérer, on l'insère lorsqu'on arrive à la bonne position
	 */
	os.str("");
	os << *(score.LastChild()->LastChild()->FirstChild());
	scoreInt = atoi(os.str().c_str());
	if (this->doc.LastChild()->FirstChild()) {
		while( (child = this->doc.LastChild()->IterateChildren( child )) && i < 20 ) {
			os.str("");
			os << *(child->LastChild()->FirstChild());
			scoreInt2 = atoi(os.str().c_str());
			if (scoreInt > scoreInt2) {
				break;
			}
			i++;
		}

	}
	if (i < 20) {
		if (child)
			doc.LastChild()->InsertBeforeChild(child, *(score.LastChild()));	
		else
			doc.LastChild()->InsertEndChild(*(score.LastChild()));
		this->doc.SaveFile();
	}

}

