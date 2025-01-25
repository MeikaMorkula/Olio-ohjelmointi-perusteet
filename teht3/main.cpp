#include "chef.h"
#include "italianchef.h"
#include <iostream>

using namespace std;

int main()
{
    Chef c1("Gordon");
    c1.getName();
    c1.makeSalad(11);
    c1.makeSoup(14);

    ItalianChef c2("Luigi");
    c2.getName();
    c2.makeSalad(9);
    c2.askSecret("pizza", 12,12);
    c2.askSecret("vaarasalana", 12,12);

    return 0;
}
