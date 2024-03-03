#include <tuple>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "card.h"

using std::tuple;
using std::string;
using std::vector;
using std::map;

class HandEvaluator {
public:
    tuple<int, string> calc_score(const vector<Card> &cards) {
        auto [flush, suit_cards] = find_flush(cards);

        return std::make_tuple(0, "");
    }

private:
    tuple<bool, vector<Card>> find_flush(const vector<Card> &cards) {
        map<uint32_t, vector<Card>> counts;
        uint32_t max_count_idx = 0;
        int max_count = 0;
        for (auto card: cards) {
            counts[card.get_suit()].push_back(card);
            if (counts[card.get_suit()].size() > max_count) {
                max_count = counts[card.get_suit()].size();
                max_count_idx = card.get_suit();
            }
        }
        return make_tuple(max_count >= 5, counts[max_count_idx]);

    // tuple<bool, vector<Card>> find_street(const vector<Card> &cards)

    // }

};

// public:
//     tuple<tuple<int>, tuple<int>, string> calc_score(vector<int>& cards) {
    
//     return make_tuple(make_tuple(0), make_tuple(0), "Done");
//     }
// };