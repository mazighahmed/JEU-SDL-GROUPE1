#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include "background.h"
#include "image.h"


void initBack(Background * b)
{
    b->img=IMG_Load("level.png");
    if(b->img==NULL)
        printf("error5");
	if((b->mask = IMG_Load("masque.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

    b->pos.x=0;
    b->pos.y=0;

    b->camera_pos.x=0;
    b->camera_pos.y=1000;
    b->camera_pos.w=1280;
    b->camera_pos.h=800;

    b->tab[0]=IMG_Load("ord/ord1.png");
    b->tab[1]=IMG_Load("ord/ord2.png");
    b->tab[2]=IMG_Load("ord/ord3.png");
    //b->tab[3]=IMG_Load("chojra/4.png");
//if((b->tab[2] = IMG_Load("masque.jpg")) == NULL)
		//printf("ERROR:%s \n", SDL_GetError());


    b->frame=0;
}

void init_bob(Background * b)
{
b->img=IMG_Load("bob.png");
    if(b->img==NULL)
        printf("error5");
	if((b->mask = IMG_Load("masque.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

    b->pos.x=0;
    b->pos.y=0;

    b->camera_pos.x=0;
    b->camera_pos.y=1000;
    b->camera_pos.w=b->img->w;
    b->camera_pos.h=b->img->h;
}

void initBack1(Background * b)
{
    b->img=IMG_Load("level.png");
    if(b->img==NULL)
        printf("error5");
	if((b->mask = IMG_Load("masque.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

    b->pos.x=0;
    b->pos.y=0;

    b->camera_pos.x=0;
    b->camera_pos.y=0;
    b->camera_pos.w=640;
    b->camera_pos.h=800;
}

void initBack2(Background * b)
{
    b->img=IMG_Load("level.png");
    if(b->img==NULL)
        printf("error5");
	if((b->mask = IMG_Load("masque2.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

    b->pos.x=SCREEN_W/2;
    b->pos.y=0;

    b->camera_pos.x=0;
    b->camera_pos.y=0;
    b->camera_pos.w=640;
    b->camera_pos.h=800;

}
void afficher(Background b,SDL_Surface *screen)
{
   	//SDL_BlitSurface(b.mask, &b.camera_pos, screen, &b.pos);

   	SDL_BlitSurface(b.img, &b.camera_pos, screen, &b.pos);
	//SDL_BlitSurface(b.tab[b.frame],&b.camera_pos,screen,&b.pos);

}

void scrolling(Background *b,int direction,int pas)
{
    if (direction==0)
        b->camera_pos.y += pas;
    if (direction==1)
        b->camera_pos.y -= pas;
    if (direction==2)
        b->camera_pos.x +=pas;
    if (direction==3)
        b->camera_pos.x -=pas;
}
void animerBack(Background *b)
{
	
	
	static Uint32 last_frame_time = 0;
        if (SDL_GetTicks() - last_frame_time > 500) {
            b->frame = (b->frame +1)  ;
		if (b->frame ==3)
			b->frame=0;
		
           last_frame_time = SDL_GetTicks();}


}
