#include "forum.h"
#include <string.h>

void SaisirForum(Forum * forum)
{
    int i ;
    forum->nbreAuteur=0;
    forum->AdresseInternet=(char*)malloc(sizeof(char));
    forum->AdresseMailResponsable=(char*)malloc(sizeof(char));
    strcpy(forum->AdresseInternet,"http://forum.tn");
    strcpy(forum->AdresseMailResponsable,"Moderateur@gmail.com");
    forum->auteur=NULL;
    forum->nbreRub=0;
    forum->rubrique=NULL;
}

/**************************************************************/


void AfficherForum(Forum forum)
{
    int i ;
    printf("\n -------------------------------------------- WELCOME ---------------------------------------------- \n");
    printf("\n\t==>Adresse internet du forum :%s",forum.AdresseInternet);
    printf("\n\t==>Adresee Mail Responsable :%s\n",forum.AdresseMailResponsable);
    for (i=0; i<forum.nbreRub; i++)
        AfficherRubrique(forum.rubrique[i]);
}

/**************************************************************/

void AjoutAutForum(Forum* forum)
{
    forum->auteur=(Auteur*)realloc(forum->auteur,(forum->nbreAuteur+1)*sizeof(Auteur));
    SaisirAuteur(&forum->auteur[forum->nbreAuteur]);
    forum->nbreAuteur++;
}

/**************************************************************/

void Save_Inscri(Forum forum,char* ch)
{
    FILE * ficPse ;
    strcpy(forum.auteur->Pseudo,ch);
    ficPse=fopen("PseudoInscri.txt","a");
    fprintf(ficPse,"\n%s",forum.auteur->Pseudo);
    fclose(ficPse);
}

/**************************************************************/

char * Recup_Inscri( )
{
    char * ch=(char*)malloc(sizeof(char));
    FILE * ficPse ;
    ficPse=fopen("PseudoInscri.txt","r");
    if(fscanf(ficPse,"%s",ch)!=1)
        ch = NULL;
    fclose(ficPse);
    return ch ;
}

/**************************************************************/

int Est_Inscri(char * pseudo)
{
    char pse[50];
    char pse1[50];
    FILE *ficPse;
    ficPse = fopen("PseudoInscri.txt", "r");
    while (fgets(pse, sizeof(pse), ficPse) != NULL)
    {
        pse[strcspn(pse, "\n")] = '\0';
        sscanf(pse,"%s",pse1);
        if (strcmp(pse1, pseudo) == 0)
        {
            fclose(ficPse);
            return 1;
        }
    }
    fclose(ficPse);
    return 0;
}

/**************************************************************/

void AjoutRubForum(Forum* forum)
{
    forum->nbreRub++;
    forum->rubrique=(Rubrique*)realloc(forum->rubrique,forum->nbreRub*sizeof(Rubrique));
    SaisirRubrique(&(forum->rubrique[forum->nbreRub-1]));
}

/**************************************************************/

int IndiceRubForum(Forum forum,char * ch)
{
    int i ;
    for (i=0; i<forum.nbreRub; i++)
        if (strcmp(forum.rubrique[i].Theme,ch)==0)
            return i ;
    return -1;
}

/**************************************************************/
int IndiceAutForum(Forum forum,char * pse)
{
    int i ;
    for (i=0 ; i< forum.nbreAuteur ; i++ )
    {
        if (strcmp(forum.auteur[i].Pseudo,pse)==0)
            return i ;
    }
    return -1 ;
}

/**************************************************************/

void AjoutMessForum(Forum* forum,char * ch,int index)
{
    int i ;
    for (i=0; i< forum->nbreAuteur ; i++)
        if (strcmp(forum->auteur[i].Pseudo,ch)==0)
        {
            forum->auteur[i].NombreDeMessagePoste++;
            forum->auteur[i].Date1ereMessage = malloc(sizeof(Date));
            if(forum->auteur[i].Date1ereMessage->annee != 2023)
            {
                GenererDate(forum->auteur[i].Date1ereMessage);
            }
            forum->auteur[i].DateDernierMessage = malloc(sizeof(Date));
            GenererDate(forum->auteur[i].DateDernierMessage);
            break;
        }
    AjouterMessage(&forum->rubrique[index],ch);
}
/**************************************************************/

