#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
<<<<<<< HEAD
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0)!=0)
=======
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
>>>>>>> cbb83eac42415189733a97caabc38e0fb35cd62e
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
<<<<<<< HEAD
    BITMAP* ciel = load_bitmap("ciel.bmp", NULL);
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
=======

    BITMAP* terrain= load_bitmap("terrain_normal_grand.bmp", NULL);
>>>>>>> cbb83eac42415189733a97caabc38e0fb35cd62e
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
