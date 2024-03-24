#pragma once
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Card.hpp"
#include <iostream>

using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::make_tuple;
using std::sort;
using std::get;

class HandEvaluator {
public:
    tuple<int, string> calcScore(const vector<Card> &cards) {
        vector<Card> suit_cards = findFlush(cards);

        if (suit_cards.size() >= 5) {
            vector<Card> stree_flush_cards = findStreetFlush(suit_cards);
            if (stree_flush_cards.size() >= 5) {
                // Card score = stree_flush_cards.at(stree_flush_cards.size());
                return make_tuple(100, "street flush");
            }
        }

        unordered_map<uint8_t, vector<Card>> value_coutns = valueCount(cards);
        vector<tuple<std::size_t, uint8_t>> card_counts;

        for (auto kv: value_coutns) {
            card_counts.push_back({kv.second.size(), kv.first});
        }
        
        std::sort( card_counts.begin(), card_counts.end(),
            []( auto &l, auto &r) {
                if ( get<0>(l) == get<0>(r))
                {
                    return get<1>(l) > get<1>(r);
                }
                return get<0>(l) > get<0>(r);
            }
        );

        for (auto t: card_counts) {
            std::cout << get<0>(t) << " " << (int)get<1>(t) << std::endl; 
        }

        return make_tuple(0, "");
    }


private:
    vector<Card> findFlush(const vector<Card> &cards) {
        unordered_map<uint8_t, vector<Card>> counts;
        counts.reserve(4);

        uint8_t max_count_idx = 0;
        uint8_t max_count = 0;
        for (auto card: cards) {
            counts[card.getSuit()].push_back(card);
            if (counts[card.getSuit()].size() > max_count) {
                max_count = counts[card.getSuit()].size();
                max_count_idx = card.getSuit();
            }
        }
        return counts[max_count_idx];
    }


    // vector<Card> findKare(unordered_map<uint8_t, vector<Card>> &counter) {
        
    // }

    vector<Card> findStreetFlush(const vector<Card> &cards) {
        unordered_map<uint8_t, vector<Card>> value_counts = valueCount(cards);
        return findStreet(value_counts);
    }


    unordered_map<uint8_t, vector<Card>> valueCount(const vector<Card> &cards) {
        unordered_map<uint8_t, vector<Card>> counts;
        counts.reserve(7);
        for (auto card: cards) {
            counts[card.getValue()].push_back(card);
        }
        return counts;

    }


    vector<Card> findStreet(unordered_map<uint8_t, vector<Card>> &counter) {
        vector<uint8_t> sorted_values;

        for (auto kv: counter) {
            sorted_values.push_back(kv.first);
        }        
 
        std::sort( sorted_values.begin(), sorted_values.end() );
        sorted_values.push_back(sorted_values.front());

        uint8_t end_idx = 0;
        uint8_t sequence_counter = 1;

        for (uint8_t current_idx = 1; current_idx < sorted_values.size(); ++current_idx) {
            auto prev_value = sorted_values.at(current_idx - 1);
            auto cur_value = sorted_values.at(current_idx);
            if ((prev_value + 1) % 14 != cur_value) {
                sequence_counter = 1;
            }
            else {
                ++sequence_counter;
            }

            if (sequence_counter >= 5) {
                end_idx = current_idx;
            }
        }
        vector<Card> strit_cards;
        strit_cards.reserve(5);
        if (end_idx != 0) {
            for (uint8_t i = 0; i < 5 ; ++i) {
                strit_cards.push_back(counter.at(sorted_values.at(end_idx)).at(0));
                --end_idx;
            }
        }

        return strit_cards;
    }

};