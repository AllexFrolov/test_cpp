#pragma once
#include <map>
#include <string>
#include <cstdint>

using std::string;
using std::map;

class Card {
private:
    uint32_t value;
    uint32_t suit;
    static const uint32_t suits = 4;
    static const map<uint32_t, string> itov;
    static const map<uint32_t, string> itos;

public:
    Card(uint32_t card_value, uint32_t card_suit);
    Card(uint32_t card_number);
    
    uint32_t get_value() const;
    uint32_t get_suit() const;

    bool operator<(const Card& other) const;

    bool operator>(const Card& other) const;

    bool operator==(const Card& other) const;

    bool operator<=(const Card& other) const;

    bool operator>=(const Card& other) const;

    const string str() const;
};