/**
    *
*/

#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include <list>
#include <ostream>

#include "Contact.h"

/**
    *
*/
class GestionContact
{
    private:
        std::list<Contact> listContact;

    public:
        GestionContact();
        ~GestionContact();

        std::list<Contact> GetlistContact() const{ return listContact;}
        inline unsigned getSize(){return listContact.size();}

        void addContact(const Contact&);
        void removeContact(const std::string&);

        friend std::ostream& operator<<(std::ostream&, const GestionContact&);
};

#endif // GESTIONCONTACT_H