void Ajout_Mess_Rep_Forum(Forum* forum,int indxMsg,char * ch,int index)
{
    int i ;
    for (i=0; i< forum->nbreAuteur ; i++)
        if (strcmp(forum->auteur[i].Pseudo,ch)==0)
        {
            forum->auteur[i].NombreDeMessagePoste++;
            forum->auteur[i].Date1ereMessage = malloc(sizeof(Date));
            if(forum->auteur[i].Date1ereMessage->annee != 2023)
            {
                GenererDate(forum->auteur[i].Date1ereMessage);
            }
            forum->auteur[i].DateDernierMessage = malloc(sizeof(Date));
            GenererDate(forum->auteur[i].DateDernierMessage);
            break;
        }
    Ajout_Fin_Lsd(&forum->rubrique[index].message[indxMsg].LSDReponses,ch);
}

/**************************************************************/

void Save_Forum(Forum  forum)
{
    int i,j,k;
    CelluleMsg * parc ;
    FILE * ficfor ;
    ficfor=fopen("forum.txt","w");
    fprintf(ficfor,"%d",forum.nbreAuteur);
    for(i=0; i<forum.nbreAuteur; i++)
        fprintf(ficfor,"\n%s %d %d %d %d %d %d %d",forum.auteur[i].Pseudo,forum.auteur[i].Date1ereMessage->jour,forum.auteur[i].Date1ereMessage->mois,forum.auteur[i].Date1ereMessage->annee,forum.auteur[i].DateDernierMessage->jour,forum.auteur[i].DateDernierMessage->mois,forum.auteur[i].DateDernierMessage->annee,forum.auteur[i].NombreDeMessagePoste);
    fprintf(ficfor,"\n%d",forum.nbreRub);
    for (i=0; i<forum.nbreRub; i++)
    {
        fprintf(ficfor,"\n%s %s %d %d %d %d",forum.rubrique[i].Theme,forum.rubrique[i].AdresseMailAnnimateur,forum.rubrique[i].DateDeCreation->jour,forum.rubrique[i].DateDeCreation->mois,forum.rubrique[i].DateDeCreation->annee,forum.rubrique[i].nsi);
        for(j=0; j<forum.rubrique[i].nsi; j++)
            fprintf(ficfor," %s",forum.rubrique[i].SitesInternet+j);
        fprintf(ficfor,"\n%d",forum.rubrique[i].nbreMess);
        for (j=0; j<forum.rubrique[i].nbreMess; j++)
        {
            fprintf(ficfor,"\n%s %s\n%s\n ** %d %d %d",forum.rubrique[i].message[j].Titre,forum.rubrique[i].message[j].Pesduo,forum.rubrique[i].message[j].Text,forum.rubrique[i].message[j].DateDePublication->jour,forum.rubrique[i].message[j].DateDePublication->mois,forum.rubrique[i].message[j].DateDePublication->annee);
            parc = forum.rubrique[i].message[j].LSDReponses;
            fprintf(ficfor,"\n%d",Longeur_Lsd(forum.rubrique[i].message[j].LSDReponses));
            for ( k=0 ; k< Longeur_Lsd(forum.rubrique[i].message[j].LSDReponses) ; k++)
            {
                fprintf(ficfor,"\n%s %s\n%s\n ** %d %d %d",parc->Msg->Titre,parc->Msg->Pesduo,parc->Msg->Text,parc->Msg->DateDePublication->jour,parc->Msg->DateDePublication->mois,parc->Msg->DateDePublication->annee);
                parc = parc->suiv ;
            }
        }
    }
    fclose(ficfor);
}

/**************************************************************/

