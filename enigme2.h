typedef struct
{
	int etat;
	int repj;
	char qst[14];
	SDL_Surface *image;
	SDL_Rect pos;

}Enigme2;

void genererEnigme2(Enigme2 *e, char nomfichier[], Background BG);
void afficherEnigme2(Enigme2 *e, SDL_Surface *screen);
void input_enigme2(int *choix, Enigme2 e, SDL_Event event);
