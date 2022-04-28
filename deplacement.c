#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


void init_perso()
{
    int nombre_joueurs=1;
    /*for (int var=0; var<nombre_joueurs; var++)
    {
        int a=8, b=8;
        matrice_terrain[b][a].x;
        matrice_terrain[b][a].y;
    }*/
    for (int var=0; var<nombre_joueurs; var++)
    {

        acteur[var].x = matrice_terrain[5][5].x;
        acteur[var].y = matrice_terrain[5][5].y;
    }
}



void deplacement(BITMAP* terrain, BITMAP* buffer)
{
    //rectfill(buffer,150,150,250,250, makecol(0,255,255));

    BITMAP* image_joueur[4];

    int nombre_joueurs=1;
    int var;
    image_joueur[0] = load_bitmap("perso1.bmp", NULL);
    //image_joueur[1] = load_bitmap("perso1.bmp", NULL);

    //for (var=0; var<nombre_joueurs; var++)
    //{
        if (image_joueur[0]==NULL)          ///
        {
            allegro_message("Pas d'image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    //}

    //int a=8, b=8;
    int o,z;

        //clear_bitmap(buffer);
        //affichage_terrain(terrain,buffer);

        //int matrice_souris[LIGNE][COLONNE];


        //matrice_souris[i][j];

        //clear_bitmap(buffer);
        //affichage_terrain(terrain,buffer);
        //clear_bitmap(buffer);
        //affichage_terrain(terrain,buffer);

        for (var=0; var<nombre_joueurs; var++)
        {
        //textprintf_ex(buffer,font,500,300,makecol(255,0,0),-1,"PION : %d %d",acteur[var].x , acteur[var].y);
        //textprintf_ex(buffer,font,500,400,makecol(255,0,0),-1,": %d %d",matrice_terrain[5][5].x , matrice_terrain[5][5].y);

        blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);        ///variable de placement initiale a mettre

        o = mouse_x/*/34*/;                                                                                                                             ///taille cases
        z = mouse_y/*/34*/;


        //textprintf_ex(buffer,font,300,300,makecol(255,0,0),1,"SOURIS : %d %d",o,z);
        textprintf_ex(buffer,font,300,400,makecol(255,0,0),-1,"%d %d",mouse_x,mouse_y);
        textprintf_ex(buffer,font,300,500,makecol(255,0,0),-1,"PION : %d %d",acteur[var].x , acteur[var].y);
        //textprintf_ex(buffer,font,500,500,makecol(255,0,0),-1,"mouse : %d %d",o,z);

        if(mouse_b&1 && o<acteur[var].x+5*34 && o>acteur[var].x-5*34 && z<acteur[var].x+5*34 && z>acteur[var].y-5*34)                                                                                             ///mettre condition du deplacement
        {
            if(acteur[var].x<o && z<=acteur[var].y+34 && z>=acteur[var].y)
            {
                while(acteur[var].x<o)
                {
                    acteur[var].x=acteur[var].x+34;
                    //textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    //textprintf_ex(buffer,font,600,400,makecol(255,0,0),-1,"PION : %d %d",acteur[var].x , acteur[var].y);
                    //clear_bitmap(buffer);
                    //affichage_terrain(terrain,buffer);
                    //blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    //textprintf_ex(buffer,font,600,500,makecol(255,0,0),-1,"PION : %d %d",acteur[var].x , acteur[var].y);
                    //rest(50);
                }
            }
            if(acteur[var].y<z && o<=acteur[var].x+34 && o>=acteur[var].x)
            {
                while(acteur[var].y<z)
                {
                    acteur[var].y=acteur[var].y+34;
                    //textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    //textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    //clear_bitmap(buffer);
                    //affichage_terrain(terrain,buffer);
                    //blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }
            if(acteur[var].x>o && z<=acteur[var].y+34 && z>=acteur[var].y)
            {
                while(acteur[var].x>o)
                {
                    acteur[var].x=acteur[var].x-34;
                    //textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    //textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    //clear_bitmap(buffer);
                    //affichage_terrain(terrain,buffer);
                    //blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }
            if(acteur[var].y>z && o<=acteur[var].x+34 && o>=acteur[var].x)
            {
                while(acteur[var].y>z)
                {
                    acteur[var].y=acteur[var].y-34;
                    //textprintf_ex(buffer,font,600,300,makecol(255,0,0),1,"SOURIS 2 : %d %d",o,z);
                    //textprintf_ex(buffer,font,500,300,makecol(255,0,0),1,"PION : %d %d",a,b);
                    //clear_bitmap(buffer);
                    //affichage_terrain(terrain,buffer);
                    //blit(image_joueur[var], buffer, 0 ,0, acteur[var].x, acteur[var].y, image_joueur[var]->w, image_joueur[var]->h);
                    //rest(50);
                }
            }

        }

    }

}
