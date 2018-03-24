#include <iostream>
#include "cemploye.h"
using namespace std;

int main()
{

    Cemploye empl1("", "Sandwidi", "", "", "",700000,CDate(), CDate(17, 6, 1997),Cemploye::fonctionnaire);
     cout<<empl1.calculerSalaire(100);
    Cemploye empl;
    Cemploye empl2 = empl1;


    return 0;
}
