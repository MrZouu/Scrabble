#include "header.h"
int coordonneescorrectes(int ligne, int c, char sens, int tailleMot)
{
    if ((ligne<0) || (ligne>14) || (c<0) || (c>14))//Empeche le joueur de placer un mot hors du plateau
    {
        printf ("Emplacement incorrect\n");
        return 0;
    }
    if ((sens!='V')&&(sens!='H')) //Force le joueur a placer son mot en vertical ou en horizontal
    {
        printf ("sens incorrect \n");
        return 0;
    }
    if ((sens=='V'&&(ligne+tailleMot)>14)||(sens=='H'&&(c+tailleMot)>14))//Si le mot n'a pas la place pour rentrer dans le plateau, un message d'erreur apparait
    {
        printf ("Emplacement incorrect\n");
        return 0;
    }

    return 1;
}
int possedejeton(game_t *game, donnees_t*joueurs, char mot[15], int ligne, int c, char sens)
{
    int i, k;
    char jetons[8], t;
    strncpy(jetons, joueurs->jetons, 8);//Copie dans jetons le chevalet du joueur
    for (i=0; i<strlen(mot); i++)
    {
        if (game->board[ligne][c]!=' ' && game->board[ligne][c]!=mot[i])
        {
            printf ("Vous ne pouvez pas placer votre mot ici!\n");
            return 0;
        }
        if (game->board[ligne][c]!=mot[i])// Verifie si la lettre du mot n'est pas sur la case
        {
            t=0;
            for (k=0; k<strlen(jetons); k++)//Parcours le chevalet de joueur
            {
                if (mot[i]==jetons[k])//si le joueur possede le jeton
                {
                    t=1;
                    jetons[k]=' ';//Remplace le jeton posé par un espace
                    break;
                }
            }
            if (t==0)//Si le joueur ne possede pas le jeton
            {
                printf ("vous ne possedez pas ce jeton\n");
                return 0;
            }
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
    if (strcmp(jetons, joueurs->jetons)==0)//Oblige le joueur a placer un jeton
    {
        printf ("Vous devez utiliser au moins un jeton!\n");
        return 0;
    }
    strncpy(joueurs->jetons, jetons,8);//Copie jetons dans chevalet
    return 1;
}

void remplacerJeton(game_t *game, donnees_t *joueurs)
{
    int x, c=0, espace=0, jetonPiocher;
    char jetons[8];
    for (x=0; x<strlen(joueurs->jetons); x++)
    {
        if (joueurs->jetons[x]==' ')//Compte le nombre d'espaces a remplacer dans le chevalet
        {
            espace++;
        }
    }
    jetonPiocher=espace;
    while(espace!=0)
    {
        jetons[c]=' ';//met les espaces au debut
        c++;
        espace--;
    }
    for(x=0; x<strlen(joueurs->jetons); x++)
    {
        if (joueurs->jetons[x]!=' ')
        {
            jetons[c]=joueurs->jetons[x];//met les jetons restants a la fin du chevalet
            c++;
        }
    }
    jetons[7]='\0';
    strncpy(joueurs->jetons, jetons, 8);//Copie le chevalet avec les espaces au debut sans les jetons places sur le plateau
    aleatoire(game->pioche, joueurs->jetons, jetonPiocher);//Repioche des jetons pour remplacer les espaces

}

int placerMot (game_t *game, donnees_t *joueurs, char mot[15], int ligne, char colonne, char sens)//Sous programme permettant de placer un mot sur le plateau
{
    int i=0, j, a, mult;
    int c=colonne-'A';
    char jetonjoue=mot[i];
    ligne=ligne-1;
    printf("colonne:%d, ligne: %d\n", c, ligne);

    if ((coordonneescorrectes(ligne, c, sens, strlen(mot))==0)||(possedejeton(game, joueurs,  mot, ligne, c, sens)==0))
    {
        return 0;
    }
    mult=multiplicateurMot (game, strlen(mot), ligne, c, sens);


    for (i=0; i<strlen(mot); i++)
    {
        joueurs->points+=scoreCaractSpecial(mot[i], mult, game->boardtype[ligne][c]);
        game->board[ligne][c]=mot[i];// Affecte chaque lettre du mot à une case
        if (sens=='V')
        {
            ligne++;//Passe a la ligne suivante apres chaque lettre
        }
        else
        {
            c++;//Passe a la colonne suivante apres chaque lettre
        }

    }
    remplacerJeton(game, joueurs);
    return 1;
}
