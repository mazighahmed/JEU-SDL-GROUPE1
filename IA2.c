#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"IA2.h"

void init_IA2(tic *ti)
{
    int i;
    for(i=0; i<9; i++)
    {
        ti->matrice_suivi[i]=0;
    }
    for(i=0; i<9; i++)
    {
        ti->x[i]=IMG_Load("tic_tac_toe/X.png");
        ti->o[i]=IMG_Load("tic_tac_toe/O.png");
    }
    ti->failed=IMG_Load("tic_tac_toe/failed1.jpg");
    ti->win=IMG_Load("tic_tac_toe/win.jpg");
    ti->back=IMG_Load("tic_tac_toe/IA2.jpg");
    ti->pos_back.x=0;
    ti->pos_back.y=0;
    ti->pos[0].x=400;
    ti->pos[0].y=200;
    ti->pos[0].w=120;
    ti->pos[0].h=120;

    ti->pos[1].x=560;
    ti->pos[1].y=200;
    ti->pos[1].w=120;
    ti->pos[1].h=120;

    ti->pos[2].x=720;
    ti->pos[2].y=200;
    ti->pos[2].w=120;
    ti->pos[2].h=120;

    ti->pos[3].x=400;
    ti->pos[3].y=340;
    ti->pos[3].w=120;
    ti->pos[3].h=120;

    ti->pos[4].x=560;
    ti->pos[4].y=340;
    ti->pos[4].w=120;
    ti->pos[4].h=120;

    ti->pos[5].x=720;
    ti->pos[5].y=340;
    ti->pos[5].w=120;
    ti->pos[5].h=120;

    ti->pos[6].x=400;
    ti->pos[6].y=480;
    ti->pos[6].w=120;
    ti->pos[6].h=120;

    ti->pos[7].x=560;
    ti->pos[7].y=480;
    ti->pos[7].w=120;
    ti->pos[7].h=120;

    ti->pos[8].x=720;
    ti->pos[8].y=480;
    ti->pos[8].w=120;
    ti->pos[8].h=120;

    ti->whoplay=0;
    ti->whowin=0;
    ti->tour=0;
}
void afficher_tic(tic ti,SDL_Surface* ecran)
{
    SDL_BlitSurface(ti.back,NULL,ecran,NULL);
}

void afficher_j(tic ti,SDL_Surface* ecran)
{
    int i;
    for (i=0; i<9; i++)
        if(ti.matrice_suivi[i]==1)
            SDL_BlitSurface(ti.x[i],NULL,ecran,&(ti.pos[i]));
}

void reset(tic *ti)
{
    int i;
    for(i=0; i<9; i++)
    {
        ti->matrice_suivi[i]=0;
    }

    ti->whoplay=0;
    ti->whowin=0;
    ti->tour=0;

}

void afficher_machine(SDL_Surface* ecran,tic ti)
{
    int i;
    for(i=0; i<9; i++)
    {
        if(ti.matrice_suivi[i]==-1)
            SDL_BlitSurface(ti.o[i],NULL,ecran,&(ti.pos[i]));
    }

}
void evaluer(tic *ti)
{
    if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[1]==1 && ti->matrice_suivi[2]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[3]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[5]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[6]==1 && ti->matrice_suivi[7]==1 && ti->matrice_suivi[8]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[8]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[6]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[3]==1 && ti->matrice_suivi[6]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[1]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[7]==1)
    {
        ti->whowin=1;
    }
    if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[5]==1 && ti->matrice_suivi[8]==1)
    {
        ti->whowin=1;
    }

    if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[1]==-1 && ti->matrice_suivi[2]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[3]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[5]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[6]==-1 && ti->matrice_suivi[7]==-1 && ti->matrice_suivi[8]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[8]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[6]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[3]==-1 && ti->matrice_suivi[6]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[1]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[7]==-1)
    {
        ti->whowin=-1;
    }
    if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[5]==-1 && ti->matrice_suivi[8]==-1)
    {
        ti->whowin=-1;
    }
	int i;
    if (ti->whowin != 1)
	{
		for (i=0;i<9 && ti->matrice_suivi[i]==-1 || ti->matrice_suivi[i]==-1 ;i++);
			if (i==8)
			ti->whowin=-1;
	}


}


void gameover(tic *ti,SDL_Surface* ecran, char state[])
{
    switch(ti->whowin)
    {
    case 1:
        SDL_BlitSurface(ti->win,NULL,ecran,NULL);
        SDL_Flip(ecran);
	SDL_Delay(1000);
	reset(ti);
        strcpy(state, "play");
        break;
    case -1:
        SDL_BlitSurface(ti->failed,NULL,ecran,NULL);
        SDL_Flip(ecran);
	SDL_Delay(1000);
	reset(ti);
        strcpy(state, "play");
        break;
    }

}

























