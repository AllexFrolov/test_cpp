#pragma once
#include <tuple>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Card.hpp"

using std::tuple;
using std::string;
using std::vector;
using std::map;

class HandEvaluator {
public:
    tuple<int, string> calcScore(const vector<Card> &cards) {
        auto [flush, suit_cards] = findFlush(cards);

        return std::make_tuple(0, "");
    }

private:
    tuple<bool, vector<Card>> findFlush(const vector<Card> &cards) {
        map<uint8_t, vector<Card>> counts;
        uint8_t max_count_idx = 0;
        int max_count = 0;
        for (auto card: cards) {
            counts[card.getSuit()].push_back(card);
            if (counts[card.getSuit()].size() > max_count) {
                max_count = counts[card.getSuit()].size();
                max_count_idx = card.getSuit();
            }
        }
        return make_tuple(max_count >= 5, counts[max_count_idx]);

    // tuple<bool, vector<Card>> find_street(const vector<Card> &cards)

    // }

}

// public:
//     tuple<tuple<int>, tuple<int>, string> calc_score(vector<int>& cards) {
    
//     return make_tuple(make_tuple(0), make_tuple(0), "Done");
//     }
};