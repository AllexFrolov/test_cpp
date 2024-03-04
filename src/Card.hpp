#ifndef CARD_HPP
#define CARD_HPP

#include <map>
#include <string>
#include <cstdint>

using std::string;
using std::map;

class Card {
private:
    uint8_t value;
    uint8_t suit;
    static const uint8_t suits = 4;
    static const string strValues;
    static const string strSuits;

public:
    Card(uint8_t value, uint8_t suit);
    Card(uint8_t card_number);
    
    uint8_t getValue() const;
    uint8_t getSuit() const;

    bool operator<(const Card& other) const;

    bool operator>(const Card& other) const;

    bool operator==(const Card& other) const;

    bool operator<=(const Card& other) const;

    bool operator>=(const Card& other) const;

    const string str();
};

#endif