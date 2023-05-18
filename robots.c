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
#include "robots.h"
#include "collision.h"

void initEnnemi(Ennemi *e, int x, int y)
{ 
    e->url="enemy.png";
    e->img=IMG_Load(e->url);
    if(e->img == NULL)
    {
        printf("unable to load character image %s \n",SDL_GetError());
        return;
    }
        e->pos1.x=0;
        e->pos1.y=0;
        e->pos1.h=64;
        e->pos1.w=64;

        e->pos2.x=x;
        e->pos2.y=y;
        e->pos2.w = 64;
        e->pos2.h = 64;
	
	e->frame =0;
	e->timer =0;
	e->direction =0;
}




void afficherEnnemi(Ennemi e, SDL_Surface  * screen)
{

    SDL_BlitSurface(e.img, &e.pos1 ,screen, &e.pos2);
 
}


void animerEnnemi(Ennemi* e)
{
	e->pos1.y = 64*e->direction;
	if((SDL_GetTicks() - e->timer) >= 100)
	{
		e->frame++;
		e->pos1.x += 64;
		if (e->frame > 5)
		{
			e->frame = 0;
			e->pos1.x = 0;
		}
		e->timer = SDL_GetTicks();
	}
}


void moveEnnemi(Ennemi * e, SDL_Surface *mask)
{

    int xx= 2;
    int yy= 2;
	

        switch (e->direction) {
            case 0: // monter
		e->pos_abs.y -= yy;
		if (!collision_parfaite_up(mask, e->pos_abs))
                	e->pos2.y-= yy;
		else
			e->direction = rand() % 4;
                break;
            case 1: // descendre
		e->pos_abs.y += yy;
		if (!collision_parfaite_down(mask, e->pos_abs))
            		e->pos2.y+= yy;
		else 
			e->direction = rand() % 4;
                break;
            case 2: // droite
		e->pos_abs.x += xx;
		if (!collision_parfaite_right(mask, e->pos_abs, 0))
               		e->pos2.x += xx;
		else
			e->direction = rand() % 4;
                break;
            case 3: // gauche
		e->pos_abs.x -= xx;
		if (!collision_parfaite_left(mask, e->pos_abs, 0))
               		e->pos2.x -= xx;
		else
			e->direction = rand() % 4;
                break;   
        }

	static Uint32 timer = 0;
	if ( (SDL_GetTicks() - timer) >= 2000)
        {
            timer = SDL_GetTicks();
            e->direction = rand() % 4;
        }
}




int collisionBB(SDL_Rect posp,  SDL_Rect pose) 
{
	if(posp.x > pose.x + pose.w || posp.x + posp.w < pose.x || posp.y > pose.y + pose.h || posp.y + posp.h < pose.y)
		return 0;
	else
		return 1;
}

void scroll_e(Background BG, Ennemi *e, int dx)
{
	if (BG.direction != -1)
	{
		switch(BG.direction){
			case 0:
				e->pos2.y -= dx;
				break;
			case 1 :
				e->pos2.y += dx;
				break;
			case 2: 
				e->pos2.x -= dx;
				break;
			case 3:
				e->pos2.x += dx;
				break;
		}
	}
}

     








