
#include <stdio.h>
#include "donnees.h"

int main()
{
    int choix;
    int indice_spectacle;
    int indice_representation;

    initialiser_donnees();

    do
    {
        printf("\n");
        printf("=========================================\n");
        printf(" COMEDIE-FRANCAISE - CONSULTATION SAISON \n");
        printf("=========================================\n");
        printf("1 - Charger tous les fichiers de donnees\n");
        printf("2 - Afficher tous les spectacles de la saison\n");
        printf("3 - Choisir un spectacle, voir les horaires et la salle\n");
        printf("4 - Choisir un spectacle, puis un horaire, puis voir tous les tarifs\n");
        printf("0 - Fin\n");
        printf("\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                charger_toutes_les_donnees();
                break;

            case 2:
                if (verifier_donnees_consultation())
                {
                    afficher_spectacles();
                }
                break;

            case 3:
                if (verifier_donnees_consultation())
                {
                    indice_spectacle = choisir_spectacle();
                    if (indice_spectacle >= 0)
                    {
                        afficher_representations_spectacle(
                            tab_spectacles[indice_spectacle].id_spectacle
                        );
                    }
                    else
                    {
                        printf("Retour menu ou choix invalide.\n");
                    }
                }
                break;

            case 4:
                if (verifier_donnees_consultation())
                {
                    indice_spectacle = choisir_spectacle();
                    if (indice_spectacle >= 0)
                    {
                        indice_representation = choisir_representation_spectacle(
                            tab_spectacles[indice_spectacle].id_spectacle
                        );
                        if (indice_representation >= 0)
                        {
                            afficher_tarifs_representation(indice_representation);
                        }
                        else
                        {
                            printf("Retour menu ou horaire invalide.\n");
                        }
                    }
                    else
                    {
                        printf("Retour menu ou spectacle invalide.\n");
                    }
                }
                break;

            case 0:
                printf("Au revoir.\n");
                break;

            default:
                printf("Choix incorrect.\n");
                break;
        }
    }
    while (choix != 0);

    return 0;
}
