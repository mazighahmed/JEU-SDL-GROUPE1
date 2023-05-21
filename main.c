#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
#include "bouton.h"
#include "menu.h"
#include "texte.h"
#include "background.h"
#include "player.h"
#include <time.h>
#include "robots.h"
#include "enigme.h"
#include "enigme2.h"
#include "collision.h"
#include "score.h"
#include "door.h"
#include "mini-map.h"
#include "sousmenu.h"
#include "IA2.h"
#include "arduino.h"

int main()
{
    //DECLARATION VARIABLE
    int i;
    char input[20];
    Bouton bouton[20];
    int regl;
	double rotation =0;
	double zoom =0;
	
    int rob =0;
    background backg;
    SDL_Surface* screen=NULL;
    Image Play0, Exit0, Option0, Back0, bg, bg2, menu;
    Image Play1, Exit1, Option1, Back1;
   
    Image fs_0, fs_1,mus_0, mus_1, Scroll, ms, reg_0,reg_1,up_0,up_1,down_0,down_1,right_0,right_1,left_0,left_1,p_0,p_1,p2_0,p2_1,confirm0, confirm1;
    SDL_Surface *bad, *good, *good_rot, *bad_rot, *name_hud, *ecran, *win, *loose;
    Image GUI ,GUI2;
    logo Logo;
    texte score, score2, your_name;
    Player j, j2, j1;
    Uint32 dt, t_prev, timer;
    Background BG, BG2, bob, BG1;
    Ennemi e, e2, e3, e4, e5, e6, e7, e8;
	Ennemi *E;
    SDL_Rect rect1, rect2;
    Enigme eni, eni1, eni2;
    char c[1];
    char name[20] = "";

    int choix=0;
    int enigme = 0;
    int game_mode =1;

    Mix_Music* music0, *game, *menu_mus;
    Mix_Chunk* click;
    Mix_Chunk* motion;
    SDL_Event event;

    Uint8 *keystates;
    Uint8 *bebsi;

    beb bab1,bab2,bab3;
   
   ordi contour;
	
    SDL_Rect or;


    //SDL INIT
    if(IMG_Init(IMG_INIT_PNG)==-1)
        printf("ERROR SDL_IMAGE INIT");
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
        printf("ERROR SDL INIT \n");
    TTF_Init();
//INITIALISATION DU MENU
    //MIXER INIT
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    click = Mix_LoadWAV("click2.wav");
    motion = Mix_LoadWAV("motion.wav");
    music0 = Mix_LoadMUS("Music0.mp3");
  game = Mix_LoadMUS("music_game.mp3");
  menu_mus = Mix_LoadMUS("music_menu.mp3");

    //INIT TEXTE


    //IMAGES INIT

    initialiser_menu(&backg);

    //initialiser_logo(&Logo, "logo.txt");
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    Scroll = initialiser_image("boutons/scroll.png", 473, 537);
    ms = initialiser_image("boutons/bg_options.png", -250, 0);
    fs_0 = initialiser_image("boutons/fs_0.png", 830, 401);
    fs_1 = initialiser_image("boutons/fs_1.png", 830, 401);
    mus_0 = initialiser_image("boutons/mus_0.png", 770, 314);
    mus_1 = initialiser_image("boutons/mus_1.png", 770, 314);

    Play0 = initialiser_image("boutons/Play0.png", SCREEN_W/3 + 75, SCREEN_H/3 + 75);
    Option0 = initialiser_image("boutons/Options0.png", SCREEN_W/3 + 75, SCREEN_H/3 + 200);
    Exit0 = initialiser_image("boutons/Exit0.png", SCREEN_W/3 + 75, SCREEN_H/3 + 325);
    Back0 = initialiser_image("boutons/Back0.png", 25, 25);

    Play1 = initialiser_image("boutons/Play1.png", SCREEN_W/3+75, SCREEN_H/3 + 75);
    Option1 = initialiser_image("boutons/Options1.png", SCREEN_W/3 + 75, SCREEN_H/3 + 200);
    Exit1 = initialiser_image("boutons/Exit1.png", SCREEN_W/3 + 75, SCREEN_H/3 + 325);
    Back1 = initialiser_image("boutons/Back1.png", 25, 25);
    bouton[0] = initialiser_bouton(Play0, Play1);
    bouton[1] = initialiser_bouton(Option0, Option1);
    bouton[2] = initialiser_bouton(Exit0, Exit1);
    bouton[3] = initialiser_bouton(Back0, Back1);

    bouton[5] = initialiser_bouton(fs_0, fs_1);
    bouton[4] = initialiser_bouton(mus_0, mus_1);
    bouton[6] = initialiser_bouton(Scroll, Scroll);
    texte text3,text1,text2,text4, texte5;
    initialiser_texte(&text1,300,220);
    initialiser_texte(&text2,300,110);
    initialiser_texte(&text3,300,320);
    initialiser_texte(&text4,300,420);
    initialiser_texte(&texte5,430,350);
    initialiser_texte(&your_name,315,200);
    reg_0 = initialiser_image("boutons/mus_0.png", 770, 250);
    reg_1 = initialiser_image("boutons/mus_1.png", 770, 250);
    up_0 = initialiser_image("boutons/mus_0.png", 250, 150);
    up_1 = initialiser_image("boutons/mus_1.png", 250, 150);
    down_0 = initialiser_image("boutons/mus_0.png", 250, 250);
    down_1 = initialiser_image("boutons/mus_1.png", 250, 250);
    right_0 = initialiser_image("boutons/mus_0.png", 250, 350);
    right_1 = initialiser_image("boutons/mus_1.png", 250, 350);
    left_0 = initialiser_image("boutons/mus_0.png", 250, 450);
    left_1 = initialiser_image("boutons/mus_1.png", 250, 450);
    p_0 = initialiser_image("boutons/one_player0.png", SCREEN_W/3 + 75, SCREEN_H/3 + 100);
    p_1 = initialiser_image("boutons/one_player1.png", SCREEN_W/3 + 75, SCREEN_H/3 + 100);
    p2_0 = initialiser_image("boutons/two_player0.png", SCREEN_W/3 + 75, SCREEN_H/3 + 250);
    p2_1 = initialiser_image("boutons/two_player1.png", SCREEN_W/3 + 75, SCREEN_H/3 + 250);
    confirm0 = initialiser_image("boutons/confirm0.png", 500, 500);
    confirm1 = initialiser_image("boutons/confirm1.png", 500, 500);
    name_hud = IMG_Load("name.png");
    ecran = IMG_Load("menu/screen.jpg");
    bouton[7] = initialiser_bouton(reg_0, reg_1);
    bouton[8] = initialiser_bouton(up_0, up_1);
    bouton[9] = initialiser_bouton(down_0, down_1);
    bouton[10] = initialiser_bouton(right_0, right_1);
    bouton[11] = initialiser_bouton(left_0, left_1);
    bouton[12] = initialiser_bouton(Back0, Back1);
    bouton[13] = initialiser_bouton(p_0, p_1);
    bouton[14] = initialiser_bouton(p2_0, p2_1);
    bouton[15] = initialiser_bouton(confirm0, confirm1);
	if( (good = IMG_Load("good.png")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if( (bad = IMG_Load("bad.png")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if( (win = IMG_Load("win.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());
	if( (loose = IMG_Load("loose.jpg")) == NULL)
		printf("ERROR:%s \n", SDL_GetError());

//INITIALISATION JEU
	int musicc = 0;
    SDL_Rect pos_abs, pos_abs2;
    Enigme2 en;
    scoreinfo info, yo[100];
    info.score=0;
    info.temps=0;
    int best=0;
    int save =-1;
    int x;
    int show_map=0;
    minimap mini;
    tic ti;
    Menu sm;
    char ard;
	
    bg2 = initialiser_image("forest.jpg", 0, 0);
    GUI = initialiser_image("GUI.png", 0, 0);
    GUI2 = initialiser_image("GUI.png", 640, 0);
    menu = initialiser_image("menu/menu.png", 0, 0);
    texte5.txt = TTF_RenderText_Blended(texte5.police, name, texte5.color);

        init_IA2(&ti);
        sm =  init_SousMenu();
        init_map(&mini);
        initialiser_joueur(&j, "player_ahmed.png", 500,400);
        initBack(&BG);
        init_bob(&bob);// hedhi init taa lvision limite//talkaha fel background.c
        initEnnemi(&e, 600, 600);
        init_door(&bab3,1200,1000,"biben/3.png", 648, -415);
        init_door(&bab2,400,-60,"biben/2.png",1600, 50);
        init_door(&bab1,650,400,"biben/1.png", 648, 35);
        init_ordi(&contour);

        initBack2(&BG2);
        initBack1(&BG1);
        initialiser_joueur(&j1, "character_karim.png", 320, 400);
        initialiser_joueur(&j2, "character_karim.png", 960, 400);
	j2.img_vie.pos1.x = 163+640;
        initEnnemi(&e, 500, 600);
        initEnnemi(&e3, 500, -150);
        initEnnemi(&e4, 500, -150);
        initEnnemi(&e5, 1300, 600);
        initEnnemi(&e6, 1300, 600);
        initEnnemi(&e7, 1300, -500);
        initEnnemi(&e8, 1300, -500);

        initEnnemi(&e2, 1240, 600);
    strcpy(backg.state, "menu");
    initialiser_score(&score);
    initialiser_score2(&score2);
	or.x=450;
	or.y=300;
	or.h=20;
	or.w=50;
//MANETTE

    //GAME LOOP
    //AFFICHAGE ANIMATION LOGO
    //afficher_logo(&Logo, screen);

     //system("stty -F /dev/ttyS3 9600 -parenb cs8 -cstopb");
Mix_PlayMusic(menu_mus, -1);
    timer = SDL_GetTicks();
    while (!backg.done)
    {
	ard = '\0';
	//arduinoReadData(&ard);
	if (ard != '\0')
	   printf("%c \n", ard);
        t_prev = SDL_GetTicks();
        //RENDER MENU
        if (!strcmp(backg.state, "menu"))
        {
            afficher_bg(&backg, screen);
            SDL_BlitSurface(menu.img, NULL, screen, NULL);
            afficher_menu(bouton, screen);
        }
        else if (!strcmp(backg.state, "options"))
        {
            SDL_BlitSurface(ecran, NULL, screen, NULL);
            SDL_BlitSurface(ms.img, NULL, screen, &ms.pos1);
            afficher_options(bouton, screen);
        }
        else if (!strcmp(backg.state, "sousmenu"))
        {
	    SDL_BlitSurface(ecran, NULL, screen, NULL);
            afficher_sousmenu(sm,screen);
        }
        else if (!strcmp(backg.state, "play"))
        {
            if (game_mode ==2)
            {
                afficher(BG2, screen);
                afficherEnnemi(e2, screen);
                afficher(BG1, screen);
                afficher_joueur(j1, screen);
                afficher_joueur(j2, screen);
                if (e.pos2.x < SCREEN_W/2)
                    afficherEnnemi(e, screen);
                SDL_BlitSurface(GUI.img, NULL, screen, &GUI.pos1);
                SDL_BlitSurface(GUI2.img, NULL, screen, &GUI2.pos1);
                afficher_stats(j1, screen, score);
		afficher_stats(j2, screen, score2);
            }
            if (game_mode == 1)
            {
                afficher(BG, screen);
                afficher_beb(bab3,screen);//afficher beb 3
                afficher_beb(bab2,screen);//afficher beb 2
                afficher_beb(bab1,screen);//afficher beb 1
                //SDL_BlitSurface(ordi.img,NULL,screen,&ordi.pos1);
		afficher_ordi(contour,screen);
                afficher_joueur(j, screen);
                afficherEnnemi(e, screen);
                afficherEnnemi(e3, screen);
                afficherEnnemi(e4, screen);
                afficherEnnemi(e5, screen);
                afficherEnnemi(e6, screen);
                afficherEnnemi(e7, screen);
                afficherEnnemi(e8, screen);
		
                //SDL_BlitSurface(bob.img, &bob.camera_pos, screen, &bob.pos); //hedhi li tahser lvision
		//bob.pos.x = j.pos.x - SCREEN_W/2;
                if (show_map ==1)
		{
                    afficherminimap (mini, screen);
		}
		SDL_BlitSurface(GUI.img, NULL, screen, &GUI.pos1);

                afficher_stats(j, screen, score);
                if (best)
		{
			SDL_BlitSurface(ecran, NULL, screen, NULL);
                    bestscore("scores.txt", yo, texte5, screen);

		}
            }
        }
        else if (!strcmp(backg.state, "enigme"))
        {
            	if (en.etat == 0){
           	SDL_BlitSurface(ecran, NULL, screen, NULL);
                afficherEnigme2(&en, screen);
		}
		else if (en.etat == 1)
		{
			SDL_BlitSurface(ecran, NULL, screen, NULL);
			good_rot = rotozoomSurface(good, rotation, zoom, 1);
			rotation+=2;
			zoom += 0.0025;
			SDL_Rect pos = {600,300,0,0};
			pos.x -= good_rot->w/2;
			pos.y -= good_rot->h/2;
			SDL_BlitSurface(good_rot, NULL, screen, &pos);
			SDL_FreeSurface(good_rot);
		}
		else if (en.etat == -1)
		{
			SDL_BlitSurface(ecran, NULL, screen, NULL);
			bad_rot = rotozoomSurface(bad, rotation, zoom, 1);
			rotation+=2;
			zoom += 0.0025;
			SDL_Rect pos = {600,300,0,0};
			pos.x -= bad_rot->w/2;
			pos.y -= bad_rot->h/2;
			SDL_BlitSurface(bad_rot, NULL, screen, &pos);	
			SDL_FreeSurface(bad_rot);
		}
			if(rotation >=360)
			{
				enigme =0;
				en.etat =0;
				rotation=0;
				zoom =0;
				strcpy(backg.state, "play");
				if (j.vie <=0)
				{
					strcpy(backg.state, "loose");
				}
				if (rob >= 7)
				{
					strcpy(backg.state, "win");
				}
		             
			}		
        }
        else if (!strcmp(backg.state, "name"))
        {
  		SDL_BlitSurface(ecran, NULL, screen, NULL);
		//SDL_BlitSurface(name_hud, NULL, screen, NULL);
		SDL_BlitSurface (texte5.txt, NULL, screen, &texte5.pos);
          
		afficher_name(screen, your_name);
		SDL_BlitSurface(bouton[15].image[bouton[15].actif].img, NULL, screen, &bouton[15].image[bouton[15].actif].pos1);
        }
	else if (!strcmp(backg.state, "reglage"))
        {
            SDL_BlitSurface(backg.img[backg.frame], NULL, screen, NULL);
                SDL_BlitSurface(bouton[8].image[bouton[8].actif].img, NULL, screen, &bouton[8].image[bouton[8].actif].pos1);
                SDL_BlitSurface(bouton[9].image[bouton[9].actif].img, NULL, screen, &bouton[9].image[bouton[9].actif].pos1);
                SDL_BlitSurface(bouton[10].image[bouton[10].actif].img, NULL, screen, &bouton[10].image[bouton[10].actif].pos1);
                SDL_BlitSurface(bouton[10].image[bouton[10].actif].img, NULL, screen, &bouton[10].image[bouton[10].actif].pos1);
                SDL_BlitSurface(bouton[11].image[bouton[11].actif].img, NULL, screen, &bouton[11].image[bouton[11].actif].pos1);
		SDL_BlitSurface(bouton[12].image[bouton[12].actif].img, NULL, screen, &bouton[12].image[bouton[12].actif].pos1);
                afficher_texte1(screen,text1);
                afficher_texte2(screen,text2);
                afficher_texte3(screen,text3);
                afficher_texte4(screen,text4);
        }
        else if (!strcmp(backg.state, "select"))
        {
            	SDL_BlitSurface(backg.img[backg.frame], NULL, screen, NULL);
		SDL_BlitSurface(menu.img, NULL, screen, NULL);
		SDL_BlitSurface(bouton[13].image[bouton[13].actif].img, NULL, screen, &bouton[13].image[bouton[13].actif].pos1);
		SDL_BlitSurface(bouton[14].image[bouton[14].actif].img, NULL, screen, &bouton[14].image[bouton[14].actif].pos1);
        }
	
	else if (!strcmp(backg.state, "tic"))
        {
	    gameover(&ti,screen,backg.state);
            afficher_tic(ti,screen);
            afficher_j(ti,screen);
            afficher_machine(screen,ti);
            evaluer(&ti);
		if (ti.whowin == 1)
			{
				j.score +=25;
			}
        }
	else if (!strcmp(backg.state, "loose"))
        {
            SDL_BlitSurface(loose, NULL, screen, NULL);
        }
	else if (!strcmp(backg.state, "win"))
        {
            SDL_BlitSurface(win, NULL, screen, NULL);
        }

        SDL_Flip(screen);
        //EVENT
        while(SDL_PollEvent(&event))
        {
            if (event.type==SDL_QUIT)
                backg.done = 1;


            if (!strcmp(backg.state, "menu"))
            {
                input_clavier(input, event, bouton, motion);
                input_menu(input, event, bouton, motion);
            }
            else if (!strcmp(backg.state, "options"))
            {
                input_options(input, event, bouton, motion);
            }
            else if (!strcmp(backg.state, "enigme"))
            {
                input_enigme2(&choix, en, event);

            }
            else if (!strcmp(backg.state, "name"))
            { 
		input_name(input, event, bouton, motion);
		if (game_mode == 1){
		        if (event.type==SDL_KEYDOWN)
			{
				printf("%d \n", event.key.keysym.sym);
				c[0] = (char)event.key.keysym.sym;
				if (strlen(j.name) <= 10 && event.key.keysym.sym>=97 && event.key.keysym.sym<=122)
				{
					strcat(j.name, c);
					texte5.txt = TTF_RenderText_Blended(texte5.police, j.name, texte5.color);
				}
			}
			if (!strcmp(input, "confirm"))
			{
				if(j.name[0] == '\0')
				{
					strcpy(input, "");
				}
			}
		}

		if (game_mode == 2){
		        if (event.type==SDL_KEYDOWN)
			{
				c[0] = (char)event.key.keysym.sym;
				if (strlen(j1.name) <= 10 && event.key.keysym.sym>=97 && event.key.keysym.sym<=122)
				{
					strcat(j1.name, c);
					texte5.txt = TTF_RenderText_Blended(texte5.police, j1.name, texte5.color);
				}
			}
		}
 
			
            }
		else if (!strcmp(backg.state, "select"))
		{
		    	input_select(input, event, bouton, motion);
		}
		
            else if (!strcmp(backg.state, "tic"))
            {
                if(ti.whoplay==0)
                {
                    if (event.type== SDL_MOUSEBUTTONDOWN)
                    {
                        for(i=0; i<9; i++)
                        {
                            if((event.button.x>=ti.pos[i].x)&&(event.button.x<=(ti.pos[i].x+ti.pos[0].w))&&(event.button.y>=ti.pos[i].y)&&(event.button.y<=(ti.pos[i].y+ti.pos[i].h)))
                            {
                                if (ti.matrice_suivi[i]!=1 && ti.matrice_suivi[i]!=-1)
                                {
                                    ti.matrice_suivi[i]=1;
                                    ti.whoplay=1;
			            ti.tour++;
                                }
				if(ti.tour<8)
				{
		                        x=rand()%9;
		                        while(ti.matrice_suivi[x]==1 || ti.matrice_suivi[x]==-1)
		                        {
		                            x=rand()%9;
		                        }
		                        if(ti.whoplay==1)
		                        {
		                            ti.matrice_suivi[x]=-1;
					    ti.tour++;
		                        }
		                        ti.whoplay=0;
				}
                            }
                        }
                    }
                }
            }
		
	}
          if (!strcmp(backg.state, "reglage"))
            {
                	input_reglage(input, event, bouton, motion);
			if(event.button.button==SDL_BUTTON_LEFT)
			{
				if (event.motion.y >= 25 && event.motion.y <= (25 + 100) && event.motion.x >= 25 && event.motion.x <= (25 + 100))
							{
								strcpy(backg.state, "options");
							}
			
				if (event.motion.y >= 150 && event.motion.y <= (150 + 48) && event.motion.x >= 250 && event.motion.x <= (250 + 48))
				{

									regl=1;
							while(regl)
							{
								SDL_WaitEvent(&event);

								if (event.type==SDL_QUIT)
									backg.done = 1;
								if (event.type==SDL_KEYDOWN)
								{
									j.config.key[0] = event.key.keysym.sym;
									regl = 0;
								
								}
							}
					
				}
				if (event.motion.y >= 500 && event.motion.y <= (500 + 48) && event.motion.x >= 250 && event.motion.x <= (250 + 48))
				{
							
							regl=1;
							while(regl)
							{
								SDL_WaitEvent(&event);

								if (event.type==SDL_QUIT)
									backg.done = 1;
								if (event.type==SDL_KEYDOWN)
								{
									j.config.key[1] = event.key.keysym.sym;
									regl = 0;
								
								}
							}
				}
				if (event.motion.y >= 150 && event.motion.y <= (150 + 48) && event.motion.x >= 1000 && event.motion.x <= (1000 + 48))
				{
					
								regl=1;
							while(regl)
							{
								SDL_WaitEvent(&event);

								if (event.type==SDL_QUIT)
									backg.done = 1;
								if (event.type==SDL_KEYDOWN)
								{
									j.config.key[2] = event.key.keysym.sym;
									regl = 0;
								
								}
							}
				}
				if (event.motion.y >= 500 && event.motion.y <= (500 + 48) && event.motion.x >= 1000 && event.motion.x <= (1000 + 48))
				{
				
							regl=1;
							while(regl)
							{
								SDL_WaitEvent(&event);

								if (event.type==SDL_QUIT)
									backg.done = 1;
								if (event.type==SDL_KEYDOWN)
								{
									j.config.key[3] = event.key.keysym.sym;
									regl = 0;
								
								}
							}
				}
			}
            }
 if (!strcmp(backg.state, "play")){
        if (game_mode ==1)
        {
            keystates = SDL_GetKeyState(NULL);
            update_pos_abs(&pos_abs, &j, &BG);

            if (keystates[j.config.key[0]] && j.saut.state == 0 && !collision_parfaite_down(BG.mask, pos_abs) && !collision_door_down(BG.mask,pos_abs,bab2))
            {
                j.dir=0;
                if (BG.camera_pos.y + SCREEN_H <2304 && j.pos.y > SCREEN_H/2 )
                {

                    BG.direction = 0;
                    j.move = 0;
                }
                else
                {
                    BG.direction = -1;
                    j.move = 1;
                }

            }
            else if (keystates[j.config.key[1]]  && j.saut.state == 0 && !collision_parfaite_up(BG.mask, pos_abs) && !collision_door_up(BG.mask,pos_abs,bab1)&& !collision_door3_up(BG.mask,pos_abs,bab3))
            {
                j.dir=1;
                if (BG.camera_pos.y > 0 && BG.camera_pos.y < 2304 - SCREEN_H/2 )
                {
                    BG.direction = 1;
                    j.move = 0;
                }
                else
                {
                    BG.direction = -1;
                    j.move = 1;
                }
            }
            else if (keystates[j.config.key[2]]  && !collision_parfaite_right(BG.mask, pos_abs, j.saut.state))
            {
                j.dir=2;
                if (BG.camera_pos.x + SCREEN_W <1984 && j.pos.x > SCREEN_W/2)
                {
                    BG.direction = 2;
                    j.move = 0;
                }
                else
                {
                    BG.direction = -1;
                    j.move = 1;
                }

            }
            else if (keystates[j.config.key[3]] && !collision_parfaite_left(BG.mask, pos_abs, j.saut.state))
            {
                j.dir=3;
                if (BG.camera_pos.x>0 && j.pos.x+BG.camera_pos.x < 1984 - SCREEN_W/2)
                {
                    BG.direction = 3;
                    j.move = 0;
                }
                else
                {
                    BG.direction = -1;
                    j.move = 1;
                }
            }
            else
            {
                j.dir=-1;
                BG.direction = -1;
            }
 
            if (collisionBB(j.pos,bab3.k.pos)==1 )
            {
                bab3.k.state=1;
                info.score+=500;
            }
            if (collisionBB(j.pos,bab2.k.pos)==1 && bab2.k.state==0)
            {
                bab2.k.state=1;
                info.score+=250;
                j.score+=250;
            }
            if (collisionBB(j.pos,bab1.k.pos)==1 && bab1.k.state==0)
            {
                bab1.k.state=1;
                info.score+=150;
                j.score+=150;
            }
            if (collisionBB(j.pos,bab1.k.pos)==1 && bab1.k.state==0)
            {
                bab1.k.state=1;
                info.score+=150;
                j.score+=150;
            }

            if (keystates[SDLK_SPACE] && j.dir != 0 && j.dir != 1 && j.saut.state != 1)
            {
                j.saut.state = 1;
                j.saut.x0 = j.pos.x;
                j.saut.y0 = j.pos.y;
                j.saut.dy = 10;
            }
	if (collision_door_up(BG.mask,pos_abs,bab1) &&(bab1.state==0))
		bab1.t.state=0;
		else 
		bab1.t.state=1;

		if (bab1.t.state==0 && keystates[SDLK_e] && bab1.k.state==1)
		{bab1.state=1;
		bab1.t.state=1;}


	       if (collision_door_down(BG.mask,pos_abs,bab2) &&(bab2.state==0))
		bab2.t.state=0;
		else 
		bab2.t.state=1;

		if (bab2.t.state==0 && keystates[SDLK_e] && bab2.k.state==1)
		{bab2.state=1;
		bab2.t.state=1;}


	    if (collision_door3_up(BG.mask,pos_abs,bab3) &&(bab3.state==0))
		bab3.t.state=0;
		else 
		bab3.t.state=1;

		if (bab3.t.state==0 && keystates[SDLK_e] && bab3.k.state==1)
		{bab3.state=1;
		bab3.t.state=1;}
		}
	    if (contour.state==1 && keystates[SDLK_e])
			strcpy(backg.state, "tic");

	    if(collisionBB(j.pos,or)==1)
		contour.state=1;
	    else
		contour.state=0;
        if (game_mode == 2)
        {
            keystates = SDL_GetKeyState(NULL);
            update_pos_abs(&pos_abs, &j1, &BG1);
            update_pos_abs(&pos_abs2, &j2, &BG2);
            if (keystates[j1.config.key[0]] && j1.saut.state == 0 && !collision_parfaite_down(BG1.mask, pos_abs))
            {
                j1.dir=0;
                if (BG1.camera_pos.y + SCREEN_H/2 <2304 && j1.pos.y > SCREEN_H/2 )
                {

                    BG1.direction = 0;
                    j1.move = 0;
                }
                else
                {
                    BG1.direction = -1;
                    j1.move = 1;
                }

            }
            else if (keystates[j1.config.key[1]] && j1.saut.state == 0 && !collision_parfaite_up(BG1.mask, pos_abs))
            {
                j1.dir=1;
                if (BG1.camera_pos.y > 0 && BG1.camera_pos.y < 2304 - SCREEN_H/4 )
                {
                    BG1.direction = 1;
                    j1.move = 0;
                }
                else
                {
                    BG1.direction = -1;
                    j1.move = 1;
                }
            }
            else if (keystates[j1.config.key[2]] && !collision_parfaite_right(BG1.mask, pos_abs, j1.saut.state))
            {
                j1.dir=2;
                if (BG1.camera_pos.x + SCREEN_W/2 <1984 && j1.pos.x > SCREEN_W/4 )
                {
                    BG1.direction = 2;
                    j1.move = 0;
                }
                else
                {
                    BG1.direction = -1;
                    j1.move = 1;
                }

            }
            else if (keystates[j1.config.key[3]] && !collision_parfaite_left(BG1.mask, pos_abs, j1.saut.state))
            {
                j1.dir=3;
                if (BG1.camera_pos.x>0 && j1.pos.x+BG1.camera_pos.x < 1984 - SCREEN_W/4)
                {
                    BG1.direction = 3;
                    j1.move = 0;
                }
                else
                {
                    BG1.direction = -1;
                    j1.move = 1;
                }
            }
            else
            {
                j1.dir=-1;
                BG1.direction = -1;
            }
            if (keystates[SDLK_SPACE] && j1.dir != 0 && j1.dir != 1 && j1.saut.state != 1)
            {
                j1.saut.state = 1;
                j1.saut.x0 = j1.pos.x;
                j1.saut.y0 = j1.pos.y;
                j1.saut.dy = 10;
            }
            // PLAYEr2
            keystates = SDL_GetKeyState(NULL);
            if (keystates[SDLK_DOWN] && j2.saut.state == 0 && !collision_parfaite_down(BG2.mask, pos_abs2))
            {
                j2.dir=0;
                if (BG2.camera_pos.y + SCREEN_H/2 <2304 && j2.pos.y > SCREEN_H/2)
                {
                    BG2.direction = 0;
                    j2.move = 0;
                }
                else
                {
                    BG2.direction = -1;
                    j2.move = 1;
                }

            }
            else if (keystates[SDLK_UP] && j2.saut.state == 0 && !collision_parfaite_up(BG2.mask, pos_abs2))
            {
                j2.dir=1;
                if (BG2.camera_pos.y > 0 && BG2.camera_pos.y < 2304 - SCREEN_H/2 )
                {
                    BG2.direction = 1;
                    j2.move = 0;
                }
                else
                {
                    BG2.direction = -1;
                    j2.move = 1;
                }
            }
            else if (keystates[SDLK_RIGHT] && !collision_parfaite_right(BG2.mask, pos_abs2,j2.saut.state))
            {
                j2.dir=2;
                if (BG2.camera_pos.x + SCREEN_W/4 <1984 && j2.pos.x > SCREEN_W/4 )
                {
                    BG2.direction = 2;
                    j2.move = 0;
                }
                else
                {
                    BG2.direction = -1;
                    j2.move = 1;
                }

            }
            else if (keystates[SDLK_LEFT] && !collision_parfaite_left(BG2.mask, pos_abs2,j.saut.state))
            {
                j2.dir=3;
                if (BG2.camera_pos.x>0 && j2.pos.x+BG2.camera_pos.x < 1984 - SCREEN_W/4)
                {
                    BG2.direction = 3;
                    j2.move = 0;
                }
                else
                {
                    BG2.direction = -1;
                    j2.move = 1;
                }
            }
            else
            {
                j2.dir=-1;
                BG2.direction = -1;
            }
            /*
            if(keystates[SDLK_NUM1])
            {
            	j2.acc += 0.005;
            }
            else if(keystates[SDLK_NUM2])
            {
            	j2.acc -= 0.001;
            }
            */
            if (keystates[SDLK_SPACE] && j2.dir != 0 && j2.dir != 1 && j2.saut.state != 1)
            {
                j2.saut.state = 1;
                j2.saut.x0 = j2.pos.x;
                j2.saut.y0 = j2.pos.y;
                j2.saut.dy = 10;
            }
        }//if gamemode
        //--------------
        if (keystates[SDLK_m])
        {
            show_map=1;
        }
        else
        {
            show_map =0;
        }

        if (keystates[SDLK_p])
        {
            strcpy(backg.state, "sousmenu");
        }
        if (keystates[SDLK_o])
        {
            strcpy(backg.state, "tic");
        }
        if (keystates[SDLK_i])
        {
            best= 1;
        }
        else
            best =0;
       
}
        //UPDATE
        update_menu(input, bouton, &backg, click, music0, event, screen);

        if (!strcmp(backg.state, "play"))
        {
		if (game_mode ==1){
            move_joueur(&j, dt, &BG);
            scrolling(&BG, BG.direction,j.dx);
  	    update_pos(&e, BG);
  	    update_pos(&e3, BG);
  	    update_pos(&e4, BG);
  	    update_pos(&e5, BG);
  	    update_pos(&e6, BG);
  	    update_pos(&e7, BG);
  	    update_pos(&e8, BG);
            moveEnnemi(&e, BG.mask);
            scroll_e(BG, &e, j.dx);
            moveEnnemi(&e3, BG.mask);
            scroll_e(BG, &e3, j.dx);
            moveEnnemi(&e4, BG.mask);
            scroll_e(BG, &e4, j.dx);
            moveEnnemi(&e5, BG.mask);
            scroll_e(BG, &e5, j.dx);
            moveEnnemi(&e6, BG.mask);
            scroll_e(BG, &e6, j.dx);
            moveEnnemi(&e7, BG.mask);
            scroll_e(BG, &e7, j.dx);
            moveEnnemi(&e8, BG.mask);
            scroll_e(BG, &e8, j.dx);
            scroll_biben(BG, &bab3,j.dx);
            scroll_biben(BG, &bab2,j.dx);
            scroll_biben(BG, &bab1,j.dx);
	    scroll_ordi(BG,&contour,j.dx);
	    scroll_pos(BG,&or, j.dx);
            saut(&j, &BG);
            animer_joueur(&j);
            animerEnnemi(&e);
            animerEnnemi(&e3);
            animerEnnemi(&e4);
            animerEnnemi(&e5);
            animerEnnemi(&e6);
            animerEnnemi(&e7);
            animerEnnemi(&e8);

	    MAJMinimap(pos_abs,  &mini, BG.camera_pos, 20);

            animerBack(&BG);
		}
            if (game_mode == 2)
            {
            move_joueur(&j1, dt, &BG1);
            scrolling(&BG1, BG1.direction,j1.dx);

            //update pos_absolue enemy
            e.pos_abs.x = e.pos2.x + BG1.camera_pos.x;
            e.pos_abs.y = e.pos2.y + BG1.camera_pos.y;
            e.pos_abs.w = 64;
            e.pos_abs.h = 64;
            moveEnnemi(&e, BG1.mask);
            scroll_e(BG1, &e, j1.dx);
            saut(&j1, &BG1);
            animer_joueur(&j1);
            animerEnnemi(&e);
	    MAJMinimap(pos_abs,  &mini, BG1.camera_pos, 20);

            animerBack(&BG1);



                move_joueur(&j2, dt, &BG2);
                scrolling(&BG2, BG2.direction,j2.dx);
                //update pos_absolue enemy2
                e2.pos_abs.x = e2.pos2.x + BG2.camera_pos.x;
                e2.pos_abs.y = e2.pos2.y + BG2.camera_pos.y;
                e2.pos_abs.w = 64;
                e2.pos_abs.h = 64;
                //J2
                moveEnnemi(&e2, BG2.mask);
                scroll_e(BG2, &e2, j2.dx);
                saut(&j2, &BG2);
                animer_joueur(&j2);
                animerEnnemi(&e2);
            }
            if (collisionBB(e.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e;
		}
            if (collisionBB(e3.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e3;
		}
            if (collisionBB(e4.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e4;
		}
            if (collisionBB(e5.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e5;
		}
            if (collisionBB(e6.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e6;
		}
           if (collisionBB(e7.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e7;
		}
           if (collisionBB(e8.pos2, j.pos))
		{
                strcpy(backg.state, "enigme");
		E = &e8;
		}
        }

        if (!strcmp(backg.state, "enigme"))
        {
            if(enigme == 0)
            {
                genererEnigme2(&en, "enigme.txt", BG);
                enigme = 1;
            }
            if (choix != 0)
            {
                if (choix == en.repj)
                {
	            rob++;
		    en.etat = 1;
                    E->pos2.x = -10000;
                    choix = 0;
                    j.score += 300;
                }
                else
                {
			en.etat = -1;
			choix = 0;
                    	j.vie -= 1;
                }
            }
        }
        if (!strcmp(backg.state, "sousmenu"))
        {
            save = update_SousMenu(&sm, event, &save);
            if (save == 0)
            {
                strcpy(backg.state, "play");
            }
            if (save == 1)
            {
		sauvegarder (j, BG, "sauvegarde.txt");
                strcpy(backg.state, "play");
            }
            if (save == 2)
            {
		charger (&j, &BG , "sauvegarde.txt");
                strcpy(backg.state, "play");
            }
        }
       if (!strcmp(backg.state, "select"))
        {
            if (!strcmp(input, "one"))
            {
           	game_mode = 1;
                strcpy(backg.state, "name");
            }
           if (!strcmp(input, "two"))
            {
           	game_mode = 2;
                strcpy(backg.state, "play");
            }
        }
       if (!strcmp(backg.state, "name"))
        {
            if (!strcmp(input, "confirm"))
            {
                strcpy(backg.state, "play");
            }

        }
        
        if(!strcmp(backg.state, "play")&& musicc==0 )
        {
                //Play the music
		Mix_PauseMusic();
        	Mix_PlayMusic(game, -1);
		musicc = 1;
        }
        
	strcpy(input, "");
        if ( (SDL_GetTicks() - timer) >= 1000)
        {
            info.temps = SDL_GetTicks();
        }
        dt= (SDL_GetTicks()-t_prev);
    }

    info.score=j.score;
    strcpy(info.nom_player, j.name);

    savescore(info,"scores.txt");
// LIBERER LES IMAGES DE LA MEMOIRE
    liberer_bg(backg);
    SDL_FreeSurface(menu.img);
    SDL_FreeSurface(BG.img);
    SDL_FreeSurface(BG.mask);
    SDL_FreeSurface(ms.img);
    SDL_FreeSurface(bg2.img);
    SDL_FreeSurface(GUI.img);
    SDL_FreeSurface(e.img);
    SDL_FreeSurface(j.img_vie.img);
    SDL_FreeSurface(j.shadow.img);
    SDL_FreeSurface(j.anim.image.img);
    liberer_boutons(bouton);
    Mix_FreeChunk(click);
    Mix_FreeMusic(music0);
    Mix_CloseAudio();
    liberer_texte(score);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

