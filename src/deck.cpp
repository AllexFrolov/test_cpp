#include <random>
#include <algorithm>
#include "deck.h"

Deck::Deck() {
    for (uint32_t i = 0; i < 52; ++i) {
        uint32_t value = i % 13;
        uint32_t suit = i / 13;
        cards.push_back(Card(value, suit));
    }
}

void Deck::shuffle(uint_fast32_t seed = 0) {
    auto rng = std::default_random_engine {};
    if (seed != 0) {
        rng.seed(seed);
    }
    std::shuffle(std::begin(cards), std::end(cards), rng);
}
    
Card Deck::get_card() {
    auto result = cards.back();
    cards.pop_back();
    return result;
}