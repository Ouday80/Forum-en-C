#ifndef AUTEUR_H_INCLUDED
#define AUTEUR_H_INCLUDED
#include "profil.h"
#include "message.h"

 typedef struct
 {
     Profil * profil ;
     char  Pseudo[20] ;
     Date * Date1ereMessage ;
     Date * DateDernierMessage ;
     int NombreDeMessagePoste ;
     Message * message ;
 }Auteur ;

 void SaisirAuteur(Auteur *);
 void AfficherAuteur(Auteur);
 void Save_Account(char *,int);
 int Est_Valide_Account(char *,int );


#endif // AUTEUR_H_INCLUDED
