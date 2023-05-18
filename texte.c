#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "texte.h"

void initialiser_texte(texte *txte, int x, int y)
{
	txte->police= TTF_OpenFont("ARCADECLASSIC.TTF", 60);
	txte->color.r = 0;
	txte->color.g = 143;
	txte->color.b = 17;

	txte->pos.x = x;
	txte->pos.y = y;
}

void initialiser_score(texte *txte)
{
	txte->police= TTF_OpenFont("ARCADECLASSIC.TTF", 35);
	txte->color.r = 255;
	txte->color.g = 255;
	txte->color.b = 255;

	txte->pos.x = 175;
	txte->pos.y = 49;
}
void initialiser_score2(texte *txte)
{
	txte->police= TTF_OpenFont("ARCADECLASSIC.TTF", 35);
	txte->color.r = 255;
	txte->color.g = 255;
	txte->color.b = 255;

	txte->pos.x = 175+640;
	txte->pos.y = 49;
}
void afficher_texte(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Bienvenue", txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);
}

void afficher_name(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Please enter your name", txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);
}
void afficher_texte1(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Up", txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);
}
void afficher_texte2(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Down", txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);
}
void afficher_texte3(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Right", txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);
}
void afficher_texte4(SDL_Surface *screen, texte txte)
{
	txte.txt = TTF_RenderText_Blended(txte.police, "Left", txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);
}

void liberer_texte(texte txte)
{
	TTF_CloseFont (txte.police);
}
