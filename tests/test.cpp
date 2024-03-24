#include "../src/Card.hpp"
#include "../src/Deck.hpp"
#include "../src/utils.hpp"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(UtilTests, BasicAssertions) {
  HandEvaluator he;
  vector<tuple<vector<string>, int>> test_cases {
    {{"2c", "3c", "4c", "5c", "Ac"}, 100}
  };

  for (tuple<vector<string>, int> test_case: test_cases) {
    auto [data, target] = test_case;
    vector<Card> cards;
    for (auto card_str: data) {
      cards.push_back(Card(card_str));
    }
    auto [score, _] = he.calcScore(cards);
    EXPECT_EQ(score, target);
  }

}