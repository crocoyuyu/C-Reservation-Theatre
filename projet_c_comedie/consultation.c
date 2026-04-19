
#include <stdio.h>
#include <string.h>
#include "donnees.h"

void afficher_spectacles()
{
    int i;

    printf("\n");
    printf("===== LISTE DES SPECTACLES =====\n");
    for (i = 0; i < nbspectacles; i++)
    {
        printf("%3d - %s (%s)\n", i + 1,
               tab_spectacles[i].nom_spectacle,
               tab_spectacles[i].id_spectacle);
    }
    printf("\n");
}

int choisir_spectacle()
{
    int choix;

    afficher_spectacles();
    printf("Choisissez un spectacle (0 pour retour) : ");
    scanf("%d", &choix);

    if ((choix < 1) || (choix > nbspectacles))
    {
        return -1;
    }

    return choix - 1;
}

void afficher_representations_spectacle(char id_spectacle[])
{
    int i;
    int compteur = 0;

    printf("\n");
    printf("===== REPRESENTATIONS DU SPECTACLE =====\n");
    for (i = 0; i < nbrepresentations; i++)
    {
        if (strcmp(tab_representations[i].id_spectacle, id_spectacle) == 0)
        {
            compteur++;
            printf("%3d - %s - %s - %s - %s\n",
                   compteur,
                   tab_representations[i].date_representation,
                   tab_representations[i].horaire_representation,
                   tab_representations[i].nom_salle,
                   tab_representations[i].id_representation);
        }
    }

    if (compteur == 0)
    {
        printf("Aucune representation pour ce spectacle.\n");
    }

    printf("\n");
}

int choisir_representation_spectacle(char id_spectacle[])
{
    int i;
    int choix;
    int compteur = 0;

    afficher_representations_spectacle(id_spectacle);
    printf("Choisissez un horaire / une representation (0 pour retour) : ");
    scanf("%d", &choix);

    if (choix <= 0)
    {
        return -1;
    }

    for (i = 0; i < nbrepresentations; i++)
    {
        if (strcmp(tab_representations[i].id_spectacle, id_spectacle) == 0)
        {
            compteur++;
            if (compteur == choix)
            {
                return i;
            }
        }
    }

    return -1;
}

void afficher_tarifs_representation(int indice_representation)
{
    int i;
    int trouve = 0;
    REPRESENTATION rep;

    if ((indice_representation < 0) || (indice_representation >= nbrepresentations))
    {
        printf("Representation incorrecte.\n");
        return;
    }

    rep = tab_representations[indice_representation];

    printf("\n");
    printf("===== TARIFS POUR LA REPRESENTATION =====\n");
    printf("Spectacle  : %s\n", rep.nom_spectacle);
    printf("Date       : %s\n", rep.date_representation);
    printf("Horaire    : %s\n", rep.horaire_representation);
    printf("Salle      : %s\n", rep.nom_salle);
    printf("\n");
    printf("%-18s %-38s %-15s %-8s\n",
           "Categorie",
           "Profil",
           "Type",
           "Tarif");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < nbtarifs; i++)
    {
        if ((strcmp(tab_tarifs[i].id_salle, rep.id_salle) == 0) &&
            (strcmp(tab_tarifs[i].id_cat_horaire, rep.id_cat_horaire) == 0))
        {
            printf("%-18s %-38s %-15s %3d euros\n",
                   tab_tarifs[i].categorie_billet,
                   tab_tarifs[i].profil_tarif,
                   tab_tarifs[i].type_tarif,
                   tab_tarifs[i].tarif_brut);
            trouve = 1;
        }
    }

    if (!trouve)
    {
        printf("Aucun tarif trouve pour cette representation.\n");
    }

    printf("\n");
}
