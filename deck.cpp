#include "deck.h"
#include <fstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Deck::Deck()
{
    tail = 0;
    head = 1;
    count = 0;
};

void Deck::Append(Card x)
{
    if (Full())
    {
        cout << "Limite Atingido" << endl;
        abort();
    }
    count++;
    tail = (tail % Maxt) + 1;
    deck_queue[tail] = x;
}

void Deck::Serve(Card &x)
{
    if (Empty())
    {
        cout << "Acabaram suas cartas" << endl;
        abort();
    }
    count--;
    x = deck_queue[head];
    head = (head % Maxt) + 1;
}

bool Deck::Full()
{
    return (count == Maxt);
}

bool Deck::Empty()
{
    return (count == 0);
}

int Deck::Size()
{
    return count;
}
