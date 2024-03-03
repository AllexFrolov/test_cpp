#include <vector>
#include "card.h"

using std::vector;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    void shuffle(uint_fast32_t seed = 0);
    Card get_card();
};