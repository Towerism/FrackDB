#include <gtest/gtest.h>
#include <relation/relation.hh>
#include <relation/row_checker.hh>

using std::vector;
using std::string;

class RelationTest : public ::testing::Test {
public:
  RelationTest() : attribute_list({ new Var_char_attribute("name", 15),
                                    new Integer_attribute("age"),
                                    new Var_char_attribute("state", 15) }) { }
  Attribute_list attribute_list;
};

TEST_F(RelationTest, CreateWithBadPrimaryKeyThrowsException) {
  string relation_name = "people";
  vector<string> primary_key = { "age", "name" };
  EXPECT_THROW(Relation(relation_name, attribute_list, primary_key), Attribute_list::Primary_key_exception);
}

TEST_F(RelationTest, AddRow) {
  Relation relation("people", attribute_list, { "name", "age" });
  vector<string> row = { "martin", "15", "texas" };
  relation.add(row);

  EXPECT_EQ(row, relation.get({ "martin", "15" }));
}

TEST_F(RelationTest, AddLongRowThrowsException) {
  Relation relation("people", attribute_list, { "name", "age" });
  vector<string> row = { "this", "is", "too", "long" };

  EXPECT_THROW(relation.add(row), Row_checker::Row_size_exception);
}

TEST_F(RelationTest, AddShortRowThrowsException) {
  Relation relation("people", attribute_list, { "name", "age" });
  vector<string> row = { "too", "short" };

  EXPECT_THROW(relation.add(row), Row_checker::Row_size_exception);
}

TEST_F(RelationTest, WrongTypesInRowThrowsException) {
  Relation relation("people", attribute_list, { "name", "age" });
  vector<string> row = { "this name is too long!!!!", "this is not an integer", "this state name is too long!!!!" };

  EXPECT_THROW(relation.add(row), Row_checker::Type_match_exception);
}
