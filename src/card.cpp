#include "Card.hpp"

const string Card::STR_VALUES = "23456789TJQKA"; 
const string Card::STR_SUITS = "cdhs"; 

Card::Card(uint8_t value, uint8_t suit) {
    this->value = value;
    this->suit = suit;
}

Card::Card(uint8_t card_number) {
    value = card_number / SUITS;
    suit = card_number % SUITS;
}

Card::Card(string card_text) {
    value = (uint8_t)STR_VALUES.find(card_text.at(0));
    suit = (uint8_t)STR_SUITS.find(card_text.at(1));
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

const string Card::toStr() {
    return STR_VALUES.substr(value, 1) + STR_SUITS.substr(suit, 1);
}
