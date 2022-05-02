#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

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

void case_arbre(int pos_x, int pos_y, BITMAP* buffer, BITMAP* type_case)
{
    int changement_couleur[3], couleur_pixel, ancienne_couleur[3][type_case->w][type_case->h], ancienne_couleur_pixel;
    for(int i=pos_x-55;i<pos_x-55+type_case->w;i++)
    {
        for(int j=pos_y-70;j<pos_y-70+type_case->h;j++)
        {
            ancienne_couleur_pixel=getpixel(buffer,i,j);
            ancienne_couleur[0][i-pos_x+55][j-pos_y+70]=getr(ancienne_couleur_pixel);
            ancienne_couleur[1][i-pos_x+55][j-pos_y+70]=getb(ancienne_couleur_pixel);
            ancienne_couleur[2][i-pos_x+55][j-pos_y+70]=getg(ancienne_couleur_pixel);
        }
    }
    blit(type_case,buffer,0,0,pos_x-55,pos_y-70,SCREEN_W,SCREEN_H);
    for(int i=0;i<type_case->w;i++)
    {
        for(int j=0;j<type_case->h;j++)
        {
            couleur_pixel= getpixel(type_case,i,j);
            changement_couleur[0]=getr(couleur_pixel);
            changement_couleur[1]=getb(couleur_pixel);
            changement_couleur[2]=getg(couleur_pixel);
            if (changement_couleur[0]>30 && changement_couleur[0]<35 && changement_couleur[1]>30 && changement_couleur[1]<35 && changement_couleur[2]>30 && changement_couleur[2]<35)
            {
                putpixel(buffer,pos_x+i-55,pos_y+j-70,makecol(ancienne_couleur[0][i][j],ancienne_couleur[2][i][j],ancienne_couleur[1][i][j]));
            }
        }
    }
    //blit(type_case,buffer,0,0,pos_x-55,pos_y-70,SCREEN_W,SCREEN_H);
}

void init_struct_case()
{
    matrice_terrain[0][0].hauteur=45;
    matrice_terrain[0][0].largeur=45;
    matrice_terrain[0][0].x=0;
    matrice_terrain[0][0].y=0;
    matrice_terrain[0][0].type=rand()%(6-1)+1;
    if (matrice_terrain[0][0].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
    {
        matrice_terrain[0][0].passage==1;
    }
    else
        matrice_terrain[0][0].passage==0;
    for (int i=1;i<LIGNE;i++)
    {
        matrice_terrain[i][0].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[i][0].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[i][0].x=matrice_terrain[0][0].x;
        matrice_terrain[i][0].y=matrice_terrain[i-1][0].y+(matrice_terrain[i][0].hauteur);
        matrice_terrain[i][0].type=rand()%(6-1)+1;
        if (matrice_terrain[i][0].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
        {
            matrice_terrain[i][0].passage==1;
        }
        else
            matrice_terrain[i][0].passage==0;
    }
    for (int j=1;j<COLONNE;j++)
    {
        matrice_terrain[0][j].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[0][j].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[0][j].x=matrice_terrain[0][j-1].x+(matrice_terrain[0][j].largeur);
        matrice_terrain[0][j].y=matrice_terrain[0][0].y;
        matrice_terrain[0][j].type=rand()%(6-1)+1;
        if (matrice_terrain[0][j].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
        {
            matrice_terrain[0][j].passage==1;
        }
        else
            matrice_terrain[0][j].passage==0;
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
            if (matrice_terrain[i][j].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
            {
                matrice_terrain[i][j].passage==1;
            }
            else
                matrice_terrain[i][j].passage==0;
        }
    }
}

void affichage_terrain(BITMAP* terrain, BITMAP* buffer)
{

    BITMAP* type_case[5];
    type_case[0]=load_bitmap("herbe.bmp", NULL);
    type_case[1]=load_bitmap("mer.bmp", NULL);
    type_case[2]=load_bitmap("montagne.bmp", NULL);
    type_case[3]=load_bitmap("sable.bmp", NULL);
    type_case[4]=load_bitmap("arbre_dofus.bmp", NULL);

        blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        for (int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                switch (matrice_terrain[i][j].type)
                {
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
                        blit(type_case[0],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                        break;

                }
            }
        }
        for (int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                if (matrice_terrain[i][j].type==1)
                {
                    case_arbre(matrice_terrain[i][j].x,matrice_terrain[i][j].y,buffer,type_case[4]);
                }
            }
        }
        //draw_sprite(screen, buffer, 0,0);
}
