#include <iostream>
#include <string>
using namespace std;
const int Maxt = 32;

struct Card{
    string model, group;
    int curb_weigth, engine_size , horsePower, price;
    }; 

class Deck{
    private:
        int head;
        int tail;
        int count;
        struct Card deck_queue[Maxt+1];
    public:
        Deck();
        void Append(Card x);
        void Serve(Card &x);
        bool Empty();
        bool Full();
        int Size();
        void debug();
        void Shuffle();
        void ReadFile();
};