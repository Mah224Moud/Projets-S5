#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <string>
#include <ctime>

class Date
{
    private:
        //Attributs
        struct tm *d;


    public:
        //constructors
        Date();


        //accessors
        int getJour();
        int getMois();
        int getAnnee();


        //methodes
        void fromDate(const int day, const int month, const int year);
        std::string toString();
};


#endif // DATE_H_INCLUDED
