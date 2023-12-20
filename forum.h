#ifndef FORUM_H_INCLUDED
#define FORUM_H_INCLUDED
#include "rubrique.h"
#include "auteur.h"
#include <stdio.h>

typedef struct
{
    char * AdresseInternet ;
    char * AdresseMailResponsable ;
    int nbreAuteur ;
    Auteur * auteur ;
    int nbreRub;
    Rubrique * rubrique ;
}Forum ;
void SaisirForum(Forum*);
void AfficherForum(Forum);
void AjoutAutForum(Forum*);
void Save_Inscri(Forum,char*);
char * Recup_Inscri();
int Est_Inscri(char *);
void AjoutRubForum(Forum*);
void Recup_Rub_Forum(Forum*);
void Save_Forum(Forum );
void Recup_Forum(Forum *);
int IndiceRubForum(Forum,char *);
void AjoutMessForum(Forum*,char *,int);
int IndiceAutForum(Forum,char*);
void AfficherMessAutForum(Forum,int );
void Ajout_Mess_Rep_Forum(Forum* ,int ,char * ,int);

#endif // FORUM_H_INCLUDED
