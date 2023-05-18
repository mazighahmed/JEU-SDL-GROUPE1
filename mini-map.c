#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "mini-map.h"

void init_map(minimap *m)
{ (m -> map) = IMG_Load("minimap.jpg");
  (m-> minijoueur) = IMG_Load("miniplayer.png");
  m->positionmap.x =1280- 397;
  m->positionmap.y =800 - 461;
  m->positionminijoueur.x =1280- 397;
  m->positionminijoueur.y =800 - 461;
}


void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  m->positionminijoueur.x=(posJoueur.x  * redimensionnement/100)+1280- 397;
  m->positionminijoueur.y=(posJoueur.y * redimensionnement/100)+800 - 461;
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
} 







