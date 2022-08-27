int menu()
{
    int choix;
  printf("\nTAPEZ LE CHIFFRE CORRESPONDANT A VOTRE DEMANDE:\n\n");
  printf("1.LANCER LA PARTIE\n");
  printf("2.REGLES DU JEU\n");
  printf("3.QUITTER\n");
  scanf("%d", &choix);


  printf("\n");

  switch (choix)
  {
    case 1:
       printf("Vous avez choisi de lancer une partie, prenez du plaisir et\n                QUE LE MEILLEUR GAGNE!!!\n\n");
        jeu();
       break;
    case 2: reglesjeu();

       break;

    case 3:
       printf("Vous avez choisi de quitter le jeu,\n");
       printf("A une prochaine pour de nouvelles aventures\n\n");
        break;

       default: printf ("Veuillez rentrer un caractere valide\n\n");


  return choix;
  }
}
