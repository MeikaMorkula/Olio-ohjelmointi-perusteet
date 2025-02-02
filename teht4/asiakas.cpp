#include "asiakas.h"

Asiakas::Asiakas() {}

Asiakas::Asiakas(string na, double luottor):kayttotili(na),
    luottotili(na, luottor)
{
    nimi = na;
    cout<<"Asiakkuus luotu: " <<nimi<<endl;
}

string Asiakas::getNimi() const
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<nimi<< " Kayttotilin saldo on: "<<kayttotili.getBalance()<<endl;
    cout<<nimi<< " Luottotilin velka on: "<<luottotili.getBalance()<<endl;
}

bool Asiakas::talletus(double amount)
{
    cout<<"Asiakas "<<nimi<<" tallettaa" <<endl;
    bool success= kayttotili.deposit(amount);
    if(!success)
    {
        cout<<"Talletus epaonnistui"<<endl;
    }
    return success;
}

bool Asiakas::nosto(double amount )
{
    cout<<"Asiakas "<<nimi<<" nostaa"<<endl;
    bool success= kayttotili.withdraw(amount);
    if(!success)
    {
        cout<<"nosto epaonnistui"<<endl;
    }
    return success;
}

bool Asiakas::luotonMaksu(double amount)
{
    cout<<"Asiakas "<<nimi<<" maksaa luottoa" <<endl;
    bool success= luottotili.deposit(amount);
    if(!success)
    {
        cout<<"Maksu epaonnistui"<<endl;
    }
    return success;
}

bool Asiakas::luotonNosto(double amount)
{
    cout<<"Asiakas "<<nimi<<" nostaa luottotililta" <<endl;
    bool success= luottotili.withdraw(amount);
    if(!success)
    {
        cout<<"nosto epaonnistui"<<endl;
    }
    return success;
}

bool Asiakas::tiliSiirto(double amount, Asiakas &as)
{
    //tarvittavat tarkistukset jo nosto funktiossa;
    cout<<"Asiakas "<<nimi<<" Siirtaa "<< amount << " Asiakkalle " << as.getNimi()<<endl;
    bool success = nosto(amount);
    if(success)
    {
        as.talletus(amount);
        return true;
    }
    else
    {
        cout<<"Tilisiirto epäonnistui"<<endl;
        return false;
    }

}
