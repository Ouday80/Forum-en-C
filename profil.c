#include "profil.h"
#include <stdlib.h>
#include <stdio.h>


void SaisirProfil(Profil* profil)
{
    profil->DateDeNaissance=malloc(sizeof(Date));
    profil->Prenom=(char*)malloc(sizeof(char));
    profil->Nom=(char*)malloc(sizeof(char));
    profil->Adresse=(char*)malloc(sizeof(char));
    profil->Courriel=(char*)malloc(sizeof(char));
    printf("\ndonner votre prenom :");
    gets(profil->Prenom);
    printf("\ndonner votre nom :");
    gets(profil->Nom);
    printf("\ndonner votre adresse :");
    gets(profil->Adresse);
    printf("\ndonner votre courriel :");
    gets(profil->Courriel);
    printf("\ndonner votre numero de telephone :");
    scanf("%d",&profil->NumTelephone);
    printf("\n\tdonner votre date de naissance");
    fflush(stdin);
    SaisirDate(profil->DateDeNaissance);
    do
    {
        printf("\nSaisir un mot de passe ( exactement 4 chiffres ):");
        scanf("%d",&profil->MotDePasse);
    }while((profil->MotDePasse>9999)||(profil->MotDePasse<=999));
}

/**************************************************************/

void AfficherProfil(Profil profil)
{
    printf("\nNom : %s ",profil.Nom);
    printf("\nPrenom : %s ",profil.Prenom);
    printf("\nDate de naissance : ");
    AfficherDate(*profil.DateDeNaissance);
    printf("\nAdresse : %s",profil.Adresse);
    printf("\nCourriel : %s",profil.Courriel);
    printf("\nNum de telephone : %d",profil.NumTelephone);
}

/**************************************************************/

void Save_Profil(Profil profil,char * pseudo)
{
    FILE * ficPro ;
    ficPro=fopen("profil.txt","a");
    fprintf(ficPro,"\n%s %d %s %s %s %s %d %d %d %d",pseudo,profil.MotDePasse,profil.Nom,profil.Prenom,profil.Adresse,profil.Courriel,profil.NumTelephone,profil.DateDeNaissance->jour,profil.DateDeNaissance->mois,profil.DateDeNaissance->annee);
    fclose(ficPro);

}

/**************************************************************/

void Recup_Profil(char * pseudo,Profil * pro)
{

    char test[20];
    pro->Adresse =(char*) malloc(sizeof(char));
    pro->Courriel =(char*) malloc(sizeof(char));
    pro->Nom =(char*) malloc(sizeof(char));
    pro->Prenom =(char*) malloc(sizeof(char));
    pro->DateDeNaissance = malloc(sizeof(Date));
    FILE * ficprofil ;
    ficprofil=fopen("profil.txt","r");
    while (1)
    {
        fscanf(ficprofil,"%s",&test);
        if (strcmp(pseudo,test)==0)
        {
            fscanf(ficprofil,"%d %s %s %s %s %d %d %d %d",&pro->MotDePasse,pro->Nom,pro->Prenom,pro->Adresse,pro->Courriel,&pro->NumTelephone,&pro->DateDeNaissance->jour,&pro->DateDeNaissance->mois,&pro->DateDeNaissance->annee);
            fclose(ficprofil);
            return ;
        }
    }
    printf("\nProfil inexistant !!");
    fclose(ficprofil);
}




