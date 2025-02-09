#include "seuraaja.h"

Seuraaja::Seuraaja() {}

Seuraaja::Seuraaja(string n)
{
    nimi=n;
    cout<<"Luodaan seuraaja "<< nimi <<endl;
}

void Seuraaja::paivitys(string msg)
{
    cout<<"Seuraaja "<<nimi << " Sai viestin: "<< msg <<endl;
}

string Seuraaja::getNimi() const
{
    return nimi;
}
