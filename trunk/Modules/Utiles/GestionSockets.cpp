#include "GestionSockets.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int GestionSockets::creeSocketEmission (const char *server, int port) {    
	 int sock;
    struct sockaddr_in	address;
    struct hostent *hp;

    if ((sock = socket (AF_INET, SOCK_DGRAM, 0)) == -1)
    {
		throw(new int(-1));
    }

    hp = gethostbyname(server);
    if (hp == 0)
    {
		throw(new int(-1));
    }

    memset (&address, 0, sizeof (address));
    memcpy (&address.sin_addr, hp->h_addr, hp->h_length);
    address.sin_family = AF_INET;
    address.sin_port = htons (port);

    if (connect (sock, (struct sockaddr*) &address, sizeof (struct sockaddr_in)) == -1)
    {
		throw(new int(-1));
    }

    return sock;
}

int GestionSockets::creeSocketReception(int port)
{
    int sock;
    struct sockaddr_in	address;

    if ((sock = socket (PF_INET, SOCK_DGRAM, 0)) == -1)
    {
		throw(new int(-1));
    }

    memset (&address, 0, sizeof (address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons (port);

    if (bind (sock, (struct sockaddr*) &address, sizeof (address)) == -1)
    {
		throw(new int(-1));
    }

    return sock;
}


