typedef struct
{
    char *url;
    SDL_Rect pos1;//partie de l'image qui doit etre affichée
    SDL_Rect pos2; //position de l'image par rapport l'ecran
    SDL_Rect pos_abs;
    SDL_Surface *img;
	int frame;
	int timer;
	int direction;
}Ennemi;


void initEnnemi(Ennemi *e, int x, int y);
void afficherEnnemi(Ennemi e, SDL_Surface  * screen);
void animerEnnemi(Ennemi * e);
void moveEnnemi(Ennemi * e, SDL_Surface *mask);
int collisionBB(SDL_Rect posp,  SDL_Rect pose) ;
void moveIA( Ennemi * e);

void scroll_e(Background BG, Ennemi *e, int dx);


