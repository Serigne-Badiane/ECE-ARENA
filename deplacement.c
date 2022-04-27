#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void deplacement(BITMAP* terrain, BITMAP* buffer)
{
    BITMAP*image;
    image=load_bitmap("perso1.bmp", NULL);
    while (!key[KEY_ESC])
    {
    rectfill(buffer,150,150,250,250, makecol(0,255,255));


    blit(image,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    draw_sprite(screen, buffer, 0,0);
    }
}
