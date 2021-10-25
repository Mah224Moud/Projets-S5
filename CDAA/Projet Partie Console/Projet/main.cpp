#include <iostream>
#include "Date.h"
#include "Interaction.h"
#include "Todo.h"

using namespace std;

int main()
{
    Date d;
sd

    Todo i;
    i.setContenu("Todo Quelconque");
    d.fromDate(14,07,2001);
    i.setDate(d.getDate());

    Interaction t;
    t.setContenu("Interaction Quelconque");
    d.fromDate(1,1,2001);
    t.setDate(d.getDate());

    cout<<"d = "<<d.toString()<<endl;

    cout<<i<<endl;
    cout<<t<<endl;
    return 0;
}
