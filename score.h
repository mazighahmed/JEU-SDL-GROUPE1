#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct{
int score,temps;
char nom_player[10];
SDL_Rect pos_nom,pos_score,pos_temps;
}scoreinfo;


void incrementer(scoreinfo *s);
void savescore(scoreinfo s,char *filename);
void bestscore(char *filename,scoreinfo trois[], texte txte, SDL_Surface *screen);
