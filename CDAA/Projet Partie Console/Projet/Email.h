#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED
#include <string>

class Email
{
    private:
        //Attributs
        std::string identifiant;
        std::string domaine;
        std::string mc;

    public:
        //Constructors
        Email();



        //Accessors
        std::string getIdentifiant();
        void setIdentifiant(std::string id);

        std::string getDomaine();
        void setDomaine(std::string domaine);

        std::string getMc();
        void setMc(std::string mc);


        //methodes
        void fromString(const std:: string &);
        std:: string toString();
};

#endif // EMAIL_H_INCLUDED
