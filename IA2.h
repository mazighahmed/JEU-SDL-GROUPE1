
typedef struct 
{
int matrice_suivi[9],whoplay,whowin,nbr,compteur;
SDL_Surface* x[9],*o[9],*win,*back,*failed;
SDL_Rect pos[9],pos_back;
}tic;
void init_IA2(tic *ti);
void afficher_tic(tic ti,SDL_Surface* ecran);
void afficher_j(tic ti,SDL_Surface* ecran);
void afficher_machine(SDL_Surface* ecran,tic ti);
void evaluer(tic *ti);
void gameover(tic ti,SDL_Surface* ecran);
