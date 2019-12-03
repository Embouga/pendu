#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "gerer_caracteres.h"

int main ( int argc, char** argv )
{
    char motSecret[] = "MARRON";
    char motCache[] = "******";
    int nbCoups = 0, choixDiff = -1, rejouer = 1, nbCoupsJoues = 0, answer = 1, tailleMot = 6;

    do
    {
        printf("Bienvenue dans le jeu du Pendu !\n\n");
        resetMotCache(motCache, tailleMot);

        while (choixDiff != 0 && choixDiff != 1 && choixDiff != 2 && choixDiff != 3)
        {
            printf("Choisissez votre niveau de difficulte !\n\nDIFFICILE -> Jouer avec autant de coups que de lettres dans le mot [TAPEZ 0]\nMOYEN -> Jouer en 10 coups [TAPEZ 1]\nFACILE -> Jouer en 15 coups [TAPEZ 2]\nTRES FACILE -> Jouer en 20 coups [TAPEZ 3]\n");
            scanf("%d", &choixDiff);

            switch(choixDiff)
            {
                case 0:
                    nbCoups = tailleMot;
                    break;
                case 1:
                    nbCoups = 10;
                    break;
                case 2:
                    nbCoups = 15;
                    break;
                case 3:
                    nbCoups = 20;
                    break;
                default :
                    printf("La commande n'est pas valide ! Veuillez choisir de nouveau !\n\n");
                    break;
            }

        }

        printf("Vous allez jouer avec un maximum de %d coups !", nbCoups);
        printf("\n\n");

        while (getchar() != '\n');
        while (nbCoups != 0 && !motSecretTrouve(motCache, motSecret, tailleMot))
        {
            printf("Quel est le mot secret ?  ");
            printf("%s \n", motCache);
            printf("Proposez une lettre : ");
            char caractereJoueur = lireCaractere(); //On demande un caractère au joueur
            int check = verifierCaractere(motSecret, caractereJoueur, tailleMot);

            if (verifierCaractere(motSecret, caractereJoueur, tailleMot))
                remplacerCaractere(motCache, motSecret, caractereJoueur, tailleMot); //remplace les caractères corrects dans le mot secret

            nbCoups--; //On décrémente le nombre de coups restant à jouer sinon
            nbCoupsJoues++;

            printf("\nIl vous reste %d coups a jouer\n\n", nbCoups);

        }

        if(motSecretTrouve(motCache, motSecret, tailleMot)) {
            printf ("Bravo, vous avez trouve le nombre mystere en %d coups seulement !!!\n\n", nbCoupsJoues);
        } else {
            printf("Dommage vous avez perdu !");
        }

        printf("Voulez-vous rejouer ?\n Entrez 0 pour quitter, n'importe quelle autre touche pour rejouer !\n");
        scanf("%d", &answer);

        if(answer == 0) rejouer = 0;
        printf("\n\n");


    } while (rejouer != 0);

    return 0;
}


