#ifndef CARD_HPP
#define CARD_HPP

#include <map>
#include <string>
#include <cstdint>

using std::string;

class Card {
private:
    uint8_t value;
    uint8_t suit;
    static const uint8_t SUITS = 4;
    static const string STR_VALUES;
    static const string STR_SUITS;

public:
    Card(uint8_t value, uint8_t suit);
    Card(uint8_t card_number);
    Card(string card_text);
    
    uint8_t getValue() const;
    uint8_t getSuit() const;

    bool operator<(const Card& other) const;

    bool operator>(const Card& other) const;

    bool operator==(const Card& other) const;

    bool operator<=(const Card& other) const;

    bool operator>=(const Card& other) const;

    const string toStr();
};

#endif