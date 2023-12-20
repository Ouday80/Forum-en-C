#include "date.h"
#include <time.h>

void SaisirDate(Date * date)
{
    do
    {
        printf("\ndonner le jour :");
        scanf("%d",&date->jour);
    }
    while(((date->jour)>31)||((date->jour)<=0));
    do
    {
        printf("\ndonner le mois :");
        scanf("%d",&date->mois);
    }
    while(((date->mois>12)||(date->mois)<=0));
    printf("\ndonner l'annee :");
    scanf("%d",&date->annee);

}

/**************************************************************/

void GenererDate(Date * date)
{
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    date->jour = localTime->tm_mday;
    date->mois = localTime->tm_mon + 1;
    date->annee = localTime->tm_year + 1900;

}

/**************************************************************/

void AfficherDate(Date date)
{
    printf(" %i/%i/%i",date.jour,date.mois,date.annee);
}












