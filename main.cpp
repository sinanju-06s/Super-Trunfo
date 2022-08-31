#include <iostream>
#include "deck.h"
#include<fstream>
#include<string>

using namespace std;

int main(){
    Deck P1;
    P1.ReadFile();
    cout<<"Cartas no baralho: "<<P1.Size()<<endl;
    P1.Shuffle();
    P1.debug();
    
    return 0;
}