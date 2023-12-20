#include "message.h"
#include <stdio.h>

void SaisirMessage(Message* message,char * ch)
{
    message->DateDePublication=malloc(sizeof(Date));
    fflush(stdin);
    printf("\ndonner le titre de votre messsage :");
    gets(message->Titre);
    printf("\necrire le contenu de votre msg :");
    gets(message->Text);
    GenererDate(message->DateDePublication);
    strcpy(message->Pesduo,ch);
    message->LSDReponses = NULL ;
}

/**************************************************************/

void Afficher_LSD(CelluleMsg * );

/**************************************************************/

void AfficherMessage(Message message)
{
    printf("\nAuteur : %s",message.Pesduo);
    printf("\nTitre :%s",message.Titre);
    printf("\n%s\n",message.Text);
    AfficherDate(*message.DateDePublication);
    Afficher_LSD(message.LSDReponses);
}

/**************************************************************/

void Initialiser_LSD(CelluleMsg * L)
{
    L=NULL;
}

/**************************************************************/

void Ajout_Fin_Lsd(CelluleMsg ** L,char * ch )
{
    CelluleMsg * parc, * prec ;
    CelluleMsg * nouv ;
    nouv = malloc (sizeof(CelluleMsg));
    nouv->Msg = malloc(sizeof(Message));
    SaisirMessage(nouv->Msg,ch);
    nouv ->suiv = NULL ;
    if (*L == NULL)
        *L = nouv ;
    else
    {
        parc = *L ;
        while (parc!=NULL)
        {
            prec = parc ;
            parc = parc->suiv ;
        }
        prec->suiv = nouv ;
    }

}

/**************************************************************/

int Exist_Mess(CelluleMsg * L,char * TitMsg)
{
    int tmp = -1 ;
    CelluleMsg * parc ;
    parc = L ;
    while(parc != NULL)
    {
        if (strcmp(parc->Msg->Titre,TitMsg)==0)
        {
            tmp = 1;
            return tmp ;
        }
        parc = parc->suiv ;
    }
    free(parc);
    return tmp ;
}

/**************************************************************/

void Supprimer_Msg_Lsd(CelluleMsg ** L,char * TitreRep)
{
    CelluleMsg * parc, * prec ;
    parc = *L ;
    prec = *L ;
    if ((parc!=NULL)&&(strcmp(parc->Msg->Titre,TitreRep)==0))
    {
        *L = parc->suiv ;
        free(parc);
        return ;
    }
    while ((parc != NULL )&& (strcmp(parc->Msg->Titre, TitreRep)) != 0)
    {
        prec = parc;
        parc = parc->suiv;
    }
    prec->suiv = parc->suiv ;
    free(parc);
}

/**************************************************************/

void Afficher_LSD(CelluleMsg * L)
{
    int j=0 ;
    CelluleMsg * parc ;
    if (L==NULL)
        printf("\nPas de Reponses a ce Message");
    else
    {
        parc = L ;
        while(parc != NULL)
        {
            printf("\n\n-->Reponse %d ",j+1);
            AfficherMessage(*parc->Msg) ;
            parc = parc->suiv ;
            j++;
        }
    }
}

/**************************************************************/

int Longeur_Lsd(CelluleMsg * L)
{
    int compt=0 ;
    CelluleMsg * parc ;
    parc = L ;
    while(parc != NULL)
    {
        parc = parc->suiv ;
        compt++;
    }
    free(parc);
    return compt ;
}
/**************************************************************/

void Trouver_Mot(char * ch,Message * mess)
{
    int a = 0;
    CelluleMsg * parc ;
    if ( strstr(mess->Text,ch)!= NULL)
       {
         Afficher_MSG(*mess);
         a=1;
       }
    parc = mess->LSDReponses ;
    while(parc != NULL)
    {
        if (strstr(parc->Msg->Text,ch)!=NULL)
           {
               printf("\n");
               Afficher_MSG(*parc->Msg);
               a=1;
           }
        parc  = parc->suiv ;
    }
    if(a==0)
        printf("\n        NONE  \n");
}

/**************************************************************/

void Afficher_MSG(Message message)
{
    printf("\nAuteur : %s",message.Pesduo);
    printf("\nTitre :%s",message.Titre);
    printf("\n%s\n",message.Text);
    AfficherDate(*message.DateDePublication);
}


/**************************************************************/

void Trouver_Msg_Jour(Date datejour ,Message* mess)
{
    CelluleMsg * parc ;
    int a = 0;
    if((datejour.jour == mess->DateDePublication->jour)&&(datejour.mois == mess->DateDePublication->mois)&&(datejour.annee == mess->DateDePublication->annee))
    {
        printf("\n");
        Afficher_MSG(*mess);
        a=1 ;
    }
    parc = mess->LSDReponses ;
    while(parc != NULL)
    {
        if((datejour.jour == parc->Msg->DateDePublication->jour)&&(datejour.mois == parc->Msg->DateDePublication->mois)&&(datejour.annee == parc->Msg->DateDePublication->annee))
            {
                printf("\n");
                Afficher_MSG(*parc->Msg);
                a=1;
            }
        parc = parc->suiv ;
    }
    if (a==0)
        printf("\n        NONE\n");
}






