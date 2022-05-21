#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include "bib.h"

int menu_de_fin(){

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    BITMAP* decor_de_fin = load_bitmap("summonersrift.bmp");
    BITMAP* buffer_decor = create_bitmap(SCREEN_W,SCREEN_H);

    blit(buffer_decor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    blit(decor_de_fin,buffer_decor,0,0,0,0,SCREEN_W,SCREEN_H);


}
