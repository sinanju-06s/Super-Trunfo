#include <iostream>
#include <string>
//#include "card.h"
using namespace std;

const int Maxt = 32;
class Deck
{
    private:
        int head;
        int tail;
        int count;
    public:
        Deck();
        struct Card
        {
            string model, group;
            int curb_weigth, engine_size , horsePower, price;
        };
        struct Card deck_queue[Maxt+1];
        void Append(Card x);
        void Serve(Card &x);
        bool Empty();
        bool Full();
        int Size();
        //void distribuir(Deck P2);
        void debug();
        
};