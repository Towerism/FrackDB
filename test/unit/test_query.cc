#include <gtest/gtest.h>
#include <querying/select.hh>
#include <querying/project.hh>
#include <relation/integer_attribute.hh>
#include <relation/var_char_attribute.hh>
#include <relation/row_checker.hh>
#include <evaluation/comparison.hh>

TEST(SelectTest, SelectsMatchedRows) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15) }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin" });
  relation.add({ "rick" });

  std::unique_ptr<Query> query(new Select(new Equal(Identifier("name"), "martin")));
  Relation selected_relation = query->execute(relation);

  const Row& row = selected_relation.get({ "martin" });
  EXPECT_EQ("martin", row.get_var_char("name"));
  EXPECT_EQ(1, selected_relation.size());
}

TEST(ProjectTest, ProjectionHasOnlyThoseChosenAttributes ) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15),
                                  new Integer_attribute("age") }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin", "21" });

  std::unique_ptr<Query> query(new Project({ "name" }));
  Relation projected_relation = query->execute(relation);
  const Row& row = projected_relation.get({ "martin" });

  EXPECT_EQ("martin", row.get_var_char("name"));
  EXPECT_THROW(row.get_int("age"), Row_checker::No_attribute_exception);
}

TEST(ProjectTest, ProjectionHasChosenAttributesAsItsKey) {
  Attribute_list attribute_list({ new Var_char_attribute("name", 15),
                                  new Integer_attribute("age"),
                                  new Var_char_attribute("gender", 6) }, { "name" });
  Relation relation("people", attribute_list);
  relation.add({ "martin", "21", "male" });

  std::unique_ptr<Query> query(new Project({ "name", "age" }));
  Relation projected_relation = query->execute(relation);

  const Row& row = projected_relation.get({ "martin", "21" });
}
