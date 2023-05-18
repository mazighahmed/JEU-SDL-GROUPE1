#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



//AFFICHAGE
void afficher_menu(Bouton bouton[], SDL_Surface *screen);
void afficher_options(Bouton bouton[], SDL_Surface *screen);

//INPUT
void input_menu(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son);
void input_options(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son);
void input_play();
void input_clavier(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son);
void input_reglage(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son);
void input_select(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son);
void input_name(char input[], SDL_Event event, Bouton bouton[], Mix_Chunk* son);
//UPDATE
void update_options();
void update_play();
void update_menu(char input[], Bouton bouton[], background* backg, Mix_Chunk* son, Mix_Music* music, SDL_Event event, SDL_Surface *screen);



#endif 
