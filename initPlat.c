#include "header.h"
void initboard(game_t *game) //initialisation des cases du plateau
{
    int i, j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            game->board[i][j]=' '; //On laisse deux espaces dans chaque case pour le caractere special et les jetons des joueurs
            game->boardtype[i][j]=' ';
            if ((i==0 || i==14) && (j==3 || j== 11))
            {
                game->boardtype[i][j]='&';
            }
            if ((i==0 || i==14) && j==15/2)
            {
                game->boardtype[i][j]='$';
            }
            if ((i==3|| i==11) && (j==0 || j==14)|| ((i==12) &&(j==6 || j==8)||(i==11 && j==7)))
            {
                game->boardtype[i][j]='&';
            }
            if((i==15/2)&&(j==0 || j==15-1))
            {
                game->boardtype[i][j]='$';
            }
            if ((i==2 && (j==15/2-1 || j==15/2+1)) || ((i==3 && j==15/2)))
            {
                game->boardtype[i][j]='&';
            }
            if (i==1 &&(j==5 || j==9)|| (i==13 && (j==5 || j==9)))
            {
               game->boardtype[i][j]='%';
            }
            if ((i==6 && (j==2|| j==12))||(i==7 && (j==3||j==11))||(i==8 && (j==2 || j==12)))
            {
                game->boardtype[i][j]='&';
            }
            if (i==5 &&(j==1||j==13)|| (i==9 &&(j==1||j==13)))
            {
                game->boardtype[i][j]='%';
            }

        }

    }
    char diagonale[]="$@@@@%&#&%@@@@$";
    for (i=0; i!=15; i++)
    {
        game->boardtype[i][i]=diagonale[i];
        game->boardtype[i][14-i]=diagonale[i];
    }

}
