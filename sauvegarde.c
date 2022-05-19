#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>



void sauvegarde(int nbrjoueur, int tour_joueur)
{
    FILE* pf = fopen("monFichier.txt", "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (int i=0; i<nbrjoueur; i++)
    {
        fprintf(pf, "%d ", joueur[tour_joueur].pos.case_ligne_iso);
    }
    for (int i=0; i <nbrjoueur; i++)
    {
        fprintf(pf, "%d ", joueur[tour_joueur].pos.case_colonne_iso);
    }

fclose(pf);
pf = NULL;
}


void retrait(int nbrjoueur, int tour_joueur)
{
    int valeursLues[nbrjoueur];
    FILE* pf = fopen("monFichier.txt", "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    int i=0;
    int j;

    while (i<nbrjoueur && fscanf(pf, "%d", &valeursLues[i]) == 1)
    {
        i += 1;
    }

    fclose(pf);
    pf = NULL;

    for(j = 0; j < 1; j++)
    {
         joueur[tour_joueur].pos.case_ligne_iso=valeursLues[j];
    }
    for(j = 1; j < 2; j++)
    {
         joueur[tour_joueur].pos.case_colonne_iso=valeursLues[j];
    }

    for (i = 0; i < 1; i++)
    {
        printf("apres x : %d\n",  joueur[tour_joueur].pos.case_ligne_iso);
        printf("apres y : %d\n",  joueur[tour_joueur].pos.case_colonne_iso);
    }
}
