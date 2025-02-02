#include "pankkitili.h"

Pankkitili::Pankkitili()
{

}

Pankkitili::Pankkitili(string nimi)
{
    omistaja = nimi;
    cout<<"Pankkitili luotu " << nimi <<":lle"<<endl;
}

bool Pankkitili::deposit(double amount)
{
    if(amount>=0)
    {
        saldo+=amount;
        cout<<omistaja <<" Pankkitili: talletus "<<amount<<" tehty"<<endl;
        return true;
    }
    else
    {
        cout<<"Talletus epaonnistui, Et voi tallettaa negatiivista lukua"<<endl;
        return false;
    }
}

bool Pankkitili::withdraw(double amount)
{
    if(amount>=0 && amount <= saldo)
    {
        saldo-=amount;
        cout<<omistaja <<" Pankkitili: nosto "<<amount<<" tehty"<<endl;
        return true;
    }
    else
    {
        cout<<"Nosto epaonnistui, virheellinen luku tai riittamaton saldo"<<endl;
        return false;
    }
}

double Pankkitili::getBalance() const
{
    return saldo;
}
