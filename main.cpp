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
        cout << c.toStr() << " ";
    }
    cout << endl; 
}

int main() {
    vector<Card> cards;

    HandEvaluator he;

    for (string c: vector<string> {"2c", "3c", "4c", "5c", "Jh", "2d"}) {
        cards.push_back(Card(c));
    }

    std::sort( cards.begin(), cards.end() );
    tuple<int, string> t = he.calcScore(cards);
    printContainer(cards);
    cout << std::get<0>(t) << " " << std::get<1>(t) << endl;
    return 0;
}