#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define HEIGHT 16
#define WIDTH 16
#define TAILLE 4

typedef struct donnees //2,3 ou 4 joueurs ( tableau de structure )
{

    char nom[20]; //Prénom du joueur
    char jetons[8]; //7 pions de chaque joueur
    int points;  //Compte les points du joueur
    int passertours;

}donnees_t;
typedef struct game
{
    char board[HEIGHT][WIDTH];
    char boardtype[HEIGHT][WIDTH];
    donnees_t joueurs[4];
    int nbJoueurs;
    char pioche[131];

}game_t;


void affichage (donnees_t *a);
void aleatoire(char* pioche, char* jetons, int nbJetons);
int valeur(char jeton);
void creerJoueur(game_t *game, int numJoueur);
void choixNbJoueurs(game_t*game);
int finDuJeu(game_t*game) ;
void remplissage(donnees_t *a,char* pioche);
void suprEspace(char* pioche);
int placerMot (game_t *game, donnees_t *joueurs, char mot[15], int ligne, char colonne, char sens);
void piocherJeton(game_t *game, donnees_t *a);
void jeu();
int chercherMot (char mot[15]);
int multiplicateurMot (game_t *game, int tailleMot, int ligne, int c, char sens);
int scoreCaractSpecial(char jeton, int multiplicateur, char special);
int scoreJeton (char jeton, int multiplicateur);
int coordonneescorrectes(int ligne, int c, char sens, int tailleMot);
int possedejeton(game_t *game, donnees_t*joueurs, char mot[15], int ligne, int c, char sens);
void remplacerJeton(game_t *game, donnees_t *joueurs);
void initboard(game_t *game);
void printboard(game_t *game);
void reglesjeu();


#endif // HEADER_H_INCLUDED
