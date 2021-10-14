#include "Contact.h"

/*************************
*******Constructors*******
*************************/
Contact:: Contact()
{

}


/************************
*******Accessors*********
************************/


//nom
std::string Contact:: getNom()
{
    return this->nom;
}
void Contact:: setNom(std::string name)
{
    this->nom= name;
}



//prenom
std::string Contact:: getPrenom()
{
    return this->prenom;
}
void Contact:: setPrenom(std::string lastname)
{
    this->prenom= lastname;
}


//entreprise
std::string Contact:: getEntreprise()
{
    return this->entreprise;
}
void Contact:: setEntreprise(std::string company)
{
    this->entreprise= company;
}



//telephone
std::string Contact:: getTelephone()
{
    return this->telephone;
}
void Contact:: setTelephone(std::string phone)
{
    this->telephone= phone;
}



//photo
std::string Contact:: getPhoto()
{
    return this->URIphoto;
}
void Contact:: setPhoto(std::string pic)
{
    this->URIphoto= pic;
}




/**********************
******Methodes*********
*********************/

