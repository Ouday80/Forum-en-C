#include "menu.h"

int Menu1()
{
    int Choix ;
    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t 1.     S'inscrire           ");
    printf("\n\t\t 2.     Se Connecter         ");
    printf("\n\t\t 3.     Visiteur             ");
    printf("\n\t\t 0.     Quitter <<<         ");
    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix  :");
    scanf("\n%d",&Choix);
    return Choix ;
}

/**************************************************************/

int Menu2()
{
    int Choix ;
    printf("\n--------------------------------------------FORUM----------------------------------------------------\n");
    printf("\n\t\t 1.     Afficher le Forum         ");
    printf("\n\t\t 2.     Creer une rubrique      ");
    printf("\n\t\t 3.     Rejoindre une rubrique     ");
    printf("\n\t\t 0.     Retour <<<         \n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix :");
    scanf("\n%d",&Choix);
    return Choix ;

}

/************************************************************/

int Menu3()
{
    int choix;
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t 1.     Afficher un profil          ");
    printf("\n\t\t 2.     Afficher un forum      ");
    printf("\n\t\t 0.     Retour <<<         \n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix :");
    scanf("\n%d",&choix);
    return choix ;
}

/************************************************************/

int Menu4()
{
    int choix;
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t 1.     Espace Messages       ");
    printf("\n\t\t 2.     Espace Auteurs        ");
    printf("\n\t\t 3.     Statistiques & Recherche   ");
    printf("\n\t\t 0.     Retour <<<         \n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix :");
    scanf("\n%d",&choix);
    return choix ;
}

/************************************************************/

int Menu5()
{
    int choix;
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t 1.     Ajouter un message         ");
    printf("\n\t\t 2.     Repondre a un message         ");
    printf("\n\t\t 3.     Supprimer un message         ");
    printf("\n\t\t 4.     Afficher les reponses d'un message   ");
    printf("\n\t\t 0.     Retour <<<         \n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix :");
    scanf("\n%d",&choix);
    return choix ;
}

/************************************************************/

int Menu6()
{
     int choix;
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t 1.     Afficher un auteur     ");
    printf("\n\t\t 2.     Afficher les messages d'un auteur     ");
    printf("\n\t\t 3.     Afficher le profil d'un auteur     ");
    printf("\n\t\t 0.     Retour <<<         \n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix :");
    scanf("\n%d",&choix);
    return choix ;
}

/************************************************************/

int Menu7()
{
     int choix;
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t 1.     Chercher un mot dans un texte de message      ");
    printf("\n\t\t 2.     Chercher les messages postes dans un jour donne   ");
    printf("\n\t\t 3.     Moyenne des messages postes par auteur   ");
    printf("\n\t\t 4.     Taille moyenne des messages postes    ");
    printf("\n\t\t 5.     L'auteur le plus actifs (ayant le maximum nombre des messages)  ");
    printf("\n\t\t 0.     Retour <<<         \n");
    printf("\n---------------------------------------------------------------------------------------------------\n");
    printf("\nchoix :");
    scanf("\n%d",&choix);
    return choix ;
}





