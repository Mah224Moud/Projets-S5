#include <iostream>
#include "Date.h"
#include "Email.h"

using namespace std;

int main()
{
    Date d;

    d.fromDate(1,07,2021);
    cout<<d.toString();
    return 0;
}
