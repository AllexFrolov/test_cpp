#pragma onec
#include <vector>
#include "Card.hpp"

using std::vector;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    void shuffle(uint_fast32_t seed);
    Card get_card();
};