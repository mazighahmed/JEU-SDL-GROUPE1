#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "image.h"
#include "texte.h"
#include "background.h"
#include "collision.h"
#include "player.h"


void initialiser_joueur(Player* joueur, char path[], int x, int y)
{
	joueur->pos.x = x;
	joueur->pos.y = y;
	joueur->pos.h = 128;
	joueur->pos.w = 64;
	joueur->dir = 0;
	joueur->speed = 0.2;
	joueur->acc = 0;
	joueur->vie = 3;
	joueur->score = 0;
	joueur->dx = 0;
	joueur->move = 1;
	strcpy(joueur->name, "");
	
	joueur->saut.state = 0;
	joueur->saut.gravite = 0;
	
	if((joueur->anim.image.img = IMG_Load(path)) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((joueur->shadow.img = IMG_Load("shadow.png")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((joueur->img_vie.img = IMG_Load("vie.png")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

	joueur->img_vie.pos1.x = 163;
	joueur->img_vie.pos1.y = 10;
	joueur->img_vie.pos2.x = 0;
	joueur->img_vie.pos2.y = 0;
	joueur->img_vie.pos2.w = 303;
	joueur->img_vie.pos2.h = 22;

	joueur->anim.image.pos2.w = 64;
	joueur->anim.image.pos2.h = 128;
	joueur->anim.image.pos2.x = 0;
	joueur->anim.image.pos2.y = 0;
	joueur->anim.frame = 0;
	joueur->anim.time = 0;

	joueur->config.key[0] = SDLK_s;
	joueur->config.key[1] = SDLK_z;
	joueur->config.key[2] = SDLK_d;
	joueur->config.key[3] = SDLK_q;

}


void afficher_joueur(Player joueur, SDL_Surface* screen)
{
	SDL_BlitSurface(joueur.shadow.img, NULL, screen,  &joueur.shadow.pos1);	
	SDL_BlitSurface(joueur.anim.image.img,  &joueur.anim.image.pos2, screen,   &joueur.pos);	
}

void afficher_stats(Player joueur, SDL_Surface *screen, texte txte)
{
	char str[20];
	char txt[] = "score ";
	sprintf(str, "%d", joueur.score); 
	strcat(txt, str);
	txte.txt = TTF_RenderText_Blended(txte.police, txt, txte.color);
	SDL_BlitSurface (txte.txt, NULL, screen, &txte.pos);

	joueur.img_vie.pos2.x = 101*(3-joueur.vie);
	SDL_BlitSurface (joueur.img_vie.img, &joueur.img_vie.pos2, screen, &joueur.img_vie.pos1);
}

void animer_joueur(Player* joueur)
{
	if (joueur->dir != -1)
	{
		joueur->anim.image.pos2.y = 128*joueur->dir;
		if((SDL_GetTicks() - joueur->anim.time) >= 100)
			{
				joueur->anim.frame++;
				joueur->anim.image.pos2.x += 64;
				if (joueur->anim.frame >= 8)
				{
					joueur->anim.frame = 0;
					joueur->anim.image.pos2.x = 0;
				}
				joueur->anim.time = SDL_GetTicks();
			}
	}
	else
	{
		joueur->anim.image.pos2.y = 0;
		joueur->anim.image.pos2.x = 0;
		joueur->anim.frame = 0;
	}
}

void move_joueur(Player* joueur, Uint32 dt, Background *BG)
{	
	joueur->acc -= 0.001;
	if (joueur->acc <= 0)
		joueur->acc = 0;
	else if (joueur->acc > 0.1)
		joueur->acc = 0.1;

	joueur->dx = 0.5*(joueur->acc)*(dt*dt)+(joueur->speed)*(dt);
	if (joueur->dir != -1 && joueur->move == 1)
	{	
		if (joueur->dir == 0)//DOWN		
			joueur->pos.y += joueur->dx;
		else if (joueur->dir == 1)//UP
			joueur->pos.y -= joueur->dx;
		else if (joueur->dir == 2)//RIGHT
			joueur->pos.x += joueur->dx;
		else if (joueur->dir == 3)//LEFT
			joueur->pos.x -= joueur->dx;
	}	
}

void saut(Player* joueur, Background *BG)
{
	if(joueur->saut.state == 1)
	{
		joueur->pos.y -= (joueur->saut.dy - joueur->saut.gravite);	
		joueur->saut.gravite += 0.5;
		joueur->shadow.pos1.y = joueur->saut.y0 + 120;
		joueur->pos_abs.y = joueur->shadow.pos1.y + BG->camera_pos.y;
		if (joueur->pos.y >= joueur->saut.y0)
		{
			joueur->saut.state = 0;
			joueur->saut.gravite = 0;
		}
	}
}

void update_pos_abs(SDL_Rect *pos_abs, Player *j, Background *BG)
{
		j->shadow.pos1.x = j->pos.x;
		j->shadow.pos1.y = j->pos.y + 120;
		j->pos_abs.x = j->shadow.pos1.x + BG->camera_pos.x;
		if(j->saut.state == 1)
			j->shadow.pos1.y = j->saut.y0 + 120;
		else
			j->pos_abs.y = j->shadow.pos1.y + BG->camera_pos.y;
	pos_abs->w = j->shadow.img->w;
	pos_abs->h = j->shadow.img->h;
	switch(j->dir)
	{
		case 0:
			pos_abs->y = j->pos_abs.y + j->dx;
			pos_abs->x = j->pos_abs.x;
			break;
		case 1:
			pos_abs->y = j->pos_abs.y - j->dx;
			pos_abs->x = j->pos_abs.x;
			break;
		case 2:
			pos_abs->y = j->pos_abs.y;
			pos_abs->x = j->pos_abs.x + j->dx;
			break;
		case 3:
			pos_abs->y = j->pos_abs.y;
			pos_abs->x = j->pos_abs.x - j->dx;
			break;
	}

}


