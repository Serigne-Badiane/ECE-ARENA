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
    menu();
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    init_struct_case();


    while (!key[KEY_ESC])
    {
        init_perso();
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
        draw_sprite(screen, buffer, 0,0);
    }
    return 0;

}END_OF_MAIN();
