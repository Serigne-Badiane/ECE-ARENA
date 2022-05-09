#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT,1280,720,0,0)!=0)
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
    //menu();
    srand(time(NULL));
    initialisation();

    BITMAP* terrain= load_bitmap("terrain_normal_grand.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    init_struct_case();

    init_perso();

    while (!key[KEY_ESC])
    {
        //menu();
        affichage_terrain(terrain,buffer);
        deplacement(terrain,buffer);
        draw_sprite(screen, buffer, 0,0);
    }

    return 0;

}END_OF_MAIN();
