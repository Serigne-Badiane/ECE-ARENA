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
}

void affichage_terrain()
{
    while (!key[KEY_ESC])
    {
        BITMAP* terrain= load_bitmap("terrain_iso.bmp", NULL);
        BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
        blit(terrain,buffer,0,0,mouse_x,mouse_y,SCREEN_W,SCREEN_H);
        draw_sprite(screen, buffer, 0,0);
    }
}

