#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



int main()
{

    menu();



    srand(time(NULL));
    initialisation();
    init_struct_case();
    affichage_terrain();

    return 0;

}END_OF_MAIN();
