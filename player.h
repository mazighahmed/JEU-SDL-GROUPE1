typedef struct
{
	int state;
	int x0;
	int y0;
	double gravite;
	int dy;
}
Jump;

typedef struct conf
{
	SDLKey key[6];
}
conf;

typedef struct
{
	animation anim;
	SDL_Rect pos;  	//position x et y relatif au personnage
	int dir;	//direction (0:down 1:up 2:droite 3:gauche -1:aucun mouvement)
	int vie;
	int score;
	double speed;
	double acc;
	char name[20];
	int dx;
	Jump saut;
	int move;
	SDL_Rect pos_abs;
	conf config;

	Image shadow;
	Image img_vie;
}Player;



//INITIALISATION JOUEUR
void initialiser_joueur(Player* joueur, char path[], int x, int y);


//AFFICHAGE
void afficher_joueur(Player joueur, SDL_Surface* screen);
void afficher_stats(Player joueur, SDL_Surface *screen, texte txte);


//UPDATE
void move_joueur(Player* joueur, Uint32 dt, Background *BG);
void animer_joueur(Player* joueur);
void saut(Player* joueur, Background *BG);
void update_pos_abs(SDL_Rect *pos_abs, Player *j, Background *BG);
