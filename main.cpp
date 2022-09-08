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
    cout<<setw(10)<<"Group:\t"<<x.group<<endl;
    cout<<setw(10)<<"Model:\t"<<x.model<<endl;
    cout<<setw(10)<<"(1) Curb-Weigth:"<<setw(10)<<x.curb_weigth<<endl;
    cout<<setw(10)<<"(2) Engine-Size:"<<setw(10)<<x.engine_size<<endl;
    cout<<setw(10)<<"(3) Horsepower:"<<setw(10)<<x.horsepower<<endl;
}

bool CheckTrunfo(Card X, Card Y){
    if(X.group == "1A" || Y.group == "1A"){
        cout<<"Rodada do Super Trunfo"<<endl;
        return true;
    }else return false;
}

void TrunfoRound(Deck &P1,Deck &CPU, Card &P1_Card, Card &CPU_Card,bool &turno){
    cout<<"Player Card: "<<P1_Card.group<<endl;
    cout<<"CPU Card: "<<CPU_Card.group<<endl;
    if(P1_Card.group == "1A"){
        if(CPU_Card.group[1] == 'A'){
            cout<<"A carta trunfo perdeu"<<endl;
            cout<<"Vencedor da rodada: CPU"<<endl;
            CPU.Append(P1_Card);
            CPU.Append(CPU_Card);
        }else{
            cout<<"A carta trunfo ganhou"<<endl;
            cout<<"Vencedor da rodada: Player"<<endl;
            P1.Append(CPU_Card);
            P1.Append(P1_Card);
        }
    }else{
        if(P1_Card.group[1] == 'A'){
            cout<<"A carta trunfo perdeu"<<endl;
            cout<<"Vencedor da rodada: Player"<<endl;
            P1.Append(CPU_Card);
            P1.Append(P1_Card);
        }else{
            cout<<"A carta trunfo ganhou"<<endl;
            cout<<"Vencedor da rodada: CPU"<<endl;
            CPU.Append(P1_Card);
            CPU.Append(CPU_Card);
        }
    }
    if (turno==0) turno = 1;
    else turno = 0;
}

void RegularRound(Deck &P1,Deck &CPU, Card &P1_Card, Card &CPU_Card,bool &turno){
    int player_choice;
    string tmp;

    if (turno == 0){
        cout<<"Rodada do Player"<<endl;
        cin>>player_choice;
        switch(player_choice){
            case 1:
                cout<<"Opção Escolhida: Curb-Weigth"<<endl;
                cout<<"Player:"<<P1_Card.curb_weigth<<endl;
                cout<<"CPU:"<<CPU_Card.curb_weigth<<endl;
                if(P1_Card.curb_weigth > CPU_Card.curb_weigth){
                    cout<<"Player ganhou a rodada"<<endl;
                    P1.Append(CPU_Card);
                    P1.Append(P1_Card);
                }else{
                    cout<<"CPU ganhou a rodada"<<endl;
                    CPU.Append(P1_Card);
                    CPU.Append(CPU_Card);
                }
                break;
            case 2:
                cout<<"Opção Escolhida: Engine-Size"<<endl;
                cout<<"Player:"<<P1_Card.engine_size<<endl;
                cout<<"CPU:"<<CPU_Card.engine_size<<endl;
                if(P1_Card.engine_size > CPU_Card.engine_size){
                    cout<<"Player ganhou a rodada"<<endl;
                    P1.Append(CPU_Card);
                    P1.Append(P1_Card);
                }else{
                    cout<<"CPU ganhou a rodada"<<endl;
                    CPU.Append(P1_Card);
                    CPU.Append(CPU_Card);
                }
                break;
            case 3:
                cout<<"Opção Escolhida: Horsepower"<<endl;
                cout<<"Player:"<<P1_Card.horsepower<<endl;
                cout<<"CPU:"<<CPU_Card.horsepower<<endl;
                if(P1_Card.horsepower > CPU_Card.horsepower){
                    cout<<"Player ganhou a rodada"<<endl;
                    P1.Append(CPU_Card);
                    P1.Append(P1_Card);
                }else{
                    cout<<"CPU ganhou a rodada"<<endl;
                    CPU.Append(P1_Card);
                    CPU.Append(CPU_Card);
                }
                break;
        }
        turno = 1;
        setbuf(stdin,NULL);
    }else{
        cout<<"Rodada da CPU"<<endl;
        cout<<"USANDO CIN APENAS PARA SABER O QUE ESTÁ ACONTECENDO"<<endl;
        cin>>tmp;
        int CPU_choice;
        CPU_choice = rand()%3 + 1;
        switch(CPU_choice){
            case 1:
                cout<<"Opção Escolhida: Curb-Weigth"<<endl;
                cout<<"Player:"<<P1_Card.curb_weigth<<endl;
                cout<<"CPU:"<<CPU_Card.curb_weigth<<endl;
                if(P1_Card.curb_weigth > CPU_Card.curb_weigth){
                    cout<<"Player ganhou a rodada"<<endl;
                    P1.Append(CPU_Card);
                    P1.Append(P1_Card);
                }else{
                    cout<<"CPU ganhou a rodada"<<endl;
                    CPU.Append(P1_Card);
                    CPU.Append(CPU_Card);
                }
                break;
            case 2:
                cout<<"Opção Escolhida: Engine-Size"<<endl;
                cout<<"Player:"<<P1_Card.engine_size<<endl;
                cout<<"CPU:"<<CPU_Card.engine_size<<endl;
                if(P1_Card.engine_size > CPU_Card.engine_size){
                    cout<<"Player ganhou a rodada"<<endl;
                    P1.Append(CPU_Card);
                    P1.Append(P1_Card);
                }else{
                    cout<<"CPU ganhou a rodada"<<endl;
                    CPU.Append(P1_Card);
                    CPU.Append(CPU_Card);
                }
                break;
            case 3:
                cout<<"Opção Escolhida: Horsepower"<<endl;
                cout<<"Player:"<<P1_Card.horsepower<<endl;
                cout<<"CPU:"<<CPU_Card.horsepower<<endl;
                if(P1_Card.horsepower > CPU_Card.horsepower){
                    cout<<"Player ganhou a rodada"<<endl;
                    P1.Append(CPU_Card);
                    P1.Append(P1_Card);
                }else{
                    cout<<"CPU ganhou a rodada"<<endl;
                    CPU.Append(P1_Card);
                    CPU.Append(CPU_Card);
                }
                break;
        }
        turno = 0;
    }
}

void StartGame(Deck &P1, Deck &CPU){
    Card P1_Card, CPU_Card;
    int player_choice;
    bool turno = rand()%2;

    while(P1.Size()<Maxt && CPU.Size()<Maxt){
        P1.Serve(P1_Card);
        CPU.Serve(CPU_Card);
        ShowAllAtributes(P1_Card);
        if(!CheckTrunfo(P1_Card,CPU_Card)){
            RegularRound(P1,CPU,P1_Card,CPU_Card,turno);
        }else{
            TrunfoRound(P1,CPU,P1_Card,CPU_Card,turno);
        }
        cout<<"Cartas Player Atual: "<<P1.Size()<<endl;
        cout<<"Cartas CPU Atual: "<<CPU.Size()<<endl;
    }
    cout<<"Fim de jogo"<<endl;
    cout<<"Cartas Player:"<<P1.Size()<<endl;
    cout<<"Cartas CPU: "<<CPU.Size()<<endl;
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