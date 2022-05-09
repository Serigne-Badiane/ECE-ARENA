#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>
#define taille_case 45
#define nombre_perso 2


void init_perso()                                                                                       /// INITIALISATION DES POSITIONS DES JOUEURS
{
    int nombre_joueurs = nombre_perso;
    int posa, posb;


    for (int var=0; var<nombre_joueurs; var++)
    {
        posa = rand()%(12);                                                                             /// RAND OU INITIALISATION ???
        posb = rand()%(18);

        acteur[var].x = matrice_terrain[posa][posb].x;
        acteur[var].y = matrice_terrain[posa][posb].y;
    }
}



void deplacement(BITMAP* terrain, BITMAP* buffer)                                                       /// DEPLACEMENT DES JOUEURS
{
    BITMAP* image_joueur[nombre_perso];

    BITMAP* image_deplacement;
    image_deplacement = load_bitmap("carre deplacement.bmp", NULL);

    int nombre_joueurs = nombre_perso;
    int var;

    image_joueur[0] = load_bitmap("perso1.bmp", NULL);
    image_joueur[1] = load_bitmap("perso2.bmp", NULL);

    for (var=0; var<nombre_joueurs; var++)
    {
        if (image_joueur[var]==NULL)
        {
            allegro_message("Pas l'image %d", var);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    int o,z;
    int compteur;

    for (var=0; var<nombre_joueurs; var++)
    {
        compteur=0;
        blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);

        for (int j=1; j<4; j++)
        {
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x+j*45, acteur[var].y, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x, acteur[var].y+j*45, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x-j*45, acteur[var].y, image_deplacement->h, image_deplacement->w);
            blit(image_deplacement, buffer, 0 ,0, acteur[var].x, acteur[var].y-j*45, image_deplacement->h, image_deplacement->w);
        }

        o = mouse_x/*/taille_case*/;
        z = mouse_y/*/taille_case*/;

        if(acteur[var].x==acteur[var+1].x && acteur[var].y==acteur[var+1].y)
        {
            compteur=1;
        }
        if(acteur[var].x!=acteur[var+1].x && acteur[var].y==acteur[var+1].y)
        {
            compteur=0;
        }
        if(acteur[var].x==acteur[var+1].x && acteur[var].y!=acteur[var+1].y)
        {
            compteur=0;
        }





        if(mouse_b&1 && o<acteur[var].x+4*taille_case && o>acteur[var].x-3*taille_case && z<acteur[var].y+4*taille_case && z>acteur[var].y-3*taille_case && compteur==0)       ///pas de caillon ou autre : caillou()==0 & remplacer 5 par possibilité deplacement                                                                                   ///mettre condition du deplacement
        {
            if(acteur[var].x<o && z<=acteur[var].y+taille_case && z>=acteur[var].y)
            {
                while(acteur[var].x<o)
                {
                    acteur[var].x=acteur[var].x+taille_case;
                    blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    draw_sprite(screen, buffer, 0,0);
                }
            }
            if(acteur[var].y<z && o<=acteur[var].x+taille_case && o>=acteur[var].x)
            {
                while(acteur[var].y<z)
                {
                    acteur[var].y=acteur[var].y+taille_case;
                    blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    draw_sprite(screen, buffer, 0,0);
                }
            }
            if(acteur[var].x>o && z<=acteur[var].y+taille_case && z>=acteur[var].y)
            {
                while(acteur[var].x>o)
                {
                    acteur[var].x=acteur[var].x-taille_case;
                    blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    draw_sprite(screen, buffer, 0,0);
                }
            }
            if(acteur[var].y>z && o<=acteur[var].x+taille_case && o>=acteur[var].x)
            {
                while(acteur[var].y>z)
                {
                    acteur[var].y=acteur[var].y-taille_case;
                    blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    draw_sprite(screen, buffer, 0,0);
                }
            }
        }
    }

}
