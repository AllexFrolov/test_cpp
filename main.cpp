#include <vector>
#include <iostream>
#include "deck.h"

using std::vector;
using std::cout;
using std::endl;



void print_container(vector<Card> container) {
    for(auto c: container) {
        cout << c.str() << " ";
    }
    cout << endl;
}

int main() {
    Deck deck;
    vector<Card> hand;
    vector<Card> board;

    // deck.shuffle(42);
    for(int i = 0; i < 2; ++i) {
        hand.push_back(deck.get_card());
    }
    
    for(int i = 0; i < 5; ++i) {
        board.push_back(deck.get_card());
    }

    print_container(hand);
    print_container(board);
    for (int i; i < 52 - 7; ++i) {
        auto card = deck.get_card();
        cout << card.str() << endl;
    }
    return 0;
}