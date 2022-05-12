#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
<<<<<<< Updated upstream
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 713, 0,0)!=0)         ///1272,713
=======
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1272,713,0,0)!=0)
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    BITMAP* ciel = load_bitmap("ciel.bmp", NULL);

    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int nbrjoueur = 4;
    BITMAP* bdf = load_bitmap("bdf.bmp",NULL);
    BITMAP* tir_explosif = load_bitmap("tir_explosif.bmp",NULL);
    BITMAP* feu_oku= load_bitmap("feu_oku.bmp",NULL);
    BITMAP* cac_feu= load_bitmap("cac_feu.bmp",NULL);
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* player [nbrjoueur];
    player [0] = create_bitmap(SCREEN_W, SCREEN_H);
    str_perso joueur [nbrjoueur];

    init_struct_case();

<<<<<<< Updated upstream
=======
    //init_perso();
>>>>>>> Stashed changes

    while (!key[KEY_ESC])
    {
        affichage_terrain(terrain,buffer);
        deplacement(terrain,buffer);
<<<<<<< Updated upstream
        init_joueur(nbrjoueur,joueur);
        /*for (int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                case_couleur(buffer,terrain,matrice_terrain[i][j].x,matrice_terrain[i][j].y);
            }
        }*/
        quadrillage(buffer,terrain);
        affichagesort(buffer,bdf,tir_explosif,feu_oku,cac_feu,coeurpv,joueur);
=======
>>>>>>> Stashed changes
        draw_sprite(screen, buffer, 0,0);
    }
    return 0;

}END_OF_MAIN();
