#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


void init_struct_case()
{
    matrice_terrain[0][0].hauteur=34;
    matrice_terrain[0][0].largeur=34;
    matrice_terrain[0][0].x=0;
    matrice_terrain[0][0].y=0;
    matrice_terrain[0][0].type=rand()%(6-1)+1;
    for (int i=1;i<LIGNE;i++)
    {
        matrice_terrain[i][0].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[i][0].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[i][0].x=matrice_terrain[0][0].x;
        matrice_terrain[i][0].y=matrice_terrain[i-1][0].y+(matrice_terrain[i][0].hauteur);
        matrice_terrain[i][0].type=rand()%(6-1)+1;
    }
    for (int j=1;j<COLONNE;j++)
    {
        matrice_terrain[0][j].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[0][j].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[0][j].x=matrice_terrain[0][j-1].x+(matrice_terrain[0][j].largeur);
        matrice_terrain[0][j].y=matrice_terrain[0][0].y;
        matrice_terrain[0][j].type=rand()%(6-1)+1;
    }
    for (int i=1;i<LIGNE;i++)
    {
        for(int j=1;j<COLONNE;j++)
        {
            matrice_terrain[i][j].hauteur=matrice_terrain[0][0].hauteur;
            matrice_terrain[i][j].largeur=matrice_terrain[0][0].largeur;
            matrice_terrain[i][j].x=matrice_terrain[i][j-1].x+(matrice_terrain[i][j].largeur);
            matrice_terrain[i][j].y=matrice_terrain[i-1][j].y+(matrice_terrain[i][j].hauteur);
            matrice_terrain[i][j].type=rand()%(6-1)+1;
        }
    }
}

void affichage_terrain(BITMAP* terrain, BITMAP* buffer)
{

    BITMAP* type_case[5];
    type_case[0]=load_bitmap("terre.bmp", NULL);
    type_case[1]=load_bitmap("mer.bmp", NULL);
    type_case[2]=load_bitmap("montagne.bmp", NULL);
    type_case[3]=load_bitmap("sable.bmp", NULL);
    type_case[4]=load_bitmap("arbre.bmp", NULL);

        blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        for (int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                textprintf_ex(buffer,font,matrice_terrain[i][j].x,matrice_terrain[i][j].y,makecol(0,0,0),-1,".");
                switch (matrice_terrain[i][j].type)
                {
                    case 1:
                        blit(type_case[0],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                        break;
                    case 2:
                        blit(type_case[1],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                        break;
                    case 3:
                        blit(type_case[2],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                        break;
                    case 4:
                        blit(type_case[3],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                        break;
                    case 5:
                        blit(type_case[4],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                        break;
                }
            }
        }
        //draw_sprite(screen, buffer, 0,0);
}

void case_terre(int pos_x, int pos_y, BITMAP* buffer)
{
    for(int i=0;i<matrice_terrain[0][0].largeur;i++)
    {
        for(int j=0;j<matrice_terrain[0][0].hauteur;j++)
        {
            float rougeG= 91-(0.01*pos_x)+(0.01*pos_y);
            float vertG= 121+(0.01*pos_x)-(0.01*pos_y);
            float bleuG= 42-(0.01*pos_x)+(0.01*pos_y);
            putpixel(buffer,pos_x+i,pos_y+j,makecol(rougeG,vertG,bleuG));
        }
    }
}
