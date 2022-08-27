#include "header.h"
void piocherJeton(game_t *game, donnees_t *a)
{
    int nbJetonRendu, i, j,t, x, existe;
    char jetonSaisi, jetonRendu, jeton;

    printf ("Combien de jetons souhaitez vous remplacer?\n");
    scanf ("%d", &nbJetonRendu);
    if ((nbJetonRendu<0)||(nbJetonRendu>7))//Le joueur pioche entre 1 et 7 jetons seulement
    {
        printf ("Nombre invalide, reessayez!\n");
        return 0;
    }
    else
    {
        if (nbJetonRendu==7)
        {
            for (i=0; i<7; i++)//Si le joueur souhaite changer tous ses jetons
            {
                jeton=a->jetons[i];
                char varTemp=game->pioche[0], varTemp2;
               for(x=0; x<strlen(game->pioche); x++)
                {
                    varTemp2=varTemp;
                    varTemp=game->pioche[x+1];
                    game->pioche[x+1]=varTemp2;//Decale chaque lettre de la pioche au rang suivant pour liberer la premiere place pour le jeton rendu
                }
                game->pioche[0]=jeton;//Le jeton rendu se place au debut de la pioche
                a->jetons[i]='\0';

            }
            aleatoire(game->pioche, a->jetons, 7);//On pioche 7 jetons aleatoirement dans la nouvelle pioche
        }
        else
        {
            for (i=0; i<nbJetonRendu; i++)
            {
                existe=-1;
                do
                {
                    printf ("Quels jetons souhaitez vous rendre?\n");
                    scanf (" %c", &jetonRendu);
                    for (j=i; j<7; j++)
                    {

                        if(a->jetons[j]==jetonRendu)
                        {
                            existe=j; //index du jeton dans le chevalet
                        }
                    }
                    if (existe==-1)
                    {
                        printf ("Vous ne possedez pas ce jeton, reessayez\n");
                    }
                }while (existe==-1);
                char varTemp=a->jetons[0];
                char varTemp2;
            for (x=0; x<existe; x++)
            {
                varTemp2=varTemp;
                varTemp=a->jetons[x+1];
                a->jetons[x+1]=varTemp2;//decale les jetons vers la fin du chevalet pour liberer la case 0


            }
            a->jetons[0]=jetonRendu;//Renvoie le jeton rendu au debut du chevalet

            }
            for (i=0; i<nbJetonRendu; i++)
            {

                jeton=a->jetons[i];
                char varTemp=game->pioche[0], varTemp2;
               for(x=0; x<strlen(game->pioche); x++)
                {
                    varTemp2=varTemp;
                    varTemp=game->pioche[x+1];
                    game->pioche[x+1]=varTemp2;//Decale les jetons de la pioche de 1 rang pour liberer la premiere place de la pioche
                }
                game->pioche[0]=jeton;//Le jeton rendu se retrouve au debut de la pioche

                a->jetons[7]='\0';

            }aleatoire(game->pioche, a->jetons, nbJetonRendu);

        }
        affichage(a);//Affiche le nouveau chevalet du joueur

    }
}
