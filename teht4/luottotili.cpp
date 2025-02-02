#include "luottotili.h"

Luottotili::Luottotili()
{

}

Luottotili::Luottotili(string nimi, double lraja):Pankkitili(nimi)
{
    luottoraja = lraja;
    cout<<"Luottotili luotu "<< nimi<<":lle, luottoraja: "<<luottoraja<<endl;
}

bool Luottotili::deposit(double amount)
{
    if(amount>=0 && (saldo-amount)>=0)
    {
        saldo-=amount;
        cout<<omistaja <<" Luottotili: talletus "<<amount<<" tehty, luottovelka:"<<saldo<<endl;

        return true;
    }
    else
    {
        cout<<"Talletus epaonnistui! Virheellinen numero, tai luottovelka muuttuisi positiiviseksi"<<endl;
        return false;
    }
}

bool Luottotili::withdraw(double amount)
{
    if(amount>=0 && (saldo+amount)<luottoraja  )
    {
        saldo+=amount;
        cout<<omistaja <<" Luottotili: nosto "<<amount<<" tehty, luottovelka: "<<saldo<<endl;

        return true;
    }
    else
    {
        cout<<"Nosto epaonnistui, virheellinen luku tai luottoraja ylitetty"<<endl;
        return false;
    }
}
