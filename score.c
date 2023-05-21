
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include "texte.h"
#include "image.h"
#include "background.h"
#include <SDL/SDL_mixer.h>
#include "score.h"

void incrementer(scoreinfo *s)
{

static Uint32 timer = 0;
if ( (SDL_GetTicks() - timer) >= 1000)
        {
            timer = SDL_GetTicks();
            s->score += 10;
	    s->temps += 1;
	    printf("%d %d\n",s->score, s->temps);
        }
}

void savescore(scoreinfo s,char *filename)
{
	FILE *f=fopen(filename,"a+");
	fprintf(f,"%d %d %s\n",s.score,s.temps/1000, s.nom_player);
	fclose(f);
}

void bestscore(char *filename, scoreinfo trois[], texte txte, SDL_Surface *screen)
{
FILE *f=fopen(filename,"r");
int i=0,j,b,max;
scoreinfo temp;
char ch[30];
while (fscanf(f,"%d %d %s",&trois[i].score, &trois[i].temps, trois[i].nom_player)!=EOF)
	{i++;}

	 for (j=0; j<i-1; j++)
	    {
		max=j ;
		for (b=j+1; b<i; b++)
		{
		    if (trois[b].score>trois[max].score)
		        max=b;
		}
		temp=trois[j];
		trois[j]=trois[max];
		trois[max]=temp;
	    }
	j=0;	
	while(j<3)
		{
				trois[j].pos_score.x = 100;
				trois[j].pos_score.y = SCREEN_H/3 + j * 150;
				char str[20];
				char str2[20];
				sprintf(str, "SCORE %d ", trois[j].score); 
				sprintf(str2, "PLAYTIME %dsec NAME ", trois[j].temps); 
				strcat(str, str2); 
				strcat(str, trois[j].nom_player);
				txte.txt = TTF_RenderText_Blended(txte.police, str, txte.color);
				SDL_BlitSurface (txte.txt, NULL, screen, &trois[j].pos_score);
				j++;
		}

}
