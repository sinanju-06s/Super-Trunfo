#include <iostream>
#include <string>
using namespace std;


#ifndef DECK_H
#define DECK_H
const int Maxt = 32;
struct Card
{   
    string model, group;
    int curb_weigth, engine_size, horsepower, price;
    int generalize[4];
    void Refresh()
    {
        //int i=0;
        generalize[1] = curb_weigth;
        generalize[2] = engine_size;
        generalize[3] = horsepower;
    }
    
};

class Deck
{
private:
    int head;
    int tail;
    int count;
    struct Card deck_queue[Maxt + 1];

public:
    Deck();
    void Append(Card x);
    void Serve(Card &x);
    bool Empty();
    bool Full();
    int Size();
    void debug();
};
#endif
