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
    int *pointer[3];
    Card()
    {
        int i=0;
        pointer[i++] = &curb_weigth;
        pointer[i++] = &engine_size;
        pointer[i++] = &horsepower;
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
