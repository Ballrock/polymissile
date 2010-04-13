#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL.h>
 


int main(int argc, char*argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
 
    	SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
 	
	while(1);
    	SDL_Quit();
 
    	return EXIT_SUCCESS;
}

