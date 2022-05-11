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

    int posx=8*50;
    int posy=9*28-14;

    blit(image_joueur[2], buffer, 0 ,0, posx-image_joueur[2]->w/2, posy-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
    circlefill(buffer,posx,posy, 10, makecol(255,255,255));

    if(mouse_b&1 && mouse_x>posx && mouse_x<posx+3*50+25 && mouse_y>posy-14 && mouse_y<posy+14)          ///&& mouse_y>posy && mouse_y<posy+3*28+14
    {
        circlefill(buffer,10,20, 10, makecol(255,255,255));
        while(mouse_x<posx)
        {
            if()
            {
                posx=posx+50;
                posy=posy+14;
                blit(image_joueur[4], buffer, 0 ,0, posx-image_joueur[2]->w/2, posy-image_joueur[2]->h, image_joueur[4]->w, image_joueur[4]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                posx=posx+50;
                posy=posy-14;
                blit(image_joueur[5], buffer, 0 ,0, posx-image_joueur[2]->w/2, posy-image_joueur[2]->h, image_joueur[5]->w, image_joueur[5]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
        }

    }

    /*if(mouse_b&1 && mouse_x<posx+3*50+25 && mouse_x>posx-3*50+25 && mouse_y<posy+3*28+14 && mouse_y>posy-3*28+14)       ///pas de caillon ou autre
    {
        circlefill(buffer,10,10, 10, makecol(255,255,255));

            if(mouse_b&1 && mouse_x>posx && mouse_x<posx+3*50+25 && mouse_y>posy-14 && mouse_y<posy-14)          ///&& mouse_y>posy && mouse_y<posy+3*28+14
            {
                circlefill(buffer,10,20, 10, makecol(255,255,255));
                while(mouse_x!=posx && mouse_y!=posy)
                {
                    a++;
                    if(a%2==0)
                    {
                        posx=posx+50;
                        posy=posy+14;
                        blit(image_joueur[4], buffer, 0 ,0, posx, posy, image_joueur[4]->w, image_joueur[4]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        posx=posx+50;
                        posy=posy-14;
                        blit(image_joueur[5], buffer, 0 ,0, posx, posy, image_joueur[5]->w, image_joueur[5]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }

            }

            if(mouse_x>posx && mouse_x<posx+3*50 && mouse_y<posy && mouse_y>posy-3*50)
            {
                clique = (mouse_x-posx)/50;

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
                clique = (mouse_x-posx)/50;

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
                clique = (posx-mouse_x)/50;

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
        }*/
}
