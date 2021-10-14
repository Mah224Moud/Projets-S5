#include "Date.h"
using namespace std;

Date:: Date()
{
    time_t n= time(0);
    d= localtime(&n);
}



int Date::getJour()
{
    return this->d->tm_mday;
}



int Date::getMois()
{
    return this->d->tm_mon+1;
}



int Date::getAnnee()
{
    return this->d->tm_year + 1900;
}


void Date::fromDate(const int day, const int month, const int year)
{
    time_t nt = time(NULL);
    struct tm* nd = localtime(&nt);

    nd -> tm_mday= day;
    nd -> tm_mon= month - 1;
    nd -> tm_year= year - 1900;

    nt = mktime(nd);
    d = localtime(&nt);
}



string Date::toString()
{
    return std::to_string( getJour())+"/"+std::to_string(getMois())+"/"+to_string(getAnnee());
}
