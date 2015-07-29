#include <gtest/gtest.h>
#include <memory>
#include <evaluation/comparison.hh>
#include <relation/relation.hh>
#include <relation/var_char_attribute.hh>

TEST(ComparisonTest, LessThan) {
  std::unique_ptr<Comparison> true_comparison(new Less_than(15, 17));
  std::unique_ptr<Comparison> false_comparison(new Less_than(17, 15));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, GreaterThan) {
  std::unique_ptr<Comparison> true_comparison(new Greater_than(17, 15));
  std::unique_ptr<Comparison> false_comparison(new Greater_than(15, 17));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, Equal) {
  std::unique_ptr<Comparison> true_comparison(new Equal(15, 15));
  std::unique_ptr<Comparison> false_comparison(new Equal(15, 17));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, LessEqual) {
  std::unique_ptr<Comparison> true_comparison(new Less_equal(15, 17));
  std::unique_ptr<Comparison> fringe_comparison(new Less_equal(15, 15));
  std::unique_ptr<Comparison> false_comparison(new Less_equal(17, 15));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(true, fringe_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, GreaterEqual) {
  std::unique_ptr<Comparison> true_comparison(new Greater_equal(17, 15));
  std::unique_ptr<Comparison> fringe_comparison(new Greater_equal(15, 15));
  std::unique_ptr<Comparison> false_comparison(new Greater_equal(15, 17));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(true, fringe_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, StringCompare) {
  std::unique_ptr<Comparison> true_comparison(new Less_than("bison", "car"));
  std::unique_ptr<Comparison> false_comparison(new Less_than("car", "bison"));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, BoolCompare) {
  std::unique_ptr<Comparison> true_comparison(new Equal(true, true));
  std::unique_ptr<Comparison> false_comparison(new Equal(true, false));

  EXPECT_EQ(true, true_comparison->evaluate());
  EXPECT_EQ(false, false_comparison->evaluate());
}

TEST(ComparisonTest, IdentifierSubstitution) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15) }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin" });
  const Row& row = relation.get( { "martin" });

  std::unique_ptr<Comparison> true_comparison(new Equal(Identifier("name"), "martin"));
  std::unique_ptr<Comparison> false_comparison(new Equal(Identifier("name"), "nitram"));

  EXPECT_EQ(true, true_comparison->evaluate(row)); // needs parameter to substitute name identifier
  EXPECT_EQ(false, false_comparison->evaluate(row)); // "
}
