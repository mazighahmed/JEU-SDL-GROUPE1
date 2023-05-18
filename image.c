#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "image.h"


Image initialiser_image(char path[20], int x, int y)
{	
	SDL_Surface* img=NULL;
	Image image;

	if((img = IMG_Load(path))==NULL)
		printf("ERROR:%s \n", SDL_GetError());
	
	image.img = img;
	image.pos1.x = x;
	image.pos1.y = y;
        
	return image;
} 


void liberer_image(Image image)
{
	SDL_FreeSurface(image.img);
}

void initialiser_logo(logo* anim, char path[20])
{
	int i=0;
	FILE *f;
	char temp[30];
	f = fopen(path, "r");
	if (f != NULL)
	{
		while(fscanf(f, "%s \n", temp) != EOF)
		{
			(*anim).img[i] = IMG_Load(temp);
			if ((*anim).img[i] == NULL)
				printf("Erreur: initialiser_animation()\n");
			else
				{
				printf("%s initialisé \n", temp);
				i++;
				}
		}
		(*anim).current = 0;	
		(*anim).time = 0;
		(*anim).pos.x = 0;
		(*anim).pos.y = 0;

		printf("%d images initialisé\n", i);
	}
	else printf("Erreur d'ouverture fichier \n");
		
	fclose(f);
}

void liberer_logo(logo* anim)
{
	int i;
	for (i=0; i<196; i++)
	{
		SDL_FreeSurface((*anim).img[i]);
	}

}


void afficher_logo(logo* anim, SDL_Surface *screen)
{
	SDL_Delay(1000);
	do
	{
		SDL_BlitSurface((*anim).img[(*anim).current],  NULL, screen,   &anim->pos);
		if((SDL_GetTicks() - (*anim).time) >= 33)
		{
			(*anim).current++;
			(*anim).time = SDL_GetTicks();
		}
		SDL_Flip(screen);
	}
	while((*anim).current<196);
	SDL_Delay(1500);

}

void initialiser_menu(background *bg)
{

	if((bg->img[0] = IMG_Load("menu/0.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[1] = IMG_Load("menu/1.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[2] = IMG_Load("menu/2.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[3] = IMG_Load("menu/3.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[4] = IMG_Load("menu/4.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[5] = IMG_Load("menu/5.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[6] = IMG_Load("menu/6.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[7] = IMG_Load("menu/7.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if((bg->img[8] = IMG_Load("menu/8.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

	strcpy(bg->state, "menu");
	bg->done = 0;
	bg->frame = 0;
	bg->timer = 0;
}

void afficher_bg(background *bg, SDL_Surface *screen)
{
	SDL_BlitSurface(bg->img[bg->frame], NULL, screen, NULL);
	if(SDL_GetTicks() - bg->timer > 500)
	{
		bg->timer = SDL_GetTicks();
		bg->frame ++;
		if (bg->frame > 8)
			bg->frame = 0;
	}

}

void liberer_bg(background bg)
{

	int i;
	for (i=0; i<=8; i++)
		SDL_FreeSurface(bg.img[i]);
}

