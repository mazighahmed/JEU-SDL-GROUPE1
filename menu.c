


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "bouton.h"
#include "menu.h"


void afficher_menu(Bouton bouton[], SDL_Surface *screen)
{
	SDL_BlitSurface(bouton[0].image[bouton[0].actif].img, NULL, screen, &bouton[0].image[bouton[0].actif].pos1);//PLAY
	SDL_BlitSurface(bouton[1].image[bouton[1].actif].img, NULL, screen, &bouton[1].image[bouton[1].actif].pos1);//OPTIONS
	SDL_BlitSurface(bouton[2].image[bouton[2].actif].img, NULL, screen, &bouton[2].image[bouton[2].actif].pos1);//EXIT
}


void afficher_options(Bouton bouton[], SDL_Surface *screen)
{
	SDL_BlitSurface(bouton[3].image[bouton[3].actif].img, NULL, screen, &bouton[3].image[bouton[3].actif].pos1);//BACK
	SDL_BlitSurface(bouton[4].image[bouton[4].actif].img, NULL, screen, &bouton[4].image[bouton[4].actif].pos1);//MUSIC
	SDL_BlitSurface(bouton[5].image[bouton[5].actif].img, NULL, screen, &bouton[5].image[bouton[5].actif].pos1);//FS
	SDL_BlitSurface(bouton[6].image[0].img, NULL, screen, &bouton[6].image[0].pos1);//SCROLL
	SDL_BlitSurface(bouton[7].image[bouton[7].actif].img, NULL, screen, &bouton[7].image[bouton[7].actif].pos1);//REGLAGE

}

void input_select(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son)
{
if (event.type==SDL_MOUSEBUTTONDOWN)
	{
	// CLICK GAUCHE SOURIS
		if(event.button.button==SDL_BUTTON_LEFT)
		{
			if(bouton_motion(event, bouton, 13))
			{	strcpy(input, "one");
			
			}
			else if(bouton_motion(event, bouton, 14))
			{strcpy(input, "two");
		
			}

		}
	}
	if (event.type==SDL_MOUSEMOTION)
	{	
		if(bouton_motion(event, bouton, 13)) 
		{	
			if (!bouton[13].actif)
				Mix_PlayChannel(-1, son, 0);
			bouton[13].actif = 1;
		}
		else if(bouton_motion(event, bouton, 14))
		{	
			if (!bouton[14].actif)
				Mix_PlayChannel(-1, son, 0);
			bouton[14].actif = 1;
		}
		else
		{
			bouton[14].actif = 0;
			bouton[13].actif = 0;

		}
	}
}

void input_name(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son)
{
if (event.type==SDL_MOUSEBUTTONDOWN)
	{
	// CLICK GAUCHE SOURIS
		if(event.button.button==SDL_BUTTON_LEFT)
		{
			if(bouton_motion(event, bouton, 15))
			{	strcpy(input, "confirm");
			
			}

		}
	}
	if (event.type==SDL_MOUSEMOTION)
	{	
		if(bouton_motion(event, bouton, 15)) 
		{	
			if (!bouton[15].actif)
				Mix_PlayChannel(-1, son, 0);
			bouton[15].actif = 1;
		}
		else
		{
			bouton[15].actif = 0;

		}
	}
}
void input_menu(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son)
{

	if (event.type==SDL_MOUSEBUTTONDOWN)
	{
	// CLICK GAUCHE SOURIS
		if(event.button.button==SDL_BUTTON_LEFT)
		{
		//EXIT
			if(bouton_motion(event, bouton, 2))
			{	
				strcpy(input, "quitter");
			}
		//OPTIONS
			else if(bouton_motion(event, bouton, 1))
			{
				strcpy(input, "options");
			}
		//PLAY
			else if(bouton_motion(event, bouton, 0))
			{
				strcpy(input, "play");
			}
		}
	}
	if (event.type==SDL_MOUSEMOTION)
	{
		//EXIT	
		if(bouton_motion(event, bouton, 2)) 
		{	
			if (!bouton[2].actif)
				Mix_PlayChannel(-1, son, 0);
			bouton[2].actif = 1;
		}
		//OPTIONS
		else if(bouton_motion(event, bouton, 1))
		{	
			if (!bouton[1].actif)
				Mix_PlayChannel(-1, son, 0);
			bouton[1].actif = 1;
		}
		// PLAY
		else if(bouton_motion(event, bouton, 0)) 
		{
			if (!bouton[0].actif)
				Mix_PlayChannel(-1, son, 0);
			bouton[0].actif = 1;
		}
		else
		{
			bouton[0].actif = 0;
			bouton[1].actif = 0;
			bouton[2].actif = 0;
		}	
	}
}
			
void input_options(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son)
{
	if (event.type==SDL_MOUSEBUTTONDOWN)
	{
	// CLICK GAUCHE SOURIS
		if(event.button.button==SDL_BUTTON_LEFT)
		{
		//BACK
			if(bouton_motion(event, bouton, 3))
			{
				strcpy(input, "menu");
			}
		//MUSIC 
			if(bouton_motion(event, bouton, 4))
			{
				strcpy(input, "music");
			}
		//FS
			if(bouton_motion(event, bouton, 5))
			{
				strcpy(input, "fullscreen");
			}
		//reglage
			if (bouton_motion(event, bouton, 7))
			{
				strcpy(input, "reglage");	
			}
		}
	}
	if (event.type==SDL_MOUSEMOTION)
	{	
	//BACK
		if(bouton_motion(event, bouton, 3)) 
		{
	
			bouton[3].actif = 1;
		}
	//SCROLLER
		else if (bouton_motion(event, bouton, 6) && (event.motion.state))
		{
			bouton[6].image[0].pos1.x = event.motion.x - 18;	
		}
	//reglage
		else if (bouton_motion(event, bouton, 7))
		{
			bouton[7].actif = 1;	
		}

		else
		{
			bouton[3].actif = 0;
			bouton[7].actif = 0;
		}
	}
}

