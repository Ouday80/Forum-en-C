#ifndef PROFIL_H_INCLUDED
#define PROFIL_H_INCLUDED
#include "date.h"

typedef struct
 {
    int MotDePasse ;
    char * Nom ;
    char * Prenom ;
    char * Adresse ;
    Date * DateDeNaissance ;
    char * Courriel ;
    int NumTelephone ;
 }Profil ;

 void SaisirProfil(Profil*);
 void AfficherProfil(Profil);
 void Save_Profil(Profil,char*);
 void Recup_Profil(char *,Profil*);


#endif // PROFIL_H_INCLUDED
