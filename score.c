#include "header.h"
int valeur(char jeton) //Affectation de la valeur en fonction des jetons pour comptabiliser le score
{
    int valeur;
    if(jeton=='?')
    {
        valeur= 0;
    }

    if(jeton=='A' || jeton=='E' || jeton=='I' || jeton=='L' || jeton=='N' || jeton=='O' || jeton=='I' || jeton=='R'|| jeton=='S' || jeton=='T' || jeton=='U')
    {
        valeur = 1;
    }

    if(jeton=='D' || jeton=='G' || jeton=='M')
    {
        valeur = 2;
    }

    if(jeton=='B' || jeton=='C' || jeton=='P')
    {
        valeur = 3;
    }

    if(jeton=='F' || jeton=='H' || jeton=='V')
    {
        valeur = 4;
    }

    if(jeton=='J' || jeton=='Q')
    {
        valeur = 8;
    }

    if(jeton=='K' || jeton=='W' || jeton=='X' || jeton=='Y' || jeton=='Z')
    {
        valeur = 10;
    }

    return valeur;
}

int scoreJeton (char jeton, int multiplicateur)
{
    return valeur(jeton)*multiplicateur;//multiplie chaque lettre par sa valeur
}
int scoreCaractSpecial(char jeton, int multiplicateur, char special)
{
    int mult=1;

    if(special=='&')
    {
        mult=2;
    }
    if (special=='%')
    {
        mult=3;
    }
    return scoreJeton(jeton, multiplicateur)*mult;//multiplie la lettre par rapport au multiplicateur de mot et de lettre
}
int multiplicateurMot (game_t *game, int tailleMot, int ligne, int c, char sens)
{
    int mult=1;
    for (int i=0; i<tailleMot; i++)
    {
        if (game->boardtype[ligne][c]=='@')
        {
            mult*=2;
        }
        if (game->boardtype[ligne][c]=='$')
        {
            mult*=3;
        }
        if (sens=='V')
        {
            ligne++;//Passe a la ligne suivante apres chaque lettre
        }
        else
        {
            c++;//Passe a la colonne suivante apres chaque lettre
        }

    }
    return mult;
}
