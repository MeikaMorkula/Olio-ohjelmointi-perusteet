#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas A("Seppo", 1000);
    A.showSaldo();
    cout<<endl;

    A.talletus(250);
    A.luotonNosto(150);
    A.showSaldo();
    A.luotonNosto(900);
    A.luotonMaksu(100);
    A.luotonNosto(400);

    cout<<endl;

    Asiakas B("Jorma", 1000);
    B.showSaldo();

    cout<<endl;
    A.tiliSiirto(170, B);
    cout<<endl;
    B.showSaldo();
    A.showSaldo();
    B.nosto(50);
    B.tiliSiirto(10,A);

    cout<<endl;
    Asiakas C("Carlos", 1500);
    cout<<endl;

    B.tiliSiirto(100,C);

    C.showSaldo();
    B.showSaldo();

    cout<<endl;
    A.luotonMaksu(200);
    cout<<endl;
    A.showSaldo();
    A.nosto(10);
    cout<<endl;
    A.showSaldo();
    cout<<endl;
    cout<<endl;
    A.tiliSiirto(1.50, B);
    B.showSaldo();





    return 0;
}