void input_reglage(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son)
{
	if (event.type==SDL_MOUSEBUTTONDOWN)
	{
	
		if(event.button.button==SDL_BUTTON_LEFT)
		{
		
			if(bouton_motion(event, bouton, 8))
			{
				Mix_PlayChannel(-1, son, 0);
				
			}
		
			if(bouton_motion(event, bouton, 9))
			{
				Mix_PlayChannel(-1, son, 0);
				
			}
		
			if(bouton_motion(event, bouton, 10))
			{
				Mix_PlayChannel(-1, son, 0);
				
			}
		
			if (bouton_motion(event, bouton, 11))
			{
				Mix_PlayChannel(-1, son, 0);
				
			}
			if (bouton_motion(event, bouton, 12))
			{
				Mix_PlayChannel(-1, son, 0);
			}
			
		}
	}
	if (event.type==SDL_MOUSEMOTION)
	{	
	
		if(bouton_motion(event, bouton, 8)) 
		{
	
			bouton[8].actif = 1;
		}
	
		else if (bouton_motion(event, bouton, 9)) 
		{
			bouton[9].actif = 1;
			
		}
	
		else if (bouton_motion(event, bouton, 10))
		{
			bouton[10].actif = 1;	
		}
		else if (bouton_motion(event, bouton, 11))
		{
			bouton[11].actif = 1;	
		}
		else if (bouton_motion(event, bouton, 12))
		{
			bouton[12].actif = 1;	
		}


		else
		{
			bouton[8].actif = 0;
			bouton[9].actif = 0;
			bouton[10].actif = 0;
			bouton[11].actif = 0;
			bouton[12].actif = 0;	

		}
	}
}



void input_play()
{
	printf("hello \n");
}

int slct=-1;
int i;

void input_clavier(char input[], SDL_Event event, Bouton bouton	[], Mix_Chunk* son)
{
	if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE)
    		strcpy(input, "quitter");
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_o)
	    	strcpy(input, "options");
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_p)
	    	strcpy(input, "play");
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_m)
	    	strcpy(input, "menu");
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_i)
	    	strcpy(input, "fullscreen");
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_KP_PLUS)
	    	bouton[6].image[0].pos1.x += 55;
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_KP_MINUS)
	    	bouton[6].image[0].pos1.x -= 55;
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_DOWN)
	    	{
			Mix_PlayChannel(-1, son, 0);
			for(i=0;i<3;i++)
				bouton[i].actif = 0;
			slct++;
			if(slct>2)
				slct = 0;
			bouton[slct].actif = 1;
		}
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_UP)
	    	{
			Mix_PlayChannel(-1, son, 0);
			for(i=0;i<3;i++)
				bouton[i].actif = 0;
			slct--;
			if(slct<0)
				slct = 2;
			bouton[slct].actif = 1;	
		}
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN)
	{
		for(i=0;i<3 && !bouton[i].actif;i++);
		switch (i)
		{
		case 0:
			strcpy(input, "play");
			break;
		case 1:
			strcpy(input, "options");
			break;
		case 2:
			strcpy(input, "quitter");
			break;
		}
	}
}



void update_menu(char input[], Bouton bouton[], background* backg, Mix_Chunk* son, Mix_Music* music, SDL_Event event, SDL_Surface *screen)
{
	if (!strcmp(input, "quitter"))
		{
			Mix_PlayChannel(-1, son, 0);
			SDL_Delay(500);
			backg->done = 1;
		}
	if (!strcmp(input, "fullscreen"))
		{
			if (bouton[5].actif)
				bouton[5].actif = 0;
			else
				bouton[5].actif = 1;
			Mix_PlayChannel(-1, son, 0);
			//SDL_WM_ToggleFullScreen(screen);
		}
	if (!strcmp(backg->state, "menu")) //MAIN MENU INPUT
	{
		if (!strcmp(input, "options"))
		{
			Mix_PlayChannel(-1, son, 0);
			strcpy(backg->state, "options");
		}
		if (!strcmp(input, "play"))
		{
			Mix_PlayChannel(-1, son, 0);
			strcpy(backg->state, "select");
		}
	}
	if (!strcmp(backg->state, "options")) //OPTIONS INPUT
	{
		if (!strcmp(input, "menu"))
		{
			Mix_PlayChannel(-1, son, 0);
			strcpy(backg->state, "menu");
		}

		if (!strcmp(input, "music"))
		{
			if (bouton[4].actif)
				bouton[4].actif = 0;
			else
				bouton[4].actif = 1;
			Mix_PlayChannel(-1, son, 0);

		}
		if (!strcmp(input, "reglage"))
		{
			strcpy(backg->state, "reglage");
				if (bouton[8].actif)
					bouton[8].actif = 0;
				else
					bouton[8].actif = 1;
                                        Mix_PlayChannel(-1, son, 0);

		}

		if (bouton[6].image[0].pos1.x < 473)   // SCROLL
			bouton[6].image[0].pos1.x = 473;
		else if (bouton[6].image[0].pos1.x > 473 + 300)
			bouton[6].image[0].pos1.x = 473 + 300;

		if (Mix_PlayingMusic())
		{
			Mix_VolumeMusic( ((bouton[6].image[0].pos1.x-773)*MIX_MAX_VOLUME) / 300);
		}
	}
	if (!strcmp(backg->state, "play")) //MAIN MENU INPUT
	{
		if (!strcmp(input, "options"))
		{
			Mix_PlayChannel(-1, son, 0);
			strcpy(backg->state, "options");
		}
	}
}
