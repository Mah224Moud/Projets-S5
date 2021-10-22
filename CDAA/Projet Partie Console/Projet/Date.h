/**
    *@file Date.h
    *@brief Fichier d'entête de la classe Date
    *@author DIALLO Mamoudou
    BAH Saikou Oumar
*/

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <string>
#include <ctime>


/**
    *@class Date Date.h "Date.h"
    *@brief La classe Date permet de stocker des dates dans des structures tm
    *@details La classe Date permet
        *@li de stocker une date, par défaut la date du système;
        *@li de récuperer séparement le jour, le mois et l'année;
        *@li de récuperer la date sous forme de string;
*/
class Date
{
    private:
    /**
        @struct tm
        @brief structure simple du C/C++ pour manipuler les dates
        @see https://www.cplusplus.com/reference/ctime/tm/
    */
        struct tm *d;

    public:
        Date();

        int getJour();
        int getMois();
        int getAnnee();

        void fromDate(const int day, const int month, const int year);
        void operator= (Date&);
        std::string toString();
};


#endif // DATE_H_INCLUDED
