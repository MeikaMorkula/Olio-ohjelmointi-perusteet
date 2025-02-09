#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

using namespace std;

int main()
{
    Notifikaattori n;
    Seuraaja A("A");
    Seuraaja B("B");
    Seuraaja C("C");
    Seuraaja D("D");

    n.lisaa(&A);
    n.lisaa(&B);
    n.lisaa(&C);

    cout<<endl;

    n.tulosta();
    cout<<endl;

    n.postita("Tama on viesti 1");
    cout<<endl;

    n.poista(&C);

    cout<<endl;

    n.postita("Tama on viesti 2");
    cout<<endl;

     n.poista(&B);

    n.lisaa(&D);
     n.postita("Tama on viesti 3");
     cout<<endl;

    return 0;

}
