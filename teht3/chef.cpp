#include "chef.h"

Chef::Chef() {}

Chef::Chef(string name)
{
    chefName= name;
    cout<<"Chef "<<chefName<<" Konstruktori"<<endl;
}

Chef::~Chef()
{
    cout<<"Chef "<<chefName<<" Destruktori"<<endl;
}

int Chef::makeSalad(int aines)
{
    int annoksia = aines/5;
    cout<<"Chef "<<chefName <<" With "<< aines<< " ingredients"<<
        " can make "<<annoksia <<" salads" <<endl;;

    return annoksia;
}

int Chef::makeSoup(int aines)
{
    int annoksia = aines/3;
    cout<<"Chef "<<chefName <<" With "<< aines<< " ingredients"<<
        " can make "<<annoksia <<" soups" <<endl;;

    return annoksia;
}

string Chef::getName() const
{
    cout<<"Chef "<< chefName <<endl;
    return chefName;
}
