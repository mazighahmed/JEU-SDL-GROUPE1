typedef struct 
{
SDL_Rect pos;
SDL_Rect camera_pos;
SDL_Surface *img;
SDL_Surface *mask;
int direction;
SDL_Surface *tab[4];
int frame;
}Background;

void initBack(Background *b);
void initBack1(Background *b);
void initBack2(Background *b);
void afficher(Background b,SDL_Surface *screen);
void scrolling(Background *b,int direction,int pas);
void animerBack(Background *b);
void init_bob(Background * b);
