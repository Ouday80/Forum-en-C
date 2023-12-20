#include "rubrique.h"
#include <stdio.h>


void SaisirRubrique(Rubrique * rubrique )
{
    int i ;
    rubrique->DateDeCreation=malloc(sizeof(Date));
    printf("\nSaisir le nom du theme : ");
    scanf("%s",rubrique->Theme);
    GenererDate(rubrique->DateDeCreation);
    printf("\ndonner votre adresse mail :");
    scanf("%s",rubrique->AdresseMailAnnimateur);
    printf("\ndooner le nombre de sites inetrnet associees a ce theme :");
    scanf("%d",&rubrique->nsi);
    rubrique->SitesInternet=(char**)malloc(rubrique->nsi*sizeof(char*));
    for (i=0; i<rubrique->nsi; i++)
        rubrique->SitesInternet[i]=(char*)malloc(sizeof(char));
    fflush(stdin);
    for(i=1; i<= rubrique->nsi ; i++)
    {
        printf("\nSite internet num %d :",i);
        scanf("%s",&rubrique->SitesInternet[i-1]);
    }
    rubrique->nbreMess=0;
    rubrique->message=NULL;
}

/**************************************************************/

void AfficherRubrique(Rubrique rubrique)
{
    int i ;
    printf("\ntheme : %s",rubrique.Theme);
    printf("\nAdresse Mail Annimateur : %s",rubrique.AdresseMailAnnimateur);
    printf("\nDate de creation :");
    AfficherDate(*rubrique.DateDeCreation);
    for (i=0; i< rubrique.nsi ; i++)
        printf("\nSite internet num %d : %s",i+1,rubrique.SitesInternet+i);
    printf("\n****************************************** Messages ************************************************\n");
    for (i=0; i<rubrique.nbreMess; i++)
    {
        AfficherMessage(rubrique.message[i]);
        printf("\n.....................................................................................................\n");
    }

}

/**************************************************************/


void AjouterMessage(Rubrique* rubrique,char * ch)
{
    rubrique->nbreMess++;
    rubrique->message=(Message*)realloc(rubrique->message,rubrique->nbreMess*sizeof(Message));
    SaisirMessage(&rubrique->message[rubrique->nbreMess-1],ch);
}

/**************************************************************/
 int Taille_Moy_Mess(Rubrique R)
 {
     CelluleMsg * parc ;
     int i,TAILLE=0 ;
     for (i=0;i<R.nbreMess;i++)
     {
         TAILLE += strlen(R.message[i].Text);
         parc = R.message[i].LSDReponses ;
         while(parc != NULL)
         {
             TAILLE += strlen(parc->Msg->Text);
             parc = parc->suiv ;
         }

     }
     return (int)TAILLE/R.nbreMess ;
 }

