#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <stdio.h>

typedef struct
{
    int jour ;
    int mois ;
    int annee ;

}Date ;

void SaisirDate(Date*);
void GenererDate(Date*);
void AfficherDate(Date);


#endif // DATE_H_INCLUDED
