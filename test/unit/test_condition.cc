#include <gtest/gtest.h>
#include <evaluation/condition.hh>
#include <relation/relation.hh>
#include <relation/var_char_attribute.hh>

TEST(ConditionTest, And) {
  And true_condition(true, true);
  And false_condition(false, true);

  EXPECT_EQ(true, true_condition.evaluate());
  EXPECT_EQ(false, false_condition.evaluate());
}

TEST(ConditionTest, Or) {
  Or true_condition(true, false);
  Or false_condition(false, false);

  EXPECT_EQ(true, true_condition.evaluate());
  EXPECT_EQ(false, false_condition.evaluate());
}

TEST(ConditionTest, Not) {
  Not true_condition(false);
  Not false_condition(true);

  EXPECT_EQ(true, true_condition.evaluate());
  EXPECT_EQ(false, false_condition.evaluate());
}

TEST(ConditionTest, RecursiveWithoutComparison) {
  And true_condition(std::make_shared<And>(true, std::make_shared<Or>(false, std::make_shared<Not>(false))), std::make_shared<Or>(true, false));
  Or false_condition(std::make_shared<And>(false, std::make_shared<Not>(true)), std::make_shared<And>(false, false));

  EXPECT_EQ(true, true_condition.evaluate());
  EXPECT_EQ(false, false_condition.evaluate());
}

TEST(ConditionTest, RecursiveWithComparison) {
  And true_condition(std::make_shared<Greater_than>(17, 15), std::make_shared<Less_than>(15, 17));
  Not false_condition(std::make_shared<Equal>(15, 15));

  EXPECT_EQ(true, true_condition.evaluate());
  EXPECT_EQ(false, false_condition.evaluate());
}

TEST(ConditionTest, IdentifierSupport) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15) }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin" });
  const Row& row = relation.get( { "martin" });

  And true_condition(std::make_shared<Equal>(Identifier("name"), "martin"), std::make_shared<Not>(false));
  And false_condition(std::make_shared<Equal>(Identifier("name"), "nitram"), std::make_shared<Not>(false));

  EXPECT_EQ(true, true_condition.evaluate(row)); // needs parameter to substitute name identifier
  EXPECT_EQ(false, false_condition.evaluate(row)); // "
}
