#include "game.h"

Game::Game(int maxN)
{
    maxNumber = maxN;
    cout<<"Constructor: Object init with " <<
        maxNumber <<
        " as maximum value"
        << ""
         <<endl;
}

Game::~Game()
{
    cout<<"Destructor: object cleared from memory"<<endl;
}

void Game::play()
{
    cout<<"Game started!"<<endl;
    srand(time(NULL));
    randomNumber = (rand() % maxNumber)+1;

    while(playerGuess != randomNumber)
    {
        cout<<"Arvaa numero" <<endl;
        cin>>playerGuess;
        numOfGuesses++;

        if(playerGuess<randomNumber)
        {
            cout<<"Numero on suurempi"<<endl;
        }
        else if (playerGuess>randomNumber)
        {
            cout<<"Numero on pienempi"<<endl;
        }
    }
    cout<<"Arvasit oikein! Luku oli: "<<randomNumber <<endl;
    printGameResult();
}

void Game::printGameResult()
{
    cout<<"Arvasit oikean luvun:" <<randomNumber<<
        ", Arvasit "<< numOfGuesses <<" kertaa." <<endl;
}
