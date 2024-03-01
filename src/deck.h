#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <map>
#include <string>

using std::vector;
using std::string;

class Card {
private:
    uint32_t value;
    uint32_t suit;
    static const uint32_t values = 13;
    static const std::map<uint32_t, string> itov;
    static const std::map<uint32_t, string> itos;

public:
    Card(uint32_t card_value, uint32_t card_suit) {
        value = card_value;
        suit = card_suit;
    }

    Card(uint32_t card_number) {
        value = card_number / values;
        suit = card_number % values;
    }
    uint32_t get_value() const {
        return value;
    }

    bool operator<(const Card& other) const {
        return value < other.get_value();
    }

    bool operator>(const Card& other) const {
        return value > other.get_value();
    }

    bool operator==(const Card& other) const {
        return value == other.get_value();
    }

    bool operator<=(const Card& other) const {
        return (*this < other.get_value()) || (*this == other.get_value());
    }

    bool operator>=(const Card& other) const {
        return !(*this < other.get_value());
    }

    const string str() const {
        return itov.at(value) + itos.at(suit);
    }

};

const std::map<uint32_t, std::string> Card::itov= []() {
    std::map<uint32_t, std::string> result;
    uint32_t counter = 0;
    for(char v : "23456789TJQKA") {
        if (v != '\0') {
            result[counter] = v;
            ++counter;
        }
    }
    return result;
}();

const std::map<uint32_t, std::string> Card::itos= []() {
    std::map<uint32_t, std::string> result;
    uint32_t counter = 0;
    for (char s : "cdhs") {
        if (s != '\0') {
            result[counter] = s;
            ++counter;
        }
    }
    return result;
}();

class Deck {
private:
    vector<Card> cards;

public:
    Deck() {
        for (uint32_t i = 0; i < 52; ++i) {
            uint32_t value = i % 13;
            uint32_t suit = i / 13;
            cards.push_back(Card(value, suit));
        }
    }

    void shuffle(uint_fast32_t seed = 0) {
        auto rng = std::default_random_engine {};
        if (seed != 0) {
            rng.seed(seed);
        }
        std::shuffle(std::begin(cards), std::end(cards), rng);
    }
    
    Card get_card() {
        auto result = cards.back();
        cards.pop_back();
        return result;
    }
};