#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
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
<<<<<<< Updated upstream
    menu();
    BITMAP* ciel = load_bitmap("ciel.bmp", NULL);
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

=======
    //menu();
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    int nbrjoueur = 4;
    //BITMAP* terrain= load_bitmap("terrain_normal_grand.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* bdf = load_bitmap("bdf.bmp",NULL);
    BITMAP* tir_explosif = load_bitmap("tir_explosif.bmp",NULL);
    BITMAP* feu_oku= load_bitmap("feu_oku.bmp",NULL);
    BITMAP* cac_feu= load_bitmap("cac_feu.bmp",NULL);
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* perso [nbrjoueur];
>>>>>>> Stashed changes
    init_struct_case();
    str_perso joueur [nbrjoueur];

    init_perso();
    init_joueur(nbrjoueur,joueur);

    while (!key[KEY_ESC])
    {
<<<<<<< Updated upstream
        affichage_terrain(terrain,buffer,ciel);
        deplacement(terrain,buffer);
=======
        affichage_terrain(terrain,buffer);
        deplacement(terrain,buffer);
        case_couleur(buffer,terrain,matrice_terrain[8][10].x,matrice_terrain[8][10].y);
        affichagesort(buffer,bdf,tir_explosif,feu_oku,cac_feu,coeurpv,joueur);

>>>>>>> Stashed changes
        draw_sprite(screen, buffer, 0,0);
    }

    return 0;

}END_OF_MAIN();
