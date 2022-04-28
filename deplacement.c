#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


/*void init_perso()
{
    int nombre_joueurs=1;
    for (int var=0; var<nombre_joueurs; var++)
    {
        int a=8, b=8;
        matrice_terrain[b][a].x;
        matrice_terrain[b][a].y;
    }

}*/



void deplacement(BITMAP* terrain, BITMAP* buffer)
{
    //rectfill(buffer,150,150,250,250, makecol(0,255,255));

    BITMAP* image_joueur[4];

    int nombre_joueurs=1;
    int var;
    image_joueur[0] = load_bitmap("perso1.bmp", NULL);
    //image_joueur[1] = load_bitmap("perso1.bmp", NULL);

    for (var=0; var<nombre_joueurs; var++)
    {
        if (image_joueur[var]==NULL)
        {
            allegro_message("Pas d'image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    int a=8, b=8;
    int o,z;
    for (var=0; var<nombre_joueurs; var++)
    {

        blit(image_joueur[var], buffer, 0 ,0, matrice_terrain[b][a].x, matrice_terrain[b][a].y, image_joueur[var]->w, image_joueur[var]->h);        ///variable de placement initiale a mettre
        o = mouse_x/34;
        z = mouse_y/34;
        //int matrice_souris[LIGNE][COLONNE];
        textprintf_ex(buffer,font,300,300,makecol(255,0,0),1,"SOURIS : %d %d",o,z);
        //textprintf_ex(buffer,font,400,300,makecol(255,0,0),-1,"%d %d",mouse_x,mouse_y);
        textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);

        //matrice_souris[i][j];

        if(mouse_b&1 && o<a+5 && o>a-5 && z<b+5 && z>b-5)                                                                   ///mettre condition du deplacement
        {
            if(a<o && b==z)
            {
                while(a<o)
                {
                    a++;
                    textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    clear_bitmap(buffer);
                    affichage_terrain(terrain,buffer);
                    blit(image_joueur[var], buffer, 0 ,0, matrice_terrain[b][a].x, matrice_terrain[b][a].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }
            if(a==o && b<z)
            {
                while(b<z)
                {
                    b++;
                    textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    clear_bitmap(buffer);
                    affichage_terrain(terrain,buffer);
                    blit(image_joueur[var], buffer, 0 ,0, matrice_terrain[b][a].x, matrice_terrain[b][a].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }
            if(a>o && b==z)
            {
                while(a>o)
                {
                    a--;
                    textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    clear_bitmap(buffer);
                    affichage_terrain(terrain,buffer);
                    blit(image_joueur[var], buffer, 0 ,0, matrice_terrain[b][a].x, matrice_terrain[b][a].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }
            if(a==o && b>z)
            {
                while(b>z)
                {
                    b--;
                    textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    clear_bitmap(buffer);
                    affichage_terrain(terrain,buffer);
                    blit(image_joueur[var], buffer, 0 ,0, matrice_terrain[b][a].x, matrice_terrain[b][a].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }
        }

    }

}
