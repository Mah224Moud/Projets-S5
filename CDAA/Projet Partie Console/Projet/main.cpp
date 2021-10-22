#include <iostream>
#include "Date.h"
#include "Email.h"

using namespace std;

int main()
{
    Date d, e;

    d.fromDate(1,07,2021);


    cout<<"d = "<<d.toString()<<endl;
    cout<<"e = "<<e.toString()<<endl;
    return 0;
}
