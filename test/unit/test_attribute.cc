#include <gtest/gtest.h>
#include <relation/var_char_attribute.hh>
#include <relation/integer_attribute.hh>

using std::string;
using std::vector;

TEST(AttributeTest, CreateVarChar) {
  Attribute* name = new Var_char_attribute("name", 15);

  EXPECT_TRUE(name->is_type_compatible_with("Harry"));
  delete name;
}

TEST(AttributeTest, CreateInteger) {
  Attribute* age = new Integer_attribute("age");

  EXPECT_TRUE(age->is_type_compatible_with("15"));
  EXPECT_TRUE(age->is_type_compatible_with("-27"));
  delete age;
}

TEST(AttributeTest, VarCharTooLongShouldBeTypeMismatch) {
  Attribute* name = new Var_char_attribute("name", 15);

  EXPECT_FALSE(name->is_type_compatible_with("My name is too long!"));
  delete name;
}

TEST(AttributeTest, StringForIntegerShouldBeTypeMismatch) {
  Attribute* age = new Integer_attribute("age");

  EXPECT_FALSE(age->is_type_compatible_with("Hello!"));
  delete age;
}
