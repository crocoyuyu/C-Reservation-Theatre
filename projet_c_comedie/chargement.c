
#include <stdio.h>
#include <string.h>
#include "donnees.h"

SPECTACLE tab_spectacles[MAX_SPECTACLES];
SALLE tab_salles[MAX_SALLES];
CATEGORIE_BILLET_SALLE tab_categories[MAX_CATEGORIES];
CATEGORIE_HORAIRE tab_horaires[MAX_HORAIRES];
CATEGORIE_PROFIL tab_profils[MAX_PROFILS];
REPRESENTATION tab_representations[MAX_REPRESENTATIONS];
TARIF tab_tarifs[MAX_TARIFS];

int nbspectacles = 0;
int nbsalles = 0;
int nbcategories = 0;
int nbhoraires = 0;
int nbprofils = 0;
int nbrepresentations = 0;
int nbtarifs = 0;

void initialiser_donnees()
{
    nbspectacles = 0;
    nbsalles = 0;
    nbcategories = 0;
    nbhoraires = 0;
    nbprofils = 0;
    nbrepresentations = 0;
    nbtarifs = 0;
}

int charger_spectacles(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbspectacles = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbspectacles < MAX_SPECTACLES))
    {
        nb_lus = fscanf(entree, " %39[^;];%159[^\n]\n",
                        tab_spectacles[nbspectacles].id_spectacle,
                        tab_spectacles[nbspectacles].nom_spectacle);
        if (nb_lus == 2)
        {
            nbspectacles++;
        }
    }

    fclose(entree);
    return nbspectacles;
}

int charger_salles(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbsalles = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbsalles < MAX_SALLES))
    {
        nb_lus = fscanf(entree, " %39[^;];%159[^;];%d\n",
                        tab_salles[nbsalles].id_salle,
                        tab_salles[nbsalles].nom_salle,
                        &tab_salles[nbsalles].jauge_total_salle);
        if (nb_lus == 3)
        {
            nbsalles++;
        }
    }

    fclose(entree);
    return nbsalles;
}

int charger_categories(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbcategories = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbcategories < MAX_CATEGORIES))
    {
        nb_lus = fscanf(entree, " %39[^;];%159[^;];%39[^;];%159[^;];%d\n",
                        tab_categories[nbcategories].id_salle,
                        tab_categories[nbcategories].nom_salle,
                        tab_categories[nbcategories].id_categorie_billet,
                        tab_categories[nbcategories].categorie_billet,
                        &tab_categories[nbcategories].jauge_categorie_billet);
        if (nb_lus == 5)
        {
            nbcategories++;
        }
    }

    fclose(entree);
    return nbcategories;
}

int charger_horaires(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbhoraires = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbhoraires < MAX_HORAIRES))
    {
        nb_lus = fscanf(entree, " %159[^;];%39[^\n]\n",
                        tab_horaires[nbhoraires].libelle_horaire,
                        tab_horaires[nbhoraires].id_cat_horaire);
        if (nb_lus == 2)
        {
            nbhoraires++;
        }
    }

    fclose(entree);
    return nbhoraires;
}

int charger_profils(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbprofils = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbprofils < MAX_PROFILS))
    {
        nb_lus = fscanf(entree, " %39[^;];%159[^;];%159[^\n]\n",
                        tab_profils[nbprofils].id_cat_profil,
                        tab_profils[nbprofils].profil_tarif,
                        tab_profils[nbprofils].type_tarif);
        if (nb_lus == 3)
        {
            nbprofils++;
        }
    }

    fclose(entree);
    return nbprofils;
}

int charger_representations(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbrepresentations = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbrepresentations < MAX_REPRESENTATIONS))
    {
        nb_lus = fscanf(entree, " %39[^;];%39[^;];%159[^;];%159[^;];%159[^;];%159[^;];%39[^;];%19[^;];%39[^;];%159[^\n]\n",
                        tab_representations[nbrepresentations].id_representation,
                        tab_representations[nbrepresentations].id_spectacle,
                        tab_representations[nbrepresentations].nom_spectacle,
                        tab_representations[nbrepresentations].jour_representation,
                        tab_representations[nbrepresentations].heure_representation,
                        tab_representations[nbrepresentations].horaire_representation,
                        tab_representations[nbrepresentations].id_cat_horaire,
                        tab_representations[nbrepresentations].date_representation,
                        tab_representations[nbrepresentations].id_salle,
                        tab_representations[nbrepresentations].nom_salle);
        if (nb_lus == 10)
        {
            nbrepresentations++;
        }
    }

    fclose(entree);
    return nbrepresentations;
}

int charger_tarifs(char nom_fichier[])
{
    FILE *entree;
    char ligne[TAILLE_LIGNE];
    int nb_lus;

    nbtarifs = 0;
    entree = fopen(nom_fichier, "r");
    if (entree == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    fgets(ligne, TAILLE_LIGNE, entree);

    while ((!feof(entree)) && (nbtarifs < MAX_TARIFS))
    {
        nb_lus = fscanf(entree, " %39[^;];%39[^;];%159[^;];%159[^;];%d;%159[^;];%39[^;];%39[^;];%159[^;];%159[^;];%d\n",
                        tab_tarifs[nbtarifs].id_categorie_billet,
                        tab_tarifs[nbtarifs].id_salle,
                        tab_tarifs[nbtarifs].nom_salle,
                        tab_tarifs[nbtarifs].categorie_billet,
                        &tab_tarifs[nbtarifs].jauge_categorie_billet,
                        tab_tarifs[nbtarifs].type_tarif,
                        tab_tarifs[nbtarifs].id_cat_profil,
                        tab_tarifs[nbtarifs].id_cat_horaire,
                        tab_tarifs[nbtarifs].profil_tarif,
                        tab_tarifs[nbtarifs].horaire_tarif,
                        &tab_tarifs[nbtarifs].tarif_brut);
        if (nb_lus == 11)
        {
            nbtarifs++;
        }
    }

    fclose(entree);
    return nbtarifs;
}

int charger_toutes_les_donnees()
{
    int ok = 1;

    if (charger_spectacles("DATA/spectacle_25_26.txt") <= 0) ok = 0;
    if (charger_salles("DATA/info_salle.txt") <= 0) ok = 0;
    if (charger_categories("DATA/cat_billet_salle.txt") <= 0) ok = 0;
    if (charger_horaires("DATA/cat_horaire.txt") <= 0) ok = 0;
    if (charger_profils("DATA/cat_profil.txt") <= 0) ok = 0;
    if (charger_representations("DATA/representation_25_26.txt") <= 0) ok = 0;
    if (charger_tarifs("DATA/info_tarif.txt") <= 0) ok = 0;

    if (ok)
    {
        printf("Chargement termine.\n");
        printf("Spectacles      : %d\n", nbspectacles);
        printf("Salles          : %d\n", nbsalles);
        printf("Categories      : %d\n", nbcategories);
        printf("Horaires        : %d\n", nbhoraires);
        printf("Profils         : %d\n", nbprofils);
        printf("Representations : %d\n", nbrepresentations);
        printf("Tarifs          : %d\n", nbtarifs);
    }
    else
    {
        printf("Le chargement est incomplet.\n");
    }

    return ok;
}

int verifier_donnees_consultation()
{
    if ((nbspectacles <= 0) || (nbrepresentations <= 0) || (nbtarifs <= 0))
    {
        printf("Veuillez d'abord charger les fichiers de donnees.\n");
        return 0;
    }
    return 1;
}
