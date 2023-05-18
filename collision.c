#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
#include "bouton.h"
#include "menu.h"
#include "texte.h"
#include "background.h"
#include "player.h"
#include <time.h>
#include "robots.h"
#include "enigme.h"
#include "collision.h"




SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y)
{SDL_Color color;
Uint32 col=0;
char *pPosition = (char *) pSurface -> pixels;
pPosition+=(pSurface->pitch *y);
pPosition+=(pSurface ->format->BytesPerPixel *x);
memcpy(&col,pPosition,pSurface ->format ->BytesPerPixel);

SDL_GetRGB(col,pSurface -> format,&color.r ,&color.g ,&color.b);
//printf("%d %d %d",color.r ,color.g ,color.b);
return (color);
}

int collision_parfaite_right(SDL_Surface *mask , SDL_Rect pos_abs,int state)
{  SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;

/*pos[0].x = pos_abs.x + pos_abs.w;
pos[0].y = pos_abs.y;
pos[1].x = pos_abs.x + pos_abs.w;
pos[1].y = pos_abs.y + pos_abs.h/2;*/
pos[2].x = pos_abs.x + pos_abs.w;
pos[2].y = pos_abs.y + pos_abs.h;

colp = GetPixel(mask,pos[2].x ,pos[2].y);
if((0==colp.r) && (0 == colp.g) && (0 ==colp.b) || ((0==colp.r) && (255 == colp.g) && (1 ==colp.b) && state==0) )
collision = 1;
return (collision);
}

int collision_parfaite_left(SDL_Surface *mask, SDL_Rect pos_abs,int state)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;

pos.y = pos_abs.y + pos_abs.h;
pos.x = pos_abs.x;


colp = GetPixel(mask, pos.x ,pos.y);
if( ((0==colp.r) && (0 == colp.g) && (0 ==colp.b)) || ( (0==colp.r) && (255 == colp.g) && (1 ==colp.b) && state==0 ) )
collision = 1;
return (collision);
}


int collision_parfaite_up(SDL_Surface *mask, SDL_Rect pos_abs)
{
SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;

pos[0].x = pos_abs.x;
pos[0].y = pos_abs.y;
pos[1].x = pos_abs.x + pos_abs.w/2;
pos[1].y = pos_abs.y;
pos[2].x = pos_abs.x + pos_abs.w/2;
pos[2].y = pos_abs.y;

for(i=0; i<3; i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((0==colp.r) && (0 == colp.g) && (0 ==colp.b) || (0==colp.r) && (255 == colp.g) && (0 ==colp.b))
collision = 1;
}
return collision;
}

int collision_parfaite_down(SDL_Surface *mask, SDL_Rect pos_abs)
{
SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;

pos[0].x = pos_abs.x;
pos[0].y = pos_abs.y + pos_abs.h;
pos[1].x = pos_abs.x + pos_abs.w/2;
pos[1].y = pos_abs.y + pos_abs.h;
pos[2].x = pos_abs.x + pos_abs.w/2;
pos[2].y = pos_abs.y + pos_abs.h;

for(i=0; i<3; i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((0==colp.r) && (0 == colp.g) && (0 ==colp.b) || (0==colp.r) && (255 == colp.g) && (0 ==colp.b))
collision = 1;
}
return (collision);
}





