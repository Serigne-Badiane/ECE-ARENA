#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



int main()
{
    srand(time(NULL));
    initialisation();
    BITMAP* terrain= load_bitmap("terrain_normal.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    init_struct_case();
    affichage_terrain(terrain,buffer);

    return 0;
}END_OF_MAIN();
