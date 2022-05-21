#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void sauvegarde(int nbrjoueur, int tour_joueur)         ///pour la revanche
{
    FILE* pf = fopen("AAA.txt", "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (tour_joueur=0; tour_joueur<nbrjoueur; tour_joueur++)
    {
        fprintf(pf, "%d ", joueur[tour_joueur].classe);
        fprintf(pf, "%d ", joueur[tour_joueur].classe);
    }

fclose(pf);
pf = NULL;
}


void retrait(int nbrjoueur, int tour_joueur)
{
    int valeursLues[100];

    FILE* pf = fopen("AAA.txt", "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    int i=0;

    while (i<100 && fscanf(pf, "%d", &valeursLues[i]) == 1)
    {
        i += 1;
    }

    fclose(pf);
    pf = NULL;

    for (i=0; i<100; i++)
    {
        joueur[tour_joueur].classe=valeursLues[i];
    }


}
