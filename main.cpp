/**
 * @file main.cpp
 * @author Pedro Ubine, Thiago Mantovani Martins
 * @brief 
 * “Super Trunfo” foi um jogo de cartas lançado na década de 70 que se popularizou durante as décadas de 80 e 90.
 * O jogo consiste em um baralho (deck) com 32 cartas com um conjunto de atributos e valores para cada um destes atributos.
 * Uma destas cartas (1A) é a carta Super Trunfo.
 * Haviam diversos decks, cada um com seu respectivo tema, por exemplo: carros, barcos, aviões.
 * Sobre o jogo:
 * Objetivo: ganhar todas as cartas do baralho.
 * O jogo: O jogo é todo baseado em comparar as cartas que você possui com as do
 * seu adversário (no caso o computador). Para que sua carta vença, o atributo (ou
 * característica) escolhido precisa ter valor maior do que a carta do seu adversário.
 * Quando sua carta vence, você ganha a carta do seu adversário. Em seguida,
 * coloca ambas no fim do seu deck.
 * Como jogar:
 * 1) Embaralham-se as 32 cartas e dividem-se em dois decks (um para
 * cada jogador –P1 e P2).
 * 2) É retirada a carta do topo do deck de P1 e P2.
 * 3) Escolhe-se o atributo que vai ser comparado e verifica-se quem
 * venceu.
 * 4) O vencedor recebe a carta do oponente e a coloca no final do seu
 * deck, seguida da carta vencedora.
 * 5) Repete-se os passos 2 a 4 até que um dos jogadores fique com o deck
 * vazio.
 * Importante>> CARTA SUPER TRUNFO
 * Entre as cartas, existe a carta SUPER TRUNFO (1A). Esta carta vence todas
 * as cartas do baralho, independentemente de suas características. Ela perde
 * apenas para as cartas que tenham a letra A no grupo (2A, 3A, 4A, etc).
 * Quando a carta SUPER TRUNFO aparecer, a comparação será automática.
 * Portanto, não há necessidade de escolher um atributo para comparar.
 * Vence o jogo quem possuir todas as cartas no seu deck.
 * 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "deck.h"
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
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