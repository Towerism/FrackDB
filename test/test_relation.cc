#include <gtest/gtest.h>
#include <relation.hh>

using std::vector;
using std::string;

TEST(RelationTest, Create) {
  string relation_name = "people";
  vector<string> attribute_names = { "name", "age" };
  Relation relation(relation_name, attribute_names);

  EXPECT_EQ(relation_name, relation.get_name());
  EXPECT_EQ(attribute_names, relation.get_attribute_names());
  EXPECT_EQ(attribute_names, relation.get_primary_key());
}

TEST(RelationTest, CreateWithPrimaryKey) {
  string relation_name = "people";
  vector<string> attribute_names = { "name", "age", "state" };
  vector<string> primary_key = { "name", "age" };
  Relation relation(relation_name, attribute_names, primary_key);

  EXPECT_EQ(relation_name, relation.get_name());
  EXPECT_EQ(attribute_names, relation.get_attribute_names());
  EXPECT_EQ(primary_key, relation.get_primary_key());
}

TEST(RelationTest, CreateWithBadPrimaryKeyThrowsException) {
  string relation_name = "people";
  vector<string> attribute_names = { "name", "age", "state" };
  vector<string> primary_key = { "age", "name" };

  EXPECT_THROW(Relation(relation_name, attribute_names, primary_key), Relation::Primary_key_exception);
}

TEST(RelationTest, AddRow) {
  Relation relation("people", { "name", "age", "state"}, { "name", "age" });
  vector<string> row = { "martin", "15", "texas" };
  relation.add(row);

  EXPECT_EQ(row, relation.get({ "martin", "15" }));
}
