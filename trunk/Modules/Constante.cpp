#include "Constante.h"

const char Constante::ADRESSESERVEUR[] = "127.0.0.1";
const char Constante::PATHBESTSCORE[] = "bestScores.xml";

void Constante::setTableColor(SDL_Surface *ecran)
{
	Constante::couleurs[C_NOIR]          = SDL_MapRGB(ecran->format, 0x00, 0x00, 0x00);
  	Constante::couleurs[C_BLEU_FONCE]    = SDL_MapRGB(ecran->format, 0x00, 0x00, 0x80);
  	Constante::couleurs[C_VERT_FONCE]    = SDL_MapRGB(ecran->format, 0x00, 0x80, 0x00);
  	Constante::couleurs[C_CYAN_FONCE]    = SDL_MapRGB(ecran->format, 0x00, 0x80, 0x80);
 	Constante::couleurs[C_ROUGE_FONCE]   = SDL_MapRGB(ecran->format, 0x80, 0x00, 0x00);
  	Constante::couleurs[C_MAGENTA_FONCE] = SDL_MapRGB(ecran->format, 0x80, 0x00, 0x80);
  	Constante::couleurs[C_OCRE]          = SDL_MapRGB(ecran->format, 0x80, 0x80, 0x00);
  	Constante::couleurs[C_GRIS_CLAIR]    = SDL_MapRGB(ecran->format, 0xC0, 0xC0, 0xC0);
  	Constante::couleurs[C_GRIS]          = SDL_MapRGB(ecran->format, 0x80, 0x80, 0x80);
  	Constante::couleurs[C_BLEU]          = SDL_MapRGB(ecran->format, 0x00, 0x00, 0xFF);
  	Constante::couleurs[C_VERT]          = SDL_MapRGB(ecran->format, 0x00, 0xFF, 0x00);
  	Constante::couleurs[C_CYAN]          = SDL_MapRGB(ecran->format, 0x00, 0xFF, 0xFF);
  	Constante::couleurs[C_ROUGE]         = SDL_MapRGB(ecran->format, 0xFF, 0x00, 0x00);
  	Constante::couleurs[C_MAGENTA]       = SDL_MapRGB(ecran->format, 0xFF, 0x00, 0xFF);
  	Constante::couleurs[C_JAUNE]         = SDL_MapRGB(ecran->format, 0xFF, 0xFF, 0x00);
  	Constante::couleurs[C_BLANC]         = SDL_MapRGB(ecran->format, 0xFF, 0xFF, 0xFF);
}
