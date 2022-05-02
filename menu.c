#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <allegro.h>

void menu(){

    BITMAP* decor;
    BITMAP* page;
    BITMAP* Logo;


    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    decor=load_bitmap("decordo.bmp",NULL);
    page=create_bitmap(SCREEN_W,SCREEN_H);

    Logo=load_bitmap("Logo.bmp",NULL);

    clear_bitmap(page);
    if (!decor)
    {
        allegro_message("pas pu trouver images/hotplanet.bmp");
        exit(EXIT_FAILURE);
    }

    while (!key[KEY_ESC])
    {
        show_mouse(page);

        rect(page,500,300,850,500,makecol(255,0,0));

        masked_blit(Logo, page, 0, 0, 100, 100, Logo->w, Logo->h);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

    }}
