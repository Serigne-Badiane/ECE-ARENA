#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280,700,0,0)!=0)
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
    BITMAP* ciel = load_bitmap("ciel.bmp", NULL);
    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);

    //BITMAP* terrain= load_bitmap("terrain_normal_grand.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
     BITMAP* bdf = load_bitmap("bdf.bmp",NULL);
    BITMAP* tir_explosif = load_bitmap("tir_explosif.bmp",NULL);
    BITMAP* feu_oku= load_bitmap("feu_oku.bmp",NULL);
    BITMAP* cac_feu= load_bitmap("cac_feu.bmp",NULL);
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* sorts = create_bitmap(SCREEN_W, SCREEN_H);
    init_struct_case();
    str_perso test;
     test.pv = 200;
        test.pa = 10;
        test.pm = 4;

    init_struct_case();

    init_perso();
    while (!key[KEY_ESC])
    {


        affichage_terrain(terrain,buffer,ciel);
        deplacement(terrain,buffer, ciel);
        case_couleur(buffer,terrain,matrice_terrain[3][3].x,matrice_terrain[3][3].y);
        blit(bdf, buffer ,0,0,220,650,bdf->h,bdf->w);
        blit(tir_explosif, buffer ,0,0,265,650,bdf->h,bdf->w);
        blit(feu_oku, buffer ,0,0,310,650,bdf->h,bdf->w);
        blit(cac_feu, buffer ,0,0,355,650,bdf->h,bdf->w);
        rectfill(buffer,100,20,220,40,makecol(0,0,255));
        rectfill(buffer,100,45,220,65,makecol(0,255,0));
        textprintf_ex(buffer,font,35,40,makecol(255,255,255),makecol(255,0,0),"%d",test.pv);
        textprintf_ex(buffer,font,155,25,makecol(255,255,255),makecol(0,0,255),"%d",test.pa);
        textprintf_ex(buffer,font,160,50,makecol(255,255,255),makecol(0,255,0),"%d",test.pm);

        draw_sprite(buffer,coeurpv,5,10);
        draw_sprite(screen, buffer, 0,0);
    }
    return 0;

}END_OF_MAIN();
