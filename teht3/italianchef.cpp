#include "italianchef.h"


ItalianChef::ItalianChef(string name) :Chef(name)
{

    cout<<"ItalianChef "<<chefName<<" Konstruktori"<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"ItalianChef "<<chefName<<" Destruktori"<<endl;
}

bool ItalianChef::askSecret(string pw, int wt, int fl)
{
    if(pw.compare(password)==0)
    {
        flour=fl;
        water = wt;
        cout<<"Correct password!"<<endl;
        makePizza();
        return true;
    }
    else
    {
        cout<<"Wrong password!"<<endl;
        return false;
    }

}


int ItalianChef::makePizza()
{
    int annos = 0;
    int fl =flour, wt=water;

    while(fl>=5 && wt >=5)
    {
        annos++;
        fl=fl-5;
        wt=wt-5;
    }

    cout<<"ItalianChef "<< chefName <<
        " With " << flour<<" flour and "<<
        water << " water can make "<< annos
         <<" pizzas"<<endl;

    return annos;
}
