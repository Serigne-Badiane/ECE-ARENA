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
    int case_x;
    int case_y;
}t_joueur;

t_joueur acteur[NB_JOUEURS];


int addi (int a, int b);
void initialisation();
void menu();
void afficher();
void init_struct_case();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer,BITMAP*ciel);
void init_perso();
void deplacement(BITMAP* terrain, BITMAP* buffer);
<<<<<<< Updated upstream
void chrono(BITMAP* terrain, BITMAP* buffer);
=======
void init_depla();

void placement_joueur_debut(BITMAP*buffer,BITMAP*terrain);
void chrono(BITMAP* terrain, BITMAP* buffer);
void init_joueur(int nbrjoueur,str_perso joueur [4]);
void case_couleur(BITMAP* buffer,int coord_x,int coord_y,int r,int v,int b);
void terrain_couleur(BITMAP* buffer);
void quadrillage(BITMAP* buffer,BITMAP* terrain);
void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y);
>>>>>>> Stashed changes

#endif // BIB_H_INCLUDED
