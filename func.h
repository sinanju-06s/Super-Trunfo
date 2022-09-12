#include <iostream>
#include "deck.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

void ReadAllCards(Card master_deck[])
{
    ifstream Archive("./cards.csv", ios::in);
    Card temp_card;
    string tmp;
    int i = 0;

    getline(Archive, tmp);

    while (!Archive.eof())
    {
        getline(Archive, tmp, ',');
        temp_card.model = tmp;
        getline(Archive, tmp, ',');
        temp_card.curb_weigth = stoi(tmp);
        getline(Archive, tmp, ',');
        temp_card.engine_size = stoi(tmp);
        getline(Archive, tmp, ',');
        temp_card.horsepower = stoi(tmp);
        getline(Archive, tmp, ',');
        temp_card.price = stoi(tmp);
        getline(Archive, tmp,'\n');
        temp_card.group = tmp;
        temp_card.Refresh();
        master_deck[i] = temp_card;
        i++;
    }
    cout << "fim " << endl;
}

void Shuffle(Card master_deck[])
{
    int random_value;
    Card tmp;
    srand(time(NULL));
    for (int i = 0; i < Maxt; i++)
    {
        random_value = rand() % 32;
        tmp = master_deck[i];
        master_deck[i] = master_deck[random_value];
        master_deck[random_value] = tmp;
    }
}

void DivideCards(Card master_deck[], Deck &X, Deck &Y)
{
    for (int i = 0; i < Maxt; i++)
    {
        if (i % 2 == 0)
        {
            X.Append(master_deck[i]);
        }
        else
        {
            Y.Append(master_deck[i]);
        }
    }
}

void ShowAllAtributes(Card x)
{

    string fill(30, '-');

    cout << fill << endl;
    cout << "Group:" << right << setw(17) << x.group << endl;
    cout << left << setw(20) << "Model:" << left << setw(10) << x.model << endl;
    cout << left << setw(20) << "(1) Curb-Weigth:" << left << setw(10) << x.curb_weigth << endl;
    cout << left << setw(20) << "(2) Engine-Size:" << left << setw(10) << x.engine_size << endl;
    cout << left << setw(20) << "(3) Horsepower:" << left << setw(10) << x.horsepower << endl;
    cout << fill << endl;
}

bool CheckTrunfo(Card X, Card Y)
{
    if (X.group == "1A" || Y.group == "1A")
    {
        cout << "Rodada do Super Trunfo" << endl;
        return true;
    }
    else
        return false;
}

void TrunfoRound(Deck &P1, Deck &CPU, Card &P1_Card, Card &CPU_Card, bool &turno)
{
    cout << "Player Card: " << P1_Card.group << endl;
    cout << "CPU Card: " << CPU_Card.group << endl;
    if (P1_Card.group == "1A")
    {
        if (CPU_Card.group[1] == 'A')
        {
            cout << "A carta trunfo perdeu" << endl;
            cout << "Vencedor da rodada: CPU" << endl;
            CPU.Append(P1_Card);
            CPU.Append(CPU_Card);
        }
        else
        {
            cout << "A carta trunfo ganhou" << endl;
            cout << "Vencedor da rodada: Player" << endl;
            P1.Append(CPU_Card);
            P1.Append(P1_Card);
        }
    }
    else
    {
        if (P1_Card.group[1] == 'A')
        {
            cout << "A carta trunfo perdeu" << endl;
            cout << "Vencedor da rodada: Player" << endl;
            P1.Append(CPU_Card);
            P1.Append(P1_Card);
        }
        else
        {
            cout << "A carta trunfo ganhou" << endl;
            cout << "Vencedor da rodada: CPU" << endl;
            CPU.Append(P1_Card);
            CPU.Append(CPU_Card);
        }
    }
    if (turno == 0)
        turno = 1;
    else
        turno = 0;
}
void ShowChoice(int choice, Card &P1_Card, Card &CPU_Card, Deck &P1, Deck &CPU)
{
    map<int, string> mychoices;
    mychoices[1] = "Curb-Weigth";
    mychoices[2] = "Engine-Size";
    mychoices[3] = "Horsepower";

    cout << "Opção Escolhida: " << mychoices[choice-1] << endl;
    cout << "Player value:" << P1_Card.generalize[choice-1] << endl;
    cout << "CPU value:" << CPU_Card.generalize[choice] << endl;
    if (P1_Card.generalize[choice-1] > CPU_Card.generalize[choice-1])
    {
        cout << "Player ganhou a rodada" << endl;
        P1.Append(CPU_Card);
        P1.Append(P1_Card);
    }
    else
    {
        cout << "CPU ganhou a rodada" << endl;
        CPU.Append(P1_Card);
        CPU.Append(CPU_Card);
    }
}
void RegularRound(Deck &P1, Deck &CPU, Card &P1_Card, Card &CPU_Card, bool &turno)
{
    int player_choice;
    string tmp;

    if (turno == 0)
    {
        cout << "Rodada do Player" << endl;
        cin >> player_choice;
        while (player_choice != (int)player_choice || player_choice < 0 || player_choice > 3)
        {
            setbuf(stdin, NULL);
            cin.clear();
            cout << "Valor inválido, Insira novamente.\n";
            cin >> player_choice;
        }
        ShowChoice(player_choice, P1_Card, CPU_Card, P1, CPU);
        turno = 1;
    }
    else
    {
        cout << "Rodada da CPU" << endl;
        cout << "USANDO CIN APENAS PARA SABER O QUE ESTÁ ACONTECENDO" << endl;
        cin >> tmp;
        int CPU_choice;
        CPU_choice = rand() % 3 + 1;
        ShowChoice(CPU_choice, P1_Card, CPU_Card, P1, CPU);
        turno = 0;
    }
}

void StartGame(Deck &P1, Deck &CPU)
{
    Card P1_Card, CPU_Card;
    bool turno = rand() % 2;

    while (P1.Size() < Maxt && CPU.Size() < Maxt)
    {
        P1.Serve(P1_Card);
        CPU.Serve(CPU_Card);
        ShowAllAtributes(P1_Card);
        if (!CheckTrunfo(P1_Card, CPU_Card))
        {
            RegularRound(P1, CPU, P1_Card, CPU_Card, turno);
        }
        else
        {
            TrunfoRound(P1, CPU, P1_Card, CPU_Card, turno);
        }
        cout << "Cartas Player Atual: " << P1.Size() << endl;
        cout << "Cartas CPU Atual: " << CPU.Size() << endl;
    }
    cout << "Fim de jogo" << endl;
}
