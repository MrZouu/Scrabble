#include "header.h"
void printboard(game_t *game) //On affiche le plateau en lui meme avec ses limtes
{
    int i, j, k=1;
    char lettre='A';
    printf("   ");
    for (j=0; j<15; j++)
    {
        printf ("%c  ", lettre); //Affichage des lettres allant de A à O au dessus des colonnes
        lettre++;
    }
    printf ("\n  %c",0xDA);
    for(j=0;j<14;j++)
        {
            printf("%c%c%c",  0xC4,0xC4, 0xC2);

        }printf ("%c%c%c\n1 ",0xC4, 0xC4, 0xBF);


    for(i=0;i<15;i++)
    {

        if (i!=0)
        {

           printf("  %c", 0xC3);


        for(j=0;j<=13;j++)
        {
            printf("%c%c%c",0xC4, 0xC4, 0xC5);

        }
        printf ("%c%c%c",0xC4,0xC4, 0xB4);

        printf("\n");
        printf ("%-2d", i+1); //Affichage des numéros au debut de chaque ligne
        }



        for(j=0;j<15;j++)
        {
            printf ("%c%c%c", 0xB3, game->boardtype[i][j], game->board[i][j]);
        }
        printf("%c\n", 0xB3);



    }
    printf("  %c", 0xC0);
        for(j=0;j<14;j++)
        {
            printf("%c%c%c",  0xC4,0xC4, 0xC1);

        }printf ("%c%c%c\n",0xC4, 0xC4, 0xD9);


}
