#include "header.h"
void jeu()
{
    int toursjoueur=0;
    donnees_t *joueur;
    donnees_t *jetons;
    int choix;
    game_t game;
    initboard(&game);

            sprintf (game.pioche,"AAAAAAAAABBCCDDDEEEEEEEEEEEEEEEFFGGHHIIIIIIIIJKLLLLLMMMNNNNNNOOOOOOPPQRRRRRRSSSSSSTTTTTTUUUUUUVVWXYZ??\0" );

            int i, ligne, egalite=0;
            char sens, colonne;
            char mot[15], reponse[10];
            srand(time(NULL));

            choixNbJoueurs(&game);
            for (i=0; i<game.nbJoueurs; i++)
            {
                creerJoueur(&game, i);//Affiche n fois les données de chaque joueur en fonction du nombre de participants
            }
            while (finDuJeu(&game)!=0)
            {
                //system("@cls||clear");
                printboard(&game);
                joueur=&(game.joueurs[toursjoueur]);//Le joueur 1 commence
                affichage(joueur);
                printf ("%s, que voulez vous faire?\n", joueur->nom);//Demande au joueur ce qu'il veut faire
                printf ("1.Placer un mot\n");
                printf ("2. Passer votre tour\n");
                printf ("3.Piocher un nouveau jeton\n");
                scanf ("%d", &choix);
                switch (choix)
                {
                    case 1:

                            printf ("Quel mot souhaitez vous placer?\n");
                            scanf ("%s", &mot);
                            printf("Un joueur souhaite-t-il contester le mot?\n");
                            scanf ("%s", &reponse);
                            if (strncmp(reponse, "OUI", 3)==0)
                            {

                                if (chercherMot(mot)==0)
                                {
                                    printf ("Ce mot n'existe pas! Reessayez\n");
                                    continue;
                                }
                                else{printf ("Le mot existe! Continuez...\n");}
                            }
                            printf ("Dans quel sens souhaitez vous placer ce mot? V ou H\n");
                            scanf (" %c", &sens);
                            printf ("A quel endroit souhaitez vous placer votre mot?\n");
                            scanf (" %c%d", &colonne, &ligne);

                            if (placerMot(&game, joueur, mot, ligne, colonne, sens)==0)
                            {
                                printf ("impossible de placer ce mot! Reessayez! \n");
                                continue;//retourne au debut de la boucle et le joueur peut reessayer de jouer
                            }
                            joueur->passertours=0;
                            break;

                     case 2: joueur->passertours+=1;

                             break;

                    case 3: piocherJeton(&game, joueur);
                            joueur->passertours+=1;
                            break;

                    }toursjoueur++;//Apres avoir joué, c'est donc au tour du joueur suivant
                if (toursjoueur==game.nbJoueurs)//condition pour que le premier joueur joue avec le dernier
                {
                    toursjoueur=0;
                }
            }
            printf ("La partie est terminee!\n");
            for (i=0; i<game.nbJoueurs; i++)
            {

                printf("score de %s: %d\n",game.joueurs[i], game.joueurs[i].points);
            }
            joueur=&(game.joueurs[0]);//Initialise le joueur 1 comme vainqueur
            for (int i=0; i<game.nbJoueurs; i++)
            {
                if (game.joueurs[i].points>joueur->points)//Si un autre joueur a plus de points que lui...
                {
                    joueur=&(game.joueurs[i]);//...alors c'est lui le gagnant
                }

            }

            for (int i=0; i<game.nbJoueurs; i++)
            {
                if (joueur!=&(game.joueurs[i])&&(game.joueurs[i].points==joueur->points))//Si un autre joueur a autant de points que lui...
                {
                    egalite=1;
                    printf ("C'EST UNE E-GA-LI-TE!!!!!!");//....alors ils sont a egalite

                }
            }
            if (egalite==0)
            {
                printf ("LE GAGNANT EST %s\n", joueur->nom);
            }
            printf ("Felicitations, a la prochaine..\n");
}
