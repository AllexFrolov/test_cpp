#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <string>

#include "src/utils.hpp"
#include "src/Deck.hpp"

using std::vector;
using std::cout;
using std::endl;

void printContainer(vector<Card> container) {
    for(auto c: container) {
        cout << c.str() << " ";
    }
    cout << endl; 
}

int main() {
    Deck deck;
    vector<Card> hand;
    vector<Card> board;

    HandEvaluator he;

    deck.shuffle(42U);
    for(int i = 0; i < 2; ++i) {
        hand.push_back(deck.get_card());
    }
    
    for(int i = 0; i < 5; ++i) {
        board.push_back(deck.get_card());
    }

    vector<Card> cards;
    cards.reserve( hand.size() + board.size() );
    cards.insert( cards.end(), hand.begin(), hand.end() );
    cards.insert( cards.end(), board.begin(), board.end() );
    std::sort( cards.begin(), cards.end() );
    tuple<int, string> t = he.calcScore(cards);
    printContainer(hand);
    printContainer(board);
    printContainer(cards);
    cout << std::get<0>(t) << std::get<1>(t) << endl;
    return 0;
}