#include <stdio.h>
#include <stdlib.h>
#include "profil.h"
#include "auteur.h"
#include "forum.h"


int main()
{
    Profil  profil ;
    Auteur  auteur ;
    Forum forum = {.AdresseInternet = strdup("http://forum.tn"),.AdresseMailResponsable = strdup("Moderateur@gmail.com"),.nbreAuteur = 0,.auteur = {NULL,NULL,NULL, NULL, 0, NULL},.nbreRub = 0,.rubrique = {NULL, NULL, NULL, 0, NULL, 0, 0, NULL}};
    AfficherForum(forum);
    Recup_Forum(&forum);
    Profil  pro ;
    CelluleMsg * L ;
    L = malloc(sizeof(L));
    Message MsgAjout;
    Date datejour ;
    char ch[50],theme_Rub[20],pse[20],prorecup[20],TitMsg[20],TitMsgAff[20],TitRech[20];
    int Choix,i,v,a,b=0,index,index1,max,mdp ;
    while(1)
    {
        Choix = Menu1();
        fflush(stdin);
        switch(Choix)
        {
        case 1 :
            SaisirProfil(&profil);
            AjoutAutForum(&forum);
            Save_Profil(profil,forum.auteur[forum.nbreAuteur-1].Pseudo);
            Save_Account(forum.auteur[forum.nbreAuteur-1].Pseudo,profil.MotDePasse);
            printf("\n------------vous etes inscris avec succes-------------\n");
            break ;
        case 2 :
            a=0;
            printf("\nPseudo :");
            scanf("%s",ch);
            printf("\nMot de passe :");
            scanf("%d",&mdp);
            if(Est_Valide_Account(&ch,mdp)==1)
            {
                printf("\n:) Succes du connexion :)\n");
                a=1;
            }
            else
                printf("\n:( Veillez verifier vos coordonnees :(\n");
            while(a==1)
            {
                Choix=Menu2();
                fflush(stdin);
                switch(Choix)
                {
                case 1 :
                    AfficherForum(forum);
                    break;
                case 2 :
                    AjoutRubForum(&forum);
                    break;
                case 3 :
                    printf("\nSaisir le theme de la rubrique que vous souhaitez rejoindre :");
                    scanf("%s",theme_Rub);
                    index=IndiceRubForum(forum,theme_Rub);
                    if(index!=-1)
                        AfficherRubrique(forum.rubrique[index]);
                    else
                    {
                        printf("\nRubrique introuvable\n");
                        break;
                    }
                    a=0;
                    while(a==0)
                    {
                        Choix=Menu4();
                        fflush(stdin);
                        switch(Choix)
                        {
                        case 1 :
                            a=1;
                            while (a==1)
                            {
                                Choix = Menu5();
                                fflush(stdin);
                                switch(Choix)
                                {
                                case 1 :
                                    AjoutMessForum(&forum,&ch,index);
                                    break;
                                case 2 :
                                    printf("\nReponse a :");
                                    scanf("%s",TitMsg);
                                    for(i=0; i<forum.rubrique[index].nbreMess; i++)
                                    {
                                        if(strcmp(TitMsg,forum.rubrique[index].message[i].Titre)==0)
                                        {
                                            Ajout_Mess_Rep_Forum(&forum,i,&ch,index);
                                            break ;
                                        }
                                    }
                                    if (i==forum.rubrique[index].nbreMess)
                                        printf("\nMessage n'existe pas !\n");
                                    break ;
                                case 3 :
                                    printf("\nDonner le titre du message a supprimer :");
                                    scanf("%s",TitMsg);
                                    for(i=0; i<forum.rubrique[index].nbreMess; i++)
                                    {
                                        if( Exist_Mess(forum.rubrique[index].message[i].LSDReponses,TitMsg)==1 )
                                        {
                                            Supprimer_Msg_Lsd(&forum.rubrique[index].message[i].LSDReponses,TitMsg);
                                            printf("\nmessage supprimee avec succes :)");
                                            break ;
                                        }
                                    }
                                    if (i==forum.rubrique[index].nbreMess)
                                        printf("\nMessage n'existe pas !\n");
                                    break ;
                                case 4 :
                                    printf("\nSaisir le titre du message :");
                                    scanf("%s",TitMsgAff);
                                    for(i=0; i<forum.rubrique[index].nbreMess; i++)
                                    {
                                        if( strcmp(forum.rubrique[index].message[i].Titre,TitMsgAff)==0 )
                                        {
                                            Afficher_LSD(forum.rubrique[index].message[i].LSDReponses);
                                            break ;
                                        }
                                    }
                                    if (i==forum.rubrique[index].nbreMess)
                                        printf("\nMessage n'existe pas !\n");
                                    break ;
                                case 0 :
                                    a=0 ;
                                    break ;
                                default :
                                    break ;
                                }
                            }
                            break;
                        case 2 :
                            a=2 ;
                            while(a==2)
                            {
                                Choix = Menu6();
                                fflush(stdin);
                                switch(Choix)
                                {
                                case 1 :
                                    printf("\ndonner le Pseudo de l'auteur que vous souhaitez afficher :\n");
                                    scanf("%s",&pse);
                                    index1=IndiceAutForum(forum,pse);
                                    if (index1!=-1)
                                    {
                                        AfficherAuteur(forum.auteur[index1]);
                                    }
                                    else
                                    {
                                        printf("\nauteur introuvable \n");
                                        break ;
                                    }
                                    break;
                                case 2 :
                                    printf("\ndonner le Pseudo de l'auteur que vous souhaitez afficher :\n");
                                    scanf("%s",&pse);
                                    index1=IndiceAutForum(forum,pse);
                                    if (index1!=-1)
                                    {
                                        for (i=0; i< forum.rubrique[index].nbreMess ; i++)
                                            if(strcmp(forum.rubrique[index].message[i].Pesduo,pse)==0)
                                            {
                                                printf("\n.....................................................................................................\n");
                                                AfficherMessage(forum.rubrique[index].message[i]);
                                            }
                                    }

                                    else
                                    {
                                        printf("\nauteur introuvable \n");
                                        break ;
                                    }
                                    break ;
                                case 3 :
                                    printf("\ndonner le pseudo de l'auteur que vous souhaitez afficher le profil :");
                                    scanf("%s",&prorecup);
                                    Recup_Profil(&prorecup,&pro);
                                    printf("%s",prorecup);
                                    AfficherProfil(pro);
                                    break;
                                case 0 :
                                    a=0;
                                default :
                                    break ;
                                }
                            }
                            break ;
                        case 3 :
                            a=3;
                            while(a==3)
                            {
                                Choix = Menu7();
                                fflush(stdin);
                                switch(Choix)
                                {
                                case 1 :
                                    printf("\nSaisir votre mot :");
                                    scanf("%s",TitRech);
                                    for ( i=0 ; i < forum.rubrique[index].nbreMess ;i++)
                                    {
                                        printf("\nVoici les messages contenant  ''%s''\n",TitRech);
                                        Trouver_Mot(TitRech,&forum.rubrique[index].message[i]);
                                    }
                                    break;
                                case 2 :
                                    printf("\nSaisir la date du jour souhaitez :");
                                    SaisirDate(&datejour);
                                    for (i=0 ;i<forum.rubrique[index].nbreMess ;i++)
                                        Trouver_Msg_Jour(datejour,&forum.rubrique[index].message[i]);
                                    break;
                                case 3 :
                                    printf("\nAu moyenne un auteur a poste %d message(s) \n",(int)forum.rubrique[index].nbreMess/forum.nbreAuteur);
                                    break ;
                                case 4 :
                                    printf("\nUn message contient au moyen %d caracteres \n",Taille_Moy_Mess(forum.rubrique[index]));
                                    break;
                                case 5 :
                                    max = forum.auteur[0].NombreDeMessagePoste ;
                                    for (i=0 ;i<forum.nbreAuteur ;i++)
                                        if (forum.auteur[i].NombreDeMessagePoste >= max)
                                            {
                                                max = forum.auteur[i].NombreDeMessagePoste ;
                                                v = i ;
                                            }
                                    printf("\nL'auteur le plus actif est : %s \navec u nombre de messages postes : %d\n",forum.auteur[v].Pseudo,max);
                                    break ;
                                case 0 :
                                    a=0;
                                    break ;
                                default :
                                    break ;
                                }
                            }
                            break;
                        case 0 :
                            a=1;
                            break;
                        default :
                            break;
                        }
                    }
                    break;
                case 0 :
                    a=0;
                    break;
                default :
                    break;
                }
            }
            break;
        case 3 :
            a=1;
            while(a==1)
            {
                Choix=Menu3();
                fflush(stdin);
                switch(Choix)
                {
                case 1 :
                    printf("\ndonner le pseudo de l'auteur que vous souhaitez afficher le profil :");
                    scanf("%s",&prorecup);
                    Recup_Profil(&prorecup,&pro);
                    printf("%s",prorecup);
                    AfficherProfil(pro);
                    break;

                case 2 :
                    AfficherForum(forum);
                    break;
                case 0 :
                    a=0;
                    break;
                }
            }
            break;
        case 0 :
            Save_Forum(forum);
            return 0 ;
        default :
            break ;
        }
    }
    return 0;
}
