#include <gtest/gtest.h>
#include <relation/attribute_list.hh>
#include <relation/integer_attribute.hh>
#include <relation/var_char_attribute.hh>

TEST(AttributeListTest, BadPrimaryKeyThrowsException) {
  Attribute_list* attribute_list;
  EXPECT_THROW(attribute_list = new Attribute_list({ new Var_char_attribute("name", 15)}, { "bad", "primary", "key" }),
               Attribute_list::Primary_key_exception);
}

TEST(AttributeListTest, CreateUsingContiguousPrimaryKey) {
  Attribute_list attribute_list({ new Integer_attribute("a"),
                                  new Integer_attribute("b"),
                                  new Integer_attribute("c") },
                                { "a", "b" });
}

TEST(AttributeListTest, CreateUsingNonContiguousPrimaryKey) {
  Attribute_list attribute_list({ new Integer_attribute("a"),
                                  new Integer_attribute("b"),
                                  new Integer_attribute("c") },
                                { "a", "c" });
}

TEST(AttributeListTest, ConcatenateKeyForRowUsingContiguousPrimaryKey) {
  Attribute_list attribute_list({ new Integer_attribute("a"),
                                  new Integer_attribute("b"),
                                  new Integer_attribute("c") },
                                { "a", "b" });

  EXPECT_EQ("xy", attribute_list.concatenate_key_for({ "x", "y", "z" }));
}

TEST(AttributeListTest, ConcatenateKeyForRowUsingNonContiguousPrimaryKey) {
  Attribute_list attribute_list({ new Integer_attribute("a"),
                                  new Integer_attribute("b"),
                                  new Integer_attribute("c") },
                                { "a", "c" });

  EXPECT_EQ("xz", attribute_list.concatenate_key_for({ "x", "y", "z" }));
}
