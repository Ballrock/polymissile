#ifndef _COMMUNICATION
#define _COMMUNICATION

#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

class Communication {
	
public:

	static char* lire(TCPsocket, char **);
	static int ecrire(TCPsocket, char *);

};


#endif
