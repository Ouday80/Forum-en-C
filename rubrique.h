#ifndef RUBRIQUE_H_INCLUDED
#define RUBRIQUE_H_INCLUDED
#include "message.h"

  typedef struct
 {
     char  Theme[20] ;
     Date * DateDeCreation ;
     char  AdresseMailAnnimateur[25] ;
     int nsi ;
     char ** SitesInternet ;
     int nbreMess ;
     Message * message ;

 }Rubrique ;

 void SaisirRubrique(Rubrique*);
 void AfficherRubrique(Rubrique);
 void AjouterMessage(Rubrique*,char *);
 int Taille_Moy_Mess(Rubrique);

#endif // RUBRIQUE_H_INCLUDED
