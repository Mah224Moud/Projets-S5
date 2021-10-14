
#include "Date.h"
using namespace std;

/*************************
*******Constructors*******
*************************/
Date:: Date()
{
    time_t n= time(0);
    d= localtime(&n);
}


/************************
*******Accessors*********
************************/


//jour
int Date::getJour()
{
    return this->d->tm_mday;
}


//mois
int Date::getMois()
{
    return this->d->tm_mon+1;
}


//annee
int Date::getAnnee()
{
    return this->d->tm_year + 1900;
}






/**********************
******Methodes*********
*********************/
void Date::fromDate(const int day, const int month, const int year)
{
    time_t nt; //now time
    struct tm nd; //now day
    nd.tm_mday= day;
    nd.tm_mon= month - 1;
    nd.tm_year= year - 1900;

    nt= mktime(&nd);
    d= localtime_r(& nt, &nd);

}



string Date::toString()
{
    string s= ""+ getAnnee();
    return s;
    //return getJour()+"/"+getMois()+"/"+getAnnee();
}
