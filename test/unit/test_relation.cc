#include <gtest/gtest.h>
#include <relation/relation.hh>
#include <relation/row_checker.hh>
#include <relation/var_char_attribute.hh>
#include <relation/integer_attribute.hh>

using std::vector;
using std::string;

class RelationTest : public ::testing::Test {
public:
  RelationTest() : attribute_list({ new Var_char_attribute("name", 15),
                                    new Integer_attribute("age"),
                                    new Var_char_attribute("state", 15) },
                                  { "name", "age" }) { }
  Attribute_list attribute_list;
};

TEST_F(RelationTest, AddRow) {
  Relation relation("people", attribute_list);
  vector<string> row = { "martin", "15", "texas" };
  relation.add(row);

  EXPECT_EQ(row, relation.get({ "martin", "15" }));
}

TEST_F(RelationTest, AddLongRowThrowsException) {
  Relation relation("people", attribute_list);
  vector<string> row = { "this", "is", "too", "long" };

  EXPECT_THROW(relation.add(row), Row_checker::Row_size_exception);
}

TEST_F(RelationTest, AddShortRowThrowsException) {
  Relation relation("people", attribute_list);
  vector<string> row = { "too", "short" };

  EXPECT_THROW(relation.add(row), Row_checker::Row_size_exception);
}

TEST_F(RelationTest, WrongTypesInRowThrowsException) {
  Relation relation("people", attribute_list);
  vector<string> row = { "this name is too long!!!!", "this is not an integer", "this state name is too long!!!!" };

  EXPECT_THROW(relation.add(row), Row_checker::Type_match_exception);
}
