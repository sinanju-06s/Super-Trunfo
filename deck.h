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
        int i = -1;
        generalize[i++] = curb_weigth;
        generalize[i++] = engine_size;
        generalize[i++] = horsepower;
        generalize[i++] = price;
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

void ReadAllCards(Card master_deck[]);
void Shuffle(Card master_deck[]);
void DivideCards(Card master_deck[], Deck &X, Deck &Y);
void ShowAllAtributes(Card x);
bool CheckTrunfo(Card X, Card Y);
void TrunfoRound(Deck &P1, Deck &CPU, Card &P1_Card, Card &CPU_Card, bool &turno);
void ShowChoice(int choice, Card &P1_Card, Card &CPU_Card, Deck &P1, Deck &CPU);
void RegularRound(Deck &P1, Deck &CPU, Card &P1_Card, Card &CPU_Card, bool &turno);
void StartGame(Deck &P1, Deck &CPU);