#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
using namespace std;

class Seuraaja
{
public:
    Seuraaja();
    Seuraaja(string);

    Seuraaja *next = nullptr;
    void paivitys(string);
    string getNimi() const;

private:
    string nimi;
};

#endif // SEURAAJA_H
