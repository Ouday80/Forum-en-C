#include "auteur.h"
#include <stdio.h>
#include <string.h>

void SaisirAuteur(Auteur * auteur)
{
    printf("\ndonner votre Pseudo :");
    scanf("%s",auteur->Pseudo);
    auteur->Date1ereMessage=NULL;
    auteur->DateDernierMessage=NULL;
    auteur->NombreDeMessagePoste=0;
}

/**************************************************************/

void AfficherAuteur(Auteur auteur)
{
    printf("\nPseudo : %s",auteur.Pseudo);
    printf("\nNombre de Messages postes : %d",auteur.NombreDeMessagePoste);
    printf("\nDate de premier Message : ");
    AfficherDate(*auteur.Date1ereMessage);
    printf("\nDate de dernier Message : ");
    AfficherDate(*auteur.DateDernierMessage);

}

/**************************************************************/

void Save_Account(char * pseudo,int mdp )
{
    FILE * ficPse ;
    ficPse =fopen("Account.txt", "a");
    fprintf(ficPse,"\n%d%s",mdp,pseudo);
    fclose(ficPse);
}

/**************************************************************/

int Est_Valide_Account(char *pseudo,int mdp)
{
    char pse[20];
    char acc[20] ;
    sprintf(pse,"%d",mdp);
    strcat(pse,pseudo);
    FILE *ficpse;
    ficpse = fopen("Account.txt", "r");
    while(fscanf(ficpse,"%s",acc)==1)
    {
        if(strcmp(acc,pse)==0)
            return 1 ;
    }
    fclose(ficpse);
    return 0;
}

