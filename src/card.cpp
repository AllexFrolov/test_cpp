#include "Card.hpp"

const string Card::strValues = "23456789TJQKA"; 
const string Card::strSuits = "cdhs"; 

Card::Card(uint8_t value, uint8_t suit) {
    this->value = value;
    this->suit = suit;
}

Card::Card(uint8_t card_number) {
    value = card_number / suits;
    suit = card_number % suits;
}

uint8_t Card::getValue() const {
    return value;
}

uint8_t Card::getSuit() const {
    return suit;
}

bool Card::operator<(const Card& other) const {
    return value < other.getValue();
}

bool Card::operator>(const Card& other) const {
    return value > other.getValue();
}

bool Card::operator==(const Card& other) const {
    return value == other.getValue();
}

bool Card::operator<=(const Card& other) const {
    return (*this < other.getValue()) || (*this == other.getValue());
}

bool Card::operator>=(const Card& other) const {
    return !(*this < other.getValue());
}

const string Card::str() {
    return strValues.substr(value, 1) + strSuits.substr(suit, 1);
}
