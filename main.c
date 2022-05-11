#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 713, 0,0)!=0)         ///1272,713
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
    show_mouse(screen);
}

int main()
{
    srand(time(NULL));
    initialisation();
    //menu();
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int nbrjoueur = 4;
    BITMAP* bdf = load_bitmap("bdf.bmp",NULL);
    BITMAP* tir_explosif = load_bitmap("tir_explosif.bmp",NULL);
    BITMAP* feu_oku= load_bitmap("feu_oku.bmp",NULL);
    BITMAP* cac_feu= load_bitmap("cac_feu.bmp",NULL);
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    init_struct_case();
    BITMAP* player [nbrjoueur];
    player [0] = create_bitmap(SCREEN_W, SCREEN_H);
    str_perso joueur [nbrjoueur];
    while (!key[KEY_ESC])
    {
        init_perso();
        init_joueur(nbrjoueur,joueur);
        affichage_terrain(terrain,buffer);
        deplacement(terrain,buffer);
        for (int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                textprintf_ex(buffer,font,matrice_terrain[i][j].x-13,matrice_terrain[i][j].y-7,makecol(0,0,0),-1,"%d %d",i,j);
            }
        }
        quadrillage(buffer,terrain);
        affichagesort(buffer,bdf,tir_explosif,feu_oku,cac_feu,coeurpv,joueur);

        draw_sprite(screen, buffer, 0,0);
    }
    return 0;

}END_OF_MAIN();
