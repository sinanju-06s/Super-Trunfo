#include <iostream>
#include "func.h"
#include "deck.h"
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    Card MASTER_DECK[Maxt];
    ReadAllCards(MASTER_DECK);
    Shuffle(MASTER_DECK);
    
    Deck P1,CPU;
    DivideCards(MASTER_DECK,P1,CPU);
    cout<<"Tamanho do Deck P1: "<<P1.Size()<<endl;
    cout<<"Tamanho do Deck CPU: "<<CPU.Size()<<endl;
    StartGame(P1,CPU);

    return 0;
}