#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "luottotili.h"
#include "pankkitili.h"
#include <iostream>


using namespace std;
class Asiakas
{
public:
    Asiakas();
    Asiakas(string, double);

    string getNimi() const;
    void showSaldo();

    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);

    bool tiliSiirto(double, Asiakas &);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
