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
    menu();
    BITMAP* ciel = load_bitmap("ciel.bmp", NULL);
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    init_struct_case();

    init_perso();

    while (!key[KEY_ESC])
    {
        affichage_terrain(terrain,buffer,ciel);
        deplacement(terrain,buffer);
        draw_sprite(screen, buffer, 0,0);
    }

    return 0;

}END_OF_MAIN();
