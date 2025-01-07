#include <iostream>
#include <cstdlib>

using namespace std;
int game(int maxnum);

int main()
{
    int gc = game(40);
    cout<<"Arvausten maara: "<<gc<<endl;
    return 0;
}


int game(int maxnum)
{
    int number=0, guess=0, guesscount = 0;

    srand(time(NULL));
    number = rand() % maxnum;

    while(guess != number)
    {
        cout<<"Arvaa numero" <<endl;
        cin>>guess;
        guesscount++;

        if(guess<number)
        {
            cout<<"Numero on suurempi"<<endl;
        }
        else if (guess>number)
        {
            cout<<"Numero on pienempi"<<endl;
        }
    }

    cout<<"Oikea vastaus! Numero oli: "<< number <<endl;

    return guesscount;
}
