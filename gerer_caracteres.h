#ifndef GERER_CARACTERES_H_INCLUDED
#define GERER_CARACTERES_H_INCLUDED


#endif // GERER_CARACTERES_H_INCLUDED


char lireCaractere();

int verifierCaractere(char* chaine, char caractere, int taille);

void remplacerCaractere(char *chaine, char *chaineInitiale, char caractere, int taille);

int motSecretTrouve(char *chaine, char *chaineInitiale, int taille);

void resetMotCache(char* chaine, int taille);
