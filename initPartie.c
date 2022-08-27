#include "header.h"
void remplissage(donnees_t *a, char* pioche) //recupération du nom et initialisation des jetons et des points des joueurs
{
    fflush (stdin);
    printf ("Nom joueur: ");
    gets(a->nom);
    a->points=0;
    a->passertours=0;
    aleatoire(pioche,a->jetons, 7);

}

void affichage (donnees_t *a) //affichage de la structure
{
    int i, val;
    printf ("nom : %s\n",a->nom); //Affichage du nom du joueur
    printf ("jetons: ");
    for (i=0; i<7; i++)
    {
        val=valeur(a->jetons[i]);
        printf (" %c %d\t", a->jetons[i], val);//Affichage du chevalet du joueur
    }
    printf("\n");
    printf ("points : %d\n", a->points);//Affichage du score du joueur

}


void creerJoueur(game_t *game, int numJoueur) //Sous programme qui permet d'assigner des jetons et un score a chaque joueur
{
    remplissage(&(game->joueurs[numJoueur]), game->pioche);
}

void choixNbJoueurs(game_t*game) //Choix du nombre de joueurs voulant participer
{
    int i=0;
    while ((i<2)||(i>4))
    {
        printf ("Combien de joueurs desirent jouer?\n");
        scanf ("%d", &i);
        if ((i<2)|| (i>4)) //Entre 2 et 4 joueurs requis pour jouer
        {
            printf ("Choix invalide... Le nombre de joueurs doit etre entre 2 et 4\n");
        }
    }
    game->nbJoueurs=i; //On envoie à la structure le nombre de joueurs qui participent


}

int finDuJeu(game_t*game) //Determine quand le jeu s'arrete
{

    if(strlen(game->pioche)==0)
    {
        for (int i=0; i<game->nbJoueurs; i++)
        {
            if (strlen(game->joueurs[i].jetons)==0)//Si les joueurs n'ont plus de jetons dans leur chevalet et que la pioche est vide
            {
                return 0;
            }
        }
    }
    for (int i=0; i<game->nbJoueurs; i++)
        {
            if (game->joueurs[i].passertours>3) //Si chaque joueur saute 3 fois son tour de suite
            {
                return 0;
            }
        }

    return 1;
}
