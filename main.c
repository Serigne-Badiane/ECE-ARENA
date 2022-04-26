#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    initialisation();
    affichage_terrain();

    return 0;
}END_OF_MAIN();
