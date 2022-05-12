#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


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

    image_joueur[8] = load_bitmap("player/player9.bmp", NULL);
    image_joueur[9] = load_bitmap("player/player10.bmp", NULL);
    image_joueur[10] = load_bitmap("player/player11.bmp", NULL);
    image_joueur[11] = load_bitmap("player/player12.bmp", NULL);

    for (int test=0; test<12; test++)
    {
        if (image_joueur[test]==NULL)
        {
            allegro_message("Pas l'image %d", test);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    int a=0;

    blit(image_joueur[2], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
    circlefill(buffer,play[0].x,play[0].y, 3, makecol(255,255,255));

    if(mouse_x>=play[0].x-1*50+25 && mouse_x<=play[0].x+1*50+25 && mouse_y>=play[0].y-28-28 && mouse_y<=play[0].y+28+28)
    {
        circlefill(buffer, mouse_x, mouse_y, 15, makecol(255,255,255));
    }

    if(mouse_b&1 && mouse_x>=play[0].x && mouse_x<=play[0].x+3*50+25 && mouse_y>=play[0].y && mouse_y<=play[0].y+28+28)
    {
        while(play[0].x<mouse_x && play[0].y<mouse_y)
        {
            a++;
            play[0].x=play[0].x+25;
            play[0].y=play[0].y+14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);

            if(a%2==0)
            {
                blit(image_joueur[4], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[4]->w, image_joueur[4]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[5], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[5]->w, image_joueur[5]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }
    if(mouse_b&1 && mouse_x>play[0].x-3*50-25 && mouse_x<play[0].x && mouse_y>play[0].y && mouse_y<play[0].y+28+14)
    {
        while(play[0].x>mouse_x && play[0].y<mouse_y)
        {
            a++;
            play[0].x=play[0].x-25;
            play[0].y=play[0].y+14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);


            if(a%2==0)
            {
                blit(image_joueur[0], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[4]->w, image_joueur[4]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[1], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[5]->w, image_joueur[5]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }
    if(mouse_b&1 && mouse_x>play[0].x && mouse_x<play[0].x+3*50+25 && mouse_y<play[0].y && mouse_y>play[0].y-28-14)
    {
        while(play[0].x<mouse_x && play[0].y>mouse_y)
        {
            a++;
            play[0].x=play[0].x+25;
            play[0].y=play[0].y-14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);

            if(a%2==0)
            {
                blit(image_joueur[4], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[4]->w, image_joueur[4]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[5], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[5]->w, image_joueur[5]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }
    if(mouse_b&1 && mouse_x<play[0].x && mouse_x>play[0].x-3*50-25 && mouse_y<play[0].y && mouse_y>play[0].y-28-14)
    {
        while(play[0].x>mouse_x && play[0].y>mouse_y)
        {
            a++;
            play[0].x=play[0].x-25;
            play[0].y=play[0].y-14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);

            if(a%2==0)
            {
                blit(image_joueur[0], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[4]->w, image_joueur[4]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[1], buffer, 0 ,0, play[0].x-image_joueur[2]->w/2, play[0].y-image_joueur[2]->h, image_joueur[5]->w, image_joueur[5]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }


    if(mouse_x>=play[1].x-1*50+25 && mouse_x<=play[1].x+1*50+25 && mouse_y>=play[1].y-28-28 && mouse_y<=play[1].y+28+28)
    {
        circlefill(buffer, mouse_x, mouse_y, 15, makecol(255,255,255));
    }

    blit(image_joueur[8], buffer, 0 ,0, play[1].x-image_joueur[8]->w/2, play[1].y-image_joueur[8]->h, image_joueur[8]->w, image_joueur[8]->h);
    circlefill(buffer,play[1].x,play[1].y, 3, makecol(255,255,255));

    if(mouse_b&1 && mouse_x>=play[1].x && mouse_x<=play[1].x+3*50+25 && mouse_y>=play[1].y && mouse_y<=play[1].y+28+28)
    {
        while(play[1].x<mouse_x && play[1].y<mouse_y)
        {
            a++;
            play[1].x=play[1].x+25;
            play[1].y=play[1].y+14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);

            if(a%2==0)
            {
                blit(image_joueur[8], buffer, 0 ,0, play[1].x-image_joueur[8]->w/2, play[1].y-image_joueur[8]->h, image_joueur[8]->w, image_joueur[8]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[9], buffer, 0 ,0, play[1].x-image_joueur[9]->w/2, play[1].y-image_joueur[9]->h, image_joueur[9]->w, image_joueur[9]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
        }
    }
    if(mouse_b&1 && mouse_x>play[1].x-3*50-25 && mouse_x<play[1].x && mouse_y>play[1].y && mouse_y<play[1].y+28+14)
    {
        while(play[1].x>mouse_x && play[1].y<mouse_y)
        {
            a++;
            play[1].x=play[1].x-25;
            play[1].y=play[1].y+14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);


            if(a%2==0)
            {
                blit(image_joueur[10], buffer, 0 ,0, play[1].x-image_joueur[10]->w/2, play[1].y-image_joueur[10]->h, image_joueur[10]->w, image_joueur[10]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[11], buffer, 0 ,0, play[1].x-image_joueur[11]->w/2, play[1].y-image_joueur[11]->h, image_joueur[11]->w, image_joueur[11]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }
    if(mouse_b&1 && mouse_x>play[1].x && mouse_x<play[1].x+3*50+25 && mouse_y<play[1].y && mouse_y>play[1].y-28-14)
    {
        while(play[1].x<mouse_x && play[1].y>mouse_y)
        {
            a++;
            play[1].x=play[1].x+25;
            play[1].y=play[1].y-14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);

            if(a%2==0)
            {
                blit(image_joueur[8], buffer, 0 ,0, play[1].x-image_joueur[8]->w/2, play[1].y-image_joueur[8]->h, image_joueur[8]->w, image_joueur[8]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[9], buffer, 0 ,0, play[1].x-image_joueur[9]->w/2, play[1].y-image_joueur[9]->h, image_joueur[9]->w, image_joueur[9]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }
    if(mouse_b&1 && mouse_x<play[1].x && mouse_x>play[1].x-3*50-25 && mouse_y<play[1].y && mouse_y>play[1].y-28-14)
    {
        while(play[1].x>mouse_x && play[1].y>mouse_y)
        {
            a++;
            play[1].x=play[1].x-25;
            play[1].y=play[1].y-14;
            clear_bitmap(buffer);
            affichage_terrain(terrain,buffer);

            if(a%2==0)
            {
                blit(image_joueur[10], buffer, 0 ,0, play[1].x-image_joueur[10]->w/2, play[1].y-image_joueur[10]->h, image_joueur[10]->w, image_joueur[10]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }
            else
            {
                blit(image_joueur[11], buffer, 0 ,0, play[1].x-image_joueur[11]->w/2, play[1].y-image_joueur[11]->h, image_joueur[11]->w, image_joueur[11]->h);
                draw_sprite(screen, buffer, 0,0);
                rest(500);
            }

        }
    }



}
