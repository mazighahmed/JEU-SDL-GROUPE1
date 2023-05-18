#ifndef TEXTE_H
#define TEXTE_H

typedef struct
{
  TTF_Font *police;
  SDL_Rect pos;
  SDL_Colour color;
  SDL_Surface *txt;
}texte;

void initialiser_texte(texte *txte, int x, int y);
void initialiser_score(texte *txte);
void initialiser_score2(texte *txte);
void afficher_texte(SDL_Surface *screen,texte txte);
void afficher_texte1(SDL_Surface *screen,texte txte);
void afficher_texte2(SDL_Surface *screen,texte txte);
void afficher_texte3(SDL_Surface *screen,texte txte);
void afficher_texte4(SDL_Surface *screen,texte txte);
void afficher_name(SDL_Surface *screen,texte txte);
void liberer_texte(texte txte);

#endif
