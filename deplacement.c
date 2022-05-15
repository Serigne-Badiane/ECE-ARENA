#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void placement_joueur_debut(BITMAP*buffer,BITMAP*buffer_couleur)
{
    for(int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            switch(matrice_terrain[i][j].placement_debut)
            {
                case 1:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,100,100);
                    break;
                case 2:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,170,100);
                    break;
                case 3:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,100,170);
                    break;
                case 4:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,170,100,100);
                    break;
            }
        }
    }

    for(int a=0;a<4;a++)
    {
        while(play[a].case_ligne==0 || play[a].case_colonne==0)
        {
            for(int i=0;i<LIGNE;i++)
            {
                for(int j=0;j<COLONNE;j++)
                {
                    if (getr(getpixel(buffer_couleur,mouse_x,mouse_y))==getr(getpixel(buffer_couleur,matrice_terrain[i][j].x,matrice_terrain[i][j].y)) && getb(getpixel(buffer_couleur,mouse_x,mouse_y))==getb(getpixel(buffer_couleur,matrice_terrain[i][j].x,matrice_terrain[i][j].y)) && getg(getpixel(buffer_couleur,mouse_x,mouse_y))==getg(getpixel(buffer_couleur,matrice_terrain[i][j].x,matrice_terrain[i][j].y)) && mouse_b & 1)
                    {
                        if (matrice_terrain[i][j].placement_debut==a+1 && matrice_terrain[i][j].passage==1)
                        {
                            case_couleur(buffer, matrice_terrain[i][j].x,matrice_terrain[i][j].y,40,150,78);
                            play[a].case_ligne=i;
                            play[a].case_colonne=j;
                            while (mouse_b & 1)                 ///blindage click gauche
                            {
                                rest(150);
                            }
                            //rest(300);                                      ///sinon trop rapide donc tous les joueurs au meme endroit
                        }
                    }
                }
            }
            draw_sprite(screen, buffer, 0,0);
        }
    }
}

void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* buffer_couleur)
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

    //los = load_bitmap("los.bmp", NULL);

    for (int test=0; test<12; test++)
    {
        if (image_joueur[test]==NULL)
        {
            allegro_message("Pas l'image %d", test);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }


    for(int j=0; j<4; j++)
    {
        blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);

        int i=play[j].case_ligne;
        int p=play[j].case_colonne;

        if(p%2==0)
        {
            for(int o=p+1; o<p+4; o++)
            {
                if(matrice_terrain[i-1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-1][o].x, matrice_terrain[i-1][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-4; o--)
            {
                if(matrice_terrain[i-1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-1][o].x, matrice_terrain[i-1][o].y, 140,140,140);
                }
            }
            for(int o=p+1; o<p+4; o++)
            {
                if(matrice_terrain[i+1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+1][o].x, matrice_terrain[i+1][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-4; o--)
            {
                if(matrice_terrain[i+1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+1][o].x, matrice_terrain[i+1][o].y, 140,140,140);
                }
            }
            for(int o=p+1; o<p+5; o+=2)
            {
                if(matrice_terrain[i+2][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+2][o].x, matrice_terrain[i+2][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-5; o-=2)
            {
                if(matrice_terrain[i+2][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+2][o].x, matrice_terrain[i+2][o].y, 140,140,140);
                }
            }
            for(int o=p+1; o<p+4; o++)
            {
                if(matrice_terrain[i][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i][o].x, matrice_terrain[i][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-4; o--)
            {
                if(matrice_terrain[i][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i][o].x, matrice_terrain[i][o].y, 140,140,140);
                }
            }
                if(matrice_terrain[i-1][p].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-1][p].x, matrice_terrain[i-1][p].y, 140,140,140);
                }
                if(matrice_terrain[i+1][p].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+1][p].x, matrice_terrain[i+1][p].y, 140,140,140);
                }
        }

        else
        {
            for(int o=p; o<p+4; o++)
            {
                if(matrice_terrain[i-1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-1][o].x, matrice_terrain[i-1][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-4; o--)
            {
                if(matrice_terrain[i-1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-1][o].x, matrice_terrain[i-1][o].y, 140,140,140);
                }
            }
            for(int o=p+1; o<p+5; o+=2)
            {
                if(matrice_terrain[i-2][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-2][o].x, matrice_terrain[i-2][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-5; o-=2)
            {
                if(matrice_terrain[i-2][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i-2][o].x, matrice_terrain[i-2][o].y, 140,140,140);
                }
            }
            for(int o=p+1; o<p+4; o++)
            {
                if(matrice_terrain[i][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i][o].x, matrice_terrain[i][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-4; o--)
            {
                if(matrice_terrain[i][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i][o].x, matrice_terrain[i][o].y, 140,140,140);
                }
            }
            for(int o=p; o<p+4; o++)
            {
                if(matrice_terrain[i+1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+1][o].x, matrice_terrain[i+1][o].y, 140,140,140);
                }
            }
            for(int o=p-1; o>p-4; o--)
            {
                if(matrice_terrain[i+1][o].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i+1][o].x, matrice_terrain[i+1][o].y, 140,140,140);
                }
            }
        }
    }
}

void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur)
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
    for(int i=0;i<LIGNE;i++)
    {
        for(int t=0; t<COLONNE; t++)
        {
            if (getr(getpixel(buffer,mouse_x,mouse_y))==140 && getb(getpixel(buffer,mouse_x,mouse_y))==140 && getg(getpixel(buffer,mouse_x,mouse_y))==140 && mouse_b&1)
            {
                if(getr(getpixel(buffer_couleur,mouse_x,mouse_y))==getr(getpixel(buffer_couleur,matrice_terrain[i][t].x,matrice_terrain[i][t].y)) && getb(getpixel(buffer_couleur,mouse_x,mouse_y))==getb(getpixel(buffer_couleur,matrice_terrain[i][t].x,matrice_terrain[i][t].y)) && getg(getpixel(buffer_couleur,mouse_x,mouse_y))==getg(getpixel(buffer_couleur,matrice_terrain[i][t].x,matrice_terrain[i][t].y)))
                {
                /*while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].y<matrice_terrain[i][t].y)
                {
                    matrice_terrain[play[j].case_ligne][play[j].case_colonne].y+=matrice_terrain[0][0].hauteur;
                    blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                    rest(300);
                }
                while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].x<matrice_terrain[i][t].x)
                {
                    matrice_terrain[play[j].case_ligne][play[j].case_colonne].x+=matrice_terrain[0][0].largeur;
                    blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                    rest(200);
                }
                while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].y>matrice_terrain[i][t].y)
                {
                    matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-=matrice_terrain[0][0].hauteur;
                    blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                    rest(200);
                }
                while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].x>matrice_terrain[i][t].x)
                {
                    matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-=matrice_terrain[0][0].largeur;
                    blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                    rest(200);
                }*/
                blit(image_joueur[2], buffer, 0 ,0, matrice_terrain[i][t].x-image_joueur[2]->w/2, matrice_terrain[i][t].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                }
            }
        }
    }
}
