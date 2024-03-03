#include "card.h"


Card::Card(uint32_t value, uint32_t suit) {
    this->value = value;
    this->suit = suit;
}

Card::Card(uint32_t card_number) {
    value = card_number / suits;
    suit = card_number % suits;
}

uint32_t Card::get_value() const {
    return value;
}

uint32_t Card::get_suit() const {
    return suit;
}

bool Card::operator<(const Card& other) const {
    return value < other.get_value();
}

bool Card::operator>(const Card& other) const {
    return value > other.get_value();
}

bool Card::operator==(const Card& other) const {
    return value == other.get_value();
}

bool Card::operator<=(const Card& other) const {
    return (*this < other.get_value()) || (*this == other.get_value());
}

bool Card::operator>=(const Card& other) const {
    return !(*this < other.get_value());
}

const string Card::str() const {
    return itov.at(value) + itos.at(suit);
}


const map<uint32_t, string> Card::itov= []() {
    map<uint32_t, string> result;
    uint32_t counter = 0;
    for(char v : "23456789TJQKA") {
        if (v != '\0') {
            result[counter] = v;
            ++counter;
        }
    }
    return result;
}();

const map<uint32_t, string> Card::itos= []() {
    map<uint32_t, string> result;
    uint32_t counter = 0;
    for (char s : "cdhs") {
        if (s != '\0') {
            result[counter] = s;
            ++counter;
        }
    }
    return result;
}();
