#include <gtest/gtest.h>
#include <relation/relation.hh>

using std::vector;
using std::string;

TEST(RelationTest, CreateWithBadPrimaryKeyThrowsException) {
  string relation_name = "people";
  vector<string> attribute_names = { "name", "age", "state" };
  vector<string> primary_key = { "age", "name" };
  EXPECT_THROW(Relation(relation_name, attribute_names, primary_key), Attribute_list::Primary_key_exception);
}

TEST(RelationTest, AddRow) {
  Relation relation("people", { "name", "age", "state" }, { "name", "age" });
  vector<string> row = { "martin", "15", "texas" };
  relation.add(row);

  EXPECT_EQ(row, relation.get({ "martin", "15" }));
}

TEST(RelationTest, AddLongRowThrowsException) {
  Relation relation("people", { "name", "age", "state" });
  vector<string> row = { "this", "is", "too", "long" };

  EXPECT_THROW(relation.add(row), Attribute_list::Row_size_exception);
}

TEST(RelationTest, AddShortRowThrowsException) {
  Relation relation("people", { "name", "age", "state" });
  vector<string> row = { "too", "short" };

  EXPECT_THROW(relation.add(row), Attribute_list::Row_size_exception);
}
