
#ifndef DONNEES_H
#define DONNEES_H

#include <stdio.h>

#define MAX_SPECTACLES 100
#define MAX_SALLES 100
#define MAX_CATEGORIES 1500
#define MAX_HORAIRES 50
#define MAX_PROFILS 50
#define MAX_REPRESENTATIONS 1200
#define MAX_TARIFS 2000

#define TAILLE_ID 40
#define TAILLE_LIBELLE 160
#define TAILLE_DATE 20
#define TAILLE_LIGNE 1024

typedef struct
{
    char id_spectacle[TAILLE_ID];
    char nom_spectacle[TAILLE_LIBELLE];
} SPECTACLE;

typedef struct
{
    char id_salle[TAILLE_ID];
    char nom_salle[TAILLE_LIBELLE];
    int jauge_total_salle;
} SALLE;

typedef struct
{
    char id_salle[TAILLE_ID];
    char nom_salle[TAILLE_LIBELLE];
    char id_categorie_billet[TAILLE_ID];
    char categorie_billet[TAILLE_LIBELLE];
    int jauge_categorie_billet;
} CATEGORIE_BILLET_SALLE;

typedef struct
{
    char libelle_horaire[TAILLE_LIBELLE];
    char id_cat_horaire[TAILLE_ID];
} CATEGORIE_HORAIRE;

typedef struct
{
    char id_cat_profil[TAILLE_ID];
    char profil_tarif[TAILLE_LIBELLE];
    char type_tarif[TAILLE_LIBELLE];
} CATEGORIE_PROFIL;

typedef struct
{
    char id_representation[TAILLE_ID];
    char id_spectacle[TAILLE_ID];
    char nom_spectacle[TAILLE_LIBELLE];
    char jour_representation[TAILLE_LIBELLE];
    char heure_representation[TAILLE_LIBELLE];
    char horaire_representation[TAILLE_LIBELLE];
    char id_cat_horaire[TAILLE_ID];
    char date_representation[TAILLE_DATE];
    char id_salle[TAILLE_ID];
    char nom_salle[TAILLE_LIBELLE];
} REPRESENTATION;

typedef struct
{
    char id_categorie_billet[TAILLE_ID];
    char id_salle[TAILLE_ID];
    char nom_salle[TAILLE_LIBELLE];
    char categorie_billet[TAILLE_LIBELLE];
    int jauge_categorie_billet;
    char type_tarif[TAILLE_LIBELLE];
    char id_cat_profil[TAILLE_ID];
    char id_cat_horaire[TAILLE_ID];
    char profil_tarif[TAILLE_LIBELLE];
    char horaire_tarif[TAILLE_LIBELLE];
    int tarif_brut;
} TARIF;

extern SPECTACLE tab_spectacles[MAX_SPECTACLES];
extern SALLE tab_salles[MAX_SALLES];
extern CATEGORIE_BILLET_SALLE tab_categories[MAX_CATEGORIES];
extern CATEGORIE_HORAIRE tab_horaires[MAX_HORAIRES];
extern CATEGORIE_PROFIL tab_profils[MAX_PROFILS];
extern REPRESENTATION tab_representations[MAX_REPRESENTATIONS];
extern TARIF tab_tarifs[MAX_TARIFS];

extern int nbspectacles;
extern int nbsalles;
extern int nbcategories;
extern int nbhoraires;
extern int nbprofils;
extern int nbrepresentations;
extern int nbtarifs;

void initialiser_donnees();

int charger_spectacles(char nom_fichier[]);
int charger_salles(char nom_fichier[]);
int charger_categories(char nom_fichier[]);
int charger_horaires(char nom_fichier[]);
int charger_profils(char nom_fichier[]);
int charger_representations(char nom_fichier[]);
int charger_tarifs(char nom_fichier[]);
int charger_toutes_les_donnees();

int verifier_donnees_consultation();

void afficher_spectacles();
int choisir_spectacle();
void afficher_representations_spectacle(char id_spectacle[]);
int choisir_representation_spectacle(char id_spectacle[]);
void afficher_tarifs_representation(int indice_representation);

#endif
