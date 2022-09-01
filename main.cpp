#include <iostream>
#include "deck.h"
#include<fstream>
#include<string>

using namespace std;

int main(){
    Deck MASTER_DECK,P1,CPU;

    MASTER_DECK.ReadFile(P1,CPU);

    cout << "\nP1" << endl;
    P1.debug();
    cout << "\nCPU" << endl;
    CPU.debug();
    cout << "\nMASTER DEBUG 2" << endl;
    MASTER_DECK.debug();
    
    return 0;
}