#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include "date.h"

typedef struct
 {
     char  Titre[20];
     char  Text[150];
     Date * DateDePublication ;
     char  Pesduo[20] ;
     struct CelluleMsg * LSDReponses ;
 }Message ;

  struct CelluleMsg
 {
     Message * Msg ;
     struct CelluleMsg * suiv ;
 } ;

 typedef struct CelluleMsg CelluleMsg ;


void Initialiser_LSD(CelluleMsg *);
void Ajout_Fin_Lsd(CelluleMsg **,char * );
void Supprimer_Msg_Lsd(CelluleMsg **,char *);
void Afficher_LSD(CelluleMsg *);
void SaisirMessage(Message*,char *);
void AfficherMessage(Message);
int Exist_Mess(CelluleMsg*,char *);
int Longeur_Lsd(CelluleMsg * );
void Trouver_Mot(char * ,Message*);
void Afficher_MSG(Message);
void Trouver_Msg_Jour(Date,Message*);


#endif // MESSAGE_H_INCLUDED
