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

// void Deck::ReadFile(Deck &P1, Deck &CP)
// {
//     Card temp_card,deck_shuffle[32];
//     int i = 0;
//     ifstream Archive("./cards.csv",ios::in);
//     string tmp;

//     getline(Archive,tmp);

//     while(!Archive.eof()){
//         getline(Archive,tmp,',');
//         temp_card.model = tmp;
//         getline(Archive,tmp,',');
//         temp_card.curb_weigth= stoi(tmp);
//         getline(Archive,tmp,',');
//         temp_card.engine_size = stoi(tmp);
//         getline(Archive,tmp,',');
//         temp_card.horsePower = stoi(tmp);
//         getline(Archive,tmp,',');
//         temp_card.price = stoi(tmp);
//         getline(Archive,tmp,'\n');
//         temp_card.group = tmp.substr(0,tmp.size()-1);
        
//         deck_shuffle[i] = temp_card;
//         i++;
//     }
//     debug();
//     Shuffle(deck_shuffle,P1,CP);
// }

// void Deck::Shuffle(Card deck_shuffle[],Deck &P1, Deck &CP)
// {
//     bool insert;
//     int x = 0;
//     srand(time(NULL));
//     for(int i = 0; i <32; i++)
//     {
//         x = rand() % 32;
//         insert = false;

//         while(!insert)
//         {
//             if(x == 32)
//             {
//                 x = 0;
//             }
//             if(deck_shuffle[x].group == "00")
//             {
//                 x++;
//             } 
//             else 
//             {
//                 Append(deck_shuffle[x]);
//                 deck_shuffle[x].group = "00";
//                 insert = true;
//             }
//         }
//     }
//     debug();
//     Divide(P1,CP);
// }

// void Deck::Divide(Deck &P1,Deck &CP)
// {
//     Card temp_card;
//     for(int i = 1; i<=32; i++)
//     {
//         if(i % 2 == 0) 
//         {
//             Serve(temp_card);
//             P1.Append(temp_card);
//         } 
//         else 
//         {
//             Serve(temp_card);
//             CP.Append(temp_card);
//         }
//     }
// }

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
                deck_queue[i].horsepower << "|"  << deck_queue[i].price << "|" << deck_queue[i].group << endl;
        
    }
    cout << "Cartas no baralho: "<< Size() <<endl;
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
