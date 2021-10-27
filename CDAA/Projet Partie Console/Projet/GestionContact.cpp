/**
    *
*/

#include "GestionContact.h"

/**
    *
*/
GestionContact::GestionContact()
{

}

/**
    *
*/
GestionContact::~GestionContact()
{
    listContact.clear();
}


/**
    *
*/
void GestionContact::addContact(const Contact& c)
{
    listContact.push_back(c);
}

/**
    *@todo Demander au prof
*/

/*
Contact* GestionContact::getContactByName(const std::string& nom)
{
    auto it = listContact.begin();
    bool found = false;

    while((it != listContact.end()) && (found == false))
    {
        if(it->getNom() == nom)
        {
            found = true;
        }
        else
            it++;
    }

    if(found) return it;
    else return NULL;
}
*/

/**
    *
*/
void GestionContact::removeContact(const std::string& nom)
{
    auto it = listContact.begin();
    bool found = false;

    while((it != listContact.end()) && (found == false))
    {
        if(it->getNom() == nom)
        {
            found = true;
            it = listContact.erase(it);
        }
        else
            it++;
    }
}

/**
    *
*/
std::ostream& operator<<(std::ostream& os, const GestionContact& gest)
{
    for(auto it : gest.getlistContact())
    {
        os << it << "\n\n";
    }
    return os;
}

