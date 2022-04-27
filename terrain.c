#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
    show_mouse(screen);
}

void init_struct_case()
{
    matrice_terrain[0][0].hauteur=23;
    matrice_terrain[0][0].largeur=40;
    matrice_terrain[0][0].x=-4;
    matrice_terrain[0][0].y=13;
    matrice_terrain[0][0].type=rand()%(5-1)+1;
    for (int i=1;i<18;i++)
    {
        matrice_terrain[i][0].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[i][0].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[i][0].x=matrice_terrain[i-1][0].x+(2*matrice_terrain[i][0].largeur);
        matrice_terrain[i][0].y=matrice_terrain[0][0].y;
        matrice_terrain[i][0].type=rand()%(5-1)+1;
    }
    for (int j=1;j<20;j++)
    {
        matrice_terrain[0][j].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[0][j].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[0][j].x=matrice_terrain[0][0].x;
        matrice_terrain[0][j].y=matrice_terrain[0][j-1].y+(2*matrice_terrain[0][j].hauteur);
        matrice_terrain[0][j].type=rand()%(5-1)+1;
    }
    for (int i=1;i<18;i++)
    {
        for(int j=1;j<20;j++)
        {
            matrice_terrain[i][j].hauteur=matrice_terrain[0][0].hauteur;
            matrice_terrain[i][j].largeur=matrice_terrain[0][0].largeur;
            matrice_terrain[i][j].x=matrice_terrain[i-1][j].x+(2*matrice_terrain[i][j].largeur);
            matrice_terrain[i][j].y=matrice_terrain[i][j-1].y+(2*matrice_terrain[i][j].hauteur);
            matrice_terrain[i][j].type=rand()%(5-1)+1;
        }
    }
}

void affichage_terrain()
{
    BITMAP* terrain= load_bitmap("terrain_iso.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    while (!key[KEY_ESC])
    {
        blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        for (int i=0;i<18;i++)
        {
            for(int j=0;j<20;j++)
            {
                textprintf_ex(buffer,font,matrice_terrain[i][j].x,matrice_terrain[i][j].y,makecol(0,0,0),-1,".");
                /*switch (matrice_terrain[i][j].type)
                {
                     case 1:
                }*/
            }
        }
        draw_sprite(screen, buffer, 0,0);
    }
}

//void case_terre()
