#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 26
#define COLONNE 52
#define NB_JOUEURS 4

typedef struct
{
    int x;
    int y;
    int hauteur;
    int largeur;
    int passage;
    int placement_debut;
}t_case;
typedef struct
{
    int x;
    int y;
    int case_ligne;
    int case_colonne;
}t_joueur;

typedef struct{

    t_joueur pos;
    int pa;
    int pm;
    int pv;
    int classe;

}str_perso;

t_case matrice_terrain[LIGNE][COLONNE];



t_joueur play[4];

typedef struct{
    BITMAP* sort1;
    BITMAP* sort2;
    BITMAP* sort3;
    BITMAP* sort4;
    BITMAP* expli1;
    BITMAP* expli2;
    BITMAP* expli3;
    BITMAP* expli4;

}sortperso;

void load_cra_feu (sortperso* perso);
void load_mage_eau (sortperso* perso);

int addi (int a, int b);
void initialisation();
void menu();
void afficher();
void init_struct_case();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);
void affichagesort (BITMAP* buffer,sortperso perso,BITMAP * coeurpv, str_perso joueur [4]);


void usesort (BITMAP* buffer,BITMAP* bdf1,BITMAP* bdf2,BITMAP* bdf3,str_perso joueur1,str_perso joueur2);

void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* buffer_couleur);
void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur);

void placement_joueur_debut(BITMAP*buffer,BITMAP*terrain);
void chrono(BITMAP* terrain, BITMAP* buffer);
void init_joueur(int nbrjoueur,str_perso joueur [4]);
void case_couleur(BITMAP* buffer,int coord_x,int coord_y,float r,float v,float b);
void terrain_couleur(BITMAP* buffer);
void quadrillage(BITMAP* buffer,BITMAP* terrain);
void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y);

#endif // BIB_H_INCLUDED
