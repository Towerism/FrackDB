#include <gtest/gtest.h>
#include <relation/var_char_attribute.hh>
#include <relation/integer_attribute.hh>

using std::string;
using std::vector;

class AttributeTest : public ::testing::Test {
public:

  ~AttributeTest() { delete attribute; }

  Attribute* attribute = nullptr;
};

TEST_F(AttributeTest, CreateVarChar) {
  attribute = new Var_char_attribute("name", 15);

  EXPECT_TRUE(attribute->is_type_compatible_with("Harry"));
}

TEST_F(AttributeTest, CreateInteger) {
  attribute = new Integer_attribute("funds");

  EXPECT_TRUE(attribute->is_type_compatible_with("15"));
  EXPECT_TRUE(attribute->is_type_compatible_with("-27"));
}

TEST_F(AttributeTest, VarCharTooLongShouldBeTypeMismatch) {
  attribute = new Var_char_attribute("name", 15);

  EXPECT_FALSE(attribute->is_type_compatible_with("My name is too long!"));
}

TEST_F(AttributeTest, StringForIntegerShouldBeTypeMismatch) {
  attribute = new Integer_attribute("age");

  EXPECT_FALSE(attribute->is_type_compatible_with("Hello!"));
}
