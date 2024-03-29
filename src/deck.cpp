#include "Deck.hpp"

Deck::Deck() {
    for (uint8_t i = 0; i < 52; ++i) {
        cards.push_back(Card(i));
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