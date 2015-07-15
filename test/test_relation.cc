#include <gtest/gtest.h>
#include <attribute_list.hh>
#include <relation.hh>

using std::vector;
using std::string;

TEST(RelationTest, CreateWithBadPrimaryKeyThrowsException) {
  string relation_name = "people";
  vector<string> attribute_names = { "name", "age", "state" };
  vector<string> primary_key = { "age", "name" };

  EXPECT_THROW(Relation(relation_name, attribute_names, primary_key), Attribute_list::Primary_key_exception);
}

TEST(RelationTest, AddRow) {
  Relation relation("people", { "name", "age", "state"}, { "name", "age" });
  vector<string> row = { "martin", "15", "texas" };
  relation.add(row);

  EXPECT_EQ(row, relation.get({ "martin", "15" }));
}
