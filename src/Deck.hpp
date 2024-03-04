#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"

#include <random>
#include <algorithm>
#include <vector>

using std::vector;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    void shuffle(uint_fast32_t seed);
    Card get_card();
};
#endif