#include "Contact.h"

Contact:: Contact()
{

}


std::string Contact:: getNom()
{
    return this->nom;
}
void Contact:: setNom(std::string name)
{
    this->nom= name;
}


std::string Contact:: getPrenom()
{
    return this->prenom;
}
void Contact:: setPrenom(std::string lastname)
{
    this->prenom= lastname;
}


std::string Contact:: getEntreprise()
{
    return this->entreprise;
}
void Contact:: setEntreprise(std::string company)
{
    this->entreprise= company;
}


std::string Contact:: getTelephone()
{
    return this->telephone;
}
void Contact:: setTelephone(std::string phone)
{
    this->telephone= phone;
}


std::string Contact:: getPhoto()
{
    return this->URIphoto;
}


void Contact:: setPhoto(std::string pic)
{
    this->URIphoto= pic;
}

