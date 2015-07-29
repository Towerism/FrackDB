#include <gtest/gtest.h>
#include <querying/select.hh>
#include <relation/var_char_attribute.hh>
#include <evaluation/comparison.hh>

TEST(QueryTest, Select) {
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
