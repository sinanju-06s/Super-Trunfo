#include <iostream>
#include "deck.h"
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void ReadAllCards(Card master_deck[]){
    ifstream Archive("./cards.csv",ios::in);
    Card temp_card;
    string tmp;
    int i = 0;

    getline(Archive,tmp);

    while(!Archive.eof()){
        getline(Archive,tmp,',');
        temp_card.model = tmp;
        getline(Archive,tmp,',');
        temp_card.curb_weigth= stoi(tmp);
        getline(Archive,tmp,',');
        temp_card.engine_size = stoi(tmp);
        getline(Archive,tmp,',');
        temp_card.horsepower = stoi(tmp);
        getline(Archive,tmp,',');
        temp_card.price = stoi(tmp);
        getline(Archive,tmp,'\n');
        //temp_card.group = tmp.substr(0,tmp.size()-1);
        temp_card.group = tmp;
        master_deck[i] = temp_card;
        i++;
    }
}

void Shuffle(Card master_deck[]){
    int random_value;
    Card tmp;
    srand (time(NULL));
    for(int i=0;i<Maxt;i++){
        random_value = rand() % 32;
        tmp = master_deck[i];
        master_deck[i] = master_deck[random_value];
        master_deck[random_value] = tmp;
    }
}

void DivideCards(Card master_deck[],Deck &X,Deck &Y){
    for(int i=0;i<Maxt;i++){
        if(i%2 == 0){
            X.Append(master_deck[i]);
        }else{
            Y.Append(master_deck[i]);
        }
    }
}

void ShowAllAtributes(Card x){
    cout<<setw(10)<<"Group:"<<setw(10)<<x.group<<endl;
    cout<<setw(10)<<"Model:"<<setw(10)<<x.model<<endl;
    cout<<setw(10)<<"(1) Curb-Weigth:"<<setw(10)<<x.curb_weigth<<endl;
    cout<<setw(10)<<"(2) Engine-Size:"<<setw(10)<<x.engine_size<<endl;
    cout<<setw(10)<<"(3) Horsepower:"<<setw(10)<<x.horsepower<<endl;
    cout<<"Escolha um atributo"<<endl;
}

void CheckTrunfo(Card X, Card Y){
    if(X.group == "1A" || Y.group == "1A"){
        cout<<"Rodada do Super Trunfo"<<endl;
    }
}

void StartGame(Deck &P1, Deck &CPU){
    Card P1_Card, CPU_Card;
    int player_choice;

    while(P1.Size()<Maxt && CPU.Size()<Maxt){
        P1.Serve(P1_Card);
        CPU.Serve(CPU_Card);
        ShowAllAtributes(P1_Card);
        CheckTrunfo(P1_Card,CPU_Card);
        cin>>player_choice;
    }
}

int main(){
    // Deck MASTER_DECK,P1,CPU;

    // MASTER_DECK.ReadFile(P1,CPU);
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