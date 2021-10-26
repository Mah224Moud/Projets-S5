/**
    *@file Date.h
    *@brief Fichier d'entête de la classe Date
    *@author DIALLO Mamoudou
    *@author BAH Saikou Oumar
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
        tm* d;

    public:
        /// Constructeur par défaut de la classe Date
        Date();
        /// Constructeur avec paramètre jour, mois et année de la classe Date
        Date(const int, const int, const int);

        int getJour();
        int getMois();
        int getAnnee();

        tm getDate();
        void setDate(const tm&);

        void fromDate(const int day, const int month, const int year);
        std::string toString();

        bool operator==(const tm&);
};


#endif // DATE_H_INCLUDED
