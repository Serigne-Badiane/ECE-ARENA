#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>
#define taille_case 45
#define nombre_perso 1


void init_perso()                                                                                       /// INITIALISATION DES POSITIONS DES JOUEURS
{
    int fin=0;
    int a,b;

    if(mouse_b&1 && fin==0)
    {
        a=mouse_x/26;
        b=mouse_y/32;

        for (int var=0; var<1; var++)
        {
            acteur[var].x = matrice_terrain[b][a].x;
            acteur[var].y = matrice_terrain[b][a].y;
        }
    }
}



void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* ciel)                                                       /// DEPLACEMENT DES JOUEURS
{
    BITMAP* image_joueur[nombre_perso*8];

    BITMAP* image_deplacement;
    image_deplacement = load_bitmap("deplacement.bmp", NULL);

    int nombre_joueurs = nombre_perso;
    int var;

    image_joueur[0] = load_bitmap("player/player1.bmp", NULL);
    image_joueur[1] = load_bitmap("player/player2.bmp", NULL);
    image_joueur[2] = load_bitmap("player/player3.bmp", NULL);
    image_joueur[3] = load_bitmap("player/player4.bmp", NULL);
    image_joueur[4] = load_bitmap("player/player5.bmp", NULL);
    image_joueur[5] = load_bitmap("player/player6.bmp", NULL);
    image_joueur[6] = load_bitmap("player/player7.bmp", NULL);
    image_joueur[7] = load_bitmap("player/player8.bmp", NULL);

    //image_joueur[1] = load_bitmap("test2.bmp", NULL);
    //image_joueur[2] = load_bitmap("MARCHER11.bmp", NULL);
    //image_joueur[3] = load_bitmap("MARCHER12.bmp", NULL);

    for (var=0; var<nombre_joueurs*8; var++)
    {
        if (image_joueur[var]==NULL)
        {
            allegro_message("Pas l'image %d", var);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    int o,z;

    for (var=0; var<nombre_joueurs; var++)
    {
        blit(image_joueur[2], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);

        for (int j=1; j<3; j++)
        {
            /*blit(image_deplacement, buffer, 0 ,0, acteur[var].x+j*45, acteur[var].y+j*23, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x, acteur[var].y+j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-j*45, acteur[var].y, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x, acteur[var].y-j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+j*45, acteur[var].y-j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+j*45, acteur[var].y+j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-j*45, acteur[var].y-j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-j*45, acteur[var].y+j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+1*45, acteur[var].y-j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-1*45, acteur[var].y-j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-j*45, acteur[var].y+1*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-j*45, acteur[var].y-1*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+j*45, acteur[var].y+1*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+j*45, acteur[var].y-1*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+1*45, acteur[var].y+j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-1*45, acteur[var].y+j*45, image_deplacement->h, image_deplacement->w);*/
        }


        o = mouse_x/*/taille_case*/;
        z = mouse_y/*/taille_case*/;

        /*if(o<acteur[var].x+4*taille_case && o>acteur[var].x-3*taille_case && z<acteur[var].y+4*taille_case && z>acteur[var].y-3*taille_case)
        {
            blit(image_deplacement, buffer, 0 ,0, o-20, z-20, image_deplacement->h, image_deplacement->w);
        }*/


        if(mouse_b&1 && mouse_x<acteur[var].x+3*matrice_terrain[0][0].largeur && mouse_x>acteur[var].x-3*matrice_terrain[0][0].largeur && mouse_y<acteur[var].y+3*matrice_terrain[0][0].hauteur && mouse_x>acteur[var].y-3*matrice_terrain[0][0].hauteur)       ///remplacer 3 par characteristique perso && pas de caillon ou autre : caillou()==0 & remplacer 5 par possibilité deplacement                                                                                   ///mettre condition du deplacement
        {
            if(acteur[var].x<o && z<=acteur[var].y+taille_case && z>=acteur[var].y)
            {
                while(acteur[var].x<o && acteur[var].y<z)
                {
                    acteur[var].x=acteur[var].x+taille_case;
                    acteur[var].y=acteur[var].y+23;
                    if(acteur[var].x%2==0)
                    {
                        blit(image_joueur[4], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[5], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }

                }
            }
            if(acteur[var].y<z && o<=acteur[var].x+taille_case && o>=acteur[var].x)
            {
                while(acteur[var].y<z)
                {
                    acteur[var].y=acteur[var].y+taille_case;
                    if(acteur[var].x%2==0)
                    {
                        blit(image_joueur[2], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[3], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }
            if(acteur[var].x>o && z<=acteur[var].y+taille_case && z>=acteur[var].y)
            {
                while(acteur[var].x>o)
                {
                    acteur[var].x=acteur[var].x-taille_case;
                    if(acteur[var].x%2==0)
                    {
                        blit(image_joueur[0], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[1], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }
            if(acteur[var].y>z && o<=acteur[var].x+taille_case && o>=acteur[var].x)
            {
                while(acteur[var].y>z)
                {
                    acteur[var].y=acteur[var].y-taille_case;
                    if(acteur[var].x%2==0)
                    {
                        blit(image_joueur[6], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                    else
                    {
                        blit(image_joueur[7], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                        draw_sprite(screen, buffer, 0,0);
                        rest(500);
                    }
                }
            }
        }
    }

}
