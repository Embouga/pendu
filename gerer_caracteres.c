#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "gerer_caracteres.h"

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int verifierCaractere(char *chaine, char caractere, int taille)
{
    int j = 0;
    for (int i = 0; i < taille; i++){
        j += chaine[i] == caractere;
    }
    return (j > 0);
}

void remplacerCaractere(char *chaine, char *chaineInitiale, char caractere, int taille)
{
    for (int i = 0; i < taille; i++){
        if (chaineInitiale[i] == caractere)
            chaine[i] = caractere;
    }
}

int motSecretTrouve(char *chaine, char *chaineInitiale, int taille)
{
    int j = 0;
    for (int i = 0; i < taille; i++){
        j += chaine[i] == chaineInitiale[i];
    }
    return j == taille;
}

void resetMotCache(char* chaine, int taille)
{
    char reset = '*';
    for (int i = 0; i < taille; i++){
        chaine[i] = reset;
    }
}
