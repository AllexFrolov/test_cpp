#include <tuple>
#include <string>
#include <vector>
#include "deck.h"

using std::tuple;
using std::string;
using std::vector;

class HandEvaluator {
public:
    tuple<int, string> calc_score(vector<Card> &cards) {
        
        return std::make_tuple(0, "");
    }
// private:

};

// public:
//     tuple<tuple<int>, tuple<int>, string> calc_score(vector<int>& cards) {
    
//     return make_tuple(make_tuple(0), make_tuple(0), "Done");
//     }
// };