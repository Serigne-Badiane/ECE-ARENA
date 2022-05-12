#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 700, 0,0)!=0)         ///1272,713
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

    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int nbrjoueur = 4;
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* player [nbrjoueur];
    player[0] = create_bitmap(SCREEN_W, SCREEN_H);
    str_perso joueur [nbrjoueur];
    sortperso sortjoueur [nbrjoueur];
    load_cra_feu(&sortjoueur[0]);


    //menu();
    init_struct_case();

    init_depla();

    while (!key[KEY_ESC])
    {

        affichage_terrain(terrain,buffer);
        //chrono(terrain, buffer);
        deplacement(terrain,buffer);
        init_joueur(nbrjoueur,joueur);
        /*for (int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                case_couleur(buffer,terrain,matrice_terrain[i][j].x,matrice_terrain[i][j].y);
            }
        }*/
        quadrillage(buffer,terrain);
        affichagesort(buffer,sortjoueur[0],coeurpv,joueur);
        draw_sprite(screen, buffer, 0,0);
    }
    return 0;

}END_OF_MAIN();
