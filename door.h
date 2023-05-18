#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{
SDL_Rect pos;
SDL_Surface *img;
int state;
}touche;

typedef struct
{
SDL_Rect pos;
SDL_Surface *img;
int state;
}key;

typedef struct
{
SDL_Rect pos;
SDL_Surface *img;
key k;
touche t;
int state;
}beb;

void init_door(beb *b,int x,int y,char url[],int z,int v);
void afficher_beb(beb b,SDL_Surface *screen);
void scroll_biben(Background BG, beb *b, int dx);
void init_key(key *k,int x,int y);
int collision_door_up(SDL_Surface *mask, SDL_Rect pos_abs,beb d);
int collision_door3_up(SDL_Surface *mask, SDL_Rect pos_abs,beb d);
int collision_door_down(SDL_Surface *mask, SDL_Rect pos_abs,beb b);
