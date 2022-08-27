#include <iostream>
#include "deck.h"
#include<fstream>
#include<string>

using namespace std;

void distribuir(Deck P1)
{
    struct Deck::Card card_tmp;
    string tmp;
    ifstream Archive("./cards.csv", ios::in);

    getline(Archive,tmp);
    while (Archive.good())
    {
        getline(Archive,card_tmp.model,',');

        getline(Archive,tmp,',');
        card_tmp.curb_weigth = stoi(tmp);
        
        getline(Archive,tmp,',');
        card_tmp.engine_size = stoi(tmp);

        getline(Archive,tmp,',');
        card_tmp.horsePower = stoi(tmp);

        getline(Archive,tmp,',');
        card_tmp.price = stoi(tmp);

        getline(Archive,card_tmp.group,',');

        cout << card_tmp.model << endl << card_tmp.curb_weigth << endl << card_tmp.group;
    }

    P1.Append(card_tmp);
}

int main()
{

    Deck P1;

    distribuir(P1);

    return 0;
}