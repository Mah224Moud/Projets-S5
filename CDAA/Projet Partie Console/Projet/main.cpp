#include <iostream>
#include "Date.h"
#include "Interaction.h"
#include "Todo.h"
#include "Email.h"

#include <string>

using namespace std;

int main()
{
    Email e("saikououmarbah21gmail.com");

    cout << "Identifiant : " << e.getIdentifiant() << endl;
    cout << "Domaine : " << e.getDomaine() << endl;
    cout << "mc : " << e.getMc() << endl;
    cout << e.toString() << "\n"<< endl;

    Email f;
    f.fromString("Saikou_Bah@etu.u-bourgogne.fr");

    cout << "Identifiant : " << f.getIdentifiant() << endl;
    cout << "Domaine : " << f.getDomaine() << endl;
    cout << "mc : " << f.getMc() << endl;
    cout << f.toString() << "\n" << endl;


    Email g("saikououmarbah21@gmail.com");

    cout << "Identifiant : " << g.getIdentifiant() << endl;
    cout << "Domaine : " << g.getDomaine() << endl;
    cout << "mc : " << g.getMc() << endl;
    cout << g.toString() << "\n"<< endl;

    return 0;
}
