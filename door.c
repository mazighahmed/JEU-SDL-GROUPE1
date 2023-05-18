#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include "background.h"
#include "image.h"
#include "door.h"
#include "robots.h"
#include "collision.h"




void init_door(beb *b,int x,int y,char url[],int z,int v)
{
	b->img=IMG_Load(url);
	b->pos.x=0;
	b->pos.y=-1000;
	b->state=0;
	
	b->k.img=IMG_Load("key.png");
	b->k.pos.x=x;
	b->k.pos.y=y;
	b->k.pos.w=30;
	b->k.pos.h=32;
	b->k.state=0;

	b->t.img=IMG_Load("E.png");
	b->t.pos.x=z;
	b->t.pos.y=v;
	b->t.pos.w=30;
	b->t.pos.h=32;
	b->t.state=1;

	
	
}



void afficher_beb(beb b,SDL_Surface *screen)	
{
	if (b.k.state==0)
	{SDL_BlitSurface(b.k.img,NULL,screen,&b.k.pos);}
	if (b.state==0)
	SDL_BlitSurface(b.img,NULL,screen,&b.pos);
	if (b.t.state==0)
	SDL_BlitSurface(b.t.img,NULL,screen,&b.t.pos);
	
}

void scroll_biben(Background BG, beb *b, int dx)
{
	if (BG.direction != -1)
	{
		switch(BG.direction){
			case 0:
				b->pos.y -= dx;
				b->k.pos.y-= dx;
				b->t.pos.y-= dx;
				break;
			case 1 :
				b->pos.y += dx;
				b->k.pos.y+= dx;
				b->t.pos.y+= dx;
				break;
			case 2: 
				b->pos.x -= dx;
				b->k.pos.x-= dx;
				b->t.pos.x-= dx;
				break;
			case 3:
				b->pos.x += dx;
				b->k.pos.x+= dx;
				b->t.pos.x+= dx;
				break;
		}
	}
}


int collision_door_up(SDL_Surface *mask, SDL_Rect pos_abs,beb d)
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
if((254==colp.r) && (0 == colp.g) && (0 ==colp.b) && (d.state==0))
collision = 1;
else
collision=0;
}
return collision;
}

int collision_door3_up(SDL_Surface *mask, SDL_Rect pos_abs,beb d)
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
if((255==colp.r) && (255 == colp.g) && (1 ==colp.b) && (d.state==0))
collision = 1;
else
collision=0;
}
return collision;
}


int collision_door_down(SDL_Surface *mask, SDL_Rect pos_abs,beb b)
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
if((0==colp.r) && (0 == colp.g) && (254 ==colp.b) && (b.state==0))
collision = 1;
}
return (collision);
}

