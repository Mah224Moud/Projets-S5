#include "Date.h"
/**
 *@namespace std: utilisation de std
*/
using namespace std;

/**
    *@brief Constructueur par défaut.
    *@details Avec le constructeur par défaut, la date est initialisé à la date courante
*/
Date::Date()
{
    time_t n= time(0);
    d= localtime(&n);
}

/**
    *@brief Constructeur avec paramètre.
    *@details Avec ce constructeur, on indique le jour, le mois et l'année souhaité
    *@param day : le jour;
    *@param month : le mois;
    *@param year : l'année;
*/
Date::Date(const int day, const int month, const int year)
{
    time_t n= time(0);
    d = localtime(&n);
    d -> tm_mday = day;
    d -> tm_mon = month - 1;
    d -> tm_year = year - 1900;
}

/**
    *@brief Récupération du jour de la date
    *@return un entier qui représente le jour
*/
int Date::getJour()
{
    return this->d->tm_mday;
}

/**
    *@brief Récupération du mois de la date
    *@return un entier qui représente le mois
*/
int Date::getMois()
{
    return this->d->tm_mon+1;
}

/**
    *@brief Récupération de l'année de la date
    *@return un entier qui représente l'année
*/
int Date::getAnnee()
{
    return this->d->tm_year + 1900;
}

/**
    *@brief Récupération de la date.
    *@details Cette fonction renvoie l'instance tm pointée par d.
*/
tm Date::getDate()
{
    return *d;
}

/**
    *@brief
    *@details
*/
void Date::setDate(const tm& t)
{
    *d = t;
}

/**
    @brief Récupération en fonction des paramètres day, month et year d'une structure tm contenant la date définie
    @param day : le jour de la nouvelle date
    @param month : le mois de la nouvelle date
    @param year : l'année de la nouvelle date
*/
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

/**
    @brief Récupération de la date avec le format jj/mm/aaaa
    @return Chaine de caractère contenant la date
*/
string Date::toString()
{
    return std::to_string( getJour())+"/"+std::to_string(getMois())+"/"+to_string(getAnnee());
}

/**
    *@brief Surchage de l'opérateur d'égalité
    *@details Cette fonction compare deux dates.
    Elle renvoie true si les jours, mois et années sont identiques.
    *@param autre : le tm à comparer avec le tm de la date actuelle.
*/
bool Date::operator==(const tm& autre)
{
    return d->tm_mday == autre.tm_mday && d->tm_mon == autre.tm_mon && d->tm_year == autre.tm_year;
}
