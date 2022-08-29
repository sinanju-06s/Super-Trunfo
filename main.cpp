#include <iostream>
#include "deck.h"
#include<fstream>
#include<string>

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
        y.group = tmp.substr(0,tmp.size()-1);

        n.Append(y);
    }
}

int main(){

    Deck P1;
    read_all_cards(P1);
    cout<<"Cartas no baralho: "<<P1.Size()<<endl;
    P1.Shuffle();
    P1.debug();
    

    return 0;
}