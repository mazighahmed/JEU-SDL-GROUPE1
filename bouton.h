#ifndef __GUARD_STRUCTS__
#define __GUARD_STRUCTS__

typedef struct bt
{
int actif;
Image image[2];
}
Bouton;

Bouton initialiser_bouton(Image img1, Image img2);
int bouton_motion(SDL_Event event, Bouton bouton[], int type);
void liberer_boutons(Bouton bouton[]);


#endif 

