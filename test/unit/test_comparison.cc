#include <gtest/gtest.h>
#include <evaluation/comparison.hh>
#include <relation/relation.hh>
#include <relation/var_char_attribute.hh>

TEST(ComparisonTest, LessThan) {
  Less_than true_comparison(15, 17);
  Less_than false_comparison(17, 15);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, GreaterThan) {
  Greater_than true_comparison(17, 15);
  Greater_than false_comparison(15, 17);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, Equal) {
  Equal true_comparison(15, 15);
  Equal false_comparison(15, 17);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, LessEqual) {
  Less_equal true_comparison(15, 17);
  Less_equal fringe_comparison(15, 15);
  Less_equal false_comparison(17, 15);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(true, fringe_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, GreaterEqual) {
  Greater_equal true_comparison(17, 15);
  Greater_equal fringe_comparison(15, 15);
  Greater_equal false_comparison(15, 17);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(true, fringe_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, StringCompare) {
  Less_than true_comparison("bison", "car");
  Less_than false_comparison("car", "bison");

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, BoolCompare) {
  Equal true_comparison(true, true);
  Equal false_comparison(true, false);

  EXPECT_EQ(true, true_comparison.evaluate());
  EXPECT_EQ(false, false_comparison.evaluate());
}

TEST(ComparisonTest, IdentifierSupport) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15) }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin" });
  const Row& row = relation.get( { "martin" });

  Equal true_comparison(Identifier("name"), "martin");
  Equal false_comparison(Identifier("name"), "nitram");

  EXPECT_EQ(true, true_comparison.evaluate(row)); // needs parameter to substitute name identifier
  EXPECT_EQ(false, false_comparison.evaluate(row)); // "
}
