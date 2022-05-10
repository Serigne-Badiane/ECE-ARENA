#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 14
#define COLONNE 18
#define NB_JOUEURS 4

typedef struct
{
    int type;
    int x;
    int y;
    int hauteur;
    int largeur;
    int passage;
}t_case;
typedef struct{

    int pa;
    int pm;
    int pv;

}str_perso;


t_case matrice_terrain[LIGNE][COLONNE];

typedef struct
{
    int x;
    int y;
}t_joueur;

t_joueur acteur[NB_JOUEURS];


int addi (int a, int b);
void initialisation();
void afficher();
void init_struct_case();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);
void init_perso();
void deplacement(BITMAP* terrain, BITMAP* buffer);
void chrono(BITMAP* terrain, BITMAP* buffer);

#endif // BIB_H_INCLUDED
