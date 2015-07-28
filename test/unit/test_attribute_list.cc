#include <gtest/gtest.h>
#include <relation/attribute_list.hh>
#include <relation/integer_attribute.hh>
#include <relation/primary_key_checker.hh>
#include <relation/var_char_attribute.hh>

TEST(AttributeListTest, BadPrimaryKeyThrowsException) {
  std::unique_ptr<Attribute_list> attribute_list;
  EXPECT_THROW(attribute_list = std::make_unique<Attribute_list>(Attribute_list({ new Var_char_attribute("name", 15)}, { "bad", "primary", "key" })),
               Primary_key_checker::Primary_key_exception);
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

TEST(AttributeListTest, GetIndexMap) {
  Attribute_list attribute_list({ new Integer_attribute("a"),
                                  new Integer_attribute("b"),
                                  new Integer_attribute("c") },
                                { "a", "c" });
  std::map<std::string, int> index_map = attribute_list.get_index_map();

  EXPECT_EQ(0, index_map["a"]);
  EXPECT_EQ(1, index_map["b"]);
  EXPECT_EQ(2, index_map["c"]);
}
