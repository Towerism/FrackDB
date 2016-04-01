#include <gtest/gtest.h>
#include <memory>
#include <evaluation/condition.hh>
#include <relation/relation.hh>
#include <relation/var_char_attribute.hh>

TEST(ConditionTest, And) {
  std::unique_ptr<Condition> true_condition(new And(true, true));
  std::unique_ptr<Condition> false_condition(new And(false, true));

  EXPECT_EQ(true, true_condition->evaluate());
  EXPECT_EQ(false, false_condition->evaluate());
}

TEST(ConditionTest, Or) {
  std::unique_ptr<Condition> true_condition(new Or(true, false));
  std::unique_ptr<Condition> false_condition(new Or(false, false));

  EXPECT_EQ(true, true_condition->evaluate());
  EXPECT_EQ(false, false_condition->evaluate());
}

TEST(ConditionTest, Not) {
  std::unique_ptr<Condition> true_condition(new Not(false));
  std::unique_ptr<Condition> false_condition(new Not(true));

  EXPECT_EQ(true, true_condition->evaluate());
  EXPECT_EQ(false, false_condition->evaluate());
}

TEST(ConditionTest, RecursiveWithoutComparison) {
  std::unique_ptr<Condition> true_condition(new And(new And(true, new Or(false, new Not(false))), new Or(true, false)));
  std::unique_ptr<Condition> false_condition(new Or(new And(false, new Not(true)), new And(false, false)));

  EXPECT_EQ(true, true_condition->evaluate());
  EXPECT_EQ(false, false_condition->evaluate());
}

TEST(ConditionTest, RecursiveWithComparison) {
  std::unique_ptr<Condition> true_condition(new And(new Greater_than(17, 15), new Less_than(15, 17)));
  std::unique_ptr<Condition> false_condition(new Not(new Equal(15, 15)));

  EXPECT_EQ(true, true_condition->evaluate());
  EXPECT_EQ(false, false_condition->evaluate());
}

TEST(ConditionTest, IdentifierSubstitution) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15) }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin" });
  const Row& row = relation.get( { "martin" });

  std::unique_ptr<Condition> true_condition(new And(new Equal(Identifier("name"), "martin"), new Not(false)));
  std::unique_ptr<Condition> false_condition(new And(new Equal(Identifier("name"), "nitram"), new Not(false)));

  EXPECT_EQ(true, true_condition->evaluate(row));
  EXPECT_EQ(false, false_condition->evaluate(row));
}
