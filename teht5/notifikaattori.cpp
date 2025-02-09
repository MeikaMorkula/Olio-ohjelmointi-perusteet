#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {}

void Notifikaattori::lisaa(Seuraaja * user)
{
    user->next=seuraajat;

    seuraajat=user;
    cout<<"Notifikaattori lisaa seuraajan "
         <<user->getNimi()<<endl;
}

void Notifikaattori::poista(Seuraaja * user)
{
    Seuraaja *A = seuraajat;

    if(A==user)
    {
        cout<<"Notifikaattori poistaa seuraajan "<<
            A->getNimi()<<endl;

         seuraajat = user->next;

    return;
    }

    while(A != nullptr)
    {
        if(A->next== user)
        {
            cout<<"Notifikaattori poistaa seuraajan "<<
                user->getNimi()<<endl;

            A->next=user->next;
            return;
        }
        else
        {
            A = A->next;
        }
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja *A = seuraajat;
    while(A != nullptr)
    {
        cout<<"Seuraaja "<<A->getNimi()<<endl;
        A = A->next;
    }
}

void Notifikaattori::postita(string msg)
{
    Seuraaja *A = seuraajat;
    cout<<"Notifikaattori postaa viestin: "<<msg<<endl;
    while(A != nullptr)
    {

        A->paivitys(msg);
        A = A->next;
    }
}
