#include <iostream>
#include "Date.h"
#include "Email.h"

using namespace std;

int main()
{
    Email d;
    d.setIdentifiant("mamoudou");
    d.setDomaine("gmail");
    d.setMc("com");
    cout<<d.toString();
    return 0;
}
