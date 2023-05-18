#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "texte.h"
#include "image.h"
#include "background.h"
#include "player.h"
#include "enigme.h"
#include "sousmenu.h"

Menu init_SousMenu()
{
    Menu sous_menu;
    sous_menu.image_bg = IMG_Load("forest.jpg");
    sous_menu.pos_bg.x = 0;
    sous_menu.pos_bg.y = 0;

    sous_menu.nbr_boutton = 3;

//bouton 1
    sous_menu.tab[0].Img[0] = IMG_Load("resume0.png");
    sous_menu.tab[0].Img[1] =IMG_Load("resume1.png");
    sous_menu.tab[0].Pos.x =  SCREEN_W/3+75;
    sous_menu.tab[0].Pos.y = SCREEN_H/3 - 30;

    sous_menu.tab[0].num = 0;
//bouton 2
    sous_menu.tab[1].Img[0] = IMG_Load("save0.png");
    sous_menu.tab[1].Img[1] =     IMG_Load("save1.png");
    sous_menu.tab[1].Pos.x = SCREEN_W/3+75;
    sous_menu.tab[1].Pos.y = SCREEN_H/3 + 75;
    sous_menu.tab[1].num = 1;

    sous_menu.tab[2].Img[0] = IMG_Load("boutons/load0.png");
    sous_menu.tab[2].Img[1] = IMG_Load("boutons/load1.png");
    sous_menu.tab[2].Pos.x = SCREEN_W/3+150;
    sous_menu.tab[2].Pos.y = SCREEN_H/3 + 250;
    sous_menu.tab[2].num = 2;

    return sous_menu;
}
//son bref
/*
void initialiser_audiobref(Mix_Chunk *music)
{
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
music=Mix_LoadWAV("motion.wav");
Mix_PlayChannel(-1,music,0);
if(music==NULL)
printf("%s",SDL_GetError());
}
//son continue
void initialiser_son(Mix_Music *son)
{
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
Mix_PlayChannel(-1,son,0);
son=Mix_LoadMUS("bob.mp3");
if(son==NULL)
printf("%s",SDL_GetError());
}
*/

void afficher_sousmenu(Menu sous_menu,SDL_Surface *ecran)
{ 
int i;
Mix_Music *son;
SDL_BlitSurface(sous_menu.image_bg, NULL, ecran, &sous_menu.pos_bg);
for( i=0; i < sous_menu.nbr_boutton; i++)
    {
        if(sous_menu.tab[i].num == sous_menu.num_bt_actif)
        {
            SDL_BlitSurface(sous_menu.tab[i].Img[1], NULL, ecran, &sous_menu.tab[i].Pos);
        }
        else
        {
            SDL_BlitSurface(sous_menu.tab[i].Img[0], NULL, ecran, &sous_menu.tab[i].Pos);
        }
    }
}


int update_SousMenu(Menu *sous_menu, SDL_Event input, int *interface) {
Mix_Music *music;
    int lancer_sauvegarde = 0; 
    if (input.type == SDL_KEYDOWN) {
        if (input.key.keysym.sym == SDLK_UP) {
            sous_menu->num_bt_actif--;
            if (sous_menu->num_bt_actif <= 0) {
                sous_menu->num_bt_actif = 0;
            }
           
        }
        else if (input.key.keysym.sym == SDLK_DOWN) {
            sous_menu->num_bt_actif++;
            if (sous_menu->num_bt_actif >= 2) {
                sous_menu->num_bt_actif = 2; 
        }
            
        }
        else if (input.key.keysym.sym == SDLK_RETURN) {
            *interface = sous_menu->tab[sous_menu->num_bt_actif].num;
            if (*interface == 0) {
                lancer_sauvegarde = 1;
            }
        }
    }
   
 return lancer_sauvegarde;
 }
 

void liberer_SousMenu(Menu* sous_menu) 
{
    int i;
     for (i = 0; i < sous_menu->nbr_boutton; i++) 
        {
        SDL_FreeSurface(sous_menu->tab[i].Img[0]);
        SDL_FreeSurface(sous_menu->tab[i].Img[1]);
        sous_menu->tab[i].Img[0] = NULL;
        sous_menu->tab[i].Img[1] = NULL;
        }

     SDL_FreeSurface(sous_menu->image_bg);
     sous_menu->image_bg = NULL;
}
//son bref
void liberer_musiquebref(Mix_Chunk *music)
{
Mix_FreeChunk(music);
}
//son continue
void liberer_musique(Mix_Music *son)
{
Mix_FreeMusic(son);
}
