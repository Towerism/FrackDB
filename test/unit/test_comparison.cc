#include <gtest/gtest.h>
#include <evaluation/comparison.hh>

TEST(ComparisonTest, LessThan) {
  Comparison true_comparison(15, new Less_than, 17);
  Comparison false_comparison(17, new Less_than, 15);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, GreaterThan) {
  Comparison true_comparison(17, new Greater_than, 15);
  Comparison false_comparison(15, new Greater_than, 17);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, Equal) {
  Comparison true_comparison(15, new Equal, 15);
  Comparison false_comparison(15, new Equal, 17);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, StringCompare) {
  Comparison true_comparison("bison", new Less_than, "car");
  Comparison false_comparison("car", new Less_than, "bison");

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}
