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
#include "player.h"
#include "enigme.h"

void initialiser_txt(text *txte)
{
	txte->police= TTF_OpenFont("ARCADECLASSIC.TTF", 30);
	txte->color.r = 0;
	txte->color.g = 147;
	txte->color.b = 17;
}

void genererEnigme(Enigme *e, char nomfichier[], Background BG)
{
	int alea;
	FILE *f;
	int i;

	srand(time(NULL));
	alea = rand() % 4;
	f = fopen(nomfichier, "r");
	if (f != NULL)
	{	
		i = 0;
		while(fscanf(f, "%s %s %s %s %d \n", e->qst, e->rep1, e->rep2, e->rep3, &e->repj) != EOF && i<alea)
		{
			i++;
		}	
	}
	else printf("Erreur d'ouverture fichier \n");
	
	fclose(f);
	
	e->bg = IMG_Load("enigme.jpg");
	e->etat = 0;
	e->pos.x = BG.camera_pos.w/2 - 300;
	e->pos.y = BG.camera_pos.h/2 - 300;
	e->pos_rep1.x = e->pos.x + 50;
	e->pos_rep2.x =  e->pos.x + 50;
	e->pos_rep3.x =  e->pos.x + 50;
	e->pos_qst.x =  e->pos.x + 200;

	e->pos_qst.y =  e->pos.y + 150;
	e->pos_rep1.y = e->pos.y + 300;
	e->pos_rep2.y = e->pos.y + 400;
	e->pos_rep3.y = e->pos.y + 500;

	initialiser_txt(&(e->txte));
	
}

void afficherEnigme(Enigme *e, SDL_Surface *screen)
{
	SDL_BlitSurface(e->bg, NULL, screen, &e->pos);

	e->txte.txt = TTF_RenderText_Blended(e->txte.police, e->qst, e->txte.color);  
	SDL_BlitSurface (e->txte.txt, NULL, screen, &e->pos_qst);

	e->txte.txt = TTF_RenderText_Blended(e->txte.police, e->rep1, e->txte.color);
	SDL_BlitSurface (e->txte.txt, NULL, screen, &e->pos_rep1);

	e->txte.txt = TTF_RenderText_Blended(e->txte.police, e->rep2, e->txte.color);
	SDL_BlitSurface (e->txte.txt, NULL, screen, &e->pos_rep2);

	e->txte.txt = TTF_RenderText_Blended(e->txte.police, e->rep3, e->txte.color);
	SDL_BlitSurface (e->txte.txt, NULL, screen, &e->pos_rep3);
}


void sauvegarder (Player p, Background b, char *nomfichier)
{
   FILE* f = fopen(nomfichier, "w");
    if (f != NULL) 
      {

    fprintf(f, "person\n");
    fprintf(f, "%f\n", p.speed);
    fprintf(f, "%d\n", p.vie);
    fprintf(f, "%d %d %d %d\n", p.pos.x, p.pos.y, p.pos.w, p.pos.h);

    fprintf(f, "background\n");
    fprintf(f,"%d %d\n",b.camera_pos.x,b.camera_pos.y);
    fprintf(f, "%d\n", b.frame);
    fclose(f);
	}
	else
		printf("Erreur lors de l'ouverture du fichier %s\n", nomfichier);

}
void charger ( Player * p, Background *b , char * nomfichier)
{

	FILE* f = fopen(nomfichier, "r");
	    if (f != NULL) 
	      {
		printf("Erreur lors de l'ouverture du fichier %s\n", nomfichier);

	    fscanf(f, "person\n");
	    fscanf(f, "%lf\n", &p->speed);
	    fscanf(f, "%d\n", &p->vie);
	    fscanf(f, "%hd %hd \n", &p->pos.x, &p->pos.y);
	    fscanf(f, "%d\n", &p->score);

	    fscanf(f, "background\n");
	    fscanf(f,"%hd %hd\n",&b->pos.x,&b->pos.y);
	    fscanf(f,"%hd %hd\n",&b->camera_pos.x,&b->camera_pos.y);
	    fscanf(f, "%d\n", &b->frame);
	    fclose(f);
		}
		else
			printf("Erreur lors de l'ouverture du fichier %s\n", nomfichier);

}

void input_enigme(int *choix, Enigme e, SDL_Event event)
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






