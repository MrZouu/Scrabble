#include "header.h"
void aleatoire(char* pioche, char* jetons, int nbJetons)
{
    int i, j, k, n; //Chaine qui va recuperer la valeur de la pioche avec les caracteres pioch�s en moins
    for(i=0;i<nbJetons;i++)
    {
       j=rand()%strlen(pioche);
       jetons[i]= pioche[j];//Place le jeton aleatoire dans le chevalet
       pioche[j]=' ';   //remplace le caractere pioch� par du vide
       suprEspace(pioche); //appelle le sous programme pour enlever les espaces de la chaine
    }jetons[7]='\0';
}

void suprEspace(char* pioche) //Code trouv� sur https://codes-sources.commentcamarche.net/forum/affich-1283618-supprimer-les-espaces-dans-une-chaine-de-caracteres
{
int i,j,n;
n=strlen(pioche);
for (i=0;i<n;i++)
  if (pioche[i]==' ')
    {
        for(j=i;j<(n-1);j++)
        {
            pioche[j]=pioche[j+1];  //Enleve les espaces en les rempla�ants par les caracteres qui suivent
        }
        pioche[j]='\0';
    }


}
