#include <iostream>
#include <string>


#include "Date.h"
#include "Contact.h"
#include "GestionTodo.h"
#include "Email.h"
#include "GestionContact.h"
#include "GestionInteraction.h"

using namespace std;

void testDateComparator();
void testContact();// Test Classe Contact
void testEmail();
void testGestionTodo();
void testGestionInteraction();
void testGestionContact();


int main()
{
    //testGestionTodo();
    //testGestionInteraction();
    //testContact();
    //testGestionContact();
    testDateComparator();
}

void testContact()
{
    Date d;

    //Contact contact;
    Contact contact("BAH", "Saikou Oumar", "Ramuo's");
    d.fromDate(14, 07, 2001);
    contact.setDateCreation(d.getDate());
    contact.setDateLastModif(d.getDate());
    contact.setEmail("saikououmarbah21@gmail.com");
    contact.setTelephone("0666693425");
    //contact.setPhoto("photo.png");


    Interaction i("Test 1 Interaction");
    d.fromDate(1, 1, 2021);
    i.setDate(d.getDate());
    contact.addInteraction(i);

    Interaction j;
    j.setContenu("Test 2 Interaction");
    contact.addInteraction(j);

    Interaction k;
    d.fromDate(13,03,2020);
    k.setDate(d.getDate());
    k.setContenu("Test 2 Interaction");
    contact.addInteraction(k);



    cout << contact << endl;
}


void testEmail()
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

}

void testGestionTodo()
{
    Date d;

    Interaction i1("Interaction 1");
    d.fromDate(1,2,2000);
    i1.setDate(d.getDate());

    Interaction i2("Interaction 2");
    d.fromDate(2, 12, 2020);
    i2.setDate(d.getDate());

    Interaction i3("Interaction 3");

    Todo t1;
    t1.setInteraction(i1);
    t1.setContenu("Todo 1");


    Todo t2(i1, "Todo 2");
    d.fromDate(13,10,2022);
    t2.setDate(d.getDate());

    Todo t3;
    t3.setInteraction(i3);
    t3.setContenu("Todo 3");


    Todo t4(i2, "Todo 4");
    d.fromDate(13,10,2022);
    t4.setDate(d.getDate());

    Todo t5;
    t5.setInteraction(i3);
    t5.setContenu("Todo 5");


    Todo t6(i3, "Todo 6");
    d.fromDate(13,10,2023);
    t6.setDate(d.getDate());

    GestionTodo gest;

    gest.addTodo(t1);
    gest.addTodo(t2);
    gest.addTodo(t3);
    gest.addTodo(t4);
    gest.addTodo(t5);
    gest.addTodo(t6);


    cout << gest << endl;
    cout << "\n\n" << endl;

    gest.removeTodo("Todo 3");
    cout << gest << endl;
    cout << "\n\n" << endl;

    gest.removeAllInteractionTodo(i3);
    cout << gest << endl;
    cout << "\n\n" << endl;

    cout << gest.getAllInteractionTodo(i1) << endl;
}

void testGestionContact()
{
    Date d;

    //Contact contact;
    Contact contact("BAH", "Saikou Oumar", "Ramuo's");
    d.fromDate(14, 07, 2001);
    contact.setDateCreation(d.getDate());
    contact.setDateLastModif(d.getDate());
    contact.setEmail("saikououmarbah21@gmail.com");
    contact.setTelephone("0666693425");
    //contact.setPhoto("photo.png");


    Interaction i("Test 1 Interaction");
    d.fromDate(1, 1, 2021);
    i.setDate(d.getDate());
    contact.addInteraction(i);

    Interaction j;
    j.setContenu("Test 2 Interaction");
    contact.addInteraction(j);

    Interaction k;
    d.fromDate(13,03,2020);
    k.setDate(d.getDate());
    k.setContenu("Test 2 Interaction");
    contact.addInteraction(k);

    Contact contact1("DIALLO", "Mamoudou", "Ramuo's");
    d.fromDate(13, 12, 1995);
    contact1.setDateCreation(d.getDate());
    contact1.setDateLastModif(d.getDate());
    contact1.setEmail("Diallo_Mamoudou@etu.u-bourgogne.fr");
    contact1.setTelephone("0749211152");
    contact1.setPhoto("photo.png");


    Interaction i1("Test 11 Interaction");
    d.fromDate(1, 1, 2021);
    i1.setDate(d.getDate());
    contact1.addInteraction(i1);

    Interaction j1;
    j1.setContenu("Test 12 Interaction");
    contact1.addInteraction(j1);

    Interaction k1;
    d.fromDate(13,03,2020);
    k1.setDate(d.getDate());
    k1.setContenu("Test 13 Interaction");
    contact1.addInteraction(k1);

    GestionContact gest;
    gest.addContact(contact);
    gest.addContact(contact1);

    cout << gest << endl;

    gest.removeContact("BAH");
    cout << "\n\n";
    cout << gest << endl;

}

void testDateComparator()
{
    tm* date1 = new tm();
    tm* date2 = new tm();

    Date d;

    *date1 = d.getDate();

    d.fromDate(27, 10, 2021);
    *date2 = d.getDate();

    d.setDate(*date2);

    if(d <= *date1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if(d >= *date1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

void testGestionInteraction()
{
    Date d;

    Interaction i("Test 1 Interaction");
    d.fromDate(1, 1, 2021);
    i.setDate(d.getDate());

    Todo td1(i, "Todo 1");
    Todo td2(i, "Todo 2");
    d.fromDate(1, 1, 2022);
    td2.setDate(d.getDate());


    Interaction j("Test 2 Interaction");
    Todo td3(j, "Todo 3");
    Todo td4(j, "Todo 4");
    d.fromDate(1, 1, 2022);
    td4.setDate(d.getDate());

    Interaction k("Test 3 Interaction");
    d.fromDate(1, 1, 2001);
    k.setDate(d.getDate());
    Todo td5(k, "Todo 5");
    Todo td6(k, "Todo 6");
    d.fromDate(1, 1, 2022);
    td6.setDate(d.getDate());

    GestionInteraction gest;

    gest.addInteraction(i);
    gest.addTodo("Test 1 Interaction", td1);
    gest.addTodo("Test 1 Interaction", td2);


    gest.addInteraction(j);
    gest.addTodo("Test 2 Interaction", td3);
    gest.addTodo("Test 2 Interaction", td4);

    gest.addInteraction(k);
    gest.addTodo("Test 3 Interaction", td5);
    gest.addTodo("Test 4 Interaction", td6);

    cout << gest << endl;

    gest.removeInteraction("Test 2 Interaction");

    cout << "\n\n" << endl;
    cout << gest << endl;

}

