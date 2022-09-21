#include <iostream>
#include "deck.h"

void ReadAllCards(Card master_deck[]);
void Shuffle(Card master_deck[]);
void DivideCards(Card master_deck[], Deck &X, Deck &Y);
void ShowAllAtributes(Card x);
bool CheckTrunfo(Card X, Card Y);
void TrunfoRound(Deck &P1, Deck &CPU, Card &P1_Card, Card &CPU_Card, bool &turno);
void ShowChoice(int choice, Card &P1_Card, Card &CPU_Card, Deck &P1, Deck &CPU);
void RegularRound(Deck &P1, Deck &CPU, Card &P1_Card, Card &CPU_Card, bool &turno);
void StartGame(Deck &P1, Deck &CPU);
void Menu(Deck &P1, Deck &CPU);