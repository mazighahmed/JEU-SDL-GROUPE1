#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "texte.h"
#include "score.h"
#include "background.h"
#include "image.h"
#include "enigme2.h"
#include <time.h>

void genererEnigme2(Enigme2 *e, char nomfichier[], Background BG)
{
	int alea;
	FILE *f;
	int i;

	srand(time(NULL));
	alea = rand() % 4; //de 0 a 3	
	f = fopen(nomfichier, "r");
	if (f != NULL)
	{	
		i = 0;
		while(fscanf(f, "%s %d \n", e->qst, &e->repj) != EOF && i<alea)
		{
			i++;
		}
		if( (e->image = IMG_Load(e->qst)) == NULL)
			printf("ERROR:%s \n", SDL_GetError());	
	}
	else printf("Erreur d'ouverture fichier \n");
	e->pos.x = BG.camera_pos.w/2 - 300;
	e->pos.y = BG.camera_pos.h/2 - 300;
	e->etat = 0;	
	fclose(f);


}

void afficherEnigme2(Enigme2 *e, SDL_Surface *screen)
{
	SDL_BlitSurface(e->image, NULL, screen, &e->pos);
}

void input_enigme2(int *choix, Enigme2 e, SDL_Event event)
{
        if (e.etat == 0)
        {
            if (event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    if (event.motion.y >= 300 + e.pos.y && event.motion.y <= (300 + 75) + e.pos.y && event.motion.x >= 50 && event.motion.x <= (50 + 400)+ e.pos.x)
                    {
                        *choix = 1;
                    }
                    if (event.motion.y >= 400+ e.pos.y && event.motion.y <= (400 + 75) + e.pos.y && event.motion.x >= 50 && event.motion.x <= (50 + 400)+ e.pos.x)
                    {
                        *choix = 2;
                    }
                    if (event.motion.y >= 500+ e.pos.y && event.motion.y <= (500 + 75) + e.pos.y && event.motion.x >= 50 && event.motion.x <= (50 + 400)+ e.pos.x)
                    {
                        *choix = 3;
                    }
                }
            }
        }
}




