#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>
///#define taille_case 45
///#define nombre_perso 1


void deplacement(BITMAP* terrain, BITMAP* buffer)
{
    BITMAP* image_joueur[32];

    image_joueur[0] = load_bitmap("player/player1.bmp", NULL);
    image_joueur[1] = load_bitmap("player/player2.bmp", NULL);
    image_joueur[2] = load_bitmap("player/player3.bmp", NULL);
    image_joueur[3] = load_bitmap("player/player4.bmp", NULL);
    image_joueur[4] = load_bitmap("player/player5.bmp", NULL);
    image_joueur[5] = load_bitmap("player/player6.bmp", NULL);
    image_joueur[6] = load_bitmap("player/player7.bmp", NULL);
    image_joueur[7] = load_bitmap("player/player8.bmp", NULL);

    for (int test=0; test<8; test++)
    {
        if (image_joueur[test]==NULL)
        {
            allegro_message("Pas l'image %d", test);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    int posx=8*50-image_joueur[2]->w/2;
    int posy=9*28-image_joueur[2]->h/2;

    blit(image_joueur[2], buffer, 0 ,0, posx, posy, image_joueur[2]->w, image_joueur[2]->h);

    int clique=0;

    if(mouse_b&1 && mouse_x<posx+3*50 && mouse_x>posx-3*50 && mouse_y<posy+3*50 && mouse_y>posy-3*50)       ///pas de caillon ou autre
    {
            if(mouse_x>posx && mouse_x<posx+3*50 && mouse_y>posy && mouse_y<posy+3*50)
            {
                clique = (mouse_x-posx)/50 + 2;

                for(int n=1; n<=clique; n++)
                {
                    posx=posx+25;
                    posy=posy+14;

                    if(n==1 || n==3)
                    {
                        blit(image_joueur[4], buffer, 0 ,0, posx, posy, image_joueur[4]->w, image_joueur[4]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[5], buffer, 0 ,0, posx, posy, image_joueur[5]->w, image_joueur[5]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }

            if(mouse_x>posx && mouse_x<posx+3*50 && mouse_y<posy && mouse_y>posy-3*50)
            {
                clique = (mouse_x-posx)/50 + 2;

                for(int n=1; n<=clique; n++)
                {
                    posx=posx+25;
                    posy=posy-14;

                    if(n==1 || n==3)
                    {
                        blit(image_joueur[4], buffer, 0 ,0, posx, posy, image_joueur[4]->w, image_joueur[4]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[5], buffer, 0 ,0, posx, posy, image_joueur[5]->w, image_joueur[5]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }
            if(mouse_x<posx && mouse_x>posx-3*50 && mouse_y<posy+3*50 && mouse_y>posy)
            {
                clique = (mouse_x-posx)/50 + 5;

                for(int n=1; n<=clique; n++)
                {
                    posx=posx-25;
                    posy=posy+14;

                    if(n==1 || n==3)
                    {
                        blit(image_joueur[4], buffer, 0 ,0, posx, posy, image_joueur[4]->w, image_joueur[4]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[5], buffer, 0 ,0, posx, posy, image_joueur[5]->w, image_joueur[5]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }
            if(mouse_x<posx && mouse_x>posx-3*50 && mouse_y>posy-3*50 && mouse_y<posy)
            {
                clique = (posx-mouse_x)/50 + 3;

                for(int n=1; n<=clique; n++)
                {
                    posx=posx-25;
                    posy=posy-14;

                    if(n==1 || n==3)
                    {
                        blit(image_joueur[4], buffer, 0 ,0, posx, posy, image_joueur[4]->w, image_joueur[4]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[5], buffer, 0 ,0, posx, posy, image_joueur[5]->w, image_joueur[5]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }
        }
}
