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
    static const std::map<uint32_t, string> itoc;

public:
    Card(uint32_t card_number) {
        value = card_number;
    }

    uint32_t operator()() const {
        return value;
    }

    bool operator<(const Card& other) {
        return value < other();
    }

    bool operator>(const Card& other) {
        return value > other();
    }

    bool operator==(const Card& other) {
        return value == other();
    }

    bool operator<=(const Card& other) {
        return (*this < other()) || (*this == other());
    }

    bool operator>=(const Card& other) {
        return !(*this < other());
    }

    const string str() const {
        return itoc.at(value);
    }

};

const std::map<uint32_t, std::string> Card::itoc = []() {
    std::map<uint32_t, std::string> result;
    uint32_t counter = 0;
    for(char v : "23456789TJQKA") {
        for (char s : "cdhs") {
            if (v != '\0' and s != '\0') {
                result[counter] = string(1, v) + s;
                ++counter;
            }
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
            cards.push_back(Card(i));
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