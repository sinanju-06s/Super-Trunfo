#include <iostream>
#include "deck.h"
#include<fstream>
#include<string>
//#include"card.h"

using namespace std;

void read_all_cards(Deck &n){
    Card y;
    ifstream Archive("./cards.csv",ios::in);
    string tmp;
    getline(Archive,tmp);
    while(!Archive.eof()){
        getline(Archive,tmp,',');
        y.model = tmp;
        getline(Archive,tmp,',');
        y.curb_weigth= stoi(tmp);
        getline(Archive,tmp,',');
        y.engine_size = stoi(tmp);
        getline(Archive,tmp,',');
        y.horsePower = stoi(tmp);
        getline(Archive,tmp,',');
        y.price = stoi(tmp);
        getline(Archive,tmp,'\n');
        y.group = tmp;
        n.Append(y);
    }
}


/**void distribuir(Deck P1)
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
}*/

int main(){

    Deck P1;
    read_all_cards(P1);
    cout<<"Cartas no baralho: "<<P1.Size()<<endl;
    
    return 0;
}