#include "header.h"
int chercherMot (char mot[15])
{

    FILE*fichier=NULL;
    char ligne[100];//taille max de la ligne du fichier
    fichier=fopen("dico.txt", "r");
    if(fichier==NULL)
    {
        perror("erreur:");
    }
    while (fgets(ligne, 100, fichier))
    {
        for (int i=0; i<strlen(ligne); i++)
        {
            if (ligne[i]=='\n')
            {
                ligne[i]='\0';//Remplace le saut de ligne par une fin de ligne sur la ligne qu'on a lu dans le fichier
            }
        }
    if (strcasecmp(mot, ligne)==0)//comparaison de deux chaines de caracteres peu importe si min ou maj
    {
        return 1;
    }

    }fclose(fichier);
    return 0;
}
