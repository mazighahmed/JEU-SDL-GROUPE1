#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "bouton.h"

Bouton initialiser_bouton(Image img1, Image img2)
{
	Bouton b;
	b.image[0]=img1;
	b.image[1]=img2;
	b.actif=0;
	return b;
}

int bouton_motion(SDL_Event event, Bouton bouton[], int type)
{	
	return (  event.motion.y >= bouton[type].image[0].pos1.y && event.motion.y <= (bouton[type].image[0].pos1.y + bouton[type].image[0].pos1.h) &&
	          event.motion.x >= bouton[type].image[0].pos1.x && event.motion.x <= (bouton[type].image[0].pos1.x + bouton[type].image[0].pos1.w)    );

}

void liberer_boutons(Bouton bouton[])
{
	int i, j;
	for (i=0;i<=5;i++)
	{
		for(j=0;j<2;j++)
			SDL_FreeSurface(bouton[i].image[j].img);
	}
	SDL_FreeSurface(bouton[6].image[0].img);
}

