#include "header.h"
void reglesjeu()
{
    int i;
    printf("Vous avez choisi de regarder les regles du jeu\n\n");// regles du jeu enoncées avec les 1 1.1 1.2 etc
        printf("Choisissez l'option qui vous correspond\n\n");
        printf("1.Preparation du jeu\n");
        printf("2.Partie et calcul des scores\n");
        printf("3.Fin de partie\n");
        scanf("%d", &i);

       switch(i){
        case 1:
            printf(" 1.1     Chaque joueur tire aleatoirement sept lettres et les depose sur son chevalet.\n\n");
            break;
        case 2:

            printf(" 2.1     Le joueur choisi parmi ses lettres et pose une ou plusieurs lettres de maniere a former de nouveaux mots sur la grille, horizontalement ou verticalement. Il n est pas admis de poser un mot en diagonale. \n\n");
            printf(" 2.2     Le premier mot doit faire au moins deux lettres et recouvrir la case centrale. Les mots suivants doivent sappuyer sur des mots deja places, a la maniere des mots croises.\n\n");
            printf(" 2.3     Le score d un coup est calcule en additionnant la valeur de toutes les lettres des nouveaux mots formes.\n\n");
            printf(" 2.4     Si une nouvelle lettre posee recouvre une case  lettre compte double('&') ou lettre compte triple('%%'), sa valeur est multipliee par 2 ou par 3.\n\n");
            printf(" 2.5     Si cette case fait partie de 2 nouveaux mots formes, horizontalement et verticalement, elle compte double ou triple dans les deux sens.\n\n");
            printf(" 2.6     Si une case mot compte double('@') ou mot compte triple('$') a ete recouverte, la valeur du mot entier est doublee ou triplee. Si en recouvrant cette case,cela forme deux mots horizontalement et verticalement,\n\n");
            printf(" 2.7     La valeur des deux mots est multipliee par 2 ou par 3. Les cases multiplicatrices ne servent plus une fois recouvertes.\n\n");
            printf(" 2.8     Placer ses sept lettres sur la grille apporte une prime de 50 points. Ce genre de coup est appele scrabble\n\n");
            printf(" 2.9     Apres avoir pose ses lettres et annonce son score, le tour est termine. Il est alors possible de demander a verifier la presence d un mot joue dans un dictionnaire de reference, convenu entre les joueurs :\n\n");
            printf(" 2.10    Si un mot conteste n est pas valable, le joueur reprend ses lettres et marque zero point pour le coup. Par contre si le mot conteste est valable, le demandeur qui a conteste perd dix points.\n\n");
            printf(" 2.11    Les actions possibles sont :\n- passer son tour\n- changer une ou plusieurs lettres de son jeu, dans ce cas il est impossible de poser un nouveau mot.\n\n");
            break;
        case 3:
            printf("3.1      La partie s acheve quand le sac est vide et qu un joueur place ses dernieres lettres sur la grille.\n");
            printf("3.2      Il ajoute a son score la valeur des lettres restant de ses adversaires, qui dans le meme temps, doivent deduire de leur score la valeur des lettres qui leur restent.\n");
            printf("3.3      Le vainqueur est celui qui totalise le plus de points a la fin de la partie. \n\n");


            break;

        default:
            printf("Vous n'avez pas rentre un nombre correct.\n\n");
            break;
       }
}

