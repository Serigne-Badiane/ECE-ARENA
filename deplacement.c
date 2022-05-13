#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void init_depla()
{
    /*int a,b;
    if(mouse_b&1)
    {
        a=mouse_x/50;
        b=mouse_y/28;
        play[0].x=matrice_terrain[a][b].x;
        play[0].y=matrice_terrain[a][b].y;
    }*/

    play[0].x=matrice_terrain[9][12].x;             ///10*50;                   ///A GAUCHE Y A DROITE X
    play[0].y=matrice_terrain[9][12].y;             ///12*28-14;

    play[1].x=matrice_terrain[14][14].x;
    play[1].y=matrice_terrain[14][14].y;
}

void deplacement(BITMAP* terrain, BITMAP* buffer)
{
    BITMAP* image_joueur[32];
    BITMAP* dera;

    image_joueur[0] = load_bitmap("player/player1.bmp", NULL);
    image_joueur[1] = load_bitmap("player/player2.bmp", NULL);
    image_joueur[2] = load_bitmap("player/player3.bmp", NULL);
    image_joueur[3] = load_bitmap("player/player4.bmp", NULL);
    image_joueur[4] = load_bitmap("player/player5.bmp", NULL);
    image_joueur[5] = load_bitmap("player/player6.bmp", NULL);
    image_joueur[6] = load_bitmap("player/player7.bmp", NULL);
    image_joueur[7] = load_bitmap("player/player8.bmp", NULL);

    image_joueur[8] = load_bitmap("player/player9.bmp", NULL);
    image_joueur[9] = load_bitmap("player/player10.bmp", NULL);
    image_joueur[10] = load_bitmap("player/player11.bmp", NULL);
    image_joueur[11] = load_bitmap("player/player12.bmp", NULL);

    dera = load_bitmap("deplacement.bmp", NULL);

    for (int test=0; test<12; test++)
    {
        if (image_joueur[test]==NULL)
        {
            allegro_message("Pas l'image %d", test);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    //clear_bitmap(terrain);
    affichage_terrain(terrain,buffer);

        for(int j=0; j<2; j++)
        {

            for(int i=1; i<=3; i++)
            {
                blit(dera, terrain, 0 ,0, play[j].x-i*matrice_terrain[0][0].largeur/2, play[j].y-i*matrice_terrain[0][0].hauteur/2, image_joueur[2]->w, image_joueur[2]->h);
                blit(dera, terrain, 0 ,0, play[j].x+i*matrice_terrain[0][0].largeur/2, play[j].y-i*matrice_terrain[0][0].hauteur/2, image_joueur[2]->w, image_joueur[2]->h);
                blit(dera, terrain, 0 ,0, play[j].x-i*matrice_terrain[0][0].largeur/2, play[j].y+i*matrice_terrain[0][0].hauteur/2, image_joueur[2]->w, image_joueur[2]->h);
                blit(dera, terrain, 0 ,0, play[j].x+i*matrice_terrain[0][0].largeur/2, play[j].y+i*matrice_terrain[0][0].hauteur/2, image_joueur[2]->w, image_joueur[2]->h);
            }


            blit(image_joueur[2], terrain, 0 ,0, play[j].x, play[j].y-(image_joueur[2]->h/2), image_joueur[2]->w, image_joueur[2]->h);

            if(mouse_b&1 && mouse_x>play[j].x && mouse_x<play[j].x+2*matrice_terrain[0][0].largeur && mouse_y>play[j].y && mouse_y<play[j].y+2*matrice_terrain[0][0].hauteur)
            {
                do
                {
                    play[j].x=play[j].x+(matrice_terrain[0][0].largeur/2);
                    play[j].y=play[j].y+(matrice_terrain[0][0].hauteur/2);
                    blit(image_joueur[2], terrain, 0 ,0, play[j].x-(image_joueur[2]->w/2), play[j].y-(image_joueur[2]->h/2), image_joueur[2]->w, image_joueur[2]->h);
                    //rest(500);
                }while(play[j].x<mouse_x || play[j].y<mouse_y);
            }
            if(mouse_b&1 && mouse_x>play[j].x && mouse_x<play[j].x+2*matrice_terrain[0][0].largeur && mouse_y<play[j].y && mouse_y>play[j].y-2*matrice_terrain[0][0].hauteur)
            {
                do
                {
                    play[j].x=play[j].x+(matrice_terrain[0][0].largeur/2);
                    play[j].y=play[j].y-(matrice_terrain[0][0].hauteur/2);
                    blit(image_joueur[2], terrain, 0 ,0, play[j].x-(image_joueur[2]->w/2), play[j].y-(image_joueur[2]->h/2), image_joueur[2]->w, image_joueur[2]->h);
                //rest(500);
                }while(play[j].x<mouse_x || play[j].y>mouse_y);
            }
            if(mouse_b&1 && mouse_x<play[j].x && mouse_x>play[j].x-2*matrice_terrain[0][0].largeur && mouse_y>play[j].y && mouse_y<play[j].y+2*matrice_terrain[0][0].hauteur)
            {
                do
                {
                    play[j].x=play[j].x-(matrice_terrain[0][0].largeur/2);
                    play[j].y=play[j].y+(matrice_terrain[0][0].hauteur/2);
                    blit(image_joueur[2], terrain, 0 ,0, play[j].x-(image_joueur[2]->w/2), play[j].y-(image_joueur[2]->h/2), image_joueur[2]->w, image_joueur[2]->h);
                //rest(500);
                }while(play[j].x>mouse_x || play[j].y<mouse_y);
            }
            if(mouse_b&1 && mouse_x<play[j].x && mouse_x>play[j].x-2*matrice_terrain[0][0].largeur && mouse_y<play[j].y && mouse_y>play[j].y-2*matrice_terrain[0][0].hauteur)
            {
                do
                {
                    play[j].x=play[j].x-(matrice_terrain[0][0].largeur/2);
                    play[j].y=play[j].y-(matrice_terrain[0][0].hauteur/2);
                    blit(image_joueur[2], terrain, 0 ,0, play[j].x-(image_joueur[2]->w/2), play[j].y-(image_joueur[2]->h/2), image_joueur[2]->w, image_joueur[2]->h);
                    //rest(500);
                }while(play[j].x>mouse_x || play[j].y>mouse_y);
            }
        }
}
