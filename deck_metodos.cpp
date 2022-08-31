#include "deck.h"
#include<fstream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

Deck::Deck()
{
    tail = 0;
    head = 1;
    count = 0;
};

void Deck::ReadFile()
{
    Card temp_card;
    ifstream Archive("./cards.csv",ios::in);
    string tmp;

    getline(Archive,tmp);

    while(!Archive.eof()){
        getline(Archive,tmp,',');
        temp_card.model = tmp;
        getline(Archive,tmp,',');
        temp_card.curb_weigth= stoi(tmp);
        getline(Archive,tmp,',');
        temp_card.engine_size = stoi(tmp);
        getline(Archive,tmp,',');
        temp_card.horsePower = stoi(tmp);
        getline(Archive,tmp,',');
        temp_card.price = stoi(tmp);
        getline(Archive,tmp,'\n');
        temp_card.group = tmp.substr(0,tmp.size()-1);
        
        Append(temp_card);
    }
}


void Deck::Shuffle()
{
    struct Card temp_card1,temp_card2;
    int x,y;  
    srand(time(NULL));

    for(int i = 1; i < 128; i++)
    {   
        x = rand() % 32 + 1;
        y = rand() % 32 + 1;
        if(x == y) {i--; continue;}

        temp_card1 = deck_queue[x];
        temp_card2 = deck_queue[y];
        deck_queue[x] = temp_card2;
        deck_queue[y] = temp_card1;
    }
}


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

void Deck::debug()
{
    for (int i = 0; i < count+1; i++)
    {
        cout << deck_queue[i].model << "|" <<deck_queue[i].curb_weigth <<"|"<< deck_queue[i].engine_size << "|" << 
                deck_queue[i].horsePower << "|"  << deck_queue[i].price << "|" << deck_queue[i].group << endl;
        
    }
}
bool Deck::Full()
{
    return (count == Maxt);
}

bool Deck::Empty()
{
    return (count == 0);
}

int Deck::Size(){
    return count;
}
