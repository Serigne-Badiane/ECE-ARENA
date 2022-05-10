#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>>





int menu()
{
    BITMAP* decor;
    BITMAP* page;
    BITMAP* Logo;
    BITMAP* NewGame;
    BITMAP* Credits;
    BITMAP* Regles;
    BITMAP* Menu2;

    SAMPLE *son;



    /*allegro_init();
    install_keyboard();
    install_mouse();*/


    son = load_wav("clash-of-clans-raiding-musicvolume-increased.wav");


    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0)
    {
        printf("Error initialising sound: %s\n", allegro_error);
        return 1;
    }

    if (!son) {
      allegro_message("Error avec le fichier .wav ");
      return 1;
   }


    /*set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }*/

    play_sample(son, 255, 128, 1000, 1);

    decor=load_bitmap("decordo.bmp",NULL);
    NewGame=load_bitmap("NewGame.bmp",NULL);
    Credits=load_bitmap("Credits.bmp", NULL);
    Regles=load_bitmap("Regles.bmp", NULL);


    page=create_bitmap(SCREEN_W,SCREEN_H);

    Logo=load_bitmap("Logo.bmp",NULL);

    clear_bitmap(page);
    if (!decor)
    {
        allegro_message("pas pu trouver ");
        exit(EXIT_FAILURE);
    }

    while (!key[KEY_ESC])
    {
        show_mouse(page);


        rect(page,500,300,850,400,makecol(255,0,0));
        rect(page,500,450,850,550,makecol(255,0,0));
        rect(page,500,600,850,700,makecol(255,0,0));

        masked_blit(Logo, page, 0, 0, 100, 100, Logo->w, Logo->h);
        masked_blit(NewGame, page, 0, 0, 548, 320, Logo->w, Logo->h);
        masked_blit(Regles, page, 0, 0, 560, 616, Logo->w, Logo->h);
        masked_blit(Credits, page, 0, 0, 560, 468, Logo->w, Logo->h);


        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);


        if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850) /// Petite animation quand on passe la souris
        {


            rect(screen,500,300,850,400,makecol(0,255,255));

        }

        if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,450,850,550,makecol(255,0,255));

        }

        if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,600,850,700,makecol(0,100,255));

        }

        if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur New Game
        {


            show_mouse(Menu2);


            blit(decor,Menu2,0,0,0,0,SCREEN_W,SCREEN_H);

            blit(Menu2,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            rect(screen,500,300,850,400,makecol(0,255,255));
            rect(screen,500,450,850,550,makecol(255,0,255));
            rect(screen,500,600,850,700,makecol(0,100,255));


        }

        /*if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
        {




        }

        if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Regles
        {




        }*/

}
}
/*destroy_sample(son);*/

/*}END_OF_MAIN();*/
