#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <string>
#include "Email.h"
#include "Date.h"

class Contact
{
    private:
        //attributs
        std::string nom;
        std::string prenom;
        std::string entreprise;
        std::string telephone;
        std::string URIphoto;
        Date dateCreation;
        Email mail;



    public:
    //constructors
    Contact();


    //accessors
    std::string getNom();
    void setNom(std::string name);

    std::string getPrenom();
    void setPrenom(std::string lastname);

    std::string getEntreprise();
    void setEntreprise(std::string company);

    std::string getTelephone();
    void setTelephone (std::string phone);

    std::string getPhoto();
    void setPhoto(std::string pic);




    //methodes

};

#endif // CONTACT_H_INCLUDED
