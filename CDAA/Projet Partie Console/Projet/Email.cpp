#include "Email.h"
#include <string>

using namespace std;

Email:: Email()
{

}


string Email::getIdentifiant()
{
    return this->identifiant;
}
void Email::setIdentifiant(string id)
{
    this->identifiant= id;
}


string Email::getDomaine()
{
    return this->domaine;
}


void Email::setDomaine(string domaine)
{
    this->domaine= domaine;
}


string Email::getMc()
{
    return this->mc;
}


void Email::setMc(string mc)
{
    this->mc= mc;
}


void Email::fromString(const std:: string &)
{

}


string Email:: toString()
{

    return getIdentifiant()+"@"+getDomaine()+"."+getMc();
}
