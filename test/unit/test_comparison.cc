#include <gtest/gtest.h>
#include <evaluation/comparison_evaluator.hh>

TEST(ComparisonTest, LessThan) {
  Comparison<Operator::Less_than> true_comparison(15, 17);
  Comparison<Operator::Less_than> false_comparison(17, 15);

  EXPECT_EQ(true, Comparison_evaluator::evaluate(true_comparison));
  EXPECT_EQ(false, Comparison_evaluator::evaluate(false_comparison));
}

TEST(ComparisonTest, GreaterThan) {
  Comparison<Operator::Greater_than> true_comparison(17, 15);
  Comparison<Operator::Greater_than> false_comparison(15, 17);

  EXPECT_EQ(true, Comparison_evaluator::evaluate(true_comparison));
  EXPECT_EQ(false, Comparison_evaluator::evaluate(false_comparison));
}

TEST(ComparisonTest, Equal) {
  Comparison<Operator::Equal> true_comparison(15, 15);
  Comparison<Operator::Equal> false_comparison(17, 15);

  EXPECT_EQ(true, Comparison_evaluator::evaluate(true_comparison));
  EXPECT_EQ(false, Comparison_evaluator::evaluate(false_comparison));
}

TEST(ComparisonTest, LessEqual) {
  Comparison<Operator::Less_equal> true_comparison(15, 17);
  Comparison<Operator::Greater_equal> fringe_comparison(15, 15);
  Comparison<Operator::Less_equal> false_comparison(17, 15);

  EXPECT_EQ(true, Comparison_evaluator::evaluate(true_comparison));
  EXPECT_EQ(true, Comparison_evaluator::evaluate(fringe_comparison));
  EXPECT_EQ(false, Comparison_evaluator::evaluate(false_comparison));
}

TEST(ComparisonTest, GreaterEqual) {
  Comparison<Operator::Greater_equal> true_comparison(17, 15);
  Comparison<Operator::Greater_equal> fringe_comparison(15, 15);
  Comparison<Operator::Greater_equal> false_comparison(15, 17);

  EXPECT_EQ(true, Comparison_evaluator::evaluate(true_comparison));
  EXPECT_EQ(true, Comparison_evaluator::evaluate(fringe_comparison));
  EXPECT_EQ(false, Comparison_evaluator::evaluate(false_comparison));
}

TEST(ComparisonTest, StringCompare) {
  Comparison<Operator::Less_than> true_comparison("bison", "car");
  Comparison<Operator::Less_than> false_comparison("car", "bison");

  EXPECT_EQ(true, Comparison_evaluator::evaluate(true_comparison));
  EXPECT_EQ(false, Comparison_evaluator::evaluate(false_comparison));
}