void Recup_Forum(Forum * forum)
{
    int i,j,k,Lng_rep ;
    CelluleMsg * parc,*prec;
    char aux[20]="cc";
    FILE * ficfor ;
    ficfor=fopen("forum.txt","r");
    fscanf(ficfor,"%d",&forum->nbreAuteur);
    forum->auteur=(Auteur*)malloc(forum->nbreAuteur*sizeof(Auteur));
    for (i=0; i< forum->nbreAuteur; i++)
    {
        forum->auteur[i].Date1ereMessage=malloc(sizeof(Date));
        forum->auteur[i].DateDernierMessage=malloc(sizeof(Date));
        fscanf(ficfor,"\n%s %d %d %d %d %d %d %d",forum->auteur[i].Pseudo,&forum->auteur[i].Date1ereMessage->jour,&forum->auteur[i].Date1ereMessage->mois,&forum->auteur[i].Date1ereMessage->annee,&forum->auteur[i].DateDernierMessage->jour,&forum->auteur[i].DateDernierMessage->mois,&forum->auteur[i].DateDernierMessage->annee,&forum->auteur[i].NombreDeMessagePoste);
    }
    fscanf(ficfor,"%d",&forum->nbreRub);
    forum->rubrique=(Rubrique*)malloc(forum->nbreRub*sizeof(Rubrique));
    for (i=0; i<forum->nbreRub; i++)
    {
        forum->rubrique[i].DateDeCreation=malloc(sizeof(Date));
        fscanf(ficfor,"\n%s %s %d %d %d %d",forum->rubrique[i].Theme,forum->rubrique[i].AdresseMailAnnimateur,&forum->rubrique[i].DateDeCreation->jour,&forum->rubrique[i].DateDeCreation->mois,&forum->rubrique[i].DateDeCreation->annee,&forum->rubrique[i].nsi);
        forum->rubrique[i].SitesInternet=(char**)malloc(sizeof(char*));
        for(j=0; j<forum->rubrique[i].nsi; j++)
        {
            forum->rubrique[i].SitesInternet[j]=(char*)malloc(sizeof(char));
            fscanf(ficfor," %s",&forum->rubrique[i].SitesInternet[j]);
        }
        fscanf(ficfor,"\n%d",&forum->rubrique[i].nbreMess);
        forum->rubrique[i].message=(Message*)malloc(forum->rubrique[i].nbreMess*sizeof(Message));
        for(j=0; j<forum->rubrique[i].nbreMess; j++)
        {
            forum->rubrique[i].message[j].Text;
            fscanf(ficfor,"\n%s %s",forum->rubrique[i].message[j].Titre,forum->rubrique[i].message[j].Pesduo);
            strcpy(forum->rubrique[i].message[j].Text,"");
            while(1)
            {
                fscanf(ficfor,"%s",aux);
                if (strcmp(aux,"**")==0)
                    break ;
                strcat(forum->rubrique[i].message[j].Text,aux);
                strcat(forum->rubrique[i].message[j].Text," ");
            }
            strcpy(aux,"cc");
            forum->rubrique[i].message[j].DateDePublication=malloc(sizeof(Date));
            fscanf(ficfor,"\n %d %d %d",&forum->rubrique[i].message[j].DateDePublication->jour,&forum->rubrique[i].message[j].DateDePublication->mois,&forum->rubrique[i].message[j].DateDePublication->annee);
            forum->rubrique[i].message[j].LSDReponses = malloc(sizeof(CelluleMsg));
            fscanf(ficfor,"\n%d",&Lng_rep);
            forum->rubrique[i].message[j].LSDReponses = malloc(sizeof(CelluleMsg));
            forum->rubrique[i].message[j].LSDReponses = NULL ;

            for (k=0; k< Lng_rep ; k++)
            {
                CelluleMsg * nouv = malloc(sizeof(CelluleMsg));
                nouv->Msg = malloc(sizeof(Message));
                nouv->Msg->LSDReponses = NULL ;
                nouv->suiv = NULL ;
                fscanf(ficfor,"\n%s %s",nouv->Msg->Titre,nouv->Msg->Pesduo);
                strcpy(nouv->Msg->Text,"");
                while(1)
                {
                    fscanf(ficfor,"%s",aux);
                    if (strcmp(aux,"**")==0)
                        break ;
                    strcat(nouv->Msg->Text,aux);
                    strcat(nouv->Msg->Text," ");
                }
                strcpy(aux,"cc");
                nouv->Msg->DateDePublication=malloc(sizeof(Date));
                fscanf(ficfor,"\n %d %d %d",&nouv->Msg->DateDePublication->jour,&nouv->Msg->DateDePublication->mois,&nouv->Msg->DateDePublication->annee);
                if (forum->rubrique[i].message[j].LSDReponses == NULL)
                    forum->rubrique[i].message[j].LSDReponses = nouv ;
                else
                {
                    parc = forum->rubrique[i].message[j].LSDReponses;
                    while ( parc != NULL)
                    {
                        prec = parc ;
                        parc = parc->suiv;
                    }
                    prec->suiv = nouv;
                }

            }
        }
    }
    fclose(ficfor);
}








